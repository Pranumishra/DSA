#include<iostream>
using namespace std;

class Stack{
    public:
        int size;
        int top;
        int *arr;

        Stack(int size){
            this->size=size;
            this->top=-1;
            arr=new int [size];
        }

        void push(int val){
            if(top==size-1){
                cout<<"Overflow";
            }
            else{
                top++;
                arr[top]=val;
            }
        }

        void pop(){
            if(top==-1){
                cout<<"Underflow";
            }
            else{
                top--;
            }
        }

        bool isEmpty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }
        int getsize(){
            return top+1;
        }

        int getTop(){
            if(top==-1){
                cout<<"Stack is empty";
            }
            else{
                return arr[top];
            }
            
        }

        //this is not a stack function just to get the clear visualization of implementation.
        void print(){
            if(top==-1){
                cout<<"No element to print";
            }
            else{
                for(int i=0;i<=top;i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
        }

};

int main(){
    Stack st(10);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    cout<<st.isEmpty()<<endl;

    // st.pop();
    // st.pop();

    // cout<<st.getsize();

    // st.pop();
    // st.pop();
    // st.print();

    // st.pop();
    // st.pop();

    // cout<<st.isEmpty()<<endl;
    // st.print(); 


    // st.pop();
    return 0;
}