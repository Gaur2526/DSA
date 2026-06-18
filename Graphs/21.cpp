// Eventual Safe state using Cycle detection in directed graph (DFS)

#include<iostream>
using namespace std;

bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathvis, vector<int> &check){

    vis[node] = 1;
    pathvis[node] = 1;

    for(auto itr : adj[node]){

        if(vis[itr] == 0){ // neighbour is not visited

            if(dfs(itr,adj,vis,pathvis,check)){

                check[node] = 0;
                return true;

            }
        }
        else if(pathvis[itr] == 1){

            check[node] = 0; 
            return true;
        }
    }


    pathvis[node] = 0;
    check[node] = 1;
    return false;

}

vector<int> safeNodes(int n, vector<int> adj[]){

    vector<int> vis(n,0);
    vector<int> pathvis(n,0);
    vector<int> check(n,0);
    vector<int> safe;

    for(int i=0;i<n;i++){

        // starting node

        if(vis[i] == 0){

            dfs(i,adj,vis,pathvis,check);

        }
    }


    for(int i=0;i<n;i++){

        if(check[i] == 1){
            safe.push_back(i);
        }
    }

    sort(safe.begin(),safe.end());

    return safe;

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

    vector<int> res = safeNodes(n,adj);

    cout<<endl<<"safe nodes are : ";

    for(auto itr : res){
        cout<<itr<<" ";
    }

}