// rotten oranges using bfs

#include<iostream>
#include<climits>
using namespace std;

void timeConsumed(vector<vector<int>> &grid, vector<vector<int>> &vis, queue<pair<pair<int,int>,int>> &q, int &maxTime){

    int n = grid.size();
    int m = grid[0].size();

    int delRow[4] = {-1,0,1,0};
    int delCol[4] = {0,1,0,-1};

    while(!q.empty()){

        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;

        q.pop();

        maxTime = max(maxTime,t);

        for(int i=0;i<4;i++){

            int newRow = r + delRow[i];
            int newCol = c + delCol[i];

            if(
                (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) &&
                (vis[newRow][newCol] != 2 && grid[newRow][newCol] == 1)
            ){

                vis[newRow][newCol] = 2;
                q.push({{newRow,newCol}, t + 1});
            }

        }
    }
}
int orangeRotting(vector<vector<int>> grid){

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n,vector<int>(m));

    queue<pair<pair<int,int>,int>> q; // {{row,col},time};

    int maxTime = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(grid[i][j] == 2){ // rotten oranges
                q.push({{i,j},0}); // initially the time is 0
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }
        }
    }

    timeConsumed(grid,vis,q,maxTime);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(grid[i][j] == 1 && vis[i][j] != 2){
                return -1;
            }
        }
    }

    return maxTime;

}
int main(){

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    cout<<"Max Time required to rotten the oranges is : "<<orangeRotting(grid);


}