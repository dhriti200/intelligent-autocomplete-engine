#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "BloomFilter.h"
#include "Trie.h"

using namespace std;

int main(int argc, char* argv[])
{
    BloomFilter bf(1000000);
    srand(time(0));
    Trie trie;

    ifstream file("dataset.txt");

    string word;
    while(file >> word){
        trie.insert(word, rand()%1000 + 1);
        bf.insert(word);
    }

    // Search query comes from command line
    string prefix = argv[1];

    if(!bf.possiblyContains(prefix)){
        cout << "NOT_FOUND";
        return 0;
    }

    auto start = chrono::high_resolution_clock::now();

    auto ans = trie.getTopK(prefix,5);

    auto stop = chrono::high_resolution_clock::now();

    auto duration =
    chrono::duration_cast<chrono::microseconds>(stop-start);

    cout << "TIME:" << duration.count() << endl;

    for(auto x : ans){
        cout << x.first << "|" << x.second << endl;
    }

    return 0;
}