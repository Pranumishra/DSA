#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    int n;
    int k;
    int x;
    while(t--){
        cin>>n;
        cin>>k;
        cin>>x;
        int sum=0;
        while(k--){
            sum+=n;
            n--;
        }
        if(sum>=x){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}