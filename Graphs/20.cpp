// Detect cycle in a directed graph using DFS

#include<iostream>
using namespace std;

bool dfs(int node,vector<int> adj[], vector<int> &vis, vector<int> &pathvis){

    vis[node] = 1;
    pathvis[node] = 1;

    for(auto itr : adj[node]){

        if(!vis[itr]){ // adjacent node is not traversed yet

            if(dfs(itr,adj,vis,pathvis)){ // during backtracking the call comes here and for the false condition this statement not executes and as all neighbours processed so it ends the loop 
                return true;
            }

        }
        else if(pathvis[itr] == 1){ // means already visited and on the same path

            return true;

        }
    }

    pathvis[node] = 0;
    return false;
}

bool detect(int n,vector<int> adj[]){

    vector<int> Vis(n+1,0);
    vector<int> pathVis(n+1,0);

    for(int i=1;i<=n;i++){

        if(!Vis[i]){

            if(dfs(i,adj,Vis,pathVis)){
                return true;
            }
        }
    }

    return false;

}
int main(){

    cout<<"No. of nodes & edges : ";

    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];

    for(int i=0;i<m;i++){

        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);

    }

    if(detect(n,adj)){
        cout<<"Cycle Detect"<<endl;
    }
    else{
        cout<<"No Cycle Detect"<<endl;
    }


}