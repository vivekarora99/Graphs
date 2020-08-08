/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue> 
#include<iterator>
using namespace std;
class Graph {
    private:
        vector<vector<int> > graph;
        int size;
        vector<bool> visited;
        void bfsAux(int v);
        void dfsAux(int v);
    public:
        Graph(int n){
            graph.resize(n);
            size = n;
            visited.resize(n);
        }
        void addEdge(int s,int d) {
            graph[s].push_back(d);
        }
        void bfs(int v);
        void dfs(int v);
};
void Graph:: dfsAux(int v) {
    cout<<v<<" ";
    visited[v]=true;
    vector<int> :: iterator it=graph[v].begin();
    for(;it!=graph[v].end();it++){
        if(visited[*it]==false)
            dfsAux(*it);
    }
}
void Graph:: dfs(int v=0) {
    fill(visited.begin(),visited.end(),false);
    dfsAux(v);
    for(int i=0;i<size;i++){
        if(visited[i]==false)
            dfsAux(i);
    }
}
int main()
{   Graph g(8);
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(4,6);
    g.addEdge(4,7);
    g.addEdge(0,2);
    g.addEdge(3,7);
    g.dfs(0);
    return 0;
}

