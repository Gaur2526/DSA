// kth largest sum subarray using min heap

#include<iostream>
#include<queue>
using namespace std;

int kthLargest(vector<int> arr,int k){

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<arr.size();i++){
        int sum = 0;

        for(int j=i;j<arr.size();j++){

            sum = sum + arr[j];

            if(pq.size() < k){
                pq.push(sum);
            }
            else{

                if(pq.top() < sum){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }

    return pq.top();
}
int main(){

    vector<int> arr = {1,2,3,4,5};

    cout<<"Enter the value of K : ";
    int k;
    cin>>k;

    cout<<"Kth largest sum : "<<kthLargest(arr,k);
    
}