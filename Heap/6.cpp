// heap sort - max heap

#include<iostream>
using namespace std;

void heapify(vector<int> &arr,int size,int index){

    int largest = index;
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;

    if(leftIndex <= size && arr[largest] < arr[leftIndex]){
        largest = leftIndex;
    }

    if(rightIndex <= size && arr[largest] < arr[rightIndex]){
        largest = rightIndex;
    }

    if(largest != index){
        swap(arr[largest],arr[index]);
        heapify(arr,size,largest);
    }
}

void heapSort(vector<int> &arr){

    int size = arr.size()-1;

    while(size > 1){

        // step 1 : swapping first and last node & reducing the size
        swap(arr[1],arr[size]);
        size--;

        // step 2 : call heapify
        heapify(arr,size,1);
 
    }
}
int main(){

    vector<int> arr = {-1,54,53,55,52,50};
    int size = arr.size() - 1;

    for(int i = size/2;i>0;i--){
        heapify(arr,size,i);
    }
    
    // before heap sort the arr should be max heap

    heapSort(arr);

    cout<<"Printing heap after Sort : ";
    for(int i = 1;i<=size;i++){
        cout<<arr[i]<<" ";
    }

}