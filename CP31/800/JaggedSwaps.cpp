#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        string ans="YES";
        if(arr[0]!=1){
            ans="NO";
        }
        cout<<ans<<endl;
    }
}