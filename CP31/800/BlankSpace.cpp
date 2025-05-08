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
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int ans=0;
        int temp=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                temp=0;
            }
            else{
                temp++;
                if(temp>ans){
                    ans=temp;
                }
            }
        }
        cout<<ans<<endl;
    }
}