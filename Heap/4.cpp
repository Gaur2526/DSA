// heapify algorithm - max heap

#include<iostream>
using namespace std;

void heapify(int arr[],int n,int index){

    int largest = index; // identifies the correct position of the element
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;

    if(leftChild <= n && arr[largest] < arr[leftChild]){
        largest = leftChild;
    }

    if(rightChild <= n && arr[largest] < arr[rightChild]){
        largest = rightChild;
    }

    if(largest != index){
        swap(arr[largest],arr[index]);
        heapify(arr,n,largest);
    }
    
    else{
        return;
    }

}

int main(){
    
    int arr[6] = {-1,54,53,55,52,50};

    int size = 5;

    for(int i=size/2;i>0;i--){
        heapify(arr,size,i);

    }

    cout<<"printing heap : ";
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }

}