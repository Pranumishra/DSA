#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        if((n-1)%3==0 || (n+1)%3==0){
            cout<<"First"<<endl;
        }
        else{
            cout<<"Second"<<endl;
        }
    }
}