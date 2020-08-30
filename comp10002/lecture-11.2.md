# Lecture 11.2 -  problem-solving, algorithms and more

Some problem solving techniques:

1. Generate and test
2. Divide and conquer

## Subset sum problem

> Is there a subset of the following numbers that adds up to exactly 1,000?

```c
int subsetsum(int A[], int n, int k) {
    if(k == 0) {
        return 1;
    } else if(n==0) {
        return 0;
    } else {
        return subsetsum(A, n-1, k-A[n-1]) || subsetsum(A, n-1, k)
    }
}
```

- worst case - grows exponentially

- we haven't developed better algorithms to solve these problems, because they just have exponential complexity

- another one is solving all constraints for e.g.: exam timetabling


### Divide and conquer approach

Evaluate all subsets of the $n$ items, and if any oone of them adds to $k$, return "yes"

Either the last value `A[n-1]` is part of the sum, or it is not.

If it is, a subset sum on the first n-1 items in the arra must add to `k - A[n-1]`

Subset sum problem is an example of a very important class of related **hard** problems. Exponential time with size of input - therefore we call them *intractable*. They can be *verified* quickly though...

If any one of these problems can be solved in polynomial time, then they all can.

Important task - proving `P = NP`

*tractable* - easy to solve or deal with

## Monte Carlo methods

- use a pseudo-random number generator to allow modelling a physical system

- `srand`, then `rand`

## Spring simulation

- can set the timestep manually...

## A different way to do multiplication

```
  123
  654
-----
  492
 615
738
-----
80442
```

have done $O(n^2)$ single digit multiplications to multiply some big number...

1. split $x$ and $y$ into two halves of digits, $n/2$ digits each

   - $x = a \cdot 10^{n/2} + b$

   - $y = c \cdot 10^{n/2} + d$

Then we get

$$
(a \cdot 10^{n/2} + b)(c\cdot 10^{n/2} + d) \\
= ac\cdot10^n + bc\cdot10^{n/2} + ad\cdot10^{n/2} + bd \\
= ac\cdot10^n + 10^{n/2}(bc + ad) + bd
$$

if $n=6$, was doing 36 multiplications

here, $ac, bc, ad, bd$ each take 9 multiplications

$$
(a+b)(c+d) = ac +ad+ bc+bd \\
 =ac + (ad+ bc) +bd \\
 (ad +bc) = (a+b)(c+d) - ac -bd
$$

Then we get to reuse $ac$ and $bc$

```
ad+bc = (a+b)(c+d) - ac -bd
         n/2   n/2   ^ already had these values
```

How many multiplications are we doing?

$$
T(n) = 3T(n/2) + c_1n + c_2 \\
T(1) = 1
$$

Complexity is $O(n^{\log_2(3)}) = O(n^{1.58})$

