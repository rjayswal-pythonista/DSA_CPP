#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Graph {
    private:
        int V;
        list<int> *l;
    public:
        Graph(int v);
        void addEdge(int i, int j, bool undir);
        bool containsCycle();
        bool dfsCycle(int node, vector<bool> &visited, vector<bool> &stack);
};

Graph::Graph(int v) {
    this->V = v;
    l = new list<int>[V];
}

void Graph::addEdge(int i, int j, bool undir=false){
    l[i].push_back(j);
    if(undir){
        l[j].push_back(i);
    }
}

bool Graph::dfsCycle(int node, vector<bool> &visited, vector<bool> &stack) {
    visited[node] = true;
    stack[node] = true;

    for(auto nbr:l[node]){
        if(!visited[nbr]){
            bool nbrfoundCycle = dfsCycle(nbr, visited, stack);
            if(nbrfoundCycle) return true;
        } else if(stack[nbr] == true){
            return true;   // immediate backedge
        }
    }
    //going back
    stack[node] = false;
    return false;
}

bool Graph::containsCycle(){
    cout<<"################# Cycle Detection in Directed Graph ###################"<<endl;
    vector<bool> visited(V,false);
    vector<bool> stack(V,false);
    for(int i = 0; i < V; ++i){
        if(!visited[i]){
            if(dfsCycle(0,visited,stack)){
                return true;
            }
        }
    }
    return false;
}

int main() {
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    if(g.containsCycle()){
        cout<<"Graph contains Cycle"<<endl;
    } else {
        cout<<"Graph Does not contain Cycle"<<endl;
    }
    return 0;
}