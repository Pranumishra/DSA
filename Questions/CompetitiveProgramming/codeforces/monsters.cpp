#include <iostream>
using namespace std;
#include<bits/stdc++.h>

bool mycomp(pair<long long ,long long>a,pair<long long ,long long>b){
    if(a.second == b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}
int main() {
    long long t;
    cin >> t;
    long long n,k;

    while(t--){
        cin>>n;
        cin>>k;
        vector<long long>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<pair<long long ,long long>>mpp;
        for(int i=0;i<n;i++){
            mpp.push_back({i,arr[i]%k});
        }

        for(int i=0;i<n;i++){
            if(mpp[i].second==0)
            cout<<mpp[i].first+1<<" ";
        }

        sort(mpp.begin(),mpp.end(),mycomp);

        for(int i=0;i<n;i++){
            if(mpp[i].second!=0)
            cout<<mpp[i].first+1<<" ";
        }
        cout<<endl;
    }
}