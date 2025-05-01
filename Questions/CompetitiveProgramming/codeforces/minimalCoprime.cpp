#include <iostream>
using namespace std;
#include<bits/stdc++.h>


int main() {
    long long t;
    cin >> t;

    long long l,r;
    while(t--){
        cin>>l>>r;
        if(l==1 && r==1){
            cout<<1<<endl;
        }
        else{
            cout<<r-l<<endl;
        }      
    }
}
