#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    long long t;
    cin>>t;
    long long n;

    while(t--){
        cin>>n;
        long long ans=1;
        while(n>3){

            ans=(ans*2);
            n=n/4;
        }
        cout<<ans<<endl;
    }    
}