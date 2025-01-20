#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int main() {
    long long t;
    cin >> t;

    int n;
    while(t--){
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<int>b(n);
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        int c=0;
        int val=-1;
        int index=-1;
        for(int i=0;i<n;i++){
            if(b[i]-arr[i] > 0){
                c++;
                val=b[i]-arr[i];
                index=i;
            }
        }
        if(c>1){
            cout<<"NO"<<endl;
        }
        else if(c==0){
            cout<<"YES"<<endl;
        }
        else{
            bool found=false;
            for(int i=0;i<n;i++){
                if(i!=index){
                    if(arr[i]-b[i]<val){
                        found=true;
                        break;
                    }
                }
            }
            if(found){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
    }
}