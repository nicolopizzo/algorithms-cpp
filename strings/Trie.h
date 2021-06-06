#ifndef TRIE_H
#define TRIE_H

#define ALPH 256

#include <vector>
#include <string>

using std::vector;
using std::string;

struct TrieNode {
    int nLinks;
    bool isWord;
    TrieNode** links;

    TrieNode() {
        isWord = false;
        nLinks = 0;
        links = new TrieNode*[ALPH];
    }
};

class Trie {
    TrieNode* root;

    public:
        Trie();

        void insert(string);
        string find(string);
        void remove(string);

        vector<string> findAll();

        vector<string> lcpStrings(string);

    private:
        void insert(TrieNode*&, string);
        string find(TrieNode*, string, string="");
        void findFrom(TrieNode*, vector<string>&, string="");

        vector<string> lcpStrings(TrieNode*, string, int=0);
};

#include "Trie.cpp"

#endif