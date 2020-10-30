# Lecture 16 - Introduction to Data Compression

- assumed things could fit in memory
- secondary memory (e.g.: hard drive)





Fixed-length encoding

e.g.: 8-bit ASCII for characters

Run-length encoding

- 0 => 0
- 1 => 1
- `x{0, 1}` => x zeroes or ones

BAGGED => BA2GED



Variable-length encoding

-some symbols occur more frequently than others

- is this same as ESD 2?



E = 1

A = 00

R = 010



- no code can be a prefix of another one

- codes can be stored in a dictionary



- using a reversed dictionary is not very efficient - lots of "misses" on keys



## Tries ("tries")



- only works when keys can be decomposed



![](C:\Users\ccham\Google Drive\Uni\COMP20007 Design of Algorithms\Capture 2.PNG)



## Huffman coding

**Goal: obtain the *optimum* coding for a given set symbols and frequencies**



1. treat each symbol as a leaf, build binary tree bottom-up

2. two nodes are fused if they have the smallest two frequencies

3. eventually achieve a *Huffman tree*

- exact same shape as the Trie above



Huffman is an example of the greedy method

- goal is optimisation, many solutions work but want to find the best one
- divide into local subproblems
- build a *global* solution through *local* and *irrevocable* solutions
  - (e.g.: cannot unfuse two nodes again)

Huffman does find the optimal solution. Dijkstra and Prim's are also greedy methods which find the optimal solution.

Not always the case.

## Practical uses

Most data has *redundancy*

Compression uses redundancy to reduce space

Tries don't have to be based on a binary tree - can use arbitrary symbols



- Huffman encoding provides the basis for many advanced compression techniques
- Lempel-Ziv compression (codes assigned to sequences of symbols) e.g. GIF, PNG, ZIP
- Sequential data, linear prediction e.g.: very similar to previous ones.
  - used in FLAC
- **Lossy compression:** JPEG, MP3, MPEG etc...
  - e.g.: MP3 uses frequencies you wouldn't already be able to hear

