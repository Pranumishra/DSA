// #include<iostream>
// using namespace std;
// #include<bits/stdc++.h>

// typedef long long ll;

// int main(){
//     ll t;
//     cin>>t;

//     ll n;
//     ll m;

//     while(t--){
//         cin>>n;
//         cin>>m;
//         vector<ll>arr(n);
//         for(int i=0;i<n;i++){
//             cin>>arr[i];
//         }

//         char ch;
//         int l;
//         int r;
//         vector<ll>ans;
//         for(int i=1;i<=m;i++){
//             cin>>ch;
//             cin>>l;
//             cin>>r;
            
//             for(int j=0;j<n;j++){
//                 if(arr[j]>=l&&arr[j]<=r){
//                     if(ch=='+'){
//                         arr[j]=arr[j]+1;
//                     }
//                     else if (ch=='-'){
//                         arr[j]=arr[j]-1;
//                     }
//                 }
//             }
//             ans.push_back(*max_element (arr.begin(), arr.end()));
//         }

//         for(int i=0;i<ans.size();i++){
//             cout<<ans[i]<<" ";
//         }
//         cout<<endl;

//     }

// }



#include<iostream>
using namespace std;
#include<bits/stdc++.h>

typedef long long ll;

int main(){
    ll t;
    cin>>t;

    ll n;
    ll m;

    while(t--){
        cin>>n;
        cin>>m;
        vector<ll>arr(n);

        ll maxi=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>maxi){
                maxi=arr[i];
            }
        }

        char ch;
        int l;
        int r;
        vector<ll>ans;
        for(int i=1;i<=m;i++){
            cin>>ch;
            cin>>l;
            cin>>r;

            if(ch=='+'){
                if(maxi>=l&&maxi<=r){
                    maxi++;
                }     
            }
            else if (ch=='-'){
                if(maxi>=l&&maxi<=r){
                    maxi--;
                }                     
            }            

            ans.push_back(maxi);
        }
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }

}