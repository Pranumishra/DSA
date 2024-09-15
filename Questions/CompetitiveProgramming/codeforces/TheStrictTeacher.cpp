#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;

    int n;
    int m;
    int q;

    while(t--){
        cin>>n;
        cin>>m;
        cin>>q;
        vector<int>qry(q);
        vector<int>teacher(m);
        for(int i=0;i<m;i++){
            cin>>teacher[i];
        }
        for(int i=0;i<q;i++){
            cin>>qry[i];
        }
        int ans=0;
        if(teacher[0]>qry[0] && teacher[1]>qry[0]){
            int sir = min(teacher[0],teacher[1]);
            ans=sir-1;
            cout<<ans<<endl;
        }
        else if(teacher[0]<qry[0] && teacher[1]<qry[0]){
            int sir = max(teacher[0],teacher[1]);
            ans=n-sir;
            cout<<ans<<endl;           
        }
        else{
            int sir1=min(teacher[0],teacher[1]);
            int sir2=max(teacher[0],teacher[1]);
            ans=sir2-sir1;
            if(ans==2){
                ans=1;
            }
            else{
                ans=ans-2;
            }
            cout<<ans<<endl;
        }
        

    }
}