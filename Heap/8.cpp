// kth largest element 

#include<iostream>
#include<queue>
using namespace std;

int kthLargest(vector<int> &arr,int k){

    priority_queue<int, vector<int>, greater<int>> pq;

    // pushing first k elements 

    for(int i=0;i<k;i++){

        pq.push(arr[i]);

    }

    // checking the rest k to size-1 elements 

    for(int i=k;i<arr.size();i++){

        if(pq.top() < arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }

    }

    return pq.top();

}

int main(){

    vector<int> arr = {7,10,4,3,20,15};
    
    cout<<"Enter the value of k : ";
    int k;
    cin>>k;
    
    cout<<"Kth largest element is : " <<kthLargest(arr,k);

}