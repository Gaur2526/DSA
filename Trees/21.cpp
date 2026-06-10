// LCA of a binary tree

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

node* buildtree(node* root){

    int data;
    cin>>data;

    if(data == -1) return nullptr;

    root = new node(data);

    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;

}

node* LCA(node* root, int n1, int n2){

    // base case

    if(root == nullptr){
        return nullptr;
    }

    // this is the ans like the nodes are the matched 
    if(root->data == n1 || root->data == n2){
        return root;
    }

    node* leftans = LCA(root->left,n1,n2);
    node* rightans = LCA(root->right,n1,n2);

    // now 4 cases are there 

    if(leftans != nullptr && rightans != nullptr){
        return root;
    }

    else if(leftans != nullptr || rightans == nullptr){
        return leftans;
    }
    
    else if(leftans == nullptr || rightans != nullptr){
        return rightans;
    }
    else{
        return nullptr;
    }


}
int main(){

    node* root = nullptr;
    root = buildtree(root);

    int n1,n2;
    cin>>n1>>n2;

    node* lcaNode = LCA(root,n1,n2);

    cout<<lcaNode->data<<" ";

}
