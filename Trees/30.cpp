// creation of BST

#include<iostream>
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

node* insertIntoBST(node* root, int d){

    // base case
    if(root == nullptr){
        root = new node(d);
        return root;
    }

    if(d > root->data){

        root->right = insertIntoBST(root->right,d);
    }
    else{
        root->left = insertIntoBST(root->left,d);
    }

    return root;
}

void levelordertraversal(node* root){
    
    queue<node*> q;
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
void takeInputForBST(node* &root){

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
    takeInputForBST(root);

    levelordertraversal(root);

}