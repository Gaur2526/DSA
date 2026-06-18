// Topological Sort using DFS only on DAG(Directed Acyclic Graph)

#include<iostream>
using namespace std;

void dfs(int node,vector<int> &vis, vector<int> adj[], stack<int> &s){

    vis[node] = 1;

    for(auto itr : adj[node]){

        if(vis[itr] == 0){ // not visited
            
            dfs(itr,vis,adj,s);

        }
        
    }

    s.push(node);
}

vector<int> topoSort(int n,vector<int> adj[]){

    vector<int> vis(n,0);
    stack<int> s;
    
    for(int i=0;i<n;i++){

        if(vis[i] == 0){

            dfs(i,vis,adj,s);

        }
    }

    vector<int> res;

    while(!s.empty()){

        res.push_back(s.top());
        s.pop();

    }
    
    return res;
}
int main(){

    cout<<"Enter the no. of nodes & edges : ";
    int n,m;
    cin>>n>>m;

    vector<int> adj[n]; // 0 based indexing 

    for(int i=0;i<m;i++){

        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);

    }

    vector<int> res = topoSort(n,adj);

    cout<<endl<<"Linear sorting is : ";

    for(auto itr : res){
        cout<<itr<<" ";
    }
    
}