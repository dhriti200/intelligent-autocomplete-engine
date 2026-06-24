#include "Trie.h"
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

Trie::Trie()
{
    root = new TrieNode();
}

TrieNode* Trie::getRoot()
{
    return root;
}

void Trie::insert(string word, int freq)
{
    TrieNode* curr = root;

    for(char ch : word)
    {
        if(curr->children.find(ch) == curr->children.end())
        {
            curr->children[ch] = new TrieNode();
        }

        curr = curr->children[ch];
    }

    curr->isEnd = true;
    curr->frequency = freq;
}
bool Trie::search(string word)
{
    TrieNode* curr = root;

    for(char ch : word)
    {
        if(curr->children.find(ch) == curr->children.end())
        {
            return false;
        }

        curr = curr->children[ch];
    }

    return curr->isEnd;
}
TrieNode* Trie::findPrefixNode(string prefix)
{
    TrieNode* curr = root;

    for(char ch : prefix)
    {
        if(curr->children.find(ch) == curr->children.end())
        {
            return nullptr;
        }

        curr = curr->children[ch];
    }

    return curr;
}
void Trie::dfs(
    TrieNode* node,
    string currentWord,
    vector<pair<string,int>>& results
)
{
    if(node->isEnd)
    {
        results.push_back(
        {
            currentWord,
            node->frequency
        });
    }

    for(auto child : node->children)
    {
        dfs(
            child.second,
            currentWord + child.first,
            results
        );
    }
}
vector<pair<string,int>>
Trie::getWordsWithPrefix(string prefix)
{
    vector<pair<string,int>> results;

    TrieNode* prefixNode =
        findPrefixNode(prefix);

    if(prefixNode == nullptr)
    {
        return results;
    }

    dfs(
        prefixNode,
        prefix,
        results
    );

    return results;
}

vector<pair<string,int>>
Trie::getTopK(
    string prefix,
    int k
)
{
    vector<pair<string,int>> words =
        getWordsWithPrefix(prefix);

    priority_queue<
        pair<int,string>,
        vector<pair<int,string>>,
        greater<pair<int,string>>
    > minHeap;

    for(auto word : words)
    {
        minHeap.push(
        {
            word.second,
            word.first
        });

        if(minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    vector<pair<string,int>> result;

    while(!minHeap.empty())
    {
        result.push_back(
        {
            minHeap.top().second,
            minHeap.top().first
        });

        minHeap.pop();
    }

    reverse(
        result.begin(),
        result.end()
    );
    cout << "Matches Found: "
    << result.size()
    << endl;

    return result;

    
}
void Trie::incrementWordFrequency(string word)
{
    TrieNode* curr = root;

    for(char ch : word)
    {
        if(curr->children.find(ch) == curr->children.end())
        {
            return;
        }

        curr = curr->children[ch];
    }

    if(curr->isEnd)
    {
        curr->frequency++;
    }
}