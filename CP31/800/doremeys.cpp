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

        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }

        int ans=0;
        if(mpp.size()==1){
            cout<<"YES"<<endl;
        }
        else if(mpp.size()==2){
            for(auto it:mpp){
                if(ans==0){
                    ans+=it.second;
                }
                else{
                    ans-=it.second;
                }
            }
            if(abs(ans)<=1){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}