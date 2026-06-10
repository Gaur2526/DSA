// right view of a binary tree 

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

void solve(node* root, vector<int> &ans, int level){

    if(root == nullptr) return ;

    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->right,ans,level+1);
    solve(root->left,ans,level+1);

}

vector<int> rightView(node* root){

    vector<int> ans;
    solve(root,ans,0);

    return ans;
}

int main(){


    node* root = nullptr;
    root = buildTree(root);


    vector<int> res = rightView(root);

    for(auto itr : res){
        cout<<itr<<" ";
    }
    
}