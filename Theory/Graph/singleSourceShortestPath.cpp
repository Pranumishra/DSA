#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Graph{
    public:
    unordered_map<int,list<pair<int,int>>>adjList;

    void addEdge(int a,int b,int wt,int dirn){
        if(dirn==1){
            //directed graph
            adjList[a].push_back({b,wt});
        }
        else{
            adjList[a].push_back({b,wt});
            adjList[b].push_back({a,wt});
        }
    }


    void topoSort(int src,stack<int>&topoOrder,unordered_map<int,bool>&isVisited){
        //marking the src;
        isVisited[src]=true;

        for(auto child:adjList[src]){
            int childValue=child.first;
            if(!isVisited[childValue]){
                topoSort(childValue,topoOrder,isVisited);
            }
        }

        //on returning 
        topoOrder.push(src);
    }
};


int main(){
    Graph g;
	g.addEdge(0,1,5,1);
	g.addEdge(0,2,3,1);
	g.addEdge(2,1,2,1);
	g.addEdge(1,3,3,1);
	g.addEdge(2,3,5,1);
	g.addEdge(2,4,6,1);
	g.addEdge(4,3,1,1);


    int src=0;
    stack<int>topoOrder;
    unordered_map<int,bool>isVisited;
    g.topoSort(src,topoOrder,isVisited);

    //checking that toposort fcn is working correctly or not.
    // while(!topoOrder.empty()){
    //     cout<<topoOrder.top()<<" ";
    //     topoOrder.pop();
    // }



    //calculating the minimum distance to reach each node.

    int n=5;
    vector<int>minDistance(n,INT_MAX);

    //setting distance for the first independent node
    int currNode=topoOrder.top();
    topoOrder.pop();
    minDistance[currNode]=0;

    for(auto child:g.adjList[currNode]){
        int childValue=child.first;
        int childDistance=child.second;
        if(childDistance+minDistance[currNode]<minDistance[childValue]){
            minDistance[childValue]=childDistance+minDistance[currNode];
        }
    }

    while(!topoOrder.empty()){
        currNode=topoOrder.top();
        topoOrder.pop();
        for(auto child:g.adjList[currNode]){
            int childValue=child.first;
            int childDistance=child.second;
                if(childDistance+minDistance[currNode]<minDistance[childValue]){
                    minDistance[childValue]=childDistance+minDistance[currNode];
                }
        }
    }

    for(int i=0;i<minDistance.size();i++){
        cout<<minDistance[i]<<" ";
    }
}