#include <iostream>
using namespace std;
#include<bits/stdc++.h>


int main() {
    long long t;
    cin >> t;

    long long n,m;
    string str;
    while(t--){
        cin>>n>>m;
        cin>>str;

        vector<vector<long long>>arr(n,vector<long long>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }

        int i=0;
        int j=0;

        for(int k=0;k<n+m-2;k++){
                    if(str[k]=='D'){
                        long long sum=0;
                        for(int l=0;l<m;l++){
                            sum+=arr[i][l];
                        }
                        arr[i][j]=(-1*sum);
                        i++;
                    }
                    else{
                        long long sum=0;
                        for(int l=0;l<n;l++){
                            sum+=arr[l][j];
                        }
                        arr[i][j]=(-1*sum);  
                        j++;                  
                    }
        }

        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i][m-1];
        }
        arr[n-1][m-1]=(-1*sum);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}