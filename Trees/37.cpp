// Kth largest element in the BST

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

int KthLargest(node* root,int &cnt,int k){

    if(root == nullptr){
        return -1;
    }

    // right

    int right = KthLargest(root->right,cnt,k);
    if(right != -1){
        return right;
    }

    // node
    cnt++;
    if(cnt == k) return root->data;

    // left

    return KthLargest(root->left,cnt,k);

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

    cout<<"Enter the data for the BST : "<<endl;

    inputForBST(root);

    cout<<"Enter the kth value : ";
    int k;
    cin>>k;

    int cnt = 0;
    int ans = KthLargest(root,cnt,k);
    cout<<"Kth largest element is : "<<ans<<endl;

}