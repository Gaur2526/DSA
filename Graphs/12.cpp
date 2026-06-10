// detect a cycle in an undirected graph using BFS

#include<iostream>
using namespace std;

bool detect(int src, vector<int> adj[],vector<int> &vis, queue<pair<int,int>> &q){

    vis[src] = 1;
    q.push({src,-1});
    
    while(!q.empty()){

        int currNode = q.front().first;
        int parent = q.front().second;

        q.pop();

        for(auto adjacentNode : adj[currNode]){

            if(vis[adjacentNode] == 0){
                vis[adjacentNode] = 1;
                q.push({adjacentNode,currNode});
            }
            else if(adjacentNode != parent){ // this is the case of cycle if the node is visited and it is not the parent 
                return true;
            }
        }
    }

    return false;
    
}

bool cycle(int n, vector<int> adj[]){

    vector<int> vis(n+1,0);
    queue<pair<int,int>> q;

    for(int i=1;i<=n;i++){

        if(!vis[i]){
            if(detect(i,adj,vis,q)){
                return true;
            }
        }
    }
    return false;

}
int main(){

    cout<<"No. of vertices & edges : ";
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1]; // if 1 based indexing

    for(int i=0;i<m;i++){

        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    
    if(cycle(n,adj)){
        cout<<"Cycle Detected";
    }
    else{
        cout<<"Cycle not found";
    }

     
}