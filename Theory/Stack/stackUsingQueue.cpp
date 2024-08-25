#include<iostream>
using namespace std;
#include<queue>

class Stack{
    public:
    queue<int>q;

    void push(int val){
        q.push(val);
        for(int i=1;i<q.size();i++){
            q.push(q.front());
            q.pop();
        }
    }
    void pop(){
        q.pop();
    }
    int top(){
        return q.front();
    }
    int size(){
        return q.size();
    }

};

int main(){
    Stack st;
    st.push(12);
    st.push(13);
    st.push(14);
    st.pop();
    st.pop();
    st.push(123);
    st.pop();
    cout<<st.top()<<endl;


}