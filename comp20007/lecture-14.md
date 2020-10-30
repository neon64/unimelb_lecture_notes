# Lecture 14 - Self-Balancing Trees

Dictionary - abstract data structure

- consists of (key, value) pairs

- `search(key)`
- `insert(key, value)`
- `delete(key)`



Variety of implementations:

- unsorted array: $O(n)$ search
- sorted array: $O(\log n)$ search, $O(n)$ insert/delete
- binary tree: O($h$) where $h$ is the height of the tree
- self-balancing binary tree: $O(\log n)$ for both

## Basic binary Search Tree

Average case, balanced ($h = \log(n)$)

- Search: $\Theta(\log n)$
- Insert: $\Theta(\log n) + \Theta(1) \in \Theta(\log n)$
  - search for element, and the insert in constant time
- Delete: $\Theta(\log n) + \Theta(\log n) \in \Theta(\log n)$
  - search for element + logn operations to rearrange the tree

Worst-case: highly unbalanced binary search tree - a **STICK**

- Search: $\Theta(n)$, Insert: $\Theta(n)$, Delete: $\Theta(n)$

  - everything decays, as if we used a linked-list

  

Two options to solve this:

 - Self-balancing trees
   	- <u>**AVL trees**</u>
    - Red-black trees
   - Splay trees

- Change the representation (nodes to have >1 element)
  - <u>**2-3 trees**</u>
  - 2-3-4 trees
  - B-trees



## Self-balancing trees - AVL trees

- Named after Adelson-Velsky and Landis
- A BST where each node has a *balance factor* - the difference in height between left and right subtrees

- If the balance factor becomes 2 or -2, *rotate* the tree to adjust them.



- Search is same as in BST

  

- Insertion:
  - perform standard BST insert for node $w$,
  - starting from $w$, travel up and find the first unbalanced node (the *lowest* node with balance factor 2 or -2)
  - rebalance by performing appropriate rotations on the subtree rooted with $z$, the first unbalanced node 
    - four possible cases.



- Deletion:
  - perform standard BST deletion for node $w$
  - potentially rebalance (same as for AVL tree insertion)





## Red-black Tree

- no red node has a red child
- every path from the root to the leaves has the same number of black nodes

- black is the root



- A worst-case red-black tree has the longest path is twice as long as the shortest path



## AVL vs Red-Black tree

- AVL more balanced, but requires more freq rotations
- Red-black trees: less balanced, but require fewer rotations.



## Changing the representation: 2-3 trees

Changed tree representation: now allowing multiple elements **and** multiple children.



- 2-nodes and 3-nodes



- 3-node: 2 elements, at most three children
  - two elements $m, n$
  - L: x < $m$
  - M: $m$ < x < $n$
  - R: x > $n$

- 



- insert into a 2-node => 3-node
- insert into a 3-node => reinsert?



B-trees is the extension of this



## 2-3-4 trees



## B-trees

- a generalisation



## B+ -trees

- nodes only contain keys, values are all in the leaves (plus a bunch of optimisations)

- connecting consecutive leaves with a linked-list





## Conclusion

- C++ maps are implemented via Red-black trees
- AVL-trees tend not to be used much
  - likely data is in memory because it will be modified a lot
  - so insertions are quite frequent

- Multiple elements per node is preferred when secondary memory is involved (e.g.: hard disk)
  - Widely used in SQL dbs
  - also filesystems (Ext4, Reiser4)
    - array of elements in each node is contiguous => faster access





- Python dicts - no they use hash maps, b.c.: faster



