// Sum tree

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

node* buildtree(node* root){

    int data;
    cin>>data;

    if(data == -1) return nullptr;

    root = new node(data);

    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;
    
}

pair<bool,int> isSumTree(node* root){

    if(root == nullptr){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    // leaf node case
    if(root->left == nullptr && root->right == nullptr){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftsubtree = isSumTree(root->left);
    pair<bool,int> rightsubtree = isSumTree(root->right);

    bool isleftSumTree = leftsubtree.first;
    bool isrightSumTree = rightsubtree.first;
    
    bool nodevalue =  (root->data == (leftsubtree.second + rightsubtree.second));

    pair<bool,int> ans;

    if(isleftSumTree && isrightSumTree && nodevalue){
        ans.first = true;
        ans.second = root->data + leftsubtree.second + rightsubtree.second;
    }
    else{
        ans.second = false;
    }
    return ans;
}

int main(){

    node* root = nullptr;
    root = buildtree(root);


    if(isSumTree(root).first){
        cout<<"Sum Tree"<<endl;
    }
    else{
        cout<<"Not Sum Tree"<<endl;
    }

    return 0;
}