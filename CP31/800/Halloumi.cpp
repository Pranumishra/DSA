#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    int n;
    int k;
    while(t--){
        cin>>n;
        cin>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(k==1){
            bool found=true;
            for(int i=0;i<n-1;i++){
                if(arr[i]>arr[i+1]){
                    found=false;
                    break;
                }
            }
            if(found){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
            
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
}