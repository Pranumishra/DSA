#include <iostream>
using namespace std;

int arr[100][100];
int n;
int indegree[100];
int outdegree[100];
void input(){
    cout<<"Enter no of nodes:"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        indegree[i]=0;
        outdegree[i]=0;
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }

    int e;
    cout<<"Enter no of edges:"<<endl;
    cin>>e;

    int a;
    int b;
    while(e--){
        cin>>a;
        cin>>b;
        arr[a][b]=1;
        outdegree[a]++;
        indegree[b]++;
    }
}

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    input();
    cout<<endl;

    // print();
    // cout<<endl;

    // int node;
    // cout<<"Which node indegree you want to find :"<<endl;
    // cin>>node;
    // for(int i=0;i<n;i++){
    //     cout<<indegree[i]<<" "<<outdegree[i]<<endl;
    // }
    
    int maxi=-1;
    int mini=101;
    int maxe=-1;
    int mine=-1;

    for(int i=0;i<n;i++){
        if(indegree[i]>maxi){
            maxi=indegree[i];
            maxe=i;
        }
        if(indegree[i]<mini){
            mini=indegree[i];
            mine=i;
        }
    }

    cout<<"MaxNode is : "<<maxe<< "with indegree"<<maxi<<endl;
    cout<<"MinNode is : "<<mine<< "with indegree"<<mini<<endl;
    cout<<"degree of node 5 is "<<indegree[7]+outdegree[7];

}