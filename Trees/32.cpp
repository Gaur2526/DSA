// iterative searching in BST

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

node* insertIntoBST(node* root, int d){

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

bool found(node* root,int target){

    node* temp = root;

    while(temp != nullptr){

        if(temp->data == target){
            return true;
        }

        if(target < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }

    return false;
}

int main(){

    node* root = nullptr;

    cout<<"Enter the data for the BST: "<<endl;
    inputForBST(root);

    cout<<"Enter the key to search"<<endl;
    int key;
    cin>>key;

    if(found(root,key)){
        cout<<"Key found"<<endl;
    }
    else{
        cout<<"key not found"<<endl;
    }

}