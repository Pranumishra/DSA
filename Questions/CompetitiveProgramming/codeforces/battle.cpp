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
        int sum=0;
        for(int i=0;i<n-2;i++){
            arr[n-2]=arr[n-2]-arr[i];
        }
        int ans=arr[n-1]-arr[n-2];
        cout<<ans<<endl;

    }
}