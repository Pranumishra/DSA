#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(){
        this->next=NULL;
        this->prev=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

//finding the length
int findLength(Node* &head){
    if(head==NULL){
        return 0;
    }
    int count=1;
    Node* curr=head;
    while(curr->next!=head){
        curr=curr->next;
        count++;
    }
    return count;
}

//printing the ll
void PrintLL(Node* &head){
    Node* temp=head;
    while(temp->next!=head){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<"->";
    cout<<endl;
}

//INSERTION

void insertAtHead(Node* &head,int val){
    Node* newNode= new Node(val);
    if(head==NULL){
        head=newNode;
        head->next=head;
        head->prev=head;
    }
    else{
        newNode->next=head;
        head->prev=newNode;
        while(head->next!=head){
            head=head->next;
        }
        head->next=newNode;
        newNode->prev=head;
        head=newNode;
    }
}

void insertAtTail(Node* &head,int val){
    Node* newNode= new Node(val);
    Node* temp=head;
    if(head==NULL){
        head=newNode;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }

}

void insertAtPos(Node* &head,int val,int pos){
    int n=findLength(head);
    if(pos==1){
        //insert at head
        insertAtHead(head,val);
    }
    else if(pos==n+1){
        //at tail
        insertAtTail(head,val);
    }
    else{
        //middle
        Node* newNode= new Node(val);
        Node* temp=head;
        while(pos!=1){
            temp=temp->next;
            pos--;
        }
        temp->prev->next=newNode;
        newNode->prev=temp->prev;
        newNode->next=temp;
        temp->prev=newNode;
    }
}


//DELETION

void deleteNode(Node*&head,int pos){
    if(head==NULL){
        cout<<"LL is empty";
        return;
    }
    int n=findLength(head);
    if(n==1){
        //single node
        Node* temp=head;
        delete temp;
        head=NULL;
    }
    else if(pos==1){
        //deletion from head
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        head->prev=NULL;
        delete temp;


    }
    else if(pos==n){
        //deletion from end
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        temp->prev=NULL;
        delete temp;

    }
    else{
        Node* currNode=head;
        Node* prevNode=NULL;
        while(pos!=1){
            pos--;
            prevNode=currNode;
            currNode=currNode->next;
        }
        prevNode->next=currNode->next;
        currNode->next->prev=currNode->prev;
        currNode->next=NULL;
        currNode->prev=NULL;
        delete currNode;
    }
}
int main(){
    Node*head=NULL;
    insertAtHead(head,30);
    // insertAtTail(head,50);
    // insertAtTail(head,60);
    insertAtHead(head,20);
    insertAtHead(head,10);
    PrintLL(head);
    // insertAtPos(head,40,4);
    // PrintLL(head);

    // deleteNode(head,1);
    // deleteNode(head,1);
    // deleteNode(head,1);
    // deleteNode(head,1);
    // deleteNode(head,1);

    cout<<findLength(head);
    return 0;
}
