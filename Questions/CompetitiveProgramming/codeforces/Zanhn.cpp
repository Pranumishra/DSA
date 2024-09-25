#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    int n;
    int x;
    int y;
    while(t--){
        cin>>n;
        cin>>x;
        cin>>y;
        int mini=min(x,y);
        int ans=n/mini;
        n=n-(mini*ans);
        if(n!=0){
            ans+=1;
        }
        cout<<ans<<endl;


    }
}