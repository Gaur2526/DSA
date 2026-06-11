// nearest cell having 1 using BFS

#include<iostream>
using namespace std;

vector<vector<int>> distance(vector<vector<int>> &grid){

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m));
    queue<pair<pair<int,int>,int>> q;

    vector<vector<int>> Distance(n,vector<int>(m));

    // pushing the {row,col} having value 1
    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(grid[i][j] == 1){
                q.push({{i,j},0});
                vis[i][j] = 1;
            }
            else{
                vis[i][j] = 0;
            }
        }
    }

    // BFS logic

    int delRow[4] = {-1,0,1,0};
    int delCol[4] = {0,1,0,-1};


    while(!q.empty()){

        int currRow =q.front().first.first;
        int currCol = q.front().first.second;
        int steps = q.front().second;

        Distance[currRow][currCol] = steps;

        q.pop();

        // finding neighbours

        for(int i=0;i<4;i++){

            int newRow = currRow + delRow[i];
            int newCol = currCol + delCol[i];

            if(
                (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)&&
                (vis[newRow][newCol] == 0)
            ){
                q.push({{newRow,newCol},steps+1});
                vis[newRow][newCol] = 1;
            }
        }
    }

    return Distance;

}
int main(){

    vector<vector<int>> grid = {
        {0,0,0},
        {0,1,0},
        {1,0,1}
    };


    cout<<"Distance matrix is : "<<endl;

    vector<vector<int>> res = distance(grid);

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}