// sudoku solver

#include<iostream>
using namespace std;

bool isSafe(int row,int col,vector<vector<int>>&board,int val){

    for(int i = 0;i<board.size();i++){

        //row check

        if(board[row][i] == val){
            return false;
        }

        // col check

        if(board[i][col] == val){
            return false;
        }

        // 3*3 matrix check

        if(board[3*(row/3)+ i/3][3*(col/3) + i%3] == val){
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &board){

    for(int row = 0;row<board.size();row++){

        for(int col = 0;col<board.size();col++){

            if(board[row][col] == 0){

                for(int val=1;val<=9;val++){

                    if(isSafe(row,col,board,val)){

                        // if the value is safe then insert
                        board[row][col] = val;

                        bool nextPossibleSolution = solve(board);
                        if(nextPossibleSolution){
                            return true;
                        }
                        else{
                            board[row][col] = 0; // backtracking
                        }

                    }
                }

                return false; // if no possible solution found
            }
        }
    }

    return true;
}
int main(){

    vector<vector<int>> board = {

        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},

        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},

        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}

    };

    solve(board);

    for(int i=0;i<board.size();i++){

        for(int j=0;j<board.size();j++){
            cout<<board[i][j]<<" ";
        }

        cout<<endl;
    }
}