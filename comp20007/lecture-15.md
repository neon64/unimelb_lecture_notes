# Lecture 15 - Hash Tables

Implementation of the *dictionary* abstract data structure.
$$
\Theta(1) \text{ insert, find, delete (average case)}
$$

- continuous data structure, $m$ preallocated entries

difficulties:

- need to preallocate a lot of memory
- hash collisions

## Hash function:

$$
h(K) \to i \in [0, m-1]
$$

- should be efficient ($\Theta(1)$)

- distributes keys evenly along the table

#### Identity hash function

- $h(K) = K$
- But need to know the maximum number of keys in advance, since $K \in [0, m-1]$
- e.g.: Australian postcodes, 0-9999
- however often fails
  - $m$ is too large
  - unbounded integers (student IDs)
  - non-integer keys

#### Hashing integers

- $h(K) = K \text { mod } m$
- can set the size $m$
- small $m$ - lots of collisions, large $m$ - too much memory

#### Hashing strings

- assume A -> 0, B -> 1
- Assume 26 characters and m=101
- Each character can be mapped to a binary string of length 5 (2^5 = 32)
- e.g.:
  - 13379736 mod 101 = 64
- $m$ deliberately chosen to be prime
- otherwise if $m$ is 32, then the hash value of any key is the last character's string (since each letter is 32 bits)

$$
h(S) = (\sum_{i=0}^{|s| - 1}  chr(s_i) \times 32^{|s| - i - 1}) \text { mod }m
$$

- will quickly result in overflow

**Horner's rule - factor out things and take mod**

- can use properties of modular arithmetic

## Separate Chaining

- each entry is a pointer to a linked list
- needs even more memory

**load factor: $\alpha = n/m$**

- even distribution of $n$ keys

- successful search requires 1 + $\alpha / 2$ operations on average
  
  - $1 + [0-1]/2 \approx 1$ - roughly O(1)
  - $\alpha = 2 \implies 2$

- successful search requires $\alpha$ operations on average

- similar numbers for Insert and Delete

- Worst case $\Theta(n)$ only with a really bad hash function (e.g.: map everything to first bucket) - load factor is a more practical consideration

## Linear Probing

- deletion is very complicated
  
  - most implementations leave some 'deleted' flag

- more widely used than separate chaining

- much harder analysis

- simplified results show:
  
  - successsful search $\frac{1}{2} \times (1 + \frac{1}{1-\alpha})$
    - only makes sense if $\alpha < 1$
  - unsuccesful search $\frac{1}{2} \times (1 + \frac{1}{(1-\alpha)^2})$

- deletion virtually impossibled

Worst case $\Theta(n)$ with a bad hash function and/or clusters

## Double hashing

- first try: $h(K)$

- second try: $h(K) + s(K) \mod m$

- third try: $h(K) + 2s(K) \mod m$
  
  - can see this is a generalisation of linear probing

- both linear probing and double hashing - open addressing methods

## Rehashing

high load factors deteriorate performance

- rehashing - insert all elements into a new one, approx double the size
- very expensive, but infrequent

## Hash Tables vs BSTs

Hash Tables ignore key ordering, unlike BSTs

e.g.: "give me all records with keys between 100 and 200" are easy in a BST

- well tuned hash table is typically better than a BST

## In practice

Python dictionaries

- open addressing using pseudo-random probing
  - secondary hash follows some random sequence
- Rehashing happens when $\alpha = \frac{2}{3}$

C++ `unordered_map`

- uses chaining
- rehashing when $\alpha = 1$