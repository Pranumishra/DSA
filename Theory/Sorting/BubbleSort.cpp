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
    vector<int>arr1(arr);
    vector<int>arr2(arr);
    int c1=0;
    int c2=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr1[j]>arr1[j+1]){
                swap(arr1[j],arr1[j+1]);
                c1++;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr2[j]<arr2[j+1]){
                swap(arr2[j],arr2[j+1]);
                c2++;
            }
        }
    }

    int ans=min(c1,c2);
    cout<<ans<<endl;
}