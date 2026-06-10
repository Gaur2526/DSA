// No. of Islands using DFS

#include<iostream>
using namespace std;

void dfs(int row,int col,vector<vector<char>> &grid, vector<vector<int>> &vis){

    vis[row][col] = 1;

    int n = grid.size();
    int m = grid[0].size();

    for(int delRow = -1;delRow<=1;delRow++){

        for(int delCol = -1;delCol<=1;delCol++){

            int newRow = delRow + row;
            int newCol = delCol + col;

            if(
                (newRow>= 0 && newRow < n && newCol>=0 && newCol<m)&&
                (!vis[newRow][newCol])&&
                (grid[newRow][newCol] == '1')
            ){

                dfs(newRow,newCol,grid,vis);
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

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n,vector<int>(m,0));

    for(int row = 0;row<n;row++){
        for(int col = 0;col<m;col++){

            if(!vis[row][col] && grid[row][col] == '1'){

                noOfIslands++;
                dfs(row,col,grid,vis);

            }
        }
    }

    cout<<"No of islands is : "<<noOfIslands;


}