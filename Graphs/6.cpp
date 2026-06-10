// NO. Of provinces using DFS

#include<iostream>
using namespace std;

void dfs(int startingNode,vector<int> adj[],vector<int>&vis){

    vis[startingNode] = 1;

    for(auto itr : adj[startingNode]){

        if(!vis[itr]){
            dfs(itr,adj,vis);
        }
    }
}
int main(){

    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];

    for(int i=0;i<m;i++){

        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    vector<int> vis(n+1,0);
    int provincesCnt = 0;

    for(int i=1;i<=n;i++){

        if(!vis[i]){
            provincesCnt++;
            dfs(i,adj,vis);

        }
    }

    cout<<"No. of provinces is : "<<provincesCnt<<endl;

}