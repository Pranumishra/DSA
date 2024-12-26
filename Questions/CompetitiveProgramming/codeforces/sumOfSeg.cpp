#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    long long t;
    cin>>t;
    long long n;
    while(t--){
        cin>>n;
        vector<long long>arr(n);
        int pos=-1;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]!=-1 && arr[i]!=1){
                pos=i;
            }
        }
        set<int>s;
        if(pos!=-1){
            s.insert(arr[pos]);
            long long sum=arr[pos];
            for(int i=pos+1;i<n;i++){
                sum+=arr[i];
                s.insert(sum);
            }

            sum=arr[pos];
            for(int i=pos-1;i>=0;i--){
                sum+=arr[i];
                s.insert(sum);
            }

            sum=arr[pos];
            int i=pos+1;
            int j=pos-1;
            while(i<n && j>=0){
                sum+=arr[i];
                s.insert(sum);
                sum+=arr[j];
                s.insert(sum);
                i++;
                j--;
            }
            if(j!=-1){
                while(j>=0){
                    sum+=arr[j];
                    s.insert(sum);
                    j--;                    
                }
            }
            if(i!=n){
                sum+=arr[i];
                s.insert(sum);
                i++;                
            }


            sum=arr[pos];
            i=pos+1;
            j=pos-1;
            while(i<n && j>=0){
                sum+=arr[j];
                s.insert(sum);
                sum+=arr[i];
                s.insert(sum);
                i++;
                j--;
            }
            if(j!=-1){
                while(j>=0){
                    sum+=arr[j];
                    s.insert(sum);
                    j--;                    
                }
            }
            if(i!=n){
                sum+=arr[i];
                s.insert(sum);
                i++;                
            }
        }

        long long maxOne=0;
        long long temp=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1 || arr[i]==-1){
                temp+=arr[i];
                if(temp>maxOne){
                    maxOne=temp;
                }
                if(temp<0){
                    temp=0;
                }
            }
            else{
                temp=0;
            }
        }

        long long maxO=0;
        long long c2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1 || arr[i]==-1){
                c2+=arr[i];
                if(c2<maxO){
                    maxO=c2;
                }
                if(c2>0){
                    c2=0;
                }
            }
            else{
                c2=0;
            }
        }


        s.insert(0);

        for(int i=1;i<=maxOne;i++){
            s.insert(i);
        }

        for(int i=maxO;i<0;i++){
            s.insert(i);
        }


        cout<<s.size()<<endl;
        for(auto i:s){
            cout<<i<<" ";
        }
        cout<<endl;
    }    
}