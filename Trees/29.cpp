// flatten a binary tree to linked list

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

    if(data == -1 ) return nullptr;

    root = new node(data);

    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;

}

void flatten(node* root){

    if(root == nullptr) return;

    node* curr = root;

    while(curr != nullptr){

        if(curr->left){

            node* pred = curr->left;

            while(pred->right){
                pred = pred->right;
            }

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        curr = curr->right;
    }
    
}

void printflatten(node* root){

    node* curr = root;
    while(curr != nullptr){
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}
int main(){

    node* root = nullptr;
    root = buildtree(root);
    
    flatten(root);
    printflatten(root);
}