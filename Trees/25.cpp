//optimised approach of 24.cpp
// TC - O(N logN )
#include<iostream>
#include<map>
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

void createMapping(int in[], map<int,int> &nodeToIndex, int n){

    for(int i=0;i<n;i++){
        nodeToIndex[in[i]] = i;
    }
}

node* solve(int in[],int pre[],int &preOrderIndex,int inorderstart,int inorderend,int n, map<int,int>&nodeToIndex){

    if(preOrderIndex >= n || inorderstart > inorderend){
        return nullptr;
    }

    int frontelement = pre[preOrderIndex++];
    node* rootnode = new node(frontelement);
    int position = nodeToIndex[frontelement];

    // left call
    rootnode->left = solve(in,pre,preOrderIndex,inorderstart,position-1,n,nodeToIndex);
    //right call
    rootnode->right = solve(in,pre,preOrderIndex,position+1,inorderend,n,nodeToIndex);

    return rootnode;
}

node* buildTree(int in[],int pre[], int n,map<int,int> &nodeToIndex){

    int preorderindex = 0;

    node* ans = solve(in,pre,preorderindex,0,n-1,n,nodeToIndex);
    return ans;
}

void postorder(node* root){

    if(root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
int main(){

    int in[] = {3,1,4,0,5,2};
    int pre[] = {0,1,3,4,2,5};

    int n = 6;

    map<int,int> nodeToIndex;

    // create nodes to index mapping
    createMapping(in,nodeToIndex,n);
    node* ans = buildTree(in,pre,n,nodeToIndex);
    postorder(ans);


}