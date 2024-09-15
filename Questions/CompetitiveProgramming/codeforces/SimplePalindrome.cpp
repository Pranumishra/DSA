#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;

    int n;

    while(t--){
        cin>>n;
        vector<char>vowel={'a','e','i','o','u'};
        string ans="";
        int rem=n%5;
        int q=n/5;
        for(int i=0;i<5;i++){
            for(int j=0;j<q;j++){
                ans+=vowel[i];
            }
            if(rem!=0){
                ans+=vowel[i];
                rem--;
            }
        }
        cout<<ans<<endl;
    }

}