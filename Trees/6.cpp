// height of a tree

#include<iostream>
using namespace std;

class node{

    public:
    
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root){

    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;

    root = new node(data);

    if(data == -1) return NULL;

    cout<<"Enter the data to be inserted in the left of : "<<data<<endl;
    root->left = buildTree(root->left);
    
    cout<<"Enter the data to be inserted in the right of : "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

int height(node *root){

    if(root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int ans = max(leftHeight,rightHeight) + 1;

    return ans;

}

int main(){

    node *root = NULL;
    root = buildTree(root);

    cout<<endl<<"Height of the tree is : "<<height(root)<<endl;
    return 0;

}