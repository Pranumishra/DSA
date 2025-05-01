#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    int n;
    int m;
    while(t--){
        cin>>n;
        cin>>m;
        string x,s;
        cin>>x;
        cin>>s;

        int ans=0;
        while(x.length()<2*s.length() || ans==0){
            if(x.length()==s.length() && x.compare(s)==0){
                break;
            }
            if(x.find(s)!=string::npos){
                break;
            }
            x=x+x;
            ans++;
        }
        if(x.find(s)!=string::npos){
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}