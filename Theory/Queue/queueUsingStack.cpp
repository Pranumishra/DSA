#include<iostream>
using namespace std;
#include<stack>

class Queue{
    public:
        stack<int>s1;
        stack<int>s2;

        void push(int val){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(val);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();                
            }
        }
        void pop(){
            s1.pop();
        }
        int top(){
            return s1.top();
        }
};

int main(){
    Queue st;
    st.push(12);
    st.push(13);
    st.push(14);
    st.pop();
    st.pop();
    st.push(123);
    st.pop();
    cout<<st.top()<<endl;


}
