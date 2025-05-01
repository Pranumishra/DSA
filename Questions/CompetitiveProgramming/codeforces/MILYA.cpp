#include <iostream>
using namespace std;
#include<bits/stdc++.h>


int main() {
    long long t;
    cin >> t;

    long long n;
    while(t--){
        cin>>n;
        set<long long>a;
        set<long long>b;
        int val;
        for(int i=0;i<n;i++){
            cin>>val;
            a.insert(val);
        }
        for(int i=0;i<n;i++){
            cin>>val;
            b.insert(val);
        }

        long long n1=a.size();
        long long n2=b.size();

        if(n1+n2 <=3){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
        
    }
}