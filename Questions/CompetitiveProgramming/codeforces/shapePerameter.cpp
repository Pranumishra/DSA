#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int main() {
    long long t;
    cin >> t;

    long long n,m;

    while(t--){
        cin>>n>>m;
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i].first;
            cin>>arr[i].second;
        }
        int ans=0;
        ans+=(4*m);
        for(int i=1;i<n;i++){
            ans+=2*arr[i].first;
            ans+=2*arr[i].second;
        }
        cout<<ans<<endl;
    }
}