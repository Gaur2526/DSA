// Diameter of a tree

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

node* buildtree(node* root){

    int data;
    cin>>data;

    root = new node(data);

    if(data == -1) return NULL;

    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;

}

int height(node *root){

    if(root == nullptr) return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;

    return ans;

}
int diameter(node* root){

    if(root == nullptr) return 0;

    int leftSubtreeDia = diameter(root->left);
    int rightSubtreeDia = diameter(root->right);
    int comboleftandrightDia = height(root->left) + 1 + height(root->right);

    int ans =  max(leftSubtreeDia, max(rightSubtreeDia,comboleftandrightDia));

    return ans;
}
int main(){

    node* root = nullptr;

    root = buildtree(root);

    cout<<"Diameter is : "<<diameter(root);



}