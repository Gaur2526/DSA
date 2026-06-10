// longest common prefix - O(N * length of smallest string)

#include<iostream>
using namespace std;

int smallestLength(vector<string> &words){

    string ans;
    int smallest = INT_MAX;

    for(int i=0;i<words.size();i++){
        string &temp = words[i];
        if(smallest > temp.length()){
            ans = temp;
            smallest = temp.length();
        }
    }

    return smallest;
}

string lcf(vector<string> &words,int length){

    string ans = "";

   for(int i=0;i<length;i++){
        char ch = words[0][i];
        bool match = false;

        for(int j=1;j<words.size();j++){

            if(ch == words[j][i]){
                match = true;
            }
            else{
                match = false;
                break;
            }
        }

        if(match){
            ans.push_back(ch);
        }
        else{
            break;
        }
   }

   return ans;
}
int main(){

    vector<string> words = {"coding","code","codezen","codingninja","coders"};

    int smallestLen = smallestLength(words);

    cout<<"Longest Common prefix : "<<lcf(words,smallestLen);
}