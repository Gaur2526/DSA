// merge 2 BST's

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

void inputForBST(node* &root){

    int data;
    cin>>data;

    while(data != -1){

        root = insertIntoBST(root,data);
        cin>>data;

    }

}

void inorder(node* root,vector<int>&arr){

    if(root == nullptr){
        return;
    }

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);

}

void mergeInorder(vector<int>&ans, vector<int> arr1, vector<int> arr2){

    int i = 0;
    int j = 0;

    while(i < arr1.size() && j < arr2.size()){

        if(arr1[i] < arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while(i < arr1.size()){
        ans.push_back(arr1[i]);
        i++;
    }

    while(j < arr2.size()){
        ans.push_back(arr2[j]);
        j++;
    }

}

node* inorderToBST(int s, int e, vector<int> &ans){

    if(s > e){
        return nullptr;
    }

    int mid = s + (e-s)/2;

    node* newRoot = new node(ans[mid]);

    newRoot->left = inorderToBST(s,mid-1,ans);
    newRoot->right = inorderToBST(mid+1,e,ans);

    return newRoot;

}

int main(){

    node* root1 = nullptr;
    node* root2 = nullptr;

    cout<<"Enter the data to be inserted for BST1 : "<<endl;
    inputForBST(root1);

    cout<<"Enter the data to be inserted for BST2 : "<<endl;
    inputForBST(root2);

    vector<int> BST1;
    vector<int> BST2;

    inorder(root1,BST1);
    inorder(root2,BST2);

    vector<int> mergedBST;

    mergeInorder(mergedBST,BST1,BST2);

    node* root = nullptr;

    root = inorderToBST(0,mergedBST.size()-1,mergedBST);

    vector<int> res;

    cout<<"Combined Inorder is : ";
    inorder(root,res);

    for(auto itr : res){
        cout<<itr<<" ";
    }

}