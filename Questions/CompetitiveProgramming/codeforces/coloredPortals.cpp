#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    int n;
    int q;
    vector<vector<int>>query;
    for(int k=0;k<t;k++){
        cin>>n;
        cin>>q;
        vector<string>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>temp(2);
        for(int i=0;i<q;i++){
            cin>>temp[0];
            cin>>temp[1];
            query.push_back(temp);
        }

        for(int i=0;i<q;i++){
            int start=query[i][0]-1;
            int end=query[i][1]-1;

            int count=0;
            int ans=-1;

            if(start==end){
                cout<<0<<endl;
            }
            else{
                for(auto ch:arr[start]){
                    if(arr[end].find(ch)==string::npos){
                        count++;
                    }
                }
                if(count<2){
                    ans=(int)abs(start-end);
                    cout<<ans<<endl;
                }
                else{
                    int count1;
                    //kya apne left ja sakta hai.
                    if(start-1>=0){
                        count1=0;
                        for(auto ch:arr[start]){
                            
                            if(arr[start-1].find(ch)==string::npos){
                                count1++;
                            }

                        }
                        if(count1<2){
                            ans=1;
                            int count2=0;
                            for(auto ch:arr[start-1]){
                                if(arr[end].find(ch)==string::npos){
                                    count2++;
                                }
                            }
                            if(count2<2){
                                ans+=(int)abs(start-1-end);
                            }
                        }
                    }
                    //kya apne right ja sakta hai.
                    if(start+1<n && ans<=1){
                        count1=0;
                        for(auto ch:arr[start]){
                            if(arr[start+1].find(ch)==string::npos){
                                count1++;
                            }
                        }
                        if(count1<2){
                            ans=1;
                            int count2=0;
                            for(auto ch:arr[start+1]){
                                if(arr[end].find(ch)==string::npos){
                                    count2++;
                                }
                            }
                            if(count2<2){
                                ans+=(int)abs(start+1-end);
                            }
                        }


                    }

                    cout<<ans<<endl;
                }                
            }
        }
    }
}