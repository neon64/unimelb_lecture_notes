# Lecture 9 - Divide and Conquer Algorithms

Structure of a divide-and-conquer algorithm:

1. divide into smaller instances
2. solve recursively
3. combine the smaller solutions to solve the original instance

**Examples:** mergesort, quicksort, binary search, tree traversal, closest pair

- tries to use recursion in the most efficient way

- divide and conquer is most efficient when smaller instances can be made of one equal size

## Binary Trees

Height - does *not* include the root. length of the *longest* simple path from root

*Depth* of a vertex <img src="svgs/a9a3a4a202d80326bda413b5562d5cd1.svg?invert_in_darkmode" align=middle width=13.242037049999992pt height=22.465723500000017pt/> - length of a path from root to vertex <img src="svgs/a9a3a4a202d80326bda413b5562d5cd1.svg?invert_in_darkmode" align=middle width=13.242037049999992pt height=22.465723500000017pt/>

Empty tree has a height `-1`

Single node has height `0`

- *external node* - has no child branches -  ☐     

- *internal node* - has at least one child branch

- *full* binary tree - each node has 0 or 2 children

- *complete* tree - each level filled L-R
  
  ![](/home/chris/drive/Uni/COMP20007 Design of Algorithms/screenshot_2020-04-23_11-16-21_260778349.png)

this *complete* tree is not *full*.

but some *complete* trees can be *full*

### Computing the height of a Binary Tree

```pseudocode
function Height(T):
    if T is empty then
        return -1
    else
        return max(Height(T_left), Height(T_right)) + 1
```

How often do we check that T is empty?

Claim: the number <img src="svgs/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode" align=middle width=9.39498779999999pt height=14.15524440000002pt/> of external nodes is always one greater than the number <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> of internal nodes.

**Proof:**

Observe that every node, except for the root, is one of two children of an internal node.

Total number of nodes is the number of internal nodes  + number of external nodes.

<p align="center"><img src="svgs/eed2aece09fd5e017d2b2473a7e7b0b1.svg?invert_in_darkmode" align=middle width=972.2161547999999pt height=12.785402849999999pt/></p>

the extra <img src="svgs/034d0a6be0424bffe9a6e7ac9236c0f5.svg?invert_in_darkmode" align=middle width=8.219209349999991pt height=21.18721440000001pt/> is the root node

### Binary Tree Traversal

*preorder* - visits root, then left, then right

*inorder* - left, root, right

*postorder* - left, right, root

*level-order* - visits the nodes, level by level, starting from the root

```pseudocode
function PreorderTraverse(T):
    if T is not empty then
        visit T_root
        PreorderTraverse(T_left)
        PreorderTraverse(T_right)
```

```pseudocode
function InorderTraverse(T):
    if T is not empty then
        InorderTraverse(T_left)
        visit T_root
        InorderTraverse(T_right)
```

```pseudocode
function PostorderTraverse(T):
    if T is not empty:
        PostorderTraverse(T_left)
        PostorderTraverse(T_right)
        visit T_root
```

### Preorder Traversal Using a Stack

- we aren't actually pushing values onto this stack, just pointers

```pseudocode
push(T)
while the stack is non-empty do
    T <- pop
    visit T_root

    // reverse order because stack pops in reverse order
    if T_right is non-empty then
        push(T_right)
    if T_left is non-empty then
        push(T_left)
```

### Level-Order Traversal Using a Queue

```pseudocode
inject(T)
while the queue is not empty do
    T <- eject
    visit T_root
    if T_let is not empty then
        inject(T_left)
    if T_right is non empty then
        inject(T_right)
```

## Closest-Pair Problem - Revisited

Bruteforce solution is <img src="svgs/7f673488709d91c2cf326d97e5a437c3.svg?invert_in_darkmode" align=middle width=42.81220349999999pt height=26.76175259999998pt/>, comparing the distances between each pair of points.

But we can do better - namely <img src="svgs/ad0a754aa242d1703a16f4e21e10e57c.svg?invert_in_darkmode" align=middle width=72.01684874999998pt height=24.65753399999998pt/> with a divide and conquer approach.

1. Sort points by <img src="svgs/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode" align=middle width=9.39498779999999pt height=14.15524440000002pt/>, store in an array `byX`.

2. Sort points by <img src="svgs/deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode" align=middle width=8.649225749999989pt height=14.15524440000002pt/>, store in an array `byY`

3. Divide and conquer the cartesian plane, by identify the median <img src="svgs/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode" align=middle width=9.39498779999999pt height=14.15524440000002pt/> value, and recursively process the set <img src="svgs/8afab50701598f23027b8c8a3eccf4ac.svg?invert_in_darkmode" align=middle width=19.571971649999988pt height=22.465723500000017pt/> of points with lower <img src="svgs/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode" align=middle width=9.39498779999999pt height=14.15524440000002pt/> values, as well as the set <img src="svgs/c3e6cf52571e957457d2e5c45ddf3543.svg?invert_in_darkmode" align=middle width=20.515464749999992pt height=22.465723500000017pt/> with higher <img src="svgs/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode" align=middle width=9.39498779999999pt height=14.15524440000002pt/> values.
   
   - gives two halves with equal number of points - optimisation of splitting range of $x$ values into two equal halves (which may not have a balanced number of elements)

4. Compute minimum distance on each half. <img src="svgs/647e3b3a7d45567de4a305636543cf5c.svg?invert_in_darkmode" align=middle width=17.57428694999999pt height=22.831056599999986pt/> and <img src="svgs/7aab4271f9fc347257575e6ca95c5287.svg?invert_in_darkmode" align=middle width=18.517780049999992pt height=22.831056599999986pt/>.

<p align="center"><img src="svgs/328caad9c2dbd26e102790cc2b969073.svg?invert_in_darkmode" align=middle width=115.6981287pt height=16.438356pt/></p>

Now note that <img src="svgs/2103f85b8b1477f430fc407cad462224.svg?invert_in_darkmode" align=middle width=8.55596444999999pt height=22.831056599999986pt/> may not be the global minimum. There could be a really close pair with points on either side of the "border".

But wait. We can find some strip extended by <img src="svgs/2103f85b8b1477f430fc407cad462224.svg?invert_in_darkmode" align=middle width=8.55596444999999pt height=22.831056599999986pt/> in either direction.

Then we only need to look for points in this band.

Specifically, only need to look for combos of one point in the LHS strip, another point in the RHS strip

![](screenshot_2020-04-23_12-54-02_913470216.png)

Pick out points from array `byY`,  filter by `x` coordinate, store in `S`.

For each point in S, consider just its "close" neighbours.

- Aren't we back to where we started? Isn't this <img src="svgs/3987120c67ed5a9162aa9841b531c3a9.svg?invert_in_darkmode" align=middle width=43.02219404999999pt height=26.76175259999998pt/> again?
- No, can prove we can find the smallest distance in the 'strip' in <img src="svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.64773519999999pt height=24.65753399999998pt/> time, as for every point in the strip, need to only check a constant number of points.

**"Can be proven that this while loop will execute at most 5 times for each <img src="svgs/77a3b857d53fb44e33b53e4c8b68351a.svg?invert_in_darkmode" align=middle width=5.663225699999989pt height=21.68300969999999pt/> value."**

- < 8 shown in lecture. 

```pseudocode
minsq <- d^2
copy all points of byY with |x-m| < d to array S
k <- |S|
for i <- 0 to k-2 do
    j <- i+1

    // if the distance in just y dir is greater,
    // then we cannot improve
    while j <= k - 1 and (S[j].y - S[i].y)^2 < minsq do
        // may not actually improve the overall distance
        // if the x coords are too far away from each other
        minsq <- min(
            minsq,
            (S[j].x - S[i].x)^2 + (S[j].y - S[i].y)^2
        )
        j <- j+1
```

Solving recurrence relation
<p align="center"><img src="svgs/001fc19b678f0ca4e7892fcaee11d21a.svg?invert_in_darkmode" align=middle width=171.39742619999998pt height=16.438356pt/></p>
gives <img src="svgs/ff514eba41c59f90c20d895e80719763.svg?invert_in_darkmode" align=middle width=72.2268393pt height=24.65753399999998pt/> time complexity.

- note: the <img src="svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.64773519999999pt height=24.65753399999998pt/> here is looking for closest pairs in the middle band ^^
- without this being <img src="svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.64773519999999pt height=24.65753399999998pt/>, the overall complexity would be e.g.: <img src="svgs/3987120c67ed5a9162aa9841b531c3a9.svg?invert_in_darkmode" align=middle width=43.02219404999999pt height=26.76175259999998pt/>
