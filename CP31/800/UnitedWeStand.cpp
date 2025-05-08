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
        vector<int>b;
        vector<int>c;

        int ele=-1;

        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(arr[j]!=arr[i]){
                    if(arr[j]%arr[i]==0)
                    count++;
                }
            }
            if(count==0){
                ele=arr[i];
                break;
            }
        }

        for(int i=0;i<n;i++){
            if(ele==arr[i]){
                c.push_back(arr[i]);
            }
            else{
                b.push_back(arr[i]);
            }
        }

        if(c.size()==0 || b.size()==0){
            cout<<-1<<endl;
        }
        else{
            cout<<b.size()<<" "<<c.size()<<endl;
            for(int i=0;i<b.size();i++){
                cout<<b[i]<<" ";
            }
            cout<<endl;
            for(int i=0;i<c.size();i++){
                cout<<c[i]<<" ";
            }
            cout<<endl;
        }
    }
}