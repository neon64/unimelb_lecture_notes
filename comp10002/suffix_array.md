# Suffix Array Indexing

If the source $T$ is large, but fixed, and you want to test with a whole bunch of smaller patterns (i.e.: $m << n$)

Generate an array of suffixes

```
                           012345
For example for the string banana

6 $
5 a$
4 na$
3 ana$
2 nana$
1 anana$
0 banana$

6 $
5 a$
3 ana$
1 anana$
0 banana$
4 na$
2 nana$

then the suffix array will look like this:

i       0 1 2 3 4 5 6

A[i]    6 5 3 1 0 4 2

```

one can then perform a binary search from that suffix array...

e.g.: if we want to see if the pattern 'na' exists within our text.at

start at `i=3`... that suffix is `anana$`. That is too close to the start of the alphabet. So we choose `i=4` instead. Then we try `banana$`. That is also to close to the start. `i=5` then gives `na$` as required. We've found the pattern in the text.

$O(log(n))$ string comparisons
up to $m$ character comparisons per string comparison

Total compexity: $O(m \cdot log(n))$.

However - generating the suffix array requires a sort: $O(nlogn)$, each comparison requires as many as $n$ steps. Therefore $O(n^2 log(n))$ - not great at all!

## Ternary quicksort

- choose only 1 letter as a pivot, rather than the whole word..

- then we have the less than, equal to first letter, and greater than sides. hence *ternary* quicksort.

- then there is a parameter called `depth` - controls which letter of the word we are sorting at.