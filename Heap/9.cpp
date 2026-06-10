// is binary tree Heap(max heap)

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

    cout<<"Enter the data: ";
    int data;
    cin>>data;

    if(data == -1){
        return nullptr;
    }

    root = new node(data);

    cout<<"Enter the data to be inserted in the left of : "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data to be inserted in the right of : "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

int countNodes(node* root){

    if(root == nullptr){
        return 0;

    }

    int left = countNodes(root->left);
    int right = countNodes(root->right);

    return 1 + left + right;


}

bool isCBT(node* root, int index,int nodeCnt){

    // if the tree is empty so it is considered as a CBT

    if(root == nullptr){
        return true;
    }

    if(index >= nodeCnt){
        return false;
    }
    else{

        bool left = isCBT(root->left,2*index + 1, nodeCnt);
        bool right = isCBT(root->right,2*index + 2, nodeCnt);

        return(left && right);

    }

    return false;

}

bool isMaxHeap(node* root){

    // leaf node

    if(root->left == nullptr && root->right == nullptr){
        return true;
    }

    // left child only 

    if(root->right == nullptr){

        return root->data > root->left->data;

    }
    else{

        // both childs

        return(

            root->data > root->left->data && root->data > root->right->data 
            &&
            isMaxHeap(root->left)
            &&
            isMaxHeap(root->right)
        );
    }
}
bool isHeap(node* root){

    int index = 0;
    int nodeCnt = countNodes(root);

    if(isCBT(root,index,nodeCnt) && isMaxHeap(root)){
        return true;
    }

    return false;

}
int main(){

    node* root = nullptr;
    root = buildTree(root);


    if(isHeap(root)){
        cout<<"Yes binary tree is max heap"<<endl;
    }
    else{
        cout<<"No binary tree is max heap"<<endl;
    }
}