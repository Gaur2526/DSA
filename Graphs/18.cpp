// Bipartite Graph using BFS

#include<iostream>
using namespace std;

bool check(int start, vector<int> adj[], vector<int> &colors){

    queue<int> q;
    q.push(start);
    colors[start] = 0;

    while(!q.empty()){

        int currNode = q.front();
        q.pop();

        for(auto itr : adj[currNode]){

            // not colored yet 
            if(colors[itr] == -1){

                colors[itr] = !colors[currNode];
                q.push(itr);

            }
            else if(colors[itr] == colors[currNode]){ // colored & same as the neighbour
                return false;
            }
        }

    }

    return true;

}
bool isBipartite(int n, vector<int> adj[]){

    vector<int>colors(n+1,-1);

    // for multiple components 

    for(int i=1;i<=n;i++){

        if(colors[i] == -1){ //not colored yet means the starting point 
            if(check(i,adj,colors) == false){
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
        cout<<"Bipartite graph"<<endl;
    }
    else{
        cout<<"Not a Bipartite graph"<<endl;
    }

}