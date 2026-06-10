// No. of islands using BFS

#include<iostream>
using namespace std;

void bfs(int row,int col,vector<vector<char>> &grid, vector<vector<int>> &vis){

    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col}); // we push the row and col in the pair 

    int n = grid.size(); // no of rows in grid
    int m = grid[0].size(); // no of cols in grid


    while(!q.empty()){

        int currRow = q.front().first;
        int currCol = q.front().second;
        
        q.pop();

        // checking the neighbours and pushed if not visited 

        // we have to check in all 8 directions for a particular {row,col} so this is the way we do

        for(int delRow = -1; delRow<=1 ; delRow++){

            for(int delCol = -1; delCol<=1; delCol++){

                int newRow = currRow + delRow;
                int newCol = currCol + delCol;


                if(
                    (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)&&
                    (vis[newRow][newCol] == 0) &&
                    (grid[newRow][newCol] == '1')
                ){
                    vis[newRow][newCol] = 1;
                    q.push({newRow,newCol});
                }
            }
        }
    }
}

int main(){

    vector<vector<char>> grid = {
        {'0','1','1','0'},
        {'0','1','1','0'},
        {'0','0','1','0'},
        {'0','0','0','0'},
        {'1','1','0','1'}
    };

    int noOfIslands = 0;

    int n = grid.size(); // no of rows
    int m = grid[0].size(); // no of cols

    vector<vector<int>> vis(n,vector<int>(m,0));


    for(int row = 0;row<n;row++){
        for(int col = 0;col<m;col++){

            if(vis[row][col] == 0 && grid[row][col] == '1'){
                noOfIslands++;
                bfs(row,col,grid,vis);
            }
        }
    }

    cout<<"No of islands : "<<noOfIslands;

}