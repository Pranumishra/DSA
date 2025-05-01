#include <iostream>
using namespace std;
#include<bits/stdc++.h>


int main() {
    long long t;
    cin >> t;

    long long n,l,r;
    while(t--){
        cin>>n>>l>>r;
        vector<long long >arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        priority_queue<long long, vector<long long>, greater<long long>> pq1;
        priority_queue<long long, vector<long long>, greater<long long>> pq2;
        int sum1=0;
        int sum2=0;

        for(int i=0;i<r;i++){
            pq1.push(arr[i]);
        }
        for(int j=l-1;j<n;j++){
            pq2.push(arr[j]);
        }

        int len=r-l+1;
        while(len--){
            sum1+=pq1.top();
            pq1.pop();
            sum2+=pq2.top();
            pq2.pop();
        }

        int ans=min(sum1,sum2);
        cout<<ans<<endl;
    }

}