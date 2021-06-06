#include "Trie.h"

Trie::Trie() {
    root = nullptr;
}

void Trie::insert(string s) {
    insert(root, s);
}

void Trie::insert(TrieNode*& n, string s) {
    if (n == nullptr) {
        n = new TrieNode();
    }

    // If s is empty put a sentinel char
    if (s == "") {
        n->isWord = true;
        return;
    }

    // Else add the link if it doesn't exist, otherwise move to the next link
    char first = s[0];
    if (n->links[first] == nullptr) {
        n->nLinks++;
    }
    insert(n->links[first], s.substr(1));
}

vector<string> Trie::findAll() {
    vector<string> res;

    findFrom(root, res);


    return res;
}

void Trie::findFrom(TrieNode* n, vector<string>& v, string acc) {
    // Base case
    if (n == nullptr) {
        return;
    }

    // If a word is found, push it to the vector
    if (n->isWord) {
        v.push_back(acc);
    }

    // Check the active links and call recursively the function updating the accumulator
    for (int i = 0; i < ALPH; i++) {
        if(n->links[i] != nullptr) {
            char next = i;
            findFrom(n->links[i], v, acc+next);
        }
    }
}

vector<string> Trie::lcpStrings(string q) {
    return lcpStrings(root, q);   
}

vector<string> Trie::lcpStrings(TrieNode* n, string q, int l) {
    if (n == nullptr) {
        return {};
    }

    // If the query is consumed, find all the strings with q as prefix
    if (l == q.size()) {
        vector<string> v;
        findFrom(n, v, q);

        return v;
    }

    // Move into the tree
    char next = q[l];
    return lcpStrings(n->links[next], q, l+1);
}

string Trie::find(string s) {
    return find(root, s);
}

string Trie::find(TrieNode* n, string q, string acc) {
    // Query consumed, found the whole string
    if (q == "") {
        return acc;
    }

    // Traverse the tree
    char next = q[0];
    if(n->links[next])
        return find(n->links[next], q.substr(1), acc+next);

    // If the next link doesn't exist return the lcp
    return acc;
}