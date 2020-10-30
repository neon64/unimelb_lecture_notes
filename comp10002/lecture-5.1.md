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


**Question: can quicksort be paralellized?**

<p align="center"><img src="svgs/11d67ec1a0213426d98d77837bf2e8b8.svg?invert_in_darkmode" align=middle width=370.06076745pt height=16.438356pt/></p>

To initialise, set <img src="svgs/09ae8e973b4bcf1852db2eef4de02776.svg?invert_in_darkmode" align=middle width=47.60839049999999pt height=22.831056599999986pt/>, <img src="svgs/ff119a03c518da76dcb97a18937d7b69.svg?invert_in_darkmode" align=middle width=128.23427429999998pt height=22.831056599999986pt/>

Then increment *next*.

If equal to p, just move <img src="svgs/853d1098ca631915f4291d9c52190897.svg?invert_in_darkmode" align=middle width=31.506964499999988pt height=20.221802699999984pt/> on one.

If ? < p, then swap with value at fe, then increment fe by one, increase next

If ? > p, then swap with value at fg, then decrement fg by one, don't increase next

When next = fg - there are no more unknown elements

- next either increases, or fg decreases, therefore next will eventually meet with fg

### Creating randomness

- use

```c
rand() % n
```

- to always get the random case behaviour

## Algorithms compared

**insertion sort**

n values
n - 1 swaps max

- work done is area under graph - <img src="svgs/429bb63021b38b0934149fc7d0127491.svg?invert_in_darkmode" align=middle width=165.03877169999998pt height=26.76175259999998pt/>
  - "we get a bogey of n^2 behaviour"

**quicksort**

- n comparison to do partition

- if unlucky, biggest item is the pivot, one thing goes into right place, then must recurse into whole rest of list

        - or smallest at front

  - so end up with quadratic work - but *only* in the worst case

- if we pick pivot = A[n/2]

Normally - <img src="svgs/d00c344f0e1d3ce6ada4c1220d0a133c.svg?invert_in_darkmode" align=middle width=82.27261349999998pt height=24.65753399999998pt/>

Then

<p align="center"><img src="svgs/ee587ed613c78d5c178ea9dafdc91330.svg?invert_in_darkmode" align=middle width=262.184604pt height=49.315569599999996pt/></p>

scary mathematical stuff...

<p align="center"><img src="svgs/1d933e7429f15e029f82cf690307ce4b.svg?invert_in_darkmode" align=middle width=205.28824469999998pt height=16.438356pt/></p>


