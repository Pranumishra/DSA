#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    int n;
    for(int a=1;a<=t;a++){
        cin>>n;
        vector<int>ans(n);
        if(n&1){
            int temp=n;
            int k=1;
            for(int j=1;j<=n;j++){
                if(temp!=-1){
                    cout<<temp<<" ";
                    temp=temp-2;
                }
                else{
                    int result=2*k;
                    cout<<result<<" ";
                    k++;
                }
            }
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}