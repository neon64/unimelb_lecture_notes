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

*Depth* of a vertex $V$ - length of a path from root to vertex $V$

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

Claim: the number $x$ of external nodes is always one greater than the number $n$ of internal nodes.

**Proof:**

Observe that every node, except for the root, is one of two children of an internal node.

Total number of nodes is the number of internal nodes  + number of external nodes.

$$
\text{Let }x \text{ be the number of external nodes} \\
\text{Let }n \text{ be the number of internal nodes} \\
\;\\
2n + 1 = x + n \\
2n + 1 + 1 - n = x + n + 1 - n \\
n + 2 = x + 1 \\
x = n + 1
$$

the extra $1$ is the root node

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

Bruteforce solution is $\Theta(n^2)$, comparing the distances between each pair of points.

But we can do better - namely $\Theta (n\log n)$ with a divide and conquer approach.

1. Sort points by $x$, store in an array `byX`.

2. Sort points by $y$, store in an array `byY`

3. Divide and conquer the cartesian plane, by identify the median $x$ value, and recursively process the set $P_L$ of points with lower $x$ values, as well as the set $P_R$ with higher $x$ values.
   
   - gives two halves with equal number of points - optimisation of splitting range of $x$ values into two equal halves (which may not have a balanced number of elements)

4. Compute minimum distance on each half. $d_L$ and $d_R$.

$$
d = \min(d_L, d_R)
$$

Now note that $d$ may not be the global minimum. There could be a really close pair with points on either side of the "border".

But wait. We can find some strip extended by $d$ in either direction.

Then we only need to look for points in this band.

Specifically, only need to look for combos of one point in the LHS strip, another point in the RHS strip

![](screenshot_2020-04-23_12-54-02_913470216.png)

Pick out points from array `byY`,  filter by `x` coordinate, store in `S`.

For each point in S, consider just its "close" neighbours.

- Aren't we back to where we started? Isn't this $O(n^2)$ again?
- No, can prove we can find the smallest distance in the 'strip' in $O(n)$ time, as for every point in the strip, need to only check a constant number of points.

**"Can be proven that this while loop will execute at most 5 times for each $i$ value."**

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
$$
T(n) = 2T(n/2) + O(n)
$$
gives $O(n \log n)$ time complexity.

- note: the $O(n)$ here is looking for closest pairs in the middle band ^^
- without this being $O(n)$, the overall complexity would be e.g.: $O(n^2)$
