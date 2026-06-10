// flatten the BST into sorted linked list

#include<iostream>
#include<vector>
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

node* insertIntoBST(node* root,int d){

    if(root == nullptr){
        root = new node(d);
        return root;
    }

    if(root->data > d){
        root->left = insertIntoBST(root->left,d);
    }
    else{
        root->right = insertIntoBST(root->right,d);
    }

    return root;

}

void inputForBST(node* &root){

    int data;
    cin>>data;

    while(data != -1){

        root = insertIntoBST(root,data);
        cin>>data;
    }
}

void inorder(node* root,vector<int> &ans){

    if(root == nullptr){
        return;
    }

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);

}

node* flattenBST(vector<int> &inorderVal){

    if(inorderVal.size() == 0){
        return nullptr;
    }
    
    node* newRoot = new node(inorderVal[0]); // first element
    node* curr = newRoot;

    for(int i=1;i<inorderVal.size();i++){

        node* temp = new node(inorderVal[i]);
        curr->left = nullptr;
        curr->right = temp;
        curr = temp;
    }

    curr->left = nullptr;
    curr->right = nullptr;

    return newRoot; 

}
int main(){

    node* root = nullptr;
    cout<<"Enter the data for the BST : ";
    inputForBST(root);

    vector<int> ans;
    inorder(root,ans);

    root = flattenBST(ans);
    
}