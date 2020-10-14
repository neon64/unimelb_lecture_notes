# Lecture 6.3 : KMP pattern search

[[back to pattern search]](./README.md)

An algorithm named after Knuth, Morris, Pratt, invented it in 1974.

**Question:** under what conditions can you skip ahead the full length of the pattern when searching?

**Answer:** must move back until prefixes match...

## KMP algorithm description

- Let $n$ be the length of the text (the haystack), and $m$ be the length of the pattern (the needle)

- Construct a failure vector $F$, by defining $F[i]$ to be the maximum $k < i$ such that $P[0 . . . k − 1]$
matches $P[i − k . . . i − 1]$, with $F[0]$ set (forced) to be $−1$.

```
P:  s h e # s h e l l s
I:  0 1 2 3 4 5 6 7 8 9
F: -1 0 0 0 0 1 2 3 0 0
```

- at each position, can shift right by $i - F[i]$ where $F[i]$ accounts for 'pattern self-overlap'.
  - if $F[i]$ is zero (quite common), then we resume from location $s + i$, rather than $s + 1$ (with naive pattern search).
  - the example above, "she shells" is an outlier since there is so much repetiton

## How to construct the failure function $F$?

start with $s=2, c=0$.

If `str[s-1] == str[c] `, then we increment `c`, set `F[s] = c`, and then increment `s`.

Otherwise, if `c > 0`, then we take `c = F[c]` (decrementing it).

Finally, if they aren't equal and `c == 0`, we set `F[s] = 0` and increment `s`.

#### Alternative, equivalent version:

- We use the terms "proper prefix" and "proper suffix"
  - *Snape* proper prefixes: S, Sn, Sna, Snap (note: Snape note included)
  - *Hagrid* proper suffixes: agrid, grid, rid, i, d

Then, we define each value of the lookup table to be equal to *"the length of the longest proper prefix that matches a proper suffix in the same subpattern"*.

## How to perform the search itself?

```matlab
s <- 0
i <- 0
while s <= n - m
    if T[s + i] = P[i]
        i <- i + 1
        if i = m
            return s
    else
        s <- s + i - F[i]
        i <- max(F[i], 0)
    return not_found
```

### Analysis

- either $i$ goes up by one, $s$ is unchanged
- $s$ goes up by the same as $i$ decreases
- $s$ goes up by 1 and $i$ remains 0

$s$ will never go beyond $n$, $i$ never go beyond $m$

worst case $2n + 2m \implies O(n+m)$ so linear time.

The preprocessing phase does not dominate.

The difficult part is also to construct the failure vector F in linear time.


### KMP example from lecture

```

TEXT:
she shlls she shella by the she shells shore

PATTERN:
she shells

Construct an additional vector F in advance as follows:

P:  s h e   s h e l l s
F: -1 0 0 0 0 1 2 3 0 0

she shlls she shella by the she shells shore
she shells
      x
    i = 6, s = 0

    new i = 2
    s = 0+6-2 = 4

she shlls she shella by the she shells shore
    she shells
      x

she shlls she shella by the she shells shore
          she shells
    s = 10, i = 9

    goes to s = 10+9-0 = 19
            i = 0

she shlls she shella by the she shells shore
                   she shells

 s h e _ s h e l l s
-1 0 0 0 0 1 2 3 0 0



an even more extreme example:

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab
            aaaaaaaaaaaaaaaaaaaaab


```