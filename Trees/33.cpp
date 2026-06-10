// deletion in BST

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
            this->right = nullptr;;

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

node* minVal(node* root){

    if(root == nullptr) return nullptr;

    node* temp = root;

    while(temp->left != nullptr){

        temp = temp->left;
    }

    return temp;
}
node* deletion(node* root, int nodeToDlt){ // if we return the root so there is no need to by it by reference

    // base case

    if(root == nullptr){
        return nullptr;
    }

    if(root->data == nodeToDlt){

        // 0 child 

        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }

        // 1 child

         // 1. left child

         if(root->left != nullptr && root->right == nullptr){

            node* temp = root->left;
            delete root;
            return temp;

         }

         // 2. right child

         if(root->left == nullptr && root->right != nullptr){

            node* temp = root->right;
            delete root;
            return temp;

         }

        // 2 child

        if(root->left != nullptr && root->right != nullptr){

            int mini = minVal(root->right)->data;

            root->data = mini;

            root->right = deletion(root->right,mini);
            
            return root;
        }

    }
    else if(root->data > nodeToDlt){
        root->left = deletion(root->left,nodeToDlt);
        return root;
    }
    else{
        root->right = deletion(root->right,nodeToDlt);
        return root;
    }

}

int main(){

    node* root = nullptr;

    inputForBST(root);

    int nodeToDlt;
    cin>>nodeToDlt;

    root = deletion(root,nodeToDlt);


}