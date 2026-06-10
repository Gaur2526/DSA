// minimum cost of ropes

#include<iostream>
#include<queue>
using namespace std;

int minCost(vector<int> arr){

    priority_queue<int, vector<int>, greater<int>> pq;

    // min heap creation

    for(int i=0;i<arr.size();i++){
        pq.push(arr[i]);
    }

    int totalCost = 0;

    while(pq.size() > 1){

        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int iterationCost = first + second;

        pq.push(iterationCost);

        totalCost = totalCost + iterationCost;

    }

    return totalCost;

}

int main(){

    vector<int> arr = {4,3,2,6};

    cout<<"Minimum cost is : "<<minCost(arr);
}