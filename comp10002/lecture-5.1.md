# Lecture 5.1 - beginning sorting algorithms

## Quicksort

- choose a pivot

- take everything < pivot, put on LHS

- take everything > pivot, put on RHS

- sort each individual thing

- lends itself to a recursive implementation

```

define R = 

(fe, fg) <- partition(A, n, p)

quicksort(A[0...fe - 1])
quicksort(A[fg ...n-1])

assert: sorted
```

```cpp

if ((outcome = cmp(A + next, pivot)) < 0) {

}
```

- `cmp` returns
  - <0 if 1 is less than 2
  - 0 if 1 is equal to 2
  - > 0 if 2nd thing should become before 1st thing

if you have an aleady sorted array, then sometimes the chosen pivot will interfere

- when choosing the first element as pivot:
  
  - n root(n) - for an already sorted array
  - n^2 - reverse items
  - really fast for uniform items
  - n log(n) for random items

- when choosing (n/2) as pivot
  
  - super fast

## Algorithms compared

**insertion sort**

n values
n - 1 swaps max

- work done is area under graph - $n(n-1)/2 \implies O(n^2)$
  - "we get a bogey of n^2 behaviour"

**quicksort**

- n comparison to do partition

- if unlucky, biggest item is the pivot, one thing goes into right place, then must recurse into whole rest of list
  
        - or smallest at front
  
  - so end up with quadratic work - but *only* in the worst case

- if we pick pivot = A[n/2]

Normally - $O(n \log(n))$

Then

$$
T(n) = \begin{cases}
    1 & \text{if } n \leq 1\\
    n + \frac{2}{n}\sum_{i=0}^{n-1} T(i) & \text{if } n > 1
\end{cases}
$$

scary mathematical stuff...

$$
T(n) = 1.44n\log_2(n) + O(n)
$$


