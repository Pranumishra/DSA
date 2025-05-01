#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        string str;
        cin>>str;
        int ans=0;
        int count=0;
        int c=0;
        for(auto s:str) {
            if(s=='.'){
                count++;
                c++;
                if(count==3){
                    ans=2;
                    break;
                }
            }
            else{
                count=0;
            }
        }
        if(ans==0){
            ans=c;
        }
        cout<<ans<<endl;
    }
}