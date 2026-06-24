# Intelligent Autocomplete Engine

## Overview

An efficient autocomplete system built in C++ using Trie-based prefix indexing. The engine supports real-time word suggestions from a dataset of over 386,000 English words and ranks results using frequency-based Top-K retrieval.

The project combines multiple data structures and algorithms including Tries, DFS traversal, Min Heaps, and Bloom Filters to provide fast and scalable autocomplete functionality.

---

## Features

* Trie-based word storage and retrieval
* Prefix search with efficient traversal
* Top-K autocomplete suggestions using Min Heap
* Bloom Filter for fast negative lookups
* Dynamic frequency updates based on user interactions
* Query latency benchmarking using C++ Chrono library
* Support for large datasets (386K+ English words)

---

## Tech Stack

* C++
* STL
* Trie Data Structure
* DFS
* Priority Queue (Min Heap)
* Bloom Filter
* Chrono Library

---

## Project Architecture

User Query
→ Bloom Filter Check
→ Trie Prefix Search
→ DFS Traversal
→ Top-K Ranking (Min Heap)
→ Suggestions

---

## Dataset

The project uses a large English dictionary dataset containing approximately 386,000 words.

Each word is stored in the Trie and assigned a frequency score used for ranking autocomplete suggestions.

---

## Core Components

### Trie

Stores words character by character and enables efficient prefix-based lookup.

Operations:

* Insert Word
* Search Word
* Prefix Search

Time Complexity:

* Insert: O(L)
* Search: O(L)
* Prefix Lookup: O(P)

where:

* L = length of word
* P = length of prefix

---

### DFS Traversal

After locating a prefix node, DFS explores all descendant nodes to collect candidate words.

Example:

Prefix: "alg"

Suggestions:

* algorithm
* algebra
* algebraic

---

### Top-K Ranking

A Min Heap is used to maintain only the highest-frequency suggestions.

Benefits:

* Efficient ranking
* Reduced memory usage
* Fast retrieval of top suggestions

Time Complexity:

O(N log K)

where:

* N = matching words
* K = number of suggestions returned

---

### Bloom Filter

A Bloom Filter is used before Trie traversal to quickly reject impossible queries.

Benefits:

* Fast negative lookups
* Reduced unnecessary Trie traversals
* Improved overall performance

---

### Dynamic Frequency Updates

The engine learns from user selections.

When a user selects a suggestion, its frequency score increases, allowing more relevant suggestions to appear over time.

---

## Performance

Dataset Size:

* 386,000+ words

Observed Results:

* Specific prefixes: near-instant retrieval
* Broad prefixes (e.g., "a"): approximately 40–50 ms
* Thousands of matching words handled efficiently

---

## Sample Output

Search: alg

Suggestions:

algorithm 998

algebra 950

algebraic 920

Query Time: 1.2 ms

---

## Future Improvements

* Multiple hash functions for Bloom Filter
* Persistent frequency storage
* Web-based user interface
* Real-world search query dataset
* Personalized ranking system

---

## Learning Outcomes

This project strengthened understanding of:

* Trie Data Structures
* DFS Traversal
* Heap-Based Ranking
* Bloom Filters
* Time Complexity Analysis
* Performance Benchmarking
* Large Dataset Processing

---

## Author

Dhriti

B.Tech Computer Science (Data Science)

NSUT
