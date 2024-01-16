#include <iostream>
using namespace std;

class Node{
    public:
        char ch;
        bool lastCharacter;
        Node * childrens[26];

    Node(char ch){
        this->ch = ch;
        for(int i=0; i<26; i++) {
        this->childrens[i] = NULL;
        }
        this->lastCharacter = false;
    }
};

void createTrie(Node * root, string word){
    if(word.length() == 0){
        root->lastCharacter = true;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    Node * child;
    if(root->childrens[index] == NULL){
        child = new Node(ch);
        root->childrens[index] = child;
    }
    else{
        child = root->childrens[index];
    }
    createTrie(child, word.substr(1));
}


bool searchINTrie(Node * root,string word){
    if(word.length() == 0){
        return root->lastCharacter;
    }
    char ch = word[0];
    int index = ch - 'a';
    Node * child;
    if(root->childrens[index] != NULL){
        child = root->childrens[index];
    }
    else{
        return false;
    }
    bool ans = searchINTrie(child, word.substr(1));
    return ans;
}

void deleteInTrie(Node * root,string word){
    if(word.length() == 0){
        root->lastCharacter = false;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    Node * child;
    if(root->childrens[index] != NULL){
        child = root->childrens[index];
    }
    else{
        return;
    }

    deleteInTrie(child, word.substr(1));
}


int main(){
    Node * root = new Node('@');

    createTrie(root, "juli");
    createTrie(root, "saurabh");
    createTrie(root, "shabab");
    createTrie(root, "aliwajid");
    createTrie(root, "alishabab");
    createTrie(root, "gyan");
    createTrie(root, "shipra");
    cout << "Trie created" << endl;

    cout << searchINTrie(root, "aliwajid") << endl;
    
    deleteInTrie(root, "aliwajid");

    cout << searchINTrie(root, "aliwajid") << endl;

}   