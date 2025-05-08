#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int pos=0;
        int neg=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                pos++;
            }
            else{
                neg++;
            }
        }

        if(pos>=neg){
            if(neg&1){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else{
            int count=0;
            while(neg>pos){
                pos++;
                neg--;
                count++;
            }
            if(neg&1){
                cout<<count+1<<endl;
            }
            else{
                cout<<count+0<<endl;
            }            
        }
    }
}