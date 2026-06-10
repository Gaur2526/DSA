#include<iostream>
#include<climits>
using namespace std;

void bfs(vector<vector<int>> &oranges,vector<vector<int>> &vis,queue<pair<pair<int,int>,int>> &q,int &maxTime){

    int delRow[4] = {-1,0,1,0};
    int delCol[4] = {0,1,0,-1};

    int n = oranges.size();
    int m = oranges[0].size();

    while(!q.empty()){

        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;

        maxTime = max(maxTime,t);
        q.pop();

        for(int i=0;i<4;i++){

            int newRow = r + delRow[i];
            int newCol = c + delCol[i];

            if(
                (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)&&
                (vis[newRow][newCol] != 2 && oranges[newRow][newCol] == 1)
            ){
                q.push({{newRow,newCol},t+1});
                vis[newRow][newCol] = 2;
            }
        }
    }
}

int time(vector<vector<int>> &oranges){

    int n = oranges.size();
    int m = oranges[0].size();

    vector<vector<int>> vis(n,vector<int>(m));

    queue<pair<pair<int,int>,int>> q;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(oranges[i][j] == 2){
                q.push({{i,j},0});
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }
        }
    }

    int maxTime = 0;

    bfs(oranges,vis,q,maxTime);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(oranges[i][j] == 1 && vis[i][j] != 2){
                return -1;
            }
        }
    }

    return maxTime;

}
int main(){

    vector<vector<int>> oranges = {
        {0,1,2},
        {0,1,2},
        {2,1,1}
    };

    int rottenTime = time(oranges);

    cout<<"Rotten time is : "<<rottenTime;


}