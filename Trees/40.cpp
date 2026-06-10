// LCA In a BST

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

node* LCA(node* root, int n1, int n2){

    if(root == nullptr){
        return nullptr;
    }

    if(root->data < n1 && root->data < n2){
        return LCA(root->right,n1,n2);
    }
    
    if(root->data > n1 && root->data > n2){
        return LCA(root->left,n1,n2);
    }

    return root;
}
int main(){

    node* root = nullptr;
    cout<<"Enter the data for the BST : ";
    inputForBST(root);

    cout<<"Enter root1 and root2 : ";
    int n1,n2;
    cin>>n1>>n2;

    cout<<"LCA is : "<<LCA(root,n1,n2)->data<<endl;

}