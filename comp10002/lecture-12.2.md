# Lecture 12.2 - Mergesort etc...

## Mergesort

$O(n \log(n))$ - not bad

```c

merge(A[0 ... mid - 1], A[mid ... n-1])
    T[0 ... mid - 1] <- A[0...mid - 1] // copy out half of the array
    i, s1, s2 <- 0, 0, mid
    while s1 < mid and s2 < n
        if T[s1] < A[s2]
            A[i] <- T[s1]
            i, s1 <- i + 1, s1 + 1
        else
            A[i] <- A[s2]
            i, s2 <- i+1, s2 + 1
    A[i...s2 - 1] <- T[s1 ... mid - 1]
```

Mergesort takes O(n log (n)) time in the *worst case*.

But it needs a temp array T half the size of the original input - can be used in all recursive calls.

Complexity: exactly $n log_2(n) - n + 1$.

## Algorithms

Insertion sort - O(n^2) average and worst case, O(1) space - good if data is nearly sorted
Quicksort - O(nlogn) average, O(n^2) worst case, O(log n) space requirement (for recursion stack space?)
Merge sort - O(nlogn) worst case, O(n) space required - can be faster than quicksort on modern architectures
Heap sort - O(nlogn) worst case, O(1) space - requires more comparisons and is slower, but is algorithmically beautiful.

- don't want quicksort controlling important things??

## Heapsort

construct an imaginary tree out of the data
- left(i) = 2i+1
- right(i) = 2i+2
- parent(i) = (i-1)/2

has a property called the "heap" property.
every element is not less than either of its children

but... how to turn into a heap??

> Most parents have one child, then, thinking "I can do better than this", they have another one. Then they realise they were wrong all along and couldn't do better. Oops

> OHHHHH. The pleasure of getting an example right.

> Why bother with pseudo code when you have real code...

- build a heap from this array - **could be in the exam!!**

- average number of items below in a tree is 1
    - 1/2 have none
    - 1/4 have 2

- can't be O(1) if there are recursive calls?
    - but can use tail-call optimisation to fix that!!

- in practice, mergesort is a faster algorithm, but this is cool computer science stuff regardless

> You've gotta be excited by a tree that doesn't exist - only in your imagination.