#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int mini=INT_MAX;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]<mini){
                mini=arr[i]-arr[i-1];
            }
        }

        if(mini<0){
            cout<<0<<endl;
        }
        else{
            cout<<(mini/2)+1<<endl;
        }
    }
}