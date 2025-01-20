#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;

    int n;
    while(t--){
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int zc=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                zc++;
            }
        }

        if(zc==n){
            cout<<0<<endl;
        }
        else if(zc==0){
            cout<<1<<endl;
        }
        else{
            int c=0;
            int i=0;
            int j=n-1;
            while(arr[i]==0 && i<n){
                i++;
                c++;
            }
            while(arr[j]==0 && j>=0){
                j--;
                c++;
            }

            if(c==zc){
                cout<<1<<endl;
            }
            else{
                cout<<2<<endl;
            }
        }
    }

}