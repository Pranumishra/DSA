//TO MAKE THE CODE GENERALISED FOR ALL DATATYPES WE WILL USE TEMPLATE
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

template<typename T>
class Graph{
public:
    unordered_map<T,list<pair<T,int>>>adjList;
    //list ka first element kisike sath relation hai vo batayega , second element weight batayega.
    //if direction will be 1 it means directed graph . If dirn will be 0 it means  undirected graph
    void addEdge(T u, T v, int wt, bool dirn){
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


    //Traversal 
    //BFStraversal 
    //this bfs traversal will fail when graph is DISCONNECTED GRAPH.
    void incorrectBFStraversal(T src){
        //adj list already present as a data member
        //isVisited we will create
        unordered_map<T,bool>isVisited;

        queue<T>q;
        //initial state maintain
        q.push(src);
        isVisited[src]=true;
        while(!q.empty()){
            T currNode=q.front();
            cout<<currNode<<" ";
            q.pop();
            for(auto neighbour:adjList[currNode]){
                if(!isVisited[neighbour.first]){
                    isVisited[neighbour.first]=true;
                    q.push(neighbour.first);
                }
            }

        }

    }





    //CORRECT BFS TRAVERSAL
    void BFStraversal(T src,unordered_map<T,bool>&isVisited){
        //adj list already present as a data member
        //isVisited we will create

        queue<T>q;
        //initial state maintain
        q.push(src);
        isVisited[src]=true;
        while(!q.empty()){
            T currNode=q.front();
            cout<<currNode<<" ";
            q.pop();
            for(auto neighbour:adjList[currNode]){
                if(!isVisited[neighbour.first]){
                    isVisited[neighbour.first]=true;
                    q.push(neighbour.first);
                }
            }

        }

    }    




    //DFS Depth first search
    void DFS(T src,unordered_map<T,bool>&isVisited){
        isVisited[src]=true;
        cout<<src<<"  ";
        for(auto neighbour:adjList[src]){
            if(!isVisited[neighbour.first]){
                DFS(neighbour.first,isVisited);
            }
        }
    }
};

int main(){
    // Graph<int> g;
    // g.addEdge(2,1,1,0);
    // g.addEdge(2,3,2,0);
    // g.addEdge(2,4,3,0);
    // g.addEdge(2,5,4,0);
    // g.addEdge(3,1,5,0);
    // g.addEdge(4,1,6,0);
    // g.addEdge(5,1,7,0);
    // g.printAdjList();

    Graph<char> g;
    g.addEdge('a','b',4,0);
    g.addEdge('a','c',5,0);
    g.addEdge('c','d',6,0);
    g.addEdge('d','a',7,0);
    g.addEdge('f','g',7,0);
    g.addEdge('g','h',7,0);
    // g.printAdjList();    
    g.incorrectBFStraversal('a');
    cout<<endl;

    //CORRECT WAY OF BFS TRAVERSAL
    unordered_map<char,bool>Visited;
    for(char ch='a';ch<='g';ch++){
        if(!Visited[ch])
        g.BFStraversal(ch,Visited);
    }
    cout<<endl;
    unordered_map<char,bool>visited;
    for(char ch='a';ch<='g';ch++){
        if(!visited[ch])
        g.DFS(ch,visited);
    }
    
}