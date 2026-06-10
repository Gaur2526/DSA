// flood fill algorithm using dfs

#include<iostream>
using namespace std;

void dfs(int row,int col, vector<vector<int>> &image, vector<vector<int>> &copy, int newColor,int delRow[],int delCol[],int initialColor){

    copy[row][col] = newColor; // marking the particular row,col with the newColor

    int noOfRows = copy.size();
    int noOfCols = copy[0].size();

    // finding all the 4 neighbours

    for(int i=0;i<4;i++){

        int newRow = row + delRow[i];
        int newCol = col + delCol[i];


        if(
            (newRow >= 0 && newRow < noOfRows && newCol >= 0 && newCol < noOfCols)&&
            (image[newRow][newCol] == initialColor && copy[newRow][newCol] != newColor) // means the color has not changed in the copy array till now
        ){

            dfs(newRow,newCol,image,copy,newColor,delRow,delCol,initialColor);
        }
    }
    
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr,int sc, int newColor){

    vector<vector<int>> copy = image; // we will not change the original data/image

    int initialColor = copy[sr][sc];

    if(initialColor == newColor){
        return copy;
    }

    // 4 directions/neighbours for any (row,col);
    int delRow[4] = {-1,0,1,0};
    int delCol[4] = {0,1,0,-1};

    dfs(sr,sc,image,copy,newColor,delRow,delCol,initialColor);

    return copy;

}
int main(){

    vector<vector<int>> image = {

        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    cout<<"Enter the sr & sc : ";
    int sr,sc;
    cin>>sr>>sc;

    cout<<endl<<"Enter the new color : ";
    int newColor;
    cin>>newColor;


    cout<<endl<<"After Flood fill : "<<endl;
    vector<vector<int>> res = floodFill(image,sr,sc,newColor);

    for(int i=0;i<res.size();i++){

        for(int j=0;j<res[0].size();j++){

            cout<<res[i][j]<<" ";

        }

        cout<<endl;
    }


}