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
        string s;
        cin>>s;

        map<char,int>mpp;
        for(auto ch:s){
            mpp[ch]++;
        }

        int odd=0;
        for(auto it:mpp){
            if(it.second&1){
                odd++;
            }
        }

        if(odd-k<=1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        
    }
}