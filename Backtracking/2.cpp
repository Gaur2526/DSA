// n queens problem
// TC : O(n! * n), SC : O(n^2)
// we can optimise this by using hashmap becuase the isSafe() is taking O(n) 

#include<iostream>
using namespace std;

void addSolution(vector<vector<int>> &board,  vector<vector<int>> &ans,int n){

    vector<int> temp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);

}

bool isSafe(int row,int col,vector<vector<int>> &board,int n){

    int x = row;
    int y = col;


    /*
     we have to check 2 thing for a safe movement:
       1. each row have only 1 queen
       2. diagonal check 

       imp - column should not be checked as we have written the code that no column should be 2 queens
       imp - for row we will check for the left side only because we are inserting from left to right so at 
       particular index right position will always be empty, same for the diagonal case

    */

    // row check

    while(y>=0){ // y means we are checking columns in the left direction for the same row 

        if(board[x][y] == 1){
            return false;
        }
        y--; 
    }

    // left upper diagonal check

    x = row;
    y = col;

    while(x>=0 && y >= 0){
        if(board[x][y] == 1){
            return false;
        }
       y--;
       x--;
    }

    // left below diagonal check

    x = row;
    y = col;

    while(x < n && y >= 0){

        if(board[x][y] == 1){
            return false;
        }

      y--;
      x++;

    }

    return true;

}

void solve(int col,vector<vector<int>> &board,  vector<vector<int>> &ans,int n){

    // base case : when the all the columns get filled 
    if(col == n){
        addSolution(board,ans,n);
        return;
    }

    // solve 1 case for column 0 rest will be handle by recursion

    for(int row = 0;row<n;row++){

        if(isSafe(row,col,board,n)){
            board[row][col] = 1;

            solve(col+1,board,ans,n);

            // backtracking : remove the queen
            board[row][col] = 0;

        }
    }
}

int main(){

    cout<<"Enter the no. of queens : ";
    int n;
    cin>>n;

    // create a n*n chessboard

    vector<vector<int>> board(n, vector<int>(n,0)); // all the values are zero because we will make 1 when queen is placed
   
    vector<vector<int>> ans;

    solve(0,board,ans,n);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    

}