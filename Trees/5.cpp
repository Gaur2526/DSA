// count no. of leaf nodes

#include<iostream>
using namespace std;

class node {

    public:

    int data;
    node *left;
    node *right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;

    }
};

node *buildtreee(node *&root){

    cout<<"Enter the data : "<<endl;

    int data;
    cin>>data;

    root = new node(data);
    
    if(data == -1 ) return NULL;

    cout<<"Enter the data to be inserted in the left of : "<<data<<endl;
    root->left = buildtreee(root->left);

    cout<<"Enter the data to be inserted in the right of : "<<data<<endl;
    root->right = buildtreee(root->right);

    return root;


}

void inorder(node *root, int &cnt){

    if(root == NULL) return;

    inorder(root->left,cnt);

    if(root->left == NULL && root->right == NULL){
        cnt++;
    }

    inorder(root->right,cnt);

}
int noOfLeafNodes(node* root){

   int cnt = 0;
   inorder(root,cnt);

   return cnt;
}
int main(){

    node *root = NULL;

    buildtreee(root);
    int cnt = 0;
    cout<<noOfLeafNodes(root);

}