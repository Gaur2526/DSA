// merge 2 max heaps

#include<iostream>
using namespace std;

vector<int> merge(vector<int> arr1, vector<int> arr2){

    vector<int> res;

    int i = 0;

    while(i < arr1.size()){
        res.push_back(arr1[i]);
        i++;
    }
    i = 0;

    while(i < arr2.size()){
        res.push_back(arr2[i]);
        i++;

    }

    return res;

}
void heapify(vector<int> &merged,int index){

    int largest = index;
    int leftIndex = 2 * index + 1; // 0 based indexing
    int rightIndex = 2 * index + 2;

    if(leftIndex < merged.size() && merged[largest] < merged[leftIndex]){
        largest = leftIndex;
    }

    if(rightIndex < merged.size() && merged[largest] < merged[rightIndex]){
        largest = rightIndex;
    }

    if(largest != index){
        swap(merged[largest],merged[index]);
        heapify(merged,largest);

    }
    else{
        return;
    }

}
int main(){

    vector<int> arr1 = {10,5,6,2};
    vector<int> arr2 = {12,7,9};

    vector<int> merged = merge(arr1,arr2);

    for(int i = (merged.size()-2)/2;i>=0;i--){
        heapify(merged,i);
    }

    cout<<"Printing after heapify : ";
    for(auto itr : merged){
        cout<<itr<<" ";
    }

}