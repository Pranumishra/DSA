#include<iostream>
using namespace std;

class Queue{
    public:
        int size;
        int* arr;
        int front;
        int rear;

        Queue(int size){
            this->size=size;
            arr=new int [size];
            this->front=-1;
            this->rear=-1;
        }

        void push(int val){
            if(rear==size-1){
                cout<<"can't push"<<endl;
            }
            else if(rear==-1 && front==-1){
                rear++;
                front++;
                arr[rear]=val;
            }
            else{
                rear++;
                arr[rear]=val;
            }
        }

        void pop(){
            if(rear==-1 && front==-1){
                cout<<"can't pop"<<endl;
            }
            else if(front==rear){
                //single element
                arr[front]=-1;
                front=-1;
                rear=-1;
            }
            else{
                arr[front]=-1;
                front++;
            }
        }

        int top(){
            if(front==-1){
                cout<<"empty queue";
                return -1;
            }
            else{
                return arr[front];
            }
        }


        int back(){
            if(rear==-1){
                cout<<"empty queue";
                return -1;
            }
            if(rear==size-1){
                cout<<"full queue";
                return -1;
            }
            else{
                return arr[rear];
            }
        }
        int getsize(){
            return rear-front+1;
        }
};

int main(){
    Queue q(10);
    q.push(1);
    q.push(15);
    q.push(10);
    q.push(150);
    q.push(100);
    q.push(150);
    q.push(1000);
    q.push(15000);
    cout<<q.getsize()<<endl;
    q.pop();
    q.pop();
    cout<<q.getsize()<<endl;
    q.push(1000);
    q.push(15000);
    cout<<q.getsize()<<endl;
    q.push(15000);
}