# Lecture 5 - Recursive Algorithms (17/03/2020)

>  I need you to look at me and look puzzled, or maybe look engaged, or be sleeeepy. That makes me tick.
> 
> - Lars Kulik 2k20

## Matrix Multiplication

Numer of multiplications for a matrix of size $n$ is

$$
\begin{aligned}
M(n) &= \sum_{i=0}^{n-1} \sum_{j=0}^{n-1} \sum_{k=0}^{n-1} 1 \\
 &= \sum_{i=0}^{n-1} \sum_{j=0}^{n-1} n \\
 &= n^3
\end{aligned}
$$

Why the three nested sums?

- for each cell in the output matrix we have to sum up a whole row / column worth of information.

## Recursive algorithms

```pseudocode
function F(n)
    if n = 0 then return 1
    else return F(n-1) * n
end
```

$$
M(0) = 0 \\
M(n) = M(n-1) + 1 \text{ for } n > 0
$$

Solving this recurrence relation using telescoping and backwards substitution.

$$
M(n) = M(n-1) + 1 \\
= M(n-2) + 1 + 1 \\
= M(n-3) + 3 \\
= M(n-k) + k \\
$$

When $n=k$, we get to case $M(0)$.

$$
M(k) = M(0) + k \\
M(n) = 0 + n \\
M(n) = n
$$

So its linear.

### Binary search

$$
C(0) = 0 \\
C(n) = C(n/2) + 1 \text { for } n>0
$$

In the base case, we're not doing any comparison - thus $0$ work.

A *smoothness* rule allows us to assume that $n$ is a power of 2.

- e.g. happily assume that $n=2^4$

$$
C(n/2) = C(n/4) + 1
$$

$$
\begin{aligned}
C(n) &= C(n/2) + 1 \\
 &= C(n/4) + 1 + 1 \\
 &= C(0) + 1 + 1 + \dots + 1 \\
 &= 1 + \log_2(n)
\end{aligned}
$$

$$
\begin{aligned}
C(2^k) &= C(2^{k-1}) + 1 \\
 &= C(2^{k-2}) + 1 + 1 \\
 &= C(2^{k-k}) + 1 + 1 + \dots + 1 \\
 &= C(0) + \log_2(2^k) \\
 &= C(0) + k \\
 &= 1 + \log_2(n) \\
\end{aligned}
$$

We can just write $\log$ for any logarithmic function - only changed by some constant factor.

$$
\log_2 n = O(\ln 2) \\
\ln n = O(\log_2 n) \\
\log n^c \in O(\log n)
$$

#### Reasoning with Big-Oh

- performing one operation after the other:

$$
O(f(n)) + O(g(n)) = O(max(f(n), g(n)) \\
$$

- constants can be thrown away:

$$
c \cdot O(f(n)) = O(f(n)) \\
$$

- this one is very useful for lots of nested loops:  (e.g.: matrix multiplication)

$$
O(f(n)) \cdot O(g(n)) = O(f(n) \cdot g(n))
$$

- Stirling's algorithm for simplifying factorials:

$$
n! = O(n^{n+\frac{1}{2}})
$$
