// height balanced tree

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

int height(node* root){

    if(root == nullptr) return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;

    return ans;
}

bool isbalanced(node *root){

    if(root == nullptr) return true;

    bool leftsubtree = isbalanced(root->left);
    bool rightsubtree = isbalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;


    if(leftsubtree && rightsubtree && diff) return 1;
    
    return false;
}

int main(){

    node* root = nullptr;
    root = buildtree(root);

    cout<<isbalanced(root);

}