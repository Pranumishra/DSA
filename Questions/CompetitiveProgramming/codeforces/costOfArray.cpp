#include <iostream>
using namespace std;
#include<bits/stdc++.h>


int main() {
    long long t;
    cin >> t;

    long long n;
    long long k;
    while(t--){
        cin>>n;
        cin>>k;

        vector<long long>arr(n);
        long long ans=0;

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        long long e=n-k;

        if(e!=0){
            if(n==2){
                if(arr[1]!=1){
                    cout<<1<<endl;
                }
                else{
                    cout<<2<<endl;
                }
            }
            else{
                for(int i=1;i<=e;i++){
                    if(arr[i]!=1){
                        ans=1;
                        break;
                    }
                }
                if(ans!=0){
                    cout<<ans<<endl;
                }
                else{
                    if(arr[e+1]!=1){
                        cout<<1<<endl;
                    }
                    else{
                        cout<<2<<endl;
                    }
                }
            }
        }
        else{
            int c=1;
            for(int i=1;i<n;i+=2){
                if(arr[i]!=c){
                    ans=c;
                }
                c++;
            }
            if(ans!=0){
                cout<<ans<<endl;
            }
            else{
                cout<<c<<endl;
            }
        }

    }
}