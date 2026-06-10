// kth largest sum subarray

#include<iostream>
using namespace std;

int kthLargest(vector<int> arr,int k){

    vector<int> res;

    for(int i=0;i<arr.size();i++){
        int sum = 0;

        for(int j=i;j<arr.size();j++){

            sum = sum + arr[j];
            res.push_back(sum);

        }
    }

    sort(res.begin(),res.end());

    return res[res.size() - k];

}

int main(){

    vector<int> arr = {1,2,3,4,5};

    cout<<"Enter the value of k : ";
    int k;
    cin>>k;

    cout<<"Kth largest sum is : "<<kthLargest(arr,k);
}