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

    void findShortestPath(int n,int src,int dest){
        vector<int>distance(n+1,INT_MAX);
        set<pair<int,int>>st;
        //as we need to find min distace therfore first element of set is the distace and second is the node

        //maintaining initial state
        st.insert({0,src});
        while(!st.empty()){
            //set doenst have top and pop fcn therefore we need to do the same thing in this way.
            auto topElement=st.begin();
            pair<int,int> topPair=*topElement;
            int topDistance=topPair.first;
            int topNode=topPair.second;
            st.erase(st.begin());

            for(auto nbrPair:adjList[topNode]){
                //in adj list first node is present then distance is present
				int nbrNode = nbrPair.first;
				int nbrDist = nbrPair.second;

                if(topDistance+nbrDist<distance[nbrNode]){
					//find previousEntry and delete it
					auto previousEntry = st.find({distance[nbrNode], nbrNode});
					if(previousEntry != st.end()) {
						// entry present in set
						st.erase(previousEntry);
					}


                    //updating and inserting the value
                    distance[nbrNode]=topDistance+nbrDist;
                    st.insert({distance[nbrNode],nbrNode});
                }                
            }
        }

        cout << "Shortest Distance from " << src << " Node to " << dest << " Node: " << distance[dest] << endl;
    }
};

int main() {
	Graph g;
	g.addEdge(1,6,14,0);
	g.addEdge(1,3,9,0);
	g.addEdge(1,2,7,0);
	g.addEdge(2,3,10,0);
	g.addEdge(2,4,15,0);
	g.addEdge(3,4,11,0);
	g.addEdge(6,3,2,0);
	g.addEdge(6,5,9,0);
	g.addEdge(5,4,6,0);


	int n = 6;
	int src = 1;
	int dest = 5;
    g.findShortestPath(n,src,dest);
}