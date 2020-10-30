# Lecture 11 - Sorting Algorithms

Key Properties:

- **in place** if it doesn't require significant additional memory
- **stable** if it preserves the relative order of elements which have the same keys
- **input-insensitive** - if its running time is the same regardless of the type of input it is given.

## "Human sort" = insertion sort

for each element,

```pseudocode
function InsertionSort(A[0..n-1]):
    for i <- 1 to n - 1 do
        j <- i - 1
        # 'inserts' into the sorted list, swapping
        # to the left each time the list is out of order
        while j >= 0 and A[j+1] < A[j] do
            SWAP(A[j+1], A[j])
            j <- j - 1
```

- Decrease-And-Conquer

- The idea is recursive, but the implementation here is iterative

- In-place?
  
  - Yes (may need additional O(1) memory)
    - consider e.g.: the swap function, which needs an aux variable

- Stable? (preserves order of inputs)
  
  - Yes.
    - all these swaps happen in adjacent positions
      - not swapping when equal
    - e.g.: if the array is already sorted then no work is done inside the inner while loop

### Complexity:

- Worst-case: array is sorted but in reverse order

$$
\sum_{i=1}^{n-1} \sum_{j=0}^{i-1} 1 \\
= \sum_{i=1}^{n-1} i \\
= \frac{(n-1)n}{2} \in \Theta(n^2)
$$

- Best-case: array is sorted in ascending order

$$
\sum_{i=1}^{n-1} 1 = n- 1 \in \Theta(n)
$$

- Average case
  
  - what is our main operation? The *swap*.
    
    - why? because we have 'inverted pairs' which are in reverse order
  - best case: 0 inverted pairs
  - worst case: $n(n-1)/2$ inverted pairs
    - that's larger than $n$ what

Another way of thinking about this: insertion sort is $\Theta(n + v)$ where $v$ is the number of inverted pairs

- best case:  $v=0 \implies \Theta(n)$

- worst case: $\Theta(n + \frac{n(n-1)}{2}) = \Theta(n^2)$

- avg: would have somewhere between best and worst case
  
  - say half of the inverted pairs on average
  
  - $v = \frac{n(n-1)}{4} \implies \Theta(n  + \frac{n(n-1)}{4}) = \Theta(n^2)$
  
  - <u>also</u> quadratic complexity on average

### Insight

- real world data is already partially sorted in many cases
- this makes insertion sort a powerful sorting algorithm in practice, particularly for small arrays up to ~100 elements.

### A faster version:

```pseudocode
function InsertionSort(A[0..n-1]):
    for i <- 1 to n - 1 do
        # pre-compute this value
        v <- A[i]
        j <- i - 1
        while j >= 0 and v < A[j] do
            A[j+1] <- A[j]
            j <- j-1
        A[j+1]<-v
```

### Sentinels

A sentinel can avoid us from having to check `j>=0`

- Assume domain is bounded from below,
- Minimal element `min`
- Free cell to the left of A[0]

Insertion sort can be made faster using a min **sentinel** in that cell A[-1] and change the test to just

```
v < A[j]
```

`A[0]` is often left free deliberately.

## Selection sort

- In-place? Yes
- Not stable. (Swaps are not **local**)
- Best, average and worst case is all $\Theta(n^2)$ comparisons
- Is it input-sensitive? no - has same (bad) time complexity regardless of input
- However, has guaranteed maximum $O(n)$ swaps - so desirable in some cases.

**Conclusion:** not bad for small $n$

## Real-World Examples

### `qsort` in C

sorting algorithms can be combined to get the best of both worlds

- quicksort tends to be the fastest in practice, but not <u>stable</u>

### `Array.sort` in Javascript

- Mergesort in Firefox
- Chrome
  - numeric arrays -> std::qsort - some variation on quicksort (introsort)
  - cotiguous arrays -> stringified and sorted using mergesort, or last resort qsort
  - other types, uses either selection sort or an *AVL tree*
    - selection sort - max $n$ swaps

### Timsort in Python

hybrid stable algorithm, from merge sort and insertion sort