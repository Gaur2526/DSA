// cycle detection in an undirected graph using DFS

#include<iostream>
using namespace std;

bool detect(int node,int parent,vector<int> adj[], vector<int> &vis){

    vis[node] = 1;

    for(auto adjacentNode : adj[node]){

        if(!vis[adjacentNode]){

            if(detect(adjacentNode,node,adj,vis)){
                return true;
            }
        }
        else if(adjacentNode != parent){
            return true;
        }
    }

    return false;


}
bool cycle(int n, vector<int> adj[]){

    vector<int> vis(n+1,0);

    for(int i=1;i<=n;i++){

        if(!vis[i]){

            if(detect(i,-1,adj,vis)){
                return true;
            }
        }
    }

    return false;

}
int main(){

    cout<<"Enter the no. of nodes & edges : ";
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];

    for(int i=0;i<m;i++){

        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }


    if(cycle(n,adj)){
        cout<<"Cycle Found"<<endl;
    }
    else{
        cout<<"No Cycle Found"<<endl;
    }

}