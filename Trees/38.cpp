// inorder predecessor and sucessor in BST

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

pair<int,int> predecessorOrSucessor(node* root,int k){

    node* temp = root;

    int pred = -1;
    int succ = -1;

    while(temp->data != k){
        
        if(temp->data > k){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;  
        }

    }

    node* leftsubtree = temp->left;
    node* rightsubtree = temp->right;

    while(leftsubtree != nullptr){ // need max value from the left subtree

        pred = leftsubtree->data;
        leftsubtree = leftsubtree->right; // max value comes in right subtree
    }

    while(rightsubtree != nullptr){ // need min value from the right subtree

        succ = rightsubtree->data;
        rightsubtree = rightsubtree->left; // min value comes in the left subtree

    }

    return {pred,succ};
}

int main(){

    node* root = nullptr;
    cout<<"Enter the data for the BST : ";
    inputForBST(root);

    cout<<"Enter the key : ";
    int key;
    cin>>key;

    pair<int,int> ans = predecessorOrSucessor(root,key);
    cout<<"Inorder pred : "<<ans.first<<endl;
    cout<<"Inorder Succ : "<<ans.second<<endl;

}