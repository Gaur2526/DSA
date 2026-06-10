// kth incestor in a tree

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

node* solve(node* root,int &k,int targetNode){

    if(root == nullptr){
        return nullptr;
    }

    if(root->data == targetNode){
        return root;
    }

    node* leftans = solve(root->left,k,targetNode);
    node* rightans = solve(root->right,k,targetNode);

    // going back to the previous call

    if(leftans != nullptr && rightans == nullptr){
        k--;

        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return leftans;
    }

    if(leftans == nullptr && rightans != nullptr){
        k--;

        if(k<=0){
            k = INT_MAX;
            return root;
        }

        return rightans;
    }

    return nullptr;
    
}
int KthAncestor(node* root,int k,int targetNode){

    node* ancestor = solve(root,k,targetNode);

    if(ancestor == nullptr || ancestor->data == targetNode){
        return -1;
    }
    return ancestor->data;
}
int main(){


    node* root = nullptr;
    root = buildtree(root);

    int k,targetNode;
    cin>>k>>targetNode;

    int res = KthAncestor(root,k,targetNode);
    cout<<res<<endl;
} 