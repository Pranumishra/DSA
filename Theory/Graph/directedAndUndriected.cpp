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

int main(){
    Graph g;
    g.addEdge(2,1,0);
    g.addEdge(2,3,0);
    g.addEdge(2,4,0);
    g.addEdge(2,5,0);
    g.addEdge(3,1,0);
    g.addEdge(4,1,0);
    g.addEdge(5,1,0);
    g.printAdjList();
}