// number of enclaves using BFS

#include<iostream>
using namespace std;


int noOfEnclaves(vector<vector<int>> &grid){

    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int,int>> q;
    vector<vector<int>> vis(n,vector<int>(m,0));

    // for first row & last row

    for(int i=0;i<m;i++){

        // first row

        if(vis[0][i] == 0 && grid[0][i] == 1){

            q.push({0,i});
            vis[0][i] = 1;

        }

        // last row

        if(vis[n-1][i] == 0 && grid[n-1][i] == 1){

            q.push({n-1,i});
            vis[n-1][i] = 1;

        }
    }

    // for first col & last col

    for(int i=0;i<n;i++){

        // first col

        if(vis[i][0] == 0 && grid[i][0] == 1){

            q.push({i,0});
            vis[i][0] = 1;

        }

        // last col

        if(vis[i][m-1] == 0 && grid[i][m-1] == 1){

            q.push({i,m-1});
            vis[i][m-1] = 1;

        }
    }

    int countEnclaves = 0;

    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};

    while(!q.empty()){

        int currRow = q.front().first;
        int currCol = q.front().second;

        q.pop();

        for(int i=0;i<4;i++){

            int newRow = currRow + delRow[i];
            int newCol = currCol + delCol[i];

            if(
                (newRow >=0 && newRow < n && newCol >= 0 && newCol < m)&&
                (vis[newRow][newCol] == 0 && grid[newRow][newCol] == 1)
            ){

                q.push({newRow,newCol});
                vis[newRow][newCol] = 1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(grid[i][j] == 1 && vis[i][j] == 0){
                countEnclaves++;
            }
        }
    }

    return countEnclaves;

}
int main(){

    vector<vector<int>> grid = {
        {0,0,0,1},
        {0,1,1,0},
        {0,1,1,0},
        {0,0,0,1},
        {0,1,1,0}
    };

    int count = noOfEnclaves(grid);
    cout<<"No. of encalves is : "<<count;


}