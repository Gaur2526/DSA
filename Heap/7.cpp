// kth smallest element 

#include<iostream>
#include<queue>
using namespace std;

int KthSmallest(vector<int> &arr,int k){

    priority_queue<int> maxHeap;

    // step 1 :

    for(int i=0;i<k;i++){
        maxHeap.push(arr[i]);
    }

    // step 2 :

    for(int i = k;i<arr.size();i++){

        if(arr[i] < maxHeap.top()){

            maxHeap.pop();
            maxHeap.push(arr[i]);
            
        }
    }

    return maxHeap.top();

}
int main(){

    vector<int> arr = {7,10,4,20,15};

    cout<<"Enter the value of K : ";
    int k;
    cin>>k;
    cout<<"kth smallest is : "<<KthSmallest(arr,k);

}