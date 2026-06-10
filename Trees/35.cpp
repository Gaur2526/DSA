// validate BST: OPTIMISED APPROACH

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

node* insertIntoBST(node* root, int d){

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

bool isValid(node* root, int minRange, int maxRange){

    if(root == nullptr) return true; // empty BST is always valid 

    if(root->data <= minRange || root->data >= maxRange){
        return false;
    }

    return isValid(root->left,minRange,root->data) && isValid(root->right,root->data,maxRange);

}

int main(){

    node* root = nullptr;

    cout<<"Enter the data for the BST: "<<endl;
    inputForBST(root);

    if(isValid(root,INT_MIN,INT_MAX)){
        cout<<"Valid BST"<<endl;
    }
    else{
        cout<<"Not a Valid BST"<<endl;
    }

}