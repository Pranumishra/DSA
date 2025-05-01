#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    int n;
    int k;
    while(t--){
        cin>>n;
        cin>>k;
        vector<int>arr(n);
        bool ans=false;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==k){
                ans=true;
            }
        }
        if(ans){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
}