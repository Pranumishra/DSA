#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    vector<int>arr={1,4,6,2,4,8,6,9,0,2};
    //Suppose we are sorting in ascending order 
    //we will find the smallest element and place it at ith postion . initially i starts from 0; 
    //then we will move i forward and apply the above step.

    for(int i=0;i<arr.size()-1;i++){
        int minIndex=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[minIndex]>arr[j]){
                minIndex=j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//In selection sort we are selecting the smallest element index for the ith index till last and the swap it with the ith index element.