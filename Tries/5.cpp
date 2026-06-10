// longest common prefix - not optimised

#include<iostream>
using namespace std;

class TrieNode{

    public:
        char ch;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char d){
            ch = d;
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
            childCount = 0;
            isTerminal = false;
        }
};

class Trie{

    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');   
        }

        void utilInsert(TrieNode* root, string words){

            if(words.length() == 0){
                root->isTerminal = true;
                return;
            }

            int index = words[0] - 'a';
            TrieNode* child;

            // char is present
            if(root->children[index] != nullptr){
                child = root->children[index];
            }
            else{
                // when we insert a new node so increase the child count
                child = new TrieNode(words[0]);
                root->childCount++;
                root->children[index] = child;
                
            }

            utilInsert(child,words.substr(1));

        }
        void insert(string words){
            utilInsert(root,words);
        }

        void lcp(string str, string &ans){

            for(int i=0;i<str.length();i++){
                
                char ch = str[i];

                if(root->childCount == 1){
                    ans.push_back(ch);

                    // go to next 
                    int index = ch - 'a';
                    root = root->children[index];
                }
                else{
                    break;
                }

                if(root->isTerminal){
                    break;
                }
            }
        }
};


int main(){

    Trie* t = new Trie();

    vector<string> words = {"ninja","night","nil"};

    for(int i=0;i<words.size();i++){
        t->insert(words[i]);
    }

    string first = words[0];
    string ans = "";

    t->lcp (first,ans);


    cout<<"longest common prefix : "<<ans<<endl;

}