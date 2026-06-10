// merge k sorted arrays

#include<iostream>
#include<queue>
using namespace std;

class node{

    public:
        int data;
        int row;
        int col;

        node(int d,int r, int c){
            data = d;
            row = r;
            col = c;
        }
};

class compare{

    public:

        bool operator()(node*a, node*b){
            return a->data > b->data;
        }
};

vector<int> mergedArray(vector<vector<int>> KArrays, int k){

    vector<int> ans;

    // min heap 
    priority_queue<node*, vector<node*>,compare> minHeap; 
    /* node have 3 values  :
    
        node(data,row,col);
   */

   // insert the first element of all the k arrays into the min heap

    for(int i=0;i<k;i++){

        node* temp = new node(KArrays[i][0],i,0); // col = 0 because we are inserting the first element only
        minHeap.push(temp);

    }

    while(minHeap.size() > 0){

        // smallest element at the top out of the first element of all k arrays

        node* temp = minHeap.top();

        ans.push_back(temp->data);
        minHeap.pop();

        // enter the next element

        int rowNumber = temp->row;
        int colNumber = temp->col;

        if(colNumber+1 < KArrays[rowNumber].size()){
            node* next = new node(KArrays[rowNumber][colNumber+1],rowNumber,colNumber+1);
            minHeap.push(next);
        }

    }

    return ans;

}
int main(){

    vector<vector<int>> KArrays = {
        {1,4,7},
        {2,5,8},
        {3,6,9}
    };

    cout<<"Enter the value of k : ";
    int k;
    cin>>k;


    cout<<"Merged sorted array is : ";

    vector<int> res = mergedArray(KArrays,k);

    for(auto itr : res){

        cout<<itr<<" ";
    }

}