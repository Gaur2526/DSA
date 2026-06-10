// BST to Balanced BST

#include<iostream>
#include<vector>
#include<queue>
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

void inorder(node* root,vector<int> &arr){

    if(root == nullptr){
        return;
    }

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);

}

node* inorderToBST(int s,int e,vector<int> &arr){

    if(s > e){
        return nullptr;
    }

    int mid = s + (e - s)/2;
    node* newRoot = new node(arr[mid]);

    newRoot->left = inorderToBST(s,mid-1,arr);
    newRoot->right = inorderToBST(mid+1,e,arr);

    return newRoot;

}

void levelOrderTraversal(node* root){

    queue<node* > q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        if(temp == nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{

            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){

    node* root = nullptr;
    cout<<"Enter the data for the BST : ";
    inputForBST(root);

    vector<int> arr;
    inorder(root,arr);

    cout<<"Previous level order : "<<endl;
    levelOrderTraversal(root);


    root = inorderToBST(0,arr.size()-1,arr);

    cout<<endl;
    cout<<"New level order : "<<endl;
    levelOrderTraversal(root);



}