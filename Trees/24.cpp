// creating a binary tree using inorder & preorder and printing the postorder 
// TC - O(N^2)

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

int findPosition(int in[],int frontElement,int n){

    for(int i=0;i<n;i++){
        if(in[i] == frontElement) return i;
    }

    return -1;
}

node* solve(int in[], int pre[], int &preOrderIndex, int inorderStart,int inorderEnd,int n){

    // base case

    if(preOrderIndex >= n || inorderStart > inorderEnd){
        return nullptr;
    }

    int frontElement = pre[preOrderIndex++]; // ++ because for every iteration a new root node will be there 
    node* rootNode = new node(frontElement);
    int nodePosition = findPosition(in,frontElement,n); // finding the root value position in the inorder[]

    // left subtree call
    rootNode->left = solve(in,pre,preOrderIndex,inorderStart,nodePosition-1,n);
    // right subtree call
    rootNode->right = solve(in,pre,preOrderIndex,nodePosition+1,inorderEnd,n);

    return rootNode;
}

void postorder(node* root){

    if(root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
node* buildTree(int in[], int pre[], int n){

    int preOrderIndex = 0;
    node* ans = solve(in,pre,preOrderIndex,0,n-1,n);
    return ans;
}

int main(){

    int in[] = {3,1,4,0,5,2};
    int pre[] = {0,1,3,4,2,5};

    int n = 6;

    node* root = buildTree(in,pre,n);
    postorder(root);

}