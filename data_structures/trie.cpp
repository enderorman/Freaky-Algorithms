/*
5. Trie
Description:
A Trie is a tree-like data structure used for storing strings or sequences, where each node represents a character.

Use Case:

Prefix search, auto-completion, spell checking, or problems involving word matching like word break problem.

*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Trie {
    unordered_map<char, Trie*> children;
    bool isEndOfWord;

public:
    Trie() : isEndOfWord(false) {}

    void insert(const string& word) {
        Trie* node = this;
        for (char c : word) {
            if (node->children.find(c) == node->children.end())
                node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    bool search(const string& word) {
        Trie* node = this;
        for (char c : word) {
            if (node->children.find(c) == node->children.end())
                return false;
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    bool startsWith(const string& prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end())
                return false;
            node = node->children[c];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    cout << "Search 'apple': " << trie.search("apple") << endl;  // Output: 1
    cout << "Search 'app': " << trie.search("app") << endl;  // Output: 1
    cout << "Starts with 'ap': " << trie.startsWith("ap") << endl;  // Output: 1
}
