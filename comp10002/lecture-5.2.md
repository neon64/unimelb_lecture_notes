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

