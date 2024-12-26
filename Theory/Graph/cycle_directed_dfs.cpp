#include<iostream>
using namespace std;

int arr[100][100];
int degree[100];
bool visited[100];
bool dfsarr[100];
int n;

void input(){
    cout<<"nodes :"<<endl;
    cin>>n;

    int e;
    cout<<"edges :"<<endl;
    cin>>e;

    for(int i=0;i<n;i++){
        degree[i]=0;
        visited[i]=false;
        dfsarr[i]=false;
    }

    int from;
    int to;
    while(e--){
        cin>>from>>to;
        arr[from][degree[from]++]=to;
    }
}

bool present=false;
void dfs(int src){
    visited[src]=true;
    for(int i=0;i<degree[src];i++){
        int nbr=arr[src][i];
        if(!visited[nbr]){
            dfsarr[nbr]=true;
            dfs(nbr);
            dfsarr[nbr]=false;
        }
        else{
            if(dfsarr[nbr]){
                present=true;
                return;
            }
        }
    }
}

int main(){
    input();
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfsarr[i]=true;
            dfs(i);
            if(present){
                cout<<"Cycle Present"<<endl;
                return 0;
            }
            dfsarr[i]=false;
        }
    }
    cout<<"Cycle not present"<<endl;
}