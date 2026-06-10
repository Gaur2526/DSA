// Boundary Traversal

#include<iostream>
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

node* buildTree(node* root){

    int data;
    cin>>data;

    if(data == -1) return nullptr;

    root = new node(data);

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;

}

void leftsubtreeTraverse(node* root, vector<int>&ans){

    if(root == nullptr){
        return;
    }

    // leaf nodes case
    if(root->left == nullptr && root->right == nullptr){
        return;
    }

    ans.push_back(root->data);

    if(root->left){
        leftsubtreeTraverse(root->left,ans);
    }
    else{
        leftsubtreeTraverse(root->right,ans);
    }
}

void leafnodeTraverse(node* root, vector<int> &ans){

    if(root == nullptr){
        return;
    }

    // leaf node
    if(root->left == nullptr && root->right == nullptr){
        ans.push_back(root->data);
        return;
    }

    leafnodeTraverse(root->left,ans);
    leafnodeTraverse(root->right,ans);

}

void rightsubtreeTraverse(node* root,vector<int> &ans){

    if(root == nullptr) return ;

    if(root->left == nullptr && root->right == nullptr){
        return ;
    }

    if(root->right){
        rightsubtreeTraverse(root->right,ans);
    }
    else{
        rightsubtreeTraverse(root->left,ans);
    }

    ans.push_back(root->data);

}

vector<int> boundaryTraverse(node* root){

    vector<int> ans;

    if(root == nullptr) return ans;

    ans.push_back(root->data);

    // left subtree traversal
    leftsubtreeTraverse(root->left,ans);
    
    // traverse leaf nodes

    // 1. leaf node in left subtree
    leafnodeTraverse(root->left,ans);
    // 2. leaf node in right subtree
    leafnodeTraverse(root->right,ans);

    // right subtree traversal
    rightsubtreeTraverse(root->right,ans);

    return ans;


}
int main(){

    node* root = nullptr;
    root = buildTree(root);

    vector<int> res = boundaryTraverse(root);

    for(auto itr : res){
        cout<<itr<<" ";
    }

}