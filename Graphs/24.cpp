// Cycle Detection in Directed Graph using (BFS/Khan's Algorithm)

#include<iostream>
using namespace std;

bool cycle(int n,vector<int> adj[]){

    vector<int> indegree(n+1);

    for(int i=1;i<=n;i++){

        for(auto itr : adj[i]){
            indegree[itr]++;
        }
    }

    queue<int> q;
    int cnt = 0; // topo sort array size;

    for(int i=1;i<=n;i++){

        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){

        int node = q.front();
        q.pop();
        cnt++;

        for(auto itr : adj[node]){

            indegree[itr]--;

            if(indegree[itr] == 0){
                q.push(itr);
            }

        }
    }

    if(cnt < n){
        return true;
    }

    return false;

}

int main(){

    cout<<"Enter the no. of nodes & edges : ";

    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1]; //1 based indexing

    for(int i=0;i<m;i++){

        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);

    }

    if(cycle(n,adj)){
        cout<<"Cycle Detected"<<endl;
    }
    else{
        cout<<"No Cycle Detected"<<endl;
    }

}