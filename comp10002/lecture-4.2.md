# Lecture 4.2

## Aside - reading C type declarations

    go right when you can, go left when you must

e.g.:

```cpp
    long **foo[7];
```

1. foo is ... long
2. foo is an array of 7 ... long
3. foo is an array of 7 pointer to ... long
4. foo is an array of 7 pointer to pointer to long

```cpp
int (*arr)[8];
```

- pointer to an array of 8 integers

## Linear search with correctness

$$
\text{define}\; P = (0 \leq i \leq n) \text{ and } (x \notin A[0\dots i-1])
$$

"if there's coloured sprinkles on one side of the donut then you go arond and you get the coloured sprinkles again"

## Insertion sort

worst case O(n^2) ? - if it was sorted in reverse order

- technically triangular numbers if sorted in reverse order
- not quite triangular numbers if numbers are random

- still grows quadratically