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

class Queue{
    public:
        int size;
        Node* front;
        Node* rear;

        Queue(){
            this->size=0;
            this->front=NULL;
            this->rear=NULL;
        }

        void push(int data){
            Node* newNode=new Node(data);
            if(front==NULL && rear==NULL){
                front=newNode;
                rear=newNode;
                size++;
            }
            else{
                rear->next=newNode;
                rear=newNode;
                size++;
            }
        }

        void pop(){
            if(front==NULL && rear==NULL){
                cout<<"empty queue cant pop"<<endl;
            }
            else if(front==NULL){
                Node* temp=rear;
                rear=front;
                delete temp;
            }
            else{
                Node* temp=front;
                front=front->next;
                temp->next=NULL;
                delete temp;
                size--;
            }

        }
        void print(){
            Node* temp=front;
            while(temp!=NULL){
                cout<<temp->val<<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
        int getsize(){
            return size;
        }
        int top(){
            return front->val;
        }

};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(50);
    q.push(100);
    q.push(150);
    q.print();
    // cout<<q.getsize()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(1);
    q.push(2);
    q.push(10);
    q.push(15);
    q.pop();
    q.pop();
    q.push(999);
    cout<<q.top()<<endl;
    q.print();
    // q.pop();
    // cout<<q.top()<<endl;
    // cout<<q.getsize()<<endl;
    // q.push(1000);
    // q.push(15000);
    // cout<<q.getsize()<<endl;
    // q.push(15000);
}
