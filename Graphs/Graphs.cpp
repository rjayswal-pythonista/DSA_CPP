#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
class Node {
    public:
        string name;
        list<string> nbrs;
        Node(string name) {
            this->name = name;
        }
};

class Graph {
        unordered_map<string, Node*> m;
    public:
        Graph(vector<string> cities);
        void addEdge(string i, string j, bool undir);
        void PrintList();
};

Graph::Graph(vector<string> cities) {
        for(auto city: cities){
            m[city] = new Node(city);
        }
}
void Graph::addEdge(string i, string j, bool undir=false){
    m[i]->nbrs.push_back(j);
    if(undir){
        m[j]->nbrs.push_back(i);
    }
}

void Graph::PrintList(){
    for(auto cityPair:m){
        auto city = cityPair.first;
        Node *node = cityPair.second;
        cout<<city<<"-->";
        for(auto nbr:node->nbrs) {
            cout<<nbr<<",";
        }
        cout<<endl;
    }
}
*/
class Graph {
    private:
        int V;
        list<int> *l;
    public:
        Graph(int v);
        void addEdge(int i, int j, bool undir);
        void PrintList();
        void bfs(int source, int dest);
        void dfs(int source);
        void dfshelper(int node, bool *visited);
        bool containsCycle();
        bool dfsCycle(int node, vector<bool> &visited, int parent);
};

Graph::Graph(int v) {
    V = v;
    l = new list<int>[V];
}

void Graph::addEdge(int i, int j, bool undir=true){
    l[i].push_back(j);
    if(undir){
        l[j].push_back(i);
    }
}

void Graph::PrintList(){
    cout<<"#################### Ajacency List Representation ####################"<<endl;
    for(int i=0; i<V; ++i){
        cout<<i<<"-->";
        for(auto x:l[i]){
            cout<<x<<",";
        }
        cout<<endl;
    }
}

void Graph::bfs(int source, int dest = -1){
    queue<int> q;
    bool *visited = new bool[V]{0};

    int *dist = new int[V]{0};
    int *parent = new int[V];
    for(int i = 0; i < V; ++i){
        parent[i] = -1;
    }
    cout<<"##################### Breadth First Search ############################"<<endl;
    q.push(source);
    visited[source] = true;

    while(!q.empty()){
        int f = q.front();
        q.pop();
        cout<<f<<" ";
        for(auto nbr:l[f]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr] = true;

                parent[nbr] = f;
                dist[nbr] = dist[f] + 1;
            }
        }
    }
    cout<<endl;
    cout<<"########### Single Source Shortest Path(Undirected Graph) ###########"<<endl;
    for(int i=0; i< V; ++i){
        cout<<"Shortest distance to "<<i<<" is "<<dist[i]<<endl;
    }
    cout<<"########### Shortest Path(Undirected Graph) for given node ###########"<<endl;
    if(dest != -1){
        int temp = dest;
        while(temp != source){
            cout<<temp<<" -- ";
            temp = parent[temp];
        }
        cout<<source<<endl;
    }
}

void Graph::dfshelper(int node, bool *visited){
    visited[node] = true;
    cout<<node<<" -- ";
    for(auto nbr:l[node]){
        if(!visited[nbr]){
            dfshelper(nbr, visited);
        }
    }
    return;
}

void Graph::dfs(int source){
    bool *visited = new bool[V]{0};
    cout<<"##################### Depth First Search ############################"<<endl;
    dfshelper(source, visited);
    cout<<endl;
}

bool Graph::dfsCycle(int node, vector<bool> &visited, int parent) {
    visited[node] = true;

    for(auto nbr:l[node]){
        if(!visited[nbr]){
            bool nbrfoundCycle = dfsCycle(nbr, visited, node);
            if(nbrfoundCycle) return true;
        } else if(nbr != parent){
            return true;
        }
    }
    return false;
}

bool Graph::containsCycle(){
    cout<<"#################### Cycle Detection #######################"<<endl;
    vector<bool> visited(V,false);
    return dfsCycle(0,visited,-1);
}

int main() {
    /*
    vector<string> cities = {"Delhi","London","Paris","New York"};
    Graph g(cities);
    g.addEdge("Delhi","London");
    g.addEdge("New York","London");
    g.addEdge("Delhi","Paris");
    g.addEdge("Paris","New York");
    g.PrintList();
    */
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.PrintList();
    g.bfs(1,5);
    g.dfs(1);
    if(g.containsCycle()){
        cout<<"Graph contains Cycle"<<endl;
    } else {
        cout<<"Graph Does not contain Cycle"<<endl;
    }
    return 0;
}