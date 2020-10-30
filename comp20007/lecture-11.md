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

<p align="center"><img src="svgs/21e9340ae410417e2c8925469803f84b.svg?invert_in_darkmode" align=middle width=267.2642379pt height=49.794650399999995pt/></p>

- Best-case: array is sorted in ascending order

<p align="center"><img src="svgs/2ebfa14bcc27837f0990b518612a59bb.svg?invert_in_darkmode" align=middle width=151.5352179pt height=47.35857885pt/></p>

- Average case
  
  - what is our main operation? The *swap*.
    
    - why? because we have 'inverted pairs' which are in reverse order
  - best case: 0 inverted pairs
  - worst case: <img src="svgs/22ef3b544ce63fa8392dbb8ecc178f09.svg?invert_in_darkmode" align=middle width=77.2680051pt height=24.65753399999998pt/> inverted pairs
    - that's larger than $n$ what

Another way of thinking about this: insertion sort is <img src="svgs/4188f88f244665d504ac835e801d1444.svg?invert_in_darkmode" align=middle width=64.08677549999999pt height=24.65753399999998pt/> where <img src="svgs/6c4adbc36120d62b98deef2a20d5d303.svg?invert_in_darkmode" align=middle width=8.55786029999999pt height=14.15524440000002pt/> is the number of inverted pairs

- best case:  <img src="svgs/7c904ed55b696694007e488b27a05dd9.svg?invert_in_darkmode" align=middle width=118.88099684999999pt height=24.65753399999998pt/>

- worst case: <img src="svgs/13f6c5a1bad1f5f5d20b60043bc0c158.svg?invert_in_darkmode" align=middle width=167.55656609999997pt height=33.20539859999999pt/>

- avg: would have somewhere between best and worst case
  
  - say half of the inverted pairs on average
  
  - <img src="svgs/bfbfe9f6cac9f64413387f9e688c03d0.svg?invert_in_darkmode" align=middle width=290.07840839999994pt height=33.20539859999999pt/>
  
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
- Best, average and worst case is all <img src="svgs/7f673488709d91c2cf326d97e5a437c3.svg?invert_in_darkmode" align=middle width=42.81220349999999pt height=26.76175259999998pt/> comparisons
- Is it input-sensitive? no - has same (bad) time complexity regardless of input
- However, has guaranteed maximum <img src="svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.64773519999999pt height=24.65753399999998pt/> swaps - so desirable in some cases.

**Conclusion:** not bad for small <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/>

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