// inorder, preorder & postorder traversal

#include<iostream>
using namespace std;

class node{

    public:

    int data;
    node *left = NULL;
    node *right = NULL;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;

    }
};

node *buildtree(node *root){

    cout<<"Enter the data : "<<endl;

    int data;
    cin>>data;
    
    if(data == -1) return NULL;

    root = new node(data);

    cout<<"Enter the data to be inserted in left of : "<<data<<endl;
    root->left = buildtree(root->left);

    cout<<"Enter the data to be inserted in right of : "<<data<<endl;
    root->right = buildtree(root->right);

    return root;

}

void inorder(node *root){

    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void preorder(node *root){

    if(root == NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node *root){

    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

int main(){


    node *root = NULL;

    root = buildtree(root);

    cout<<"inorder traversal : ";
    inorder(root);

    cout<<endl;

    cout<<"preorder traversal : ";
    preorder(root);

    cout<<endl;

    cout<<"postorder traversal : ";
    postorder(root);

}