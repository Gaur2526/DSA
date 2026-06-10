// Two sum in a BST

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

void inorder(node* root,vector<int> &ans){

    if(root == nullptr){
        return;
    }

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);

}

bool twoSumInBST(vector<int> &inorderVal,int target){

    int i=0;
    int j = inorderVal.size()-1;

    while(i < j){

        int sum = inorderVal[i] + inorderVal[j];

        if(sum == target){
            return true;
        }
        else if(sum < target){
            i = i+1;
        }
        else{
            j = j-1;
        }
    }

    return false;
}

int main(){

    node* root = nullptr;

    cout<<"Enter the data for the BST : ";
    inputForBST(root);

    vector<int> inorderVal;
    inorder(root,inorderVal);

    cout<<"Enter the target sum : ";
    int target;
    cin>>target;

    if(twoSumInBST(inorderVal,target)){
        cout<<"Two Sum"<<endl;
    }
    else{
        cout<<"No Two Sum"<<endl;
    }

}
