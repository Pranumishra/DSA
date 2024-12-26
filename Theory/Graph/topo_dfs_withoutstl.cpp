#include<iostream>
using namespace std;

int arr[100][100];
bool visited[100];
int st[100];
int degree[100];
int n;
int top=0;

void input(){
    cout<<"nodes :"<<endl;
    cin>>n;

    int e;
    cout<<"edges :"<<endl;
    cin>>e;

    for(int i=0;i<n;i++){
        degree[i]=0;
        visited[i]=false;
    }

    int from;
    int to;
    while(e--){
        cin>>from>>to;
        arr[from][degree[from]++]=to;
    }
}

void topo(int src){
    visited[src]=true;
    for(int i=0;i<degree[src];i++){
        int nbr=arr[src][i];
        if(!visited[nbr]){
            topo(nbr);
        }
    }
    st[top++]=src;
}

int main(){
    input();
    for(int i=0;i<n;i++){
        if(!visited[i]){
            topo(i);
        }
    }

    cout<<endl;
    for(int i=top-1;i>=0;i--){
        cout<<st[i]<<" ";
    }

}



