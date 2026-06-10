// heapify algorithm - min heap creation

#include<iostream>
using namespace std;

void heapify(int arr[],int n,int index){

    int smallest = index;
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;

    if(leftIndex <= n && arr[smallest] > arr[leftIndex]){
        smallest = leftIndex;
    }
    
    if(rightIndex <= n && arr[smallest] > arr[rightIndex]){
        smallest = rightIndex;
    }

    if(smallest != index){
        swap(arr[smallest], arr[index]);
        heapify(arr,n,smallest);
    }


}
int main(){

    int arr[6] = {-1,54,53,55,52,50};
    int size = 5;

    for(int i=size/2;i>0;i--){
        heapify(arr,size,i);
    }

    cout<<"Printing min heap : ";
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }

}