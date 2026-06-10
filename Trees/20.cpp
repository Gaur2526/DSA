// sum of nodes on the longest path from root to leaf

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

    int data;
    cin>>data;

    if(data == -1) return nullptr;

    root = new node(data);

    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;
}

void solve(node* root,int len,int sum,int &maxlen,int &maxSum){

    if(root == nullptr){

        // if there is an left or right child exist 

        if(len > maxlen){
            maxlen = len;
            maxSum = sum;
        }

        else if(len == maxlen){
            maxSum = max(maxSum,sum);
        }

        return;
    }

    sum = sum + root->data;

    solve(root->left,len+1,sum,maxlen,maxSum);
    solve(root->right,len+1,sum,maxlen,maxSum);

}

int maxSum(node* root){

    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = 0;

    solve(root,len,sum,maxLen,maxSum);

    return maxSum;
}
int main(){

    node* root = nullptr;
    root = buildtree(root);

    int ans = maxSum(root);
    cout<<ans<<" ";
}