#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int min=INT_MAX;
    for(int i=0;i<n;i++){
        if(abs(arr[i]-0)<min){
            min=abs(arr[i]-0);
        }
    }

    cout<<min<<endl;
}