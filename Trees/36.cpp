// Kth smallest element in a BST

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

node* insertIntoBST(node* root,int d){

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

int kth(node* root,int k,int &cnt){

    if(root == nullptr){
        return -1;
    }

    // left

    int left =  kth(root->left,k,cnt);
    if(left != -1){
        return left;
    }

    // node
    cnt++;
    if(cnt == k) return root->data;

    // right
    return kth(root->right,k,cnt);


}

void inputForBST(node* &root){

    int data;
    cin>>data;

    while(data != -1){

        root = insertIntoBST(root,data);
        cin>>data;
    }
}
int main(){

    node* root = nullptr;

    cout<<"Enter the data for the BST: "<<endl;
    inputForBST(root);

    cout<<"enter the kth value:"<<endl;
    int k;
    cin>>k;

    int cnt = 0;
    int ans = kth(root,k,cnt);
    cout<<"kth smallest : "<<ans<<endl;

}