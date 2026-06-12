// number of distinct islands using DFS

#include<iostream>
#include<set>
using namespace std;

void dfs(int row,int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int,int>> &vec,int baseRow,int baseCol,int delrow[],int delcol[]){

    int n = grid.size();
    int m = grid[0].size();

    vis[row][col] = 1;
    vec.push_back({row-baseRow,col-baseCol});

    for(int i=0;i<4;i++){

        int newRow = row + delrow[i];
        int newCol = col + delcol[i];

        if(
            (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)&&
            (vis[newRow][newCol] == 0 && grid[newRow][newCol] == 1)
        ){
            dfs(newRow,newCol,grid,vis,vec,baseRow,baseCol,delrow,delcol);
        }
    }
    
}

int distinctIslands(vector<vector<int>> &grid){

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>> st; // each element of set is of type vector<pair<int,int>>
    
    int delRow[4] = {-1,0,1,0};
    int delCol[4] = {0,-1,0,1};


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            // starting point

            if(vis[i][j] == 0 && grid[i][j] == 1){
                vector<pair<int,int>> vec;
                dfs(i,j,grid,vis,vec,i,j,delRow,delCol); // last i,j are the base indexes 
                st.insert(vec);
            }
        }
    }

    return st.size();

}

int main(){

    vector<vector<int>> grid = {
        {1,1,0,1,1},
        {1,0,0,0,0},
        {0,0,0,1,1},
        {1,1,0,1,0}
    };


    cout<<"No of distinct islands : "<<distinctIslands(grid);

}