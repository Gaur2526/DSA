// Build tree from levelordertraversal

#include<iostream>
#include<queue>
using namespace std;

class node{

    public:

    int data;
    node *left;
    node *right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;

    }
};

void buildfromlevelorder(node *&root){

    queue<node* >q;
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    q.push(root);

    while(!q.empty()){

        node *temp = q.front();
        q.pop();

        cout<<"Enter data to be inserted in left of : "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);

        }

        cout<<"Enter the data to be inserted in the right of : "<<temp->data<<endl;

        int rightData;
        cin>>rightData;

        if(rightData != -1 ){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){

    node *root = NULL;

    buildfromlevelorder(root);

    return 0;
}