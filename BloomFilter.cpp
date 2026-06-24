#include "BloomFilter.h"
#include <functional>

BloomFilter::BloomFilter(int s)
{
    size = s;

    bitArray.resize(size,false);
}
void BloomFilter::insert(string word)
{
    hash<string> h;

    int index =
        h(word) % size;

    bitArray[index] = true;
}
bool BloomFilter::possiblyContains(string word)
{
    hash<string> h;

    int index =
        h(word) % size;

    return bitArray[index];
}