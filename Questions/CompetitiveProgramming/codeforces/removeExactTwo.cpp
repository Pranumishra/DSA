#include <iostream>
using namespace std;
#include<bits/stdc++.h>


int main() {
    long long t;
    cin >> t;

    long long n;
    while(t--){
        cin>>n;
        vector<long long>arr(n+1);
        unordered_map<long long,list<long long>>adjList;
        long long a,b;
        for(int i=1;i<n;i++){
            cin>>a>>b;
            arr[a]++;
            arr[b]++;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        vector<long long>lfn(n+1);
        for(auto node:adjList){
            for(auto nbr:node.second){
                if(arr[nbr]==1){
                    lfn[node.first]++;
                }
            }
        }
            long long maxi=-1;
            long long index=-1;
            for(int i=1;i<n+1;i++){
                if(arr[i]>maxi){
                    maxi=arr[i];
                    index=i;
                }
                else if(arr[i]==maxi && lfn[i]>lfn[index]){
                    maxi=arr[i];
                    index=i;                    
                }
            }
            
            long long ans=0;
            ans+=arr[index];

            for(auto nbr:adjList[index]){
                arr[nbr]=arr[nbr]-1;
            }
            arr[index]=-1;

            maxi=-1;
            index=-1;
            for(int i=1;i<n+1;i++){
                if(arr[i]>maxi){
                    maxi=arr[i];
                    index=i;
                }
            }
            ans+=arr[index]-1;   
            cout<<ans<<endl;         

    
    }
}