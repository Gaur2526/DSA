// largest BST in a binary tree

#include<iostream>
#include<climits>
using namespace std;

class node{

    public:

        int data;
        node* left;
        node* right;

        node(int d){
            this->data = d;
            this->left = nullptr;
            this->right = nullptr;
        }
};

class info{

    public:
        int maxi;
        int mini;
        bool isBST;
        int size;

};

node* buildTree(node* root){

    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return nullptr;
    }

    root = new node(data);

    cout<<"Enter the data to be inserted in the left of : "<<data<<" "<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data to be inserted in the right of : "<<data<<" "<<endl;
    root->right = buildTree(root->right);

    return root;

}

info solve(node* root,int &ans){

    // base case

    if(root == nullptr){

        return{INT_MIN,INT_MAX,true,0};

    }

    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data,right.maxi);
    currNode.mini = min(root->data,left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    // update ans

    if(currNode.isBST){
        ans = max(ans,currNode.size);

    }
    return currNode;

}

int largestBSTSize(node* root){

    int maxSize = 0;

    solve(root,maxSize);
    return maxSize;

}

int main(){

    node* root = nullptr;
    root = buildTree(root);


    cout<<"Largest BST Size is : "<<largestBSTSize(root)<<endl;

}