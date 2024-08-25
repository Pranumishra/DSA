#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    int n;
    int k;

    for(int l=0;l<t;l++){
        cin>>n;
        cin>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end(),greater<int>());
        int i=1;
        while(k>0 && i<n){
            if(arr[i]<arr[i-1]){
                if(k>0){
                    int diff=arr[i-1]-arr[i];
                    if(diff<=k){
                        arr[i]+=diff;
                        k=k-diff;
                    }
                    else{
                        arr[i]+=k;
                        k=0;                    
                    }
                }
            }
            i=i+2;
        }
        int A=0;
        int B=0;
        for(int j=0;j<n;j++){
            if(j&1){
                B+=arr[j];
            }
            else{
                A+=arr[j];
            }
        }
        int ans=A-B;
        cout<<ans<<endl;
    }
}