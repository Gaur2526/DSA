// DFS of a graph 

#include<iostream>
using namespace std;

void dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &res){

    vis[node] = 1;
    res.push_back(node);

    for(auto itr : adj[node]){

        if(!vis[itr]){
            dfs(itr,adj,vis,res);
        }
    }


}

vector<int> dfsOfGraph(int nodes,vector<int> adj[]){

    int starting = 1;
    vector<int> vis(nodes+1,0);
    vector<int> res;

    dfs(starting,adj,vis,res);

    return res;


}
int main(){

    int nodes,edges;
    cin>>nodes>>edges;

    vector<int> adj[nodes+1]; // 1 based indexing graph

    for(int i=0;i<edges;i++){

        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    cout<<"DFS is : ";
    vector<int> res = dfsOfGraph(nodes,adj);

    for(auto itr : res){
        cout<<itr<<" ";
    }
}