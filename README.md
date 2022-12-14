## Data structures and algorithms for C++

A simple library for data structures and algorithms, written in C++.

### Supported data structures
- ArrayList (dynamic Java-style list implementation)
- Queue (FIFO, with 2 pointer implementation for speed at expense of memory and O(1) dequeue)
- Stack
- IntHashSet
- HashPair (pair data structured used for the hash map)
- HashMap (any hashable data type for key), with retrievals at O(1) for best and average, O(n) for worst
- IntBits (simple bit manipulation for integers)

### Supported algorithms
Nothing yet

### Planned
- Erase window function for array list
- TreeNode, BST, Fenwick, Trie (list of words auto conversion), Radix Tree (list of sentences auto conversion), Graph w/ common algos

### Notes
- Implementation of member functions are in header files due to (1) generic types, and (2) issue with VSCode