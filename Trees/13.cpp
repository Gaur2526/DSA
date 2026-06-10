// Zig-Zag Traversal

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

node* buildTrees(node* root){

    int data;
    cin>>data;

    if (data == -1) return nullptr;

    root = new node(data);

    root->left = buildTrees(root->left);
    root->right = buildTrees(root->right);

    return root;

}

vector<int> zigZag(node* root){

    vector<int> result;

    if(root == nullptr) return result;

    queue<node* > q;

    q.push(root);

    bool lefttoright = true; // boolean for changing traversal direction

    while(!q.empty()){

        int size = q.size();

        vector<int> ans(size);

        // level wise traversal
        for(int i=0;i<size;i++){

            node* frontnode = q.front();
            q.pop();

            int index = lefttoright ? i : size - i - 1;
            ans[index] = frontnode->data;

            if(frontnode->left){
                q.push(frontnode->left);
            }

            if(frontnode->right){
                q.push(frontnode->right);
            }

        }

        //changing traversal direction after each level
        lefttoright = !lefttoright;
        for(auto itr: ans){
            result.push_back(itr);
        }
    }

    return result;
}

int main(){


    node* root = nullptr;
    root = buildTrees(root);

    vector<int> answer = zigZag(root);
    
    for(auto itr : answer){
        cout<<itr<<" ";
    }

}