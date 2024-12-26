#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    long long t;
    cin>>t;
    long long n;
    long long d;
    while(t--){
        cin>>n;
        cin>>d;
        cout<<1<<" ";
        if(n>=3 || (d%3==0)){
            cout<<3<<" ";
        }
        if(d==5){
            cout<<5<<" ";
        }
        if(n>=3 || (d==7)){
            cout<<7<<" ";
        }

        if(n>=6){
            cout<<9<<" ";
        }
        else{
            int prod=1;
            for(int i=1;i<=n;i++){
                prod=prod*i;
            }
            prod=prod*d;
            if(prod%9==0){
                cout<<9<<" ";
            }
        }
        cout<<endl;
    }    
}