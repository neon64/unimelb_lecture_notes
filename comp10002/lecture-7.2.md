# Lecture 7.2

## Boyer-Moore-Horspool pattern search

Start from RHS of pattern, work to the left.

Usually fewer comparisons than characters in the text!!

Need to precompute information

`"she#shells"`

array is the size of the alphabet of all symbols in pattern

L[a] = 10

L[#] = 10, 6

L[s] = 10, 9, 5

L[h] = 10, 8, 4

L[e] = 10, 7,

L[l] = 10, 2, 1

for she sells sea shells example, only 12 character comparisons were done!!

Algorithm to construct the shift array

```matlab

for v <- 0 to o - 1
    L[v] <- m
for i <- 0 to m - 2 // ignore the last one
    L[P[i]] = m - i - 1
```

Algorithm to search the string

```matlab
s, i <- 0, m - 1

while s <= n - 1
    if T[s + i] != P[i]
        s, i <- s + L[T[s + m - 1]], m - 1
    else if i = 0
        return s
    else
        i <- i - 1
return not_found
```

Worst case it is O(nm), not very interesting

On average very good, and experimentally it is very fast for large alphabets (ASCII) and shortish patterns (m is unter 10 or so)

-    averageness comes from the input data here... so sadly cannot enforce randomness by the algorithm

Howbout if T is fixed and large, and there are multiple patterns to check?

## Suffix arrays

1. add a new symbol, sentinel symbol which is smaller than any other symbol in the alphabet (in this case `!`)

2. take all possible suffixes (from length 1 to length of whole string)

3. sort the suffixes lexographically

![](/home/chris/GDrive/Uni/COMP10002 Foundations of Algorithms/screenshot_2019-09-18_11-17-27_753886358.png)

- binary search the suffix array!

what we actually care about is `S[i]` not `T[i...]`

need $log_2(n)$ steps to search for the pattern

- e.g.: n = billion, need only 30 steps

then need max $m$ string comparisons

## Finding repeated substrings

O(n log n) comparison sorting algorithm, but each string comparison takes as many as n steps

O(n^2 log(n)) overall - bad!!

then need a ternary quicksort...

- partition on one character, at depth $d$ in the strings, then do **three** recursive calls

#
