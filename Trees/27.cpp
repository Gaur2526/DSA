// minimum time to burn a tree

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

node* buildtree(node* root){

    int data;
    cin>>data;

    if(data == -1) return nullptr;

    root = new node(data);

    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;

}

node* createMapping(node* root,map<node*,node*> &nodeToParent,int target){

    node* targetNode = nullptr;

    queue<node*>q;
    q.push(root);

    nodeToParent[root] = nullptr;

    while(!q.empty()){

        node* front = q.front();
        q.pop();

        if(front->data == target){
            targetNode = front;
        }

        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        if(front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }

    }

    return targetNode;
}

int timeToBurn(node* targetNode, map<node*,node*> &nodeToParent){

    map<node*,bool> visited;
    queue<node*> q;

    q.push(targetNode);
    visited[targetNode] = true;

    int time = 0;

    while(!q.empty()){

        int size = q.size();
        bool flag = 0;

        for(int i=0;i<size;i++){
            // processing neighbouring nodes

            node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }

            if(front->right && !visited[front->right]){
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }

        if(flag == 1) time++;
    }

    return time;

}

int main(){

    node* root = nullptr;
    root = buildtree(root);

    int target;
    cin>>target;
    
    map<node*,node*> nodeToParent;
    node* targetNode = createMapping(root,nodeToParent,target);
    int ans = timeToBurn(targetNode,nodeToParent);

    cout<<"Time is : "<<ans<<endl;


}