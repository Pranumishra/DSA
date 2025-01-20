#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int main() {
    long long t;
    cin >> t;

    int n,a,b;
    while(t--){
        cin>>n>>a>>b;
        int ans=abs(a-b)-1;
        if(ans&1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}