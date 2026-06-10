// storing the graph using list way

#include<iostream>
#include<vector>
using namespace std;
int main(){

    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];

    for(int i=0;i<m;i++){

        int u,v;
        cin>>u>>v;

        adj[u].push_back(v); // means for any particular node push the neighbour on the corresponding index 
        adj[v].push_back(u);

    }

}