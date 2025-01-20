#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){

    long long n;
    cin>>n;
    vector<long long>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]=abs(arr[i]);
    }
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<mini){
            mini=arr[i];
        }
    }
    cout<<mini<<endl;

}