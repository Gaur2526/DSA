// insertion in trie

#include<iostream>
using namespace std;


// this class defines a single node/character 
class TrieNode{

    public:
        char ch;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char data){
            ch = data;
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
            isTerminal = false;
        }
};

// this class is the complete trie data structure 
class Trie{

    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0'); // adding null character to the root because root is not a real character 

    }
    void utilFunction(TrieNode* root, string word){

        // base case : when the string traversed fully 

        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // Assumption all the word is in CAPS

        int index = word[0] - 'A'; // this index is children[] array index, means in the whole trie we have 
        /*

           trie: 
           children[0] - 'A'
           childrent[1] - 'B'
           .
           .
           .children[25] - 'Z'

           so this index will tell you where the character comes for example in case of DUCK, D is the 0th char so 
           'D'- 'A'  = 3 so children[3] where we have to start insertion
        */
        TrieNode* child;

        // node is present 

        if(root->children[index] != nullptr){
            child = root->children[index];
        }
        else{
            // node is absent

            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        utilFunction(child,word.substr(1));

    }

    void insertWord(string word){

        utilFunction(root,word);
    }
};

int main(){

    Trie* t = new Trie();
    t->insertWord("AKASH");

    
}