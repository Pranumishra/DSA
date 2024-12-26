#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int recursion(int n,int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return k+k*(k-1);
    }

    return recursion(n-2,k)*(k-1)+recursion(n-1,k)*(k-1);
}



int memoization(int n,int k,vector<int>&dp){
    if(n==1){
        return k;
    }
    if(n==2){
        return k+k*(k-1);
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]= memoization(n-2,k,dp)*(k-1)+memoization(n-1,k,dp)*(k-1);   
    return dp[n];
}
int findWays(int n,int k){
    vector<int>dp(n+1,-1);
    return memoization(n,k,dp);
}



int bottomUp(int n,int k){
    vector<int>dp(n+1,-1);

    //filling the test cases
    dp[1]=k;
    dp[2]=k+k*(k-1);

    //filling rest cases
    for(int i=3;i<=n;i++){
        dp[i]=(k-1)*dp[i-1]+(k-1)*dp[i-2];
    }
    return dp[n];
}


int spaceOptimization(int n,int k){
    int prev=k;
    int curr=k+k*(k-1);

    int ans;
    for(int i=3;i<=n;i++){
        ans=(k-1)*(prev+curr);
        prev=curr;
        curr=ans;
    }
    return ans;

}


int main(){
    int noOfFences;
    int colors;
    cout<<"enter No of fences: ";
    cin>>noOfFences;
    cout<<"enter no of colors: ";
    cin>>colors;

    // cout<<recursion(noOfFences,colors);
    // cout<<findWays(noOfFences,colors);
    // cout<<bottomUp(noOfFences,colors);
    cout<<spaceOptimization(noOfFences,colors);
}