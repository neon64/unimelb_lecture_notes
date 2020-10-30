# Lecture 4 - Complexity Analysis (12/03/2020)

### RAM Model of Computation

>  The RAM (Random Access Machine) model of computation measures the run time  of an algorithm by summing up the number of steps needed to execute the  algorithm on a set of data.
> 
> Basic logical or arithmetic operations (+, *, =, if, call) are considered to be simple operations that take one time step.
> All memory operations take exactly one time step.

### Counting "Basic Operations"

- take the most expensive operation, and only count occurrences of that operation
- what use in this subject

### Key ideas

Large input is what matters! Large input reveals the tyranny of a high growth rate.

When analyzing algorithms, it is important to:

- Ignore constant factors
- Ignore small input sizes

We tend to use the 'element of' notation:  $t(n) \in O(g(n))$ 

Some textbooks use $t(n) = O(g(n))$ - to show that it is an upperbound, not a tight upper bound.

It is correct to say $3n \in O(n^2)$, but incorrect to say $3n = O(n^2)$.

Can also use $\Omega(n^2)$ for *lower* bounds.

$\Theta(n^2)$ for *exact* order of growth - so it is bounded on both sides by some $c1$ and $c2$:

![](Screenshot from 2020-03-13 19-53-59.png)

## **Example with big-O notation:**

Show that $1+2+\dots+n \in O(n^2)$.

$$
\sum_{i=1}^{n} i = \frac{1}{2}(n+1)n \\
= \frac{1}{2}\cdot n^2 + \frac{1}{2}\cdot n \\
\leq n^2
$$

Choose $c=2$ or something and then you can prove by first-principles.

(we shouldn't really choose $c=1$ because initially the terms will be equal not less than, and our condition below requires a strict less-than. so to be safe - choose a higher value for $c$)

$$
n > n_0 \implies t(n) < c \cdot g(n)
$$

### Maths note: changing base of logarithm

$$
\log_b x = \frac{\log_a x}{\log_a b} \\
\log_2 x = \log_2 e \cdot \log_e x \\
\frac{d(\log_2 x)}{dx} = \log_2 e\cdot \frac{d(\log_e(x))}{dx} \\
= \log_2 e \cdot \frac{1}{x}
$$

### Another approach to establish growth rate

Can prove that $t(n) \in O(g(n))$ for some $t, g$ using the definition of $O$ directly

$$
n > n_0 \implies t(n) < c \cdot g(n)
$$

There's another approach to show growth rate:

$$
\lim_{n \to \infty} \frac{t(n)}{g(n)} = \begin{cases}
0 & \text{implies t grows asymptotically slower than g} \\
c & \text{implies t and g have the same order of growth} \\
\infty & \text{implies t grows asymptotically faster than $g$}
\end{cases}
$$

We can show that $\log_2 n$ grows slower than $\sqrt{n}$

$$
\lim_{n \to \infty} \frac{\log_2 n}{\sqrt{n}} = \lim_{n \to \infty} \frac{(\log_2 e)\frac{1}{n}}{\frac{1}{2\sqrt{n}}} = 2 \log_2 e \lim_{n \to \infty} \frac{1}{\sqrt{n}} = 0
$$

therefore grows slower

- consider using L'Hopital's Rule to evaluate the limit

### Example: time complexity of selection sort

#### Steps

1. go through list, find the smallest element, put it at the front

2. repeat until list is sorted

#### Time Complexity

$$
C(n) = \sum_{i=0}^{n-2} \sum_{j=i+1}^{n-1} 1 = \sum_{i=0}^{n-2} (n-1-i)
$$

then, split the sum into two parts:

$$
\sum_{i=0}^{n-2}(n-1) + \sum_{i=0}^{n-2} (-i) \\
\\
\\
(n-1)^2 - \sum_{i=0}^{n-2} i
$$

$$
= (n-1)^2 - (n-2)(n-1)/2 \\
= n(n-1)/2
\in \Theta(n^2)
$$

**Conclusion:** selection sort is $\Theta(n^2)$