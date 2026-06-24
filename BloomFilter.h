#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <vector>
#include <string>

using namespace std;

class BloomFilter
{
private:
    vector<bool> bitArray;

    int size;

public:
    BloomFilter(int s);

    void insert(string word);

    bool possiblyContains(string word);
};

#endif