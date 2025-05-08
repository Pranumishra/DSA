#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;

    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        int diff1=c-a;
        int diff2=d-b;

        if((diff1>diff2) || diff2<0){
            cout<<-1<<endl;
        }
        else{
            int ans=0;
            ans+=diff2;
            ans+=(a+diff2-c);
            cout<<ans<<endl;
        }
    }
}