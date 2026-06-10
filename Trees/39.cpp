// vector approach for inorder pred and succ in BST

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

void inorder(node* root,vector<int>&ans){

    if(root == nullptr){
        return;
    }

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);

}

pair<int,int> predecessorOrSucessor(vector<int> &ans,int key){

    int pred = -1;
    int succ = -1;

    for(int i=0;i<ans.size();i++){
        if(ans[i] == key){
            pred = ans[i-1];
            succ = ans[i+1];
            break;
        }
    }

    return {pred,succ};
}

int main(){

    node* root = nullptr;
    cout<<"Enter the data for the BST : ";
    inputForBST(root);

    vector<int> ans;
    inorder(root,ans);

    cout<<"Enter the key : ";
    int key;
    cin>>key;

    pair<int,int> res = predecessorOrSucessor(ans,key);
    cout<<"Inorder Pred : "<<res.first<<endl;
    cout<<"Inorder Succ : "<<res.second<<endl;

}