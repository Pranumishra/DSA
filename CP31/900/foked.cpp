#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    int a;
    int b;
    while(t--){
        cin>>a;
        cin>>b;
        int xk;
        int yk;
        cin>>xk;
        cin>>yk;
        int xq;
        int yq;
        cin>>xq;
        cin>>yq;
        int ans=0;
        if(a==b){
            int xarr[4]={-1*a,-1*a,a,a};
            int yarr[4]={-1*b,b,-1*b,b};
            map<pair<int,int>,int>mpp;
            for(int i=0;i<4;i++){
                mpp[{xk-xarr[i],yk-yarr[i]}]=1;
            }
            for(int i=0;i<4;i++){
                if(mpp.find({xq-xarr[i],yq-yarr[i]})==mpp.end()){
                }
                else{
                    // cout<<"values : "<<xq-xarr[i]<<" "<<yq-yarr[i]<<endl;
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
        else{
            int xarr[8]={-1*a,-1*a,a,a,-1*b,-1*b,b,b};
            int yarr[8]={-1*b,b,-1*b,b,-1*a,a,-1*a,a};
            int ans=0;
            map<pair<int,int>,int>mpp;
            for(int i=0;i<8;i++){
                mpp[{xk-xarr[i],yk-yarr[i]}]=1;
            }
            for(int i=0;i<8;i++){
                if(mpp.find({xq-xarr[i],yq-yarr[i]})==mpp.end()){
                }
                else{
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
}