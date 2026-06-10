// BFS Of a graph

#include<iostream>
using namespace std;

vector<int> BFSofGraph(int nodes,vector<int>adj[]){

    vector<int>visited(nodes+1,0); // creating a visited array of 1 based indexing

    queue<int> q;
    q.push(1);
    visited[1] = 1;

    vector<int> res;

    while(!q.empty()){

        int node = q.front();
        q.pop();

        res.push_back(node); // pushing the node to the result array

        for(auto itr : adj[node]){

            if(!visited[itr]){
                visited[itr] = 1;
                q.push(itr);
            }
        }
    }

    return res;

}

int main(){

    cout<<"Enter the no. of nodes & edges : ";
    int nodes,edges;
    cin>>nodes>>edges;

    vector<int> adj[nodes+1];

    for(int i=0;i<edges;i++){

        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    vector<int> bfs = BFSofGraph(nodes,adj);

    cout<<"BFS is : ";
    
    for(auto itr : bfs){
        cout<<itr<<" ";
    }

}