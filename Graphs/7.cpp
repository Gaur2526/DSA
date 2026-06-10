// No. of Provinces using BFS

#include<iostream>
using namespace std;

void bfs(int startingNode,vector<int> adj[],vector<int>&vis){

    queue<int> q;
    q.push(startingNode);
    vis[startingNode] = 1;

    while(!q.empty()){

        int frontNode = q.front();
        q.pop();

        for(auto itr : adj[frontNode]){

            if(!vis[itr]){
                vis[itr] = 1;
                q.push(itr);
            }
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

    int provinceCnt = 0;

    vector<int> vis(n+1,0);

    for(int i=1;i<=n;i++){

        if(vis[i] == 0){
            provinceCnt++;
            bfs(i,adj,vis);
        }
    }

    cout<<"No. of provinces is : "<<provinceCnt;

}