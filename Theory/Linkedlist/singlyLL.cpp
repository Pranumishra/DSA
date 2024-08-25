#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

int findTail(Node* &head){
    int count=1;
    Node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
        count++;
    }
    return count;
}

// inserting in linked list

void insert_at_head(Node* &head,int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
}

void insert_at_tail(Node* &head,int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=newNode;
    }
    else{
        Node* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=newNode;
    }
}

void insert_at_position(Node* &head,int val,int pos){
    int n =findTail(head);
    if(pos<=1){
        insert_at_head(head,val);
    }
    else if(pos>=n+1){
        insert_at_tail(head,val);
    }
    else{
        // Node*newNode=new Node(val);
        // Node*curr=head;
        // Node*prev=NULL;
        // while(pos!=1){
        //     prev=curr;
        //     curr=curr->next;
        //     pos--;
        // }
        // prev->next=newNode;
        // newNode->next=curr;


        //implemented only using prev Node.

        Node*newNode=new Node(val);
        Node*prev=head;
        while(pos!=2){
            prev=prev->next;
            pos--;
        }
        newNode->next=prev->next;
        prev->next=newNode;

    }
}


//deleting from linkedlist

void deleteNode(Node* &head,int pos){

    if(head==NULL){
        cout<<"Empty LL"<<endl; 
    }
    int n=findTail(head);
    if(pos==1){
        //deleting from head
        
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;

    }
    else if(pos==n){
        //deleting from tail
        Node* temp=head;
        Node* lastNode=NULL;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        lastNode=temp->next;
        temp->next=NULL;
        delete lastNode;
    }
    else{
        //deleting from middle
        Node*curr=head;
        Node*prev=NULL;
        while(pos!=1){
            prev=curr;
            curr=curr->next;
            pos--;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }

}



void PrintLL(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}


int main(){

           // MANUAL WAY.

    // Node* first=new Node(20);
    // Node* second=new Node(30);
    // Node* third=new Node(40);
    // Node* fourth=new Node(50);
    // Node* fifth=new Node(60);
    // Node* sixth=new Node(70);
    // Node* seventh=new Node(80);

    // first->next=second;
    // second->next=third;
    // third->next=fourth;
    // fourth->next=fifth;
    // fifth->next=sixth;
    // sixth->next=seventh;

    // Advance way.
    Node* head=NULL;
    insert_at_head(head,10);
    insert_at_head(head,20);
    insert_at_head(head,30);
    insert_at_head(head,40);
    insert_at_head(head,50);
    insert_at_head(head,60);
    insert_at_head(head,70);
    insert_at_head(head,80);
    insert_at_tail(head,9);
    insert_at_tail(head,1);
    PrintLL(head);
    // insert_at_position(head,3000,1);
    // insert_at_position(head,555,7);
    // PrintLL(head);
    // insert_at_position(head,999,3);
    // PrintLL(head);

    // PrintLL(head);
    // deleteNode(head,6);
    // deleteNode(head,5);
    // deleteNode(head,3);
    // deleteNode(head,1);
    // deleteNode(head,1);
    // deleteNode(head,1);
    // deleteNode(head,1);

    // PrintLL(head);
    PrintLL(head);

    return 0;
}