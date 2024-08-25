#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    int n;
    string str;

    for(int l=0;l<t;l++){
        cin>>n;
        cin>>str;

        if(str[0]!=str[n-1]){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        
    }
}