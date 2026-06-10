// optimised - height balanced tree

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

pair<bool,int> isbalanced(node* root){

    if(root == nullptr){

        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> leftsubtree = isbalanced(root->left);
    pair<bool,int> rightsubtree = isbalanced(root->right);

    bool leftbalanced = leftsubtree.first;
    bool rightbalanced = rightsubtree.first;

    bool heightdiff = abs(leftsubtree.second - rightsubtree.second) <= 1;

    pair<bool,int> ans;

    ans.second = max(leftsubtree.second,rightsubtree.second) + 1;

    if(leftbalanced && rightbalanced && heightdiff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }

    return ans;

}
int main(){

    node* root = nullptr;
    root = buildtree(root);

    if(isbalanced(root).first){
        cout<<"height is balanced"<<endl;
    }
    else{
        cout<<"height is unbalanced"<<endl;
    }
}