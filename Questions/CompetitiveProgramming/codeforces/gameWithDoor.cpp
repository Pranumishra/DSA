#include<iostream>
using namespace std;
#include<algorithm>

int main(){
    int t;
    cin>>t;
    
    int l;
    int r;
    int L;
    int R;
    int minIndex;
    int maxIndex;
    int ans;
    for(int i=0;i<t;i++){
        cin>>l;
        cin>>r;
        cin>>L;
        cin>>R;

        if((r<L)){
            cout<<1<<endl;
        }
        else if(R<l){
            cout<<1<<endl;
        }
        else{
            minIndex=max(l,L);
            maxIndex=min(r,R);
            ans=maxIndex-minIndex;
            if(l==L && r==R){
                cout<<ans<<endl;
            }
            else if((int)abs(l-L)>0 && (int)abs(r-R)>0){
                ans+=2;
                cout<<ans<<endl;
            }
            else if((int)abs(l-L)>0 || (int)abs(r-R)>0){
                ans+=1;
                cout<<ans<<endl;                
            }
            
        }
    }
}