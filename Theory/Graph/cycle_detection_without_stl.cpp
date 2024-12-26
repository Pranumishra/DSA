#include<iostream>
using namespace std;

int degree[100];
int n;
int arr[100][100];
bool visited[100];
int parent[100];
int q[100];

void input(){
    cout<<"Enter no of nodes:"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        degree[i]=0;
        parent[i]=-1;
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
        arr[b][degree[b]++]=a;
    }
}

void bfsCycle(int src){
    int front=0;
    int rear=0;
    q[rear++]=src;
    visited[src]=true;
    while(front<rear){
        int top=q[front];
        front++;
        for(int i=0;i<degree[top];i++){
            int nbr=arr[top][i];
            if(nbr==parent[top]){
                continue;
            }
            else if(!visited[nbr]){
                visited[nbr]=true;
                parent[nbr]=top;
                q[rear++]=nbr;
            }
            else{
                cout<<"Cycle Present"<<endl;
                return;
            }
        }
    }
    cout<<"Cycle Not Present"<<endl;
}

bool detected=false;
void dfsCycle(int src){
    visited[src]=true;
    for(int i=0;i<degree[src];i++){
        int nbr=arr[src][i];
        if(nbr==parent[src]){
            continue;
        }
        else if(!visited[nbr]){
            parent[nbr]=src;
            dfsCycle(nbr);
        }
        else{
            detected=true;
            return;
        }
    }
}

int main(){
    input();
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfsCycle(i);
        }
    }
    if(detected){
        cout<<"D"<<endl;
    }
    else{
        cout<<"ND"<<endl;
    }
}
