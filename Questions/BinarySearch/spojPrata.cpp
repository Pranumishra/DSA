#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

bool is_mid_ans(vector<int>rank,int prata,int min){
    for(int i=0;i<rank.size();i++){
        int startmin=0;
        int counter=1;
        while(startmin+(rank[i]*counter)<=min){
            startmin=startmin+(rank[i]*counter);
            prata--;
            counter++;
        }
        if(prata<=0){
            return true;
        }
    }
    return false;
}

int findmintime(vector<int>rank,int prata){
    //anserspace
    int s=0;
    int highestRank= *max_element(rank.begin(),rank.end());
    int e=highestRank*(prata*(prata+1)/2);
    int ans=-1;
    int mid;
    while(s<=e){
        mid=(s+e)/2;
        if(is_mid_ans(rank,prata,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int main(){
        int prata;
        int no_of_cooks;
        vector<int>rank;
        int inputval;
        cin>>prata;
        cin>>no_of_cooks;
        for(int j=0;j<no_of_cooks;j++){
            cin>>inputval;
            rank.push_back(inputval);
        }

        int ans=findmintime(rank,prata);
        cout<<"the min time is:"<<ans<<endl;
        return 0;
}