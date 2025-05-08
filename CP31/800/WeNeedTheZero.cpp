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

        int xorr=0;
        for(int i=0;i<n;i++){
            xorr^=arr[i];
        }

        if(xorr==0){
            cout<<0<<endl;
        }
        else{
            if(n&1){
                cout<<xorr<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
        
    }
}