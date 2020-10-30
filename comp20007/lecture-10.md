# Lecture 10 - Master Theorem

Consider an arbitrary divide-and-conquer algorithm which splits up work into $a$ subproblems of size $\frac{n}{b}$ , taking $f(n)$ operations to do the splitting/combining:

$$
T(n) = a\cdot T\left(\frac{n}{b}\right) + f(n)
$$

e.g.: a common case could be (dividing each problem into 2 equal subproblems, combine step takes $n$ operations)

$$
T(n) = 2T\left(\frac{n}{2}\right) + n
$$

Can we find the closed forms for these recurrence relations more quickly than solving them by hand?

## Master Theorem

Integer constants $a \geq 1$, $b > 1$. A function $f$ with $f(n) \in \Theta(n^d), d \geq 0$

then

$$
T(n) = aT(n/b)+f(n)
$$

has solutions, and

$$
T(n) = \begin{cases}
\Theta(n^d) & \text{if } a< b^d\\
\Theta(n^d logn) & \text{if } a = b^d \\
\Theta(n^{log_b a}) & \text{if } a > b^d
\end{cases}
$$

### Examples

$$
T(n) = 2T(n/2) + n\\
a = 2,b=2, d=1
$$

$$
\Theta(n \log n)
$$

$$
T(n) = 4T(n/4) + n \\
a = 4, b = 4, d = 1\\
\Theta(n \log n)
$$

$$
T(n) = T(n/2) + n\\
a = 1, b = 2, d = 1\\
1 < 2^1 \\
\Theta(n) \tag{the n dominates}
$$

$$
T(n) = T(n/2)+1 \\
a = 1, b = 2, d=0 \\
\Theta(n^0 \log(n)) \\
\Theta(\log(n)) \\
$$

Amount of work to subdivide is quadratic:

$$
T(n) = 2T(n/2) + n^2 \\
\Theta(n^2)
$$

## Recursion Tree

$$
T(n) = 2T(n/2) + n^2
$$

What is the height of the tree? $\log_2(n)$

Costs:

$$
n^2 + n^2/2 + n^2/4 + n^2/8 + \dots = \\
n^2 \cdot (1 + 1/2 + 1/4 + 1/8 + \dots)
$$

So $O(n^2)$

Also see - *general recursion tree* to develop an intuition for the master theorem

Each of the leaves of the tree is $\Theta(1)$.

We have $a^{log_b(n)} = n^{log_b(a)}$ instances, 

​    (NOTE: how to prove that, take $log_b()$ of both sides of the equation)

At leaf level - 

$$
\Theta(n^{log_b(a)}) + \sum_{j=0}^{log_b(n)-1} a^j\cdot\left(\frac{f}{b_j}\right)
$$

If $a=b^d$, $f \in \Theta(n^d)$.

$$
\Theta(n^{log_b(b^d)}) + \sum (b^d)^j (\frac{n}{b_j})^d \\
                + \sum n^d \\
                + n^d \sum_{j=0}^{log_b{n-1}} 1 \\
                \in n^d \log_b{n} \\
\in \Theta(n^d)  \;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;
$$

RH term dominates the LH term so $T(n) = n^d \log_b{n}$