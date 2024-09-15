#include<iostream>
using namespace std;
#include<bits/stdc++.h>

bool compare(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
int main(){
    vector<int>a={1,3,5,2,4};
    vector<int>b={10,20,30,40,50};
    vector<pair<int,int>>ab;
    for(int i=0;i<5;i++){
        ab.push_back({a[i],b[i]});
    }
    cout<<"before sorting"<<endl;
    for(int i=0;i<5;i++){
        cout<<"{"<<ab[i].first<<","<<ab[i].second<<"}"<<" ";
    }
    cout<<endl;

    sort(ab.begin(),ab.end(),compare);
    cout<<"after sorting"<<endl;
    for(int i=0;i<5;i++){
        cout<<"{"<<ab[i].first<<","<<ab[i].second<<"}"<<" ";
    }
    cout<<endl;
}