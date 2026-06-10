// vertical level traversal

#include<iostream>
#include<map>
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

node* buildTree(node* root){

    int data;
    cin>>data;

    if(data == -1) return nullptr;

    root = new node(data);

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;

}

vector<int> verticalTraversal(node* root){

    map<int,map<int,vector<int> > > nodes; // hd, (level, list of nodes)
    queue<pair<node*, pair<int,int> > > q; // pair<int,int> is the hd, level 

    vector<int> ans;

    if(root == nullptr) return ans;

    q.push(make_pair(root, make_pair(0,0))); // at start the root is pushed and the hd, level is 0 

    while(!q.empty()){

        pair<node*, pair<int,int> > temp = q.front();
        q.pop();

        node* frontnode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        nodes[hd][level].push_back(frontnode->data); // storing everything in the map (hd, (level, vector<int> nodes) )

        if(frontnode->left){
            q.push(make_pair(frontnode->left, make_pair(hd - 1, level + 1))); // when we go left hd will negative and the level will increase for every child by 1 
        }

        if(frontnode->right){
            q.push(make_pair(frontnode->right, make_pair(hd+1, level+1))); // when we go right so hd will be +ve
        }

    }

    // map = (hd, (level, vector<int> nodes))

    for(auto itr : nodes){ // an whole map

        for(auto itr1 : itr.second){ // (level, vector<int>)

            for(auto itr2 : itr1.second){ // vector<int>
                ans.push_back(itr2);  // storing the result 
            } 
        }
    }

    return ans;
}

int main(){

    node* root = nullptr;
    root = buildTree(root);

    vector<int> res = verticalTraversal(root);
    cout<<endl;

    for(auto itr : res){
        cout<<itr<<" ";
    }

    return 0;
}