#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>arr(n);
        vector<int>ans;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        ans.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i-1]<=arr[i]){
                ans.push_back(arr[i]);
            }
            else{
                ans.push_back(arr[i]);
                ans.push_back(arr[i]);
            }
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}