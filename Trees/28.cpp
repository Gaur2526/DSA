// morris traversal

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

void morrisTraversal(node* root){

    if(root == nullptr) return;

    node* curr = root;
    
    while(curr != nullptr){

        if(curr->left == nullptr){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{

            node* pred = curr->left;
            while(pred->right != nullptr && pred->right != curr){
                pred = pred->right;
            }

            if(pred->right == nullptr){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right = nullptr;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}
int main(){

    node* root = nullptr;
    root = buildTree(root);

    morrisTraversal(root);
    
}