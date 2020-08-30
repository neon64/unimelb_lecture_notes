# Lecture 4.3

## Defining efficiency

$2n$ is the same as $15n + 27\sqrt{n} - elog(n)$ - we say that both are linear


To capture this idea we define sets of functions that are all asymptotically equivalent in terms of their eventual long term growth rate:

$$
    f(n) \in O(g(n))
$$

if and only if

$$
    \exists n_0, c > 0 : \forall n > n_0, f(n) \leq c \cdot g(n)
$$

This is a complex definition!

Other notes regarding time complexities:

- binary logs are our best friend: $n\log n$

- $n \log \log n$ - is that really useful?

- $n \log* n$ - iterated log

## Types of analysis

1. Best case: of academic interest only

> "if you rely on best-case analysis, you're a mug"

2. Average case:

   1. randomness required in input: high risk unless input guaranteed

   2. randmness enforced by algorithm, regardless of input

3. Worst case: bet your friend's life on it

## Premature optimisation

*premature optimisation* - when one looks at one tiny operation and tries to improve it, but the whole overall algorithm is crap.

thus, one should **avoid premature optimisation**.


## Time complexity of sorting algorithms.

Insertion sort is $O(n^2)$ - but not that bad for small $n$.

Quicksort is $O(n \log n)$ best and average case, but $O(n^2)$ worst case.


>  "there's probably someone in the room with an IQ of 237, but most definitely not me - too much alcohol in my brain"
>
> - Alistair

