#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    int n;
    for(int a=1;a<=t;a++){
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        if(n==1){
            cout<<0<<endl;
        }
        else{
            map<int,int>mpp;
            int j=0;
            while(j<n){
                mpp[arr[j]]++;
                j++;
            }      
            int count=0;
            for(int k=0;k<n;k++){
                if(mpp[arr[k]]>count){
                    count=mpp[arr[k]];
                }
            }
            cout<<n-count<<endl;
        }
        
    }
}

