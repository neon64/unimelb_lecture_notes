# Lecture 13 - Heapsort

## Priority queues

- *set* of elements where each one has a priority key
- two main operations:
  - `inject`
  - `eject`

Naive priority queue - just a plain array

- Creation - O(1)

- Finding min element, `eject` - O(n)

- Is this basically **selection sort**? Yes

- $\Theta(n^2)$ - not good

## Heap

a **balanced**, **complete**, **binary** tree

- **balanced** - difference in height between two subtrees is never > 1

- **complete** - all have two children except for last one
  
  - complete implies balanced

- **binary** - each leaf has 0-2 children

- **heap property:** parent's key is higher than children. thus the max element is at the root
  - this is a *max heap*
  - can also have a *min heap* where the parent's key is lower than the children

- `insert` - $O(\log n)$
  
  - insert at end
  - sift up

- `eject` - $O(\log n)$

- - swap with end
  - sift down

### Building a heap

- insert a single element: insert at the end, then swap with parent until the tree satisfies the *heap property* again
  
  - $O(\log n)$
  - *top down heap construction*

- can do better than $O(n \log n)$ to build a heap

  - called *bottom-up heap construction*
  - call `heapify` an existing tree
  - Algorithm: look at parents from R-L, bottom to top, **sift down** as needed
    - sifting down deeper nodes is cheaper - because you're close to the bottom
    - and on average, nodes in a complete binary tree are closer to the bottom than the top
    - this is why **sift down** is used instead of **sift up** (sift up)
  - complexity analysis (in lecture) shows heapify is $O(n)$, when using **sift down**



For a *max* heap

```pseudocode
function BottomUpHeapify(A[1..n]):
	for i <- floor(n/2) down to 1 do
		k <- i
		v <- A[k]
		heap <- False
		while not heap and 2k <= n do
			j <- 2k
			if j + 1 <= n and A[j] < A[j+1] then
				j <- j+ 1 # pick right child instead
                
            if v >= A[j] then
            	heap <- True
            else
            	A[k] <- A[j];
            	k <- j
                
       A[k] <- v
```

The downward-moving node is swapped with the *larger* of its children in a max-heap. (smaller child in a min-heap)

## Heap as a contiguous array

- balanced and complete are the required properties to do this.

- after half-way through the array, all elements are leaf nodes

$$
\text{after } 2^h - 1 \text{ where h is the height of the array}
$$

$$
\forall i \in \{ 0, 1, \dots , n\} A[i] \leq A\left[\frac{i}{2}\right]
$$

### Implementation

```pseudocode
function Heapsort(A[1...n])
    Heapify(A[1..n])
    for i <- n to 0 do
        Eject(A[1..i])
```

```pseudocode
function BottomUpHeapify(A[1..n]) // instead of 0 to n+1
    // for all the non-leaves
    for i <- [n/2] down to 1 do
        // k is the parent
        k <- i
        v <- A[k]
        heap <- False
        //                 here we reached a leaf node
        while not heap and 2 * k <= n do
            // j will become the highest value
            j <- 2*k
            if j < n then
                if A[j] < A[j+1] then j <- j + 1
            if v >= A[j] then heap <- True
            // move the child to the parent position, and maybe sift                    down further
            else A[k] <- A[j]; k <- j
        A[k] <- v
```

### Analysis

Assume $n = 2^{h+1}-1$ - heap is complete

for simplicity

counting the number of "down-sifts" - involves comparison to check which child is largest, then comparison between parent and largest child

![](/home/chris/drive/Uni/COMP20007 Design of Algorithms/screenshot_2020-05-05_21-06-28_752997975.png)

- $2^i$ nodes per level

- $2n - 2\log (n + 1) \implies O(n)$

- number of nodes increases with the level, but the number of down-sifts at decreases with the level
  
  - they balance each other out somewhat, so becomes linear

```pseudocode
function Eject(A[1..i])
    Swap(A[i], A[1])
    k <- 1
    v <- A[k]
    heap <- False
    while not heap and 2 * k <= i - 1 do
        j <- 2*k
        if j < i-1
            if A[j] < A[j+1] then j <- j+1
        // ...
        // ... same sift down as before
```

- **Transform-and-Conquer algorithm**

- In-place
  
  - yes! O(1) memory

- Stable
  
  - no. non-local swaps :(stab

- Worst case:

$$
\text{heapify:} \Theta(n) \\
\text{eject:} \Theta(\log n) \\
\Theta(n) + n \times \Theta(\log(n)) \in \Theta(n \log n)
$$

- Best case:

$$
\Theta(n) \text{ when } \text{eject is constant}
$$

(only happens if all the elements are the same)

### Heap Sort - Summary

- used in the Linux kernel
- guaranteed performance (e.g.: for security reasons)