# Lecture 6.3

Linear pattern search:

$$
O(nm)
$$


Average case is O(n) (because usually rejected on the first char) - is linear time worst case possible? Or even sub-linear?

## KMP pattern search

Can you always skip ahead the full pattern? No...

Must move back until prefixes match...

```
she#sells#sea#shells
```

Construct an additional vector `F` in advance.

```
P:  s h e # s h e l l s
F: -1 0 0 0 0 1 2 3 0 0
```

Note: usually the pattern will have each F[i] usually equal to zero => most of the time you're not moving backwards that much --> move very quickly through the pattern. The above example is an outlier since "she shells" has so much repetition.

No work has to be done for the text to be search though

With F created, doing the search is easy

```pseudocode
s, i <- 0, 0
while s <= n - m
    if T[s + i] = P[i]
        i <- i + 1
        if i = m
            return s
    else
        s <- s + i - F[i]
        i <-- max(F[i], 0)
    return not_found
```

This run O(n) since each iteration we progress through the text.

The difficult part is also to construct the failure vector F in linear time.

### History

Named after Knuth, Morris, Pratt, invented it in 1974.

### Analysis

- either $i$ goes up by one, $s$ is unchanged
- $s$ goes up by the same as $i$ decreases
- $s$ goes up by 1 and $i$ remains 0

s will never go beyond n, i never go beyond $m$

worst case 2n + 2m => O(n+m) => linear

The preprocessing phase does not dominate.

### KMP Example

```

text

she shlls she shella by the she shells shore
she shells

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


## Boyer-Moore-Horspool pattern search

Start from RHS, work to the left.

Fewer comparisons than characters in the text



Given the pattern `she shells`, we construct a shift vector

```

she shells

every char = length(pattern)

then walk through each char in the pattern (except for the last one),
S[char] = length - index_of_char_in_pattern - 1

e.g.: if there are multiple `s` values in the pattern,
then the last one (not including the final char in the pattern) will count,
the rest will just have their values overwritten)


Shift vector:
-------------
S[e] = 3
S[h] = 4
S[l] = 1
S[s] = 5
// every other char in the alphabet
S[*] = 10

she shlls she shella by the she shells shore
she shells
         |
         x

space doesn't match, shift by 10

she shlls she shella by the she shells shore
          she shells
                   |
                   x

a doesn't match, shift by 10

she shlls she shella by the she shells shore
                    she shells
                             |
                             x

h doesn't match, shift by 4

she shlls she shella by the she shells shore
                        she shells
                                 |
                                 x

h doesn't match, shift by 4

she shlls she shella by the she shells shore
                            she shells
                                     |
                                     ^
matches!
```
