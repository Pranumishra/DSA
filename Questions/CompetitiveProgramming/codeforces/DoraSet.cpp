#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;

    int l;
    int r;

    while(t--){
        cin>>l;
        cin>>r;

        if(r-l+1<3){
            cout<<0<<endl;
            continue;
        }
        int s;
        int e;
        if(l&1){
            s=l;
        }
        else{
            s=l+1;
        }

        if(r&1){
            e=r;
        }
        else{
            e=r-1;
        }

        if(e==s){
            cout<<0<<endl;
            continue;           
        }
        else{
            e=e-2;
            int ans=(e-s)/4;
            ans++;
            cout<<ans<<endl;
        }

    }

}
