# Lecture 7.3: Suffix Arrays

[[back to pattern search]](./README.md)

Links:
- [Stanford Lecture Notes - on suffix arrays and Burrows-Wheeler Transform](https://web.stanford.edu/class/cs262/presentations/lecture5.pdf)

## Problem

What happens if $T$ is fixed and large ($m$ << $n$) and there are multiple independent patterns to be checked. Is there a way of precomputing an *index*?

## Meet suffix arrays

A *suffix array* $S[0...n-1]$ is an array of pointers S[i] such that $T_{S[i]}$ lexicographically precedes $T_{S[i+1]}$.

How to construct one?

1. add a new symbol, sentinel symbol which is smaller than any other symbol in the alphabet (in this case `!`)

2. take all possible suffixes (from length 1 to length of whole string)

3. sort the suffixes lexicographically (alphabetical order)

Ends up looking like this:

![](screenshot_2019-09-18_11-17-27_753886358.png)

To find an arbitrary pattern in this text, you can binary search the suffix array! Binary search, thus need $log_2(n)$ steps to search for the pattern. e.g.: if $n=1000000000$ (a billion), it will take only thirty steps. THen you need only maximum $m$ string comparisons.

Note: all we actually need to store is the numbers $S[i]$, not each substring $T[i...]$.

- Total time is $O(m \log n)$ per search. That's very fast.

## Suffix array construction

- simple approach: use a $O(n \log n)$ comparison-based sorting algorithm with each comparison requiring as many as $n$ steps, which is $O(n^2 \log n)$ average case and $O(n^3)$ worst case. Not good.

- With ternary quicksort:
  - partition on one character, at depth $d$ in the strings, then do **three** recursive calls
  - roughly improves the worst case from $O(n^3)$ to $O(n^2)$.

- Suffix array construction is an active area of algorithmic research - best methods are O(n) overall, but take a lot of space.

## More uses for suffix arrays:

- finding repeated substrings (find all locations in $S$ where repeated subsequences appear)

- key-word in context
  - can use an inverted index (an alphabetical listing of all word that appear, together with the line numbers at which they appear)