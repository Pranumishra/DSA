#include<iostream>
using namespace std;

int degree[100];
int n;
int arr[100][100];
bool visited[100];
int q[100];

void input(){
    cout<<"Enter no of nodes:"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        degree[i]=0;
    }

    int e;
    cout<<"Enter no of edges:"<<endl;
    cin>>e;

    int a;
    int b;
    while(e--){
        cin>>a;
        cin>>b;
        arr[a][degree[a]++]=b;
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

void dfs(int src){
    cout<<src<<" ";
    visited[src]=true;
    for(int i=0;i<degree[src];i++){
        int nbr=arr[src][i];
        if(!visited[nbr]){
            dfs(nbr);
        }
    }
}

void bfs(int src){
    int rear=0;
    int front=0;
    q[rear++]=src;
    visited[src]=true;
    while(front<rear){
        int top=q[front];
        cout<<top<<" ";
        front++;
        for(int i=0;i<degree[top];i++){
            int nbr=arr[top][i];
            if(!visited[nbr]){
                visited[nbr]=true;
                q[rear++]=nbr;
            }
        }
    }

}

int main(){
    input();
    // print();
    cout<<endl;
    // cout<<"dfs : ";
    // for(int i=0;i<n;i++){
    //     if(!visited[i]){
    //         dfs(i);
    //     }
    // }

    cout<<"bfs : ";
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(i);
        }
    }
}