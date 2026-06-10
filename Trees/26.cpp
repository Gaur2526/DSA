// tree from inorder and postorder

#include<iostream>
#include<map>
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

void createMapping(int in[],map<int,int> &nodeToIndex,int n){

    for(int i=0;i<n;i++){
        nodeToIndex[in[i]] = i;
    }
}

node* solve(int in[],int post[],int &postOrderIndex,int inorderStart,int inorderEnd,map<int,int> &nodeToIndex, int n){

    if(postOrderIndex < 0 || inorderStart > inorderEnd){
        return nullptr;
    }

    int lastElement = post[postOrderIndex--];
    node* rootNode = new node(lastElement);
    int positionInorder = nodeToIndex[lastElement];

    //right call
    rootNode->right = solve(in,post,postOrderIndex,positionInorder+1,inorderEnd,nodeToIndex,n);
    // left call
    rootNode->left = solve(in,post,postOrderIndex,inorderStart,positionInorder-1,nodeToIndex,n);

    return rootNode;

}

node* buildTree(int in[],int post[],map<int,int> &nodeToIndex,int n){

    int postOrderIndex = n-1;
    node* ans = solve(in,post,postOrderIndex,0,n-1,nodeToIndex,n);
    return ans;
}

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

    int in[] = {4,8,2,5,1,6,3,7};
    int post[] = {8,4,5,2,6,7,3,1};

    int n = 8;

    map<int,int> nodeToIndex;

    // mapping node with index
    createMapping(in,nodeToIndex,n);

    node* root = buildTree(in,post,nodeToIndex,n);

    levelordertraversal(root);

}