# Lecture 5.2

## Typedefs

```c
typedef int data_t;

typedef struct {
    int a;
    int b;
} awesome;
```

Opaque type:

```c
typedef struct Point Point;

Point * point_new(int x, int y);
```

## Binary search

low through to high - 1

`cmp(a, b)` - where a and b are *pointers* to the data

-

### Binary search - Efficiency

$$
\begin{aligned}
T(n) &= 1 &\text{if } n <= 1 \\
T(n) &= 1 + T([n/2]) &\text{if } n > 1
\end{aligned}
$$

Can show that solution is $T(n) = 1 + log_2(n) \implies O(log(n))$

## Quicksort

- can we parallelize it??

$$
A[0..fe - 1] < p \\
A[fe..\text{next}-1] = p \\
A[fg..n - 1] > p
$$

To initialise, set $fe=0$, $\text{next}=fe, fg=n$

Then increment *next*.

If equal to p, just move $\text{next}$ on one.

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

