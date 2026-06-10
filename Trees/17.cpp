// bottom view of binary tree

#include<iostream>
#include<map>
#include<queue>
#include<vector>

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

node* buildTree(node* root){

    int data;
    cin>>data;

    if(data == -1) return nullptr;

    root = new node(data);

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;

}

vector<int> bottomView(node* root){

    map<int,int> mp; // hd and node data;
    queue<pair<node*,int> > q; // node and hd;

    vector<int> ans;

    q.push(make_pair(root,0)); // in starting hd = 0;

    while(!q.empty()){

        pair<node*, int> temp = q.front();
        q.pop();

        node* frontnode = temp.first;
        int hd = temp.second;

        mp[hd] = frontnode->data;

        if(frontnode->left){
            q.push(make_pair(frontnode->left,hd-1));
        }

        if(frontnode->right){
            q.push(make_pair(frontnode->right,hd+1));
        }
    }

    for(auto itr : mp){
        ans.push_back(itr.second);
    }

    return ans;
}

int main(){

    node* root = nullptr;
    root = buildTree(root);

    vector<int> res = bottomView(root);

    for(auto itr : res){
        cout<<itr<<" ";
    }
}