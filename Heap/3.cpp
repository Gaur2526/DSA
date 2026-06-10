// deletion in heap

#include<iostream>
using namespace std;

class heap{

    public:
        int arr[100];
        int size;

        heap(){
            arr[0] = -1;
            size = 0;
        }

        void insert(int val){
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1){
                int parent = index/2;
                if(arr[parent] < arr[index]){
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }

        void deleteHeap(){

            if(size == 0){
                cout<<"nothing to delete"<<endl;
                return;
            }

            arr[1] = arr[size];
            size = size - 1; // deleting the last element by not making it accessible 

            int index = 1;
            
            while(index < size){

                int leftIndex = (2 * index);
                int rightIndex = (2 * index) + 1;
                int largest = index;

                if(leftIndex <= size && arr[largest] < arr[leftIndex]){
                    largest = leftIndex;
                }
                
                if(rightIndex <= size && arr[largest] < arr[rightIndex]){
                    largest = rightIndex;
                }

                if(largest != index){
                    swap(arr[largest],arr[index]);
                    index = largest;
                }

                else{
                    return;
                }
            }

        }

        void print(){

            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    cout<<"Before deletion : ";
    h.print();
    cout<<endl;
    h.deleteHeap();
    cout<<"After deletion : ";
    h.print();

}