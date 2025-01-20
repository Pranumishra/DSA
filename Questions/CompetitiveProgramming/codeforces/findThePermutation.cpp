#include <iostream>
using namespace std;
#include<bits/stdc++.h>
// bool compareBySecond(const pair<int, int>& a, const pair<int, int>& b) {
//     if(a.second==b.second){
//         return a.first>b.first;
//     }
//     else if(a.second < b.second){
//         return true;
//     }
//     else{
//         return false;
//     }
// }
int main() {
    long long t;
    cin >> t;

    long long n;
    while(t--){
        cin>>n;
        vector<string>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<pair<long long,long long>>mpp;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<i;j++){
                if(arr[i][j]=='1'){
                    c++;
                }
            }
            mpp.push_back({i,c});
        }

        // sort(mpp.begin(),mpp.end(),compareBySecond);

        // for(int i=0;i<n;i++){
        //     cout<<mpp[i].first<<" ";
        // }
        // cout<<endl;


        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
            int c=0;
            int target=mpp[i].second;

            for(int j=0;j<n;j++){
                if(ans[j]==-1){
                    c++;
                }
                if(c>target){
                    ans[j]=i+1;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
}