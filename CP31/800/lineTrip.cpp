#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    int n;
    int x;
    while(t--){
        cin>>n;
        cin>>x;
        vector<int>arr(n+1);
        arr[0]=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        arr.push_back(x);
        int ans=0;
        for(int i=1;i<arr.size();i++){
            if(i==arr.size()-1){
                if(ans<2*(arr[i]-arr[i-1])){
                    ans=2*(arr[i]-arr[i-1]);
                }
            }
            if(ans<arr[i]-arr[i-1]){
                ans=arr[i]-arr[i-1];
            }
        }
        cout<<ans<<endl;
    }
}