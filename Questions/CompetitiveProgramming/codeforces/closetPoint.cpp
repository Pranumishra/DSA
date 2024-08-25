#include<iostream>
using namespace std;
#include<vector>

int main(){
    int t;
    cin>>t;
    
    for(int l=0;l<t;l++){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        if(n==2){
            if((int)abs(arr[0]-arr[1])>=2){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }
    }
   
}