#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    vector<int>arr={1,4,6,2,4,8,6,9,0,2};
    //Suppose we are sorting in ascending order 
    //in bubble sort we are placing the greatest element at last position 
    //therefore after k iterations k greatest elements will be at the last of the array
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}