#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Graph{
public:
    unordered_map<int,list<pair<int,int>>>adjList;
    //list ka first element kisike sath relation hai vo batayega , second element weight batayega.
    //if direction will be 1 it means directed graph . If dirn will be 0 it means  undirected graph
    void addEdge(int u, int v, int wt, bool dirn){
        if(dirn==1){
            adjList[u].push_back({v,wt});
        }
        else{
            adjList[v].push_back({u,wt});
            adjList[u].push_back({v,wt});
        }
    }
    void printAdjList(){
        for(auto l:adjList){
            cout<<l.first<<"{ ";
            for(auto i:l.second){
                cout<<"{"<<i.first<< " "<<i.second<<"}"<<" ";
            }
            cout<<"}"<<endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge(2,1,1,0);
    g.addEdge(2,3,2,0);
    g.addEdge(2,4,3,0);
    g.addEdge(2,5,4,0);
    g.addEdge(3,1,5,0);
    g.addEdge(4,1,6,0);
    g.addEdge(5,1,7,0);
    g.printAdjList();
}