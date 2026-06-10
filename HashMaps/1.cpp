// max frequency of an element 

#include<iostream>
#include<unordered_map>
using namespace std;

int maxCnt(vector<int> arr){

    unordered_map<int,int> mp;

    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }

    int maxCnt = INT_MIN;
    int element;

    for(auto itr : mp){
        
        if(itr.second > maxCnt){
            maxCnt = itr.second;
            element = itr.first;
        }
        
    }

    return element;

}

int main(){

    vector<int> arr = {2,12,2,11,-12,2,-1,2,2,11,12,2,-6};

    cout<<"max occuring element is : "<<maxCnt(arr);
    
}