#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "BloomFilter.h"
#include "Trie.h"

using namespace std;

int main()
{
    BloomFilter bf(1000000);
    srand(time(0));
    Trie trie;
    ifstream file("dataset.txt");

    string word;
    while(file >> word){
        trie.insert(word,rand()%1000 + 1);
        bf.insert(word);
    }
    cout << "Dataset Loaded Successfully!" << endl;

    while(true){
        string prefix;
        cout<<"\nSearch: ";
        cin>>prefix;

        auto allWords= trie.getWordsWithPrefix(prefix);
        cout<<"Total Matches: "<<allWords.size()<<endl;

        if(!bf.possiblyContains(prefix)){
            cout<<"Defineltely Not Present\n";
            continue;
        }

        auto start= chrono:: high_resolution_clock::now();
        auto ans= trie.getTopK(prefix,5);
        auto stop= chrono::high_resolution_clock::now();

        auto duration= chrono::duration_cast<chrono::nanoseconds>(stop-start);

        cout<<"\nQuery Time"<<duration.count()/1000000.0<<" ms\n";;

        if(ans.empty()){
            cout<<"No suggestion found\n";
            continue;
        }
        for(auto x: ans){
            cout<<x.first<<" "<<x.second<<endl;
        }
        string selectedWord;

        cout << "\nSelect a word: ";
        cin >> selectedWord;

        trie.incrementWordFrequency(selectedWord);
    }

  
}