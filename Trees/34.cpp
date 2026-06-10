// validate BST

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

node* buildBST(node* root, int data){

    if(root == nullptr){

        root = new node(data);
        return root;

    }

    if(root->data > data){
        root->left = buildBST(root->left,data);
    }
    else{
        root->right = buildBST(root->right,data);
    }

    return root;

}

void insertIntoBST(node* &root){

    int data;
    cin>>data;

    while(data != -1){

        root = buildBST(root,data);
        cin>>data;

    }

}

void balanced(node* root,vector<int> &v){

    if(root == nullptr){
        return;
    }

    balanced(root->left,v);
    v.push_back(root->data);
    balanced(root->right,v);

}

bool isBalanced(vector<int> &v){

    for(int i=1;i<v.size();i++){

        if(v[i] <= v[i-1]){
            return false;
        }
    }

    return true;
}

int main(){

    node* root = nullptr;

    cout<<"Enter the data for the BST : "<<endl;

    insertIntoBST(root);

    vector<int> v;
    balanced(root,v);

    if(isBalanced(v)){
        cout<<"valid BST"<<endl;
    }
    else{
        cout<<"not valid BST"<<endl;
    }

}