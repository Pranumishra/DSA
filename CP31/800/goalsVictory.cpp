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
        for(int i=0;i<n-1;i++){
            cin>>arr[i];
        }
        int sum=0;
        for(int i=0;i<n-1;i++){
            sum-=arr[i];
        }
        cout<<sum<<endl;
    }
}