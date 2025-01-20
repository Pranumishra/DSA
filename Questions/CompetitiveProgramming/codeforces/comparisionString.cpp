#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    long long t;
    cin>>t;
    long long n;
    string str;
    while(t--){
        cin>>n;
        cin>>str;
        long long ans=1;
        char maxe=str[0];
        long long maxc=1;

        for(int i=1;i<n;i++){
            if(str[i]==maxe){
                maxc++;
                if(maxc>ans){
                    ans=maxc;
                }
            }
            else{
                if(maxe=='<'){
                    maxe='>';
                }
                else{
                    maxe='<';
                }
                maxc=1;
            }
        }
        cout<<ans+1<<endl;
    }    
}