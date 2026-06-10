// top view of a binary tree

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

        node(int data){
            this->data = data;
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

vector<int> topView(node* root){

    map<int,int> mp; // hd, root->data
    queue<pair<node*, int> > q; // node, hd

    vector<int> ans;

    if(root == nullptr) return ans;

    q.push(make_pair(root,0)); // hd  = 0 in starting

    while(!q.empty()){

        pair<node*, int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second;

        // if one value is present for hd then do nothing 
        if(mp.find(hd) == mp.end()){
            mp[hd] = frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
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


    vector<int> res = topView(root);

    cout<<endl;

    for(auto itr : res){
        cout<<itr<<" ";
    }

    return 0;
}