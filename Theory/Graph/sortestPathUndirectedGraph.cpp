#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Graph{
public:
    unordered_map<int,list<int>>adjList;
    //if direction will be 1 it means directed graph . If dirn will be 0 it means  undirected graph
    void addEdge(int u, int v, bool dirn){
        if(dirn==1){
            adjList[u].push_back(v);
        }
        else{
            adjList[v].push_back(u);
            adjList[u].push_back(v);
        }
    }
    void printAdjList(){
        for(auto l:adjList){
            cout<<l.first<<"{ ";
            for(auto i:l.second){
                cout<<i<<" ";
            }
            cout<<"}"<<endl;
        }
    }
};


void findShortestPath(int src,int target,unordered_map<int,list<int>>&adjList){
    unordered_map<int,bool>isVisited;
    unordered_map<int,int>parent;
    queue<int>q;
    q.push(src);
    isVisited[src]=true;
    parent[src]=-1;

    while(!q.empty()){
        int currNode=q.front();
        q.pop();
        for(auto child:adjList[currNode]){
            if(!isVisited[child]){
                isVisited[child]=true;
                parent[child]=currNode;
                q.push(child);
            }
        }
    }

    //storing and printing the answer
    stack<int>st;
    while(target!=-1){
        st.push(target);
        target=parent[target];
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
}
int main(){
    Graph g;
    g.addEdge(2,1,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(1,5,0);
    g.addEdge(5,6,0);
    g.addEdge(6,4,0);
    g.addEdge(1,7,0);
    g.addEdge(7,4,0);
    findShortestPath(7,6,g.adjList);
}