// searching in trie

#include<iostream>
using namespace std;

class TrieNode{

    public:
        char ch;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char d){
            ch = d;
            for(int i =0;i<26;i++){
                children[i] = nullptr;
            }
            isTerminal = false;
        }
};

class Trie{

    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }

        void utilInsert(TrieNode* root, string word){

            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != nullptr){
                child = root->children[index];

            }
            else{

                child = new TrieNode(word[0]);
                root->children[index] = child;

            }

            utilInsert(child,word.substr(1));

        }

        void insert(string word){

            utilInsert(root,word);

        }

        bool utilSearch(TrieNode* root,string word){

            // base case
            if(word.length() == 0 ){
                return root->isTerminal; // if the current root is terminal so it returns true
            }

            int index = word[0] - 'A';
            TrieNode* child;

            // char is present at that index

            if(root->children[index] != nullptr){

                child = root->children[index];

            }
            else{
                // char is not present at that index
                return false;
            }

            return utilSearch(child,word.substr(1));

        }
        bool search(string word){

            return utilSearch(root,word);

        }

};

int main(){

    Trie* t = new Trie();
    t->insert("ARM");
    t->insert("DO");
    t->insert("TIME");

    if(t->search("TIM")){
        cout<<"Present";
    }
    else{
        cout<<"Not present";
    }

}