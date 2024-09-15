#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    vector<int>arr={1,4,6,2,4,8,6,9,0,2};
    //isme humlog sochte hai ki elements insert ho rahe hai one by one from zeroth index.
    //first element will always be sorted 
    //when we are placing 2nd element we need to place it such that array remains sorted.

    //therfore our objective is to place the kth element such that the previously sorted array still remain sorted after the insertion of kth element

    int n=arr.size();
    for(int i=0;i<n;i++){
        int currElement=arr[i];
        int j=i-1;
        while(j>=0 && currElement<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=currElement;
    }

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}