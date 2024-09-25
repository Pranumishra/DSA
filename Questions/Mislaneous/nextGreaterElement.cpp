#include<iostream>
using namespace std;
#include<vector>
#include<stack>

int main(){
    vector<int>arr={1,2,3,4};
    vector<int>ans(4);
    stack<int>st;
    st.push(-1);
    for(int i=arr.size()-1;i>=0;i--){
        if(st.top()==-1){
            ans[i]=st.top();
            st.push(arr[i]);
        }
        else if(st.top()>arr[i]){
            ans[i]=st.top();
            st.push(arr[i]);
        }
        else{
            while(st.top()!=-1 && st.top()<=arr[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(arr[i]);            
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}