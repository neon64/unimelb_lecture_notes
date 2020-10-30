# Lecture 14 - Self-Balancing Trees

Dictionary - abstract data structure

- consists of (key, value) pairs

- `search(key)`
- `insert(key, value)`
- `delete(key)`



Variety of implementations:

- unsorted array: <img src="svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.64773519999999pt height=24.65753399999998pt/> search
- sorted array: <img src="svgs/0d4b7f5b66e994af32a32cfa26868d53.svg?invert_in_darkmode" align=middle width=59.62030469999999pt height=24.65753399999998pt/> search, <img src="svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.64773519999999pt height=24.65753399999998pt/> insert/delete
- binary tree: O(<img src="svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.47111549999999pt height=22.831056599999986pt/>) where <img src="svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.47111549999999pt height=22.831056599999986pt/> is the height of the tree
- self-balancing binary tree: <img src="svgs/0d4b7f5b66e994af32a32cfa26868d53.svg?invert_in_darkmode" align=middle width=59.62030469999999pt height=24.65753399999998pt/> for both

## Basic binary Search Tree

Average case, balanced (<img src="svgs/4627f764e98ec30111199b5851009dda.svg?invert_in_darkmode" align=middle width=75.27396524999997pt height=24.65753399999998pt/>)

- Search: <img src="svgs/8f3a45a2d0c8db44abd77c529aecb6f2.svg?invert_in_darkmode" align=middle width=59.41031249999999pt height=24.65753399999998pt/>
- Insert: <img src="svgs/d187b3dc55c8b993d53a3f72d67dcccc.svg?invert_in_darkmode" align=middle width=192.79303064999996pt height=24.65753399999998pt/>
  - search for element, and the insert in constant time
- Delete: <img src="svgs/5454d72e995a3ae05bee688f9c2f14e4.svg?invert_in_darkmode" align=middle width=218.41326704999994pt height=24.65753399999998pt/>
  - search for element + logn operations to rearrange the tree

Worst-case: highly unbalanced binary search tree - a **STICK**

- Search: <img src="svgs/272e3ab168729ac17efd78e4c03be40f.svg?invert_in_darkmode" align=middle width=35.43774299999999pt height=24.65753399999998pt/>, Insert: <img src="svgs/272e3ab168729ac17efd78e4c03be40f.svg?invert_in_darkmode" align=middle width=35.43774299999999pt height=24.65753399999998pt/>, Delete: <img src="svgs/272e3ab168729ac17efd78e4c03be40f.svg?invert_in_darkmode" align=middle width=35.43774299999999pt height=24.65753399999998pt/>

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
  - perform standard BST insert for node <img src="svgs/31fae8b8b78ebe01cbfbe2fe53832624.svg?invert_in_darkmode" align=middle width=12.210846449999991pt height=14.15524440000002pt/>,
  - starting from <img src="svgs/31fae8b8b78ebe01cbfbe2fe53832624.svg?invert_in_darkmode" align=middle width=12.210846449999991pt height=14.15524440000002pt/>, travel up and find the first unbalanced node (the *lowest* node with balance factor 2 or -2)
  - rebalance by performing appropriate rotations on the subtree rooted with <img src="svgs/f93ce33e511096ed626b4719d50f17d2.svg?invert_in_darkmode" align=middle width=8.367621899999993pt height=14.15524440000002pt/>, the first unbalanced node 
    - four possible cases.



- Deletion:
  - perform standard BST deletion for node <img src="svgs/31fae8b8b78ebe01cbfbe2fe53832624.svg?invert_in_darkmode" align=middle width=12.210846449999991pt height=14.15524440000002pt/>
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
  - two elements <img src="svgs/b4630e10519a8a056e78a90a3a0a281a.svg?invert_in_darkmode" align=middle width=31.605860549999992pt height=14.15524440000002pt/>
  - L: x < <img src="svgs/0e51a2dede42189d77627c4d742822c3.svg?invert_in_darkmode" align=middle width=14.433101099999991pt height=14.15524440000002pt/>
  - M: <img src="svgs/0e51a2dede42189d77627c4d742822c3.svg?invert_in_darkmode" align=middle width=14.433101099999991pt height=14.15524440000002pt/> < x < <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/>
  - R: x > <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/>

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



