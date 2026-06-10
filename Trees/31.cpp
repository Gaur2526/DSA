// searching in BST

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

    if(d > root->data){
        root->right = insertIntoBST(root->right,d);
    }
    else{
        root->left = insertIntoBST(root->left,d);
    }

    return root;

}

bool found(node* root,int target){

    if(root == nullptr){
        return false;
    }

    if(root->data == target){
        return true;
    }

    if(root->data > target){
        return found(root->left,target);
    }
    else{
        return found(root->right,target);
    }

}

void takeInputForBST(node* &root){

    int data;
    cin>>data;

    while(data != -1){

        root = insertIntoBST(root,data);
        cin>>data;

    }
}
int main(){

    node* root = nullptr;

    cout<<"Enter the data for BST: "<<endl;
    takeInputForBST(root);

    cout<<"Enter the key to search : "<<endl;
    int key;
    cin>>key;

    if(found(root,key)){
        cout<<"key found"<<endl;
    }
    else{
        cout<<"key not found"<<endl;
    }

}