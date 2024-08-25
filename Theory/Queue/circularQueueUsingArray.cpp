#include<iostream>
using namespace std;

class Queue{
    public:
        int size;
        int* arr;
        int front;
        int rear;
        int currSize;

        Queue(int size){
            this->size=size;
            arr=new int [size];
            this->front=-1;
            this->rear=-1;
            this->currSize=0;
        }

        void push(int val){
            if(currSize==size){
                cout<<"can't push"<<endl;
            }
            else if(rear==-1 && front==-1){
                rear++;
                front++;
                arr[rear]=val;
                currSize++;
            }
            else{
                rear=(rear+1)%size;
                arr[rear]=val;
                currSize++;
            }
        }

        void pop(){
            if(currSize==0){
                cout<<"can't pop"<<endl;
            }
            else if(front==rear){
                //single element
                arr[front]=-1;
                front=-1;
                rear=-1;
                currSize--;
            }
            else{
                arr[front]=-1;
                front++;
                currSize--;
            }
        }

        int top(){
            if(currSize==0){
                cout<<"empty queue";
                return -1;
            }
            else{
                return arr[front];
            }
        }


        int getsize(){
            return currSize;
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

    q.push(1000);
    q.push(9000);
    cout<<q.getsize()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.push(15000);

    q.push(1000);
    q.push(9000);

    cout<<q.getsize()<<endl;

    // q.pop();
    // q.pop();
    // q.push(1);
    // cout<<q.getsize()<<endl;
    // cout<<q.top();
}