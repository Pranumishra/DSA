#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;

    while(t--){
        int a,b,c;
        cin>>a>>b>>c;

        if(c&1){
            //kate will start
            if(b>a){
                cout<<"Second"<<endl;
            }
            else{
                cout<<"First"<<endl;
            }
        }
        else{
            //anna will start
            if(a>b){
                cout<<"First"<<endl;
            }
            else{
                cout<<"Second"<<endl;
            }
        }
    }
}