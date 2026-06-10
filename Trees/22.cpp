// K SUM PATH

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

node* buildtree(node* root){

    string data;
    cin>>data;

    if(data == "null") return nullptr;

    int val = stoi(data);

    root = new node(val);

    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;

}

void solve(node* root, vector<int> &path,int &pathcnt,int k){

    if(root == nullptr){
        return;
    }
    
    path.push_back(root->data);

    solve(root->left,path,pathcnt,k);
    solve(root->right,path,pathcnt,k);


    int sum = 0;
    for(int i=path.size()-1;i>=0;i--){

        sum = sum + path[i];

        if(sum == k) pathcnt++;
    }

    path.pop_back(); // when we return to the parent so the last root data should not be include 

}
int path(node*root,int k){

    vector<int> path;
    int pathcnt = 0;
    int sum = 0;

    solve(root,path,pathcnt,k);
    return pathcnt;

}
int main(){

    node* root = nullptr;
    root = buildtree(root);

    int k;
    cin>>k;

    int pathcnt = path(root,k);
    cout<<pathcnt<<endl;

}