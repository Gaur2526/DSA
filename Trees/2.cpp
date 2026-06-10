//l level order traversal

#include<iostream>
using namespace std;

class node{

    public:

    int data;
    node*left;
    node*right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;

    }
};

node *buildTree(node *root){

    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;

    root = new node(data);

    if(data == -1) return NULL;

    cout<<"Enter the data for the left of : "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for the right of : "<<data<<endl;
    root->right = buildTree(root->right);


    return root;
}

// level order traversal logic

void levelordertraversal(node *root){

    queue<node* > q;
    q.push(root);
    q.push(NULL); // seperator between the levels 

    while(!q.empty()){

        node *temp = q.front();
        q.pop();

        if(temp == NULL){
            // last level is completed 
            cout<<endl;

            if(!q.empty()){ // Queue still have nodes so we have to add the sperator for the next level
                q.push(NULL);
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

    node *root = NULL;
    root = buildTree(root);


    cout<<endl<<"Printing Tree : "<<endl;
    levelordertraversal(root);
}