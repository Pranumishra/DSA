#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int arr[10]={1,2,3,3,3,3,4,5,5,7};
    int target=5;
    int start=0;
    int end=9;
    int ans=-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==target){
            ans=mid;
            start=mid+1;
        }
        else if(arr[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    cout<<ans<<endl;
}