#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode*> children;

    bool isEnd;

    int frequency;

    TrieNode()
    {
        isEnd = false;
        frequency = 0;
    }
};

class Trie
{
private:
    TrieNode* root;

public:
    Trie();

    void insert(string word, int freq);

    bool search(string word);

    TrieNode* getRoot();

    TrieNode* findPrefixNode(string prefix);

    void dfs(
        TrieNode* node,
        string currentWord,
        vector<pair<string,int>>& results  
    );

    vector<pair<string,int>>
    getWordsWithPrefix(string prefix);
    vector<pair<string,int>>
    getTopK(
        string prefix,
        int k
    );

    void incrementWordFrequency(string word);
};

#endif