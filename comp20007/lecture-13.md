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

- <img src="svgs/7f673488709d91c2cf326d97e5a437c3.svg?invert_in_darkmode" align=middle width=42.81220349999999pt height=26.76175259999998pt/> - not good

## Heap

a **balanced**, **complete**, **binary** tree

- **balanced** - difference in height between two subtrees is never > 1

- **complete** - all have two children except for last one
  
  - complete implies balanced

- **binary** - each leaf has 0-2 children

- **heap property:** parent's key is higher than children. thus the max element is at the root
  - this is a *max heap*
  - can also have a *min heap* where the parent's key is lower than the children

- `insert` - <img src="svgs/0d4b7f5b66e994af32a32cfa26868d53.svg?invert_in_darkmode" align=middle width=59.62030469999999pt height=24.65753399999998pt/>
  
  - insert at end
  - sift up

- `eject` - <img src="svgs/0d4b7f5b66e994af32a32cfa26868d53.svg?invert_in_darkmode" align=middle width=59.62030469999999pt height=24.65753399999998pt/>

- - swap with end
  - sift down

### Building a heap

- insert a single element: insert at the end, then swap with parent until the tree satisfies the *heap property* again
  
  - <img src="svgs/0d4b7f5b66e994af32a32cfa26868d53.svg?invert_in_darkmode" align=middle width=59.62030469999999pt height=24.65753399999998pt/>
  - *top down heap construction*

- can do better than <img src="svgs/ff514eba41c59f90c20d895e80719763.svg?invert_in_darkmode" align=middle width=72.2268393pt height=24.65753399999998pt/> to build a heap

  - called *bottom-up heap construction*
  - call `heapify` an existing tree
  - Algorithm: look at parents from R-L, bottom to top, **sift down** as needed
    - sifting down deeper nodes is cheaper - because you're close to the bottom
    - and on average, nodes in a complete binary tree are closer to the bottom than the top
    - this is why **sift down** is used instead of **sift up** (sift up)
  - complexity analysis (in lecture) shows heapify is <img src="svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.64773519999999pt height=24.65753399999998pt/>, when using **sift down**



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

<p align="center"><img src="svgs/4a7c60a8f9b4facdc604b634653b841f.svg?invert_in_darkmode" align=middle width=330.9386157pt height=17.9744895pt/></p>

<p align="center"><img src="svgs/8bdd57c19dfa003f75e454f319993f63.svg?invert_in_darkmode" align=middle width=215.09246714999998pt height=39.452455349999994pt/></p>

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

Assume <img src="svgs/f2b477c258b331bb4b63b32b99246a01.svg?invert_in_darkmode" align=middle width=93.47596829999998pt height=27.91243950000002pt/> - heap is complete

for simplicity

counting the number of "down-sifts" - involves comparison to check which child is largest, then comparison between parent and largest child

![](/home/chris/drive/Uni/COMP20007 Design of Algorithms/screenshot_2020-05-05_21-06-28_752997975.png)

- <img src="svgs/3a4a83447347e8eae50b856ef8a03468.svg?invert_in_darkmode" align=middle width=12.87010889999999pt height=27.15900329999998pt/> nodes per level

- <img src="svgs/389672488507122c83dc5dcf4598413e.svg?invert_in_darkmode" align=middle width=201.72807269999998pt height=24.65753399999998pt/>

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

<p align="center"><img src="svgs/1ef05969435710b033be239bb58b6559.svg?invert_in_darkmode" align=middle width=436.4199048pt height=16.438356pt/></p>

- Best case:

<p align="center"><img src="svgs/5a51abb807213967035618c0983031b7.svg?invert_in_darkmode" align=middle width=200.00430615pt height=16.438356pt/></p>

(only happens if all the elements are the same)

### Heap Sort - Summary

- used in the Linux kernel
- guaranteed performance (e.g.: for security reasons)