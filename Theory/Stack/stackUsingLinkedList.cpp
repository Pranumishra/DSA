#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(){
            this->next=NULL;
        }
        Node(int val){
            this->val=val;
            this->next=NULL;
        }
};

class Stack{
    public:
        int size;
        Node* top1;

        Stack(){
            this->size=0;
            this->top1=NULL;
        }

        void push(int data){
            Node* newNode=new Node(data);
            newNode->next=top1;
            top1=newNode;
            size++;
        }

        void pop(){
            if(top1==NULL){
                cout<<"emptyLL"<<endl;  
            }
            else{
                Node* temp=top1;
                top1=top1->next;
                temp->next=NULL;
                delete temp;
                size--;
            }

        }
        void print(){
            Node* temp=top1;
            while(temp!=NULL){
                cout<<temp->val<<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
        int givesize(){
            return size;
        }
        int top(){
            return top1->val;
        }
};

int main(){
    Stack st;

    st.push(1);
    st.push(4);
    st.push(5);
    cout<<st.top()<<endl;
    st.push(6);
    // st.print();
    // cout<<st.givesize()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.top()<<endl;
    // cout<<st.givesize()<<endl;
    // st.pop();
    // st.pop();
    // st.print();
    // cout<<st.givesize()<<endl;
}