// Convert O's with X's using DFS

#include<iostream>
using namespace std;

void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &mat,int delRow[],int delCol[]){

    vis[row][col] = 1;

    int n = mat.size();
    int m = mat[0].size();

    // finding neighours

    for(int i=0;i<4;i++){

        int newRow = row + delRow[i];
        int newCol = col + delCol[i];

        if(
            (newRow >= 0 && newRow < n && newCol >=0 && newCol < m) &&
            (vis[newRow][newCol] == 0 && mat[newRow][newCol] == 'O')
        ){
            dfs(newRow,newCol,vis,mat,delRow,delCol);
        }
    }

}

void replace(int n,int m, vector<vector<char>> &mat){

    vector<vector<int>> vis(n,vector<int>(m,0));

    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};


    // for first row & last row

    for(int i=0;i<m;i++){

        // first row

        if(vis[0][i] == 0 && mat[0][i] == 'O'){
            dfs(0,i,vis,mat,delRow,delCol);
        }

        // last row

        if(vis[n-1][i] == 0 && mat[n-1][i] == 'O'){
            dfs(n-1,i,vis,mat,delRow,delCol);
        }

    }

    // for first col & last col

    for(int i=0;i<n;i++){

        // first col

        if(vis[i][0] == 0 && mat[i][0] == 'O'){
            dfs(i,0,vis,mat,delRow,delCol);
        }

        // last col

        if(vis[i][m-1] == 0 && mat[i][m-1] == 'O'){
            dfs(i,m-1,vis,mat,delRow,delCol);
        }

    }

    // after all dfs calls

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(vis[i][j] == 0 && mat[i][j] == 'O'){ // means 'O' is not on the boundary
                mat[i][j] = 'X';
            }
        }
    }
}

int main(){

    vector<vector<char>> mat = {
        {'X','X','X','X'},
        {'X','O','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','X','O','O'}
    };

    int n = mat.size();
    int m = mat[0].size();

    cout<<"Replacing O's with X's : "<<endl;
    replace(n,m,mat);

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

}

