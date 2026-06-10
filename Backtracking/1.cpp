// Rat in a maze

#include<iostream>
using namespace std;

bool isSafe(int newX, int newY, vector<vector<bool>> &visited,vector<vector<int>> &arr,int n){

    if( (newX >= 0 && newX < n) && (newY >= 0 && newY < n) && visited[newX][newY] != 1 && arr[newX][newY] != 0){
        return true;
    }

    return false;

}

void solve(int x,int y, int n, vector<vector<int>> &arr, vector<vector<bool>> &vis, string path, vector<string> &ans){

    // base case
    
    // destination reached 
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;

    }

    // 4 movement 
    // D L R U

    vis[x][y] = 1;

    // Down movement 
    if(isSafe(x+1, y,vis,arr,n)){
        solve(x+1,y,n,arr,vis,path+'D',ans); 
    }

    // left movement

    if(isSafe(x,y-1,vis,arr,n)){
        solve(x,y-1,n,arr,vis,path + 'L',ans);
    }

    // right movement

    if(isSafe(x,y+1,vis,arr,n)){
        solve(x,y+1,n,arr,vis,path + 'R',ans);
    }

    // up movement

    if(isSafe(x-1,y,vis,arr,n)){

        solve(x-1,y,n,arr,vis,path + 'U',ans);
    }

    vis[x][y] = 0; // when return so make it zero 

}

vector<string> ratPath(vector<vector<int>> &arr, int n){

    vector<string> ans;

    string path = "";

    if(arr[0][0] == 0){
        return ans;
    }

    vector<vector<bool>> visited(n, vector<bool>(n,0));

    solve(0,0,n,arr,visited,path,ans);

    return ans;

    
}
int main(){

    vector<vector<int>> arr = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,0,0},
        {0,1,1,1}
    };

    cout<<"Enter the no. of rows : ";
    int n;
    cin>>n;


    vector<string> res = ratPath(arr,n);
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<endl;
    }

}