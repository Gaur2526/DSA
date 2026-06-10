// deletion in tries

#include<iostream>
using namespace std;

class TrieNode{

    public:
        char ch;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char d){

            ch = d;
            for(int i=0;i<26;i++){
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

    bool utilSearch(TrieNode* root, string word){

        if(word.length() == 0){

            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != nullptr){
            child = root->children[index];
        }
        else{
            return false;
        }

        return utilSearch(child,word.substr(1));

    }

    bool search(string word){

        return utilSearch(root,word);
    }

    void utilDeleteWord(TrieNode* root, string word){

        // base case : when string ends 
        if(word.length() == 0){
                root->isTerminal = false;
                return;
        }

        // finding position of char in trie

        int index = word[0] - 'A';
        TrieNode* child;

        // char is present
        if(root->children[index] != nullptr){
            child = root->children[index];
        }
        else{
            return;
        }

        utilDeleteWord(child,word.substr(1));

    }

    void deleteWord(string word){

        utilDeleteWord(root,word);

    }
};

int main(){

    Trie* t = new Trie();
    t->insert("ARM");
    t->insert("ARE");
    t->insert("DO");
    t->insert("TIME");

    cout<<"Befor deletion : ";

    if(t->search("DO")){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }

    cout<<endl<<"After Deletion : ";

    t->deleteWord("DO");

     if(t->search("DO")){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }


}