// Bipartite Graph using DFS

#include<iostream>
using namespace std;

bool dfs(int start, vector<int> adj[], vector<int> &colors){
    
    for(auto itr : adj[start]){

        // not colored

        if(colors[itr] == -1){
            colors[itr] = !colors[start];
            if(dfs(itr,adj,colors) == false){
                return false;
            }
        }
        else if(colors[itr] == colors[start]){
            return false;
        }
    }

    return true;

}

bool isBipartite(int n,vector<int> adj[]){

    vector<int> colors(n+1,-1);

    for(int i=1;i<=n;i++){
        
        if(colors[i] == -1){

            colors[i] = 0;

            if(dfs(i,adj,colors) == false){
                return false;
            }
            
        }

    }

    return true;

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

    if(isBipartite(n,adj)){
        cout<<"Bipartite Graph";
    }
    else{
        cout<<"Not Bipartite Graph";
    }

}