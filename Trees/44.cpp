// BST from preorder

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

node* BSTFromPreOrder(vector<int> &pre,int mini,int max,int &index){

    if(index >= pre.size()){
        return nullptr;
    }

    if(pre[index] <= mini || pre[index] >= max){
        return nullptr;
    }

    node* root = new node(pre[index++]);

    root->left = BSTFromPreOrder(pre,mini,root->data,index);
    root->right = BSTFromPreOrder(pre,root->data,max,index);

    return root;

}
int main(){

    node* root = nullptr;

    vector<int> pre;
    int element;
    cin>>element;

    while(element != -1){
        pre.push_back(element);
        cin>>element;
    }

    int index = 0;

    root = BSTFromPreOrder(pre,INT_MIN,INT_MAX,index);
    

}