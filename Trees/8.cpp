// optimised way : diameter of a tree

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

node *buildtree(node *root){

    int data;
    cin>>data;

    root = new node(data);

    if(data == -1) return nullptr;

    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;
}

pair<int,int> DiameterFast(node* root){

    if(root == nullptr){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> leftsubtree = DiameterFast(root->left);
    pair<int,int> rightsubtree = DiameterFast(root->right);
    
    int leftsubtreedia = leftsubtree.first;
    int rightsubtreedia = rightsubtree.first;
    int comboleftandright = leftsubtree.second + 1 + rightsubtree.second;

    pair<int,int> ans;
    ans.first = max(leftsubtreedia,max(rightsubtreedia,comboleftandright)); // max diameter
    ans.second = max(leftsubtree.second, rightsubtree.second) + 1; //height

    return ans;


}
int main(){

    node* root = nullptr;
    root = buildtree(root);

    cout<<endl<<"Diameter of the tree is : "<<DiameterFast(root).first<<endl;
    return 0;

}
