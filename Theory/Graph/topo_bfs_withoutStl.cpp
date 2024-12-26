#include<iostream>
using namespace std;

int arr[100][100];
int degree[100];
int indegree[100];
int n;
int q[100];

void input(){
    cout<<"nodes :"<<endl;
    cin>>n;

    int e;
    cout<<"edges :"<<endl;
    cin>>e;

    for(int i=0;i<n;i++){
        degree[i]=0;
        indegree[i]=0;
    }

    int from;
    int to;
    while(e--){
        cin>>from>>to;
        arr[from][degree[from]++]=to;
        indegree[to]++;
    }
}

void topo(){
    int front=0;
    int rear=0;

    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q[rear++]=i;
        }
    }

    while(front<rear){
        int top=q[front];
        cout<<top<<" ";
        front++;
        for(int i=0;i<degree[top];i++){
            int nbr=arr[top][i];
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q[rear++]=nbr;
            }
        }
    }
}

int main(){
    input();
    for(int i=0;i<n;i++){
        cout<<indegree[i]<<endl;
    }
    topo();

}