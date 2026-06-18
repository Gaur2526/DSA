// Topological Sort using BFS

#include<iostream>
using namespace std;

vector<int> topoSort(int n,vector<int> adj[]){


    vector<int> indegree(n);

    for(int i=0;i<n;i++){

        for(auto itr : adj[i]){

            indegree[itr]++;

        }
    }

    queue<int> q;

    for(int i=0;i<n;i++){

        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> linearSorting;

    while(!q.empty()){

        int node = q.front();
        q.pop();

        linearSorting.push_back(node);

        for(auto itr : adj[node]){

            indegree[itr]--; // reducing the indegree of the neighbours

            if(indegree[itr] == 0){
                q.push(itr);
            }
        }
    }

    return linearSorting;

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

    cout<<endl<<"Linear Sorting is : ";

    for(auto itr : res){
        cout<<itr<<" ";
    }

}