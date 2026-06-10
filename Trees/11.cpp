// identical trees

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

bool isIdentical(node* root1, node* root2){

    if(root1 == nullptr && root2 == nullptr){
        return true;
    }
    
    if(root1 != nullptr && root2 == nullptr){
        return false;
    }

    if(root1 == nullptr && root2 != nullptr){
        return false;
    }

    bool left = isIdentical(root1->left,root2->left);
    bool right = isIdentical(root1->right,root2->right);

    bool currvalue = (root1->data == root2->data);


    if(left && right && currvalue) return true;

    return false;

}
int main(){

    node* root1 = nullptr;
    node* root2 = nullptr;

    root1 = buildtree(root1);
    root2 = buildtree(root2);


    if(isIdentical(root1,root2)){
        cout<<"Identical"<<endl;
    }
    else{
        cout<<"Non Identical"<<endl;
    }
}