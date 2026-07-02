#!/usr/bin/env bash

pip install -r requirements.txt

g++ main.cpp Trie.cpp BloomFilter.cpp -O2 -o main