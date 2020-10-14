# Lecture 7.3: Suffix Arrays

[[back to pattern search]](./README.md)

## Algorithm

1. add a new symbol, sentinel symbol which is smaller than any other symbol in the alphabet (in this case `!`)

2. take all possible suffixes (from length 1 to length of whole string)

3. sort the suffixes lexographically

![](screenshot_2019-09-18_11-17-27_753886358.png)

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

### v2


suffice array construction is an active area of algorithmic research - best methods are O(n) overall, but take a lot of space.

What is the L[i] column?

- character which just precedes that suffix

![image1](screenshot_2019-09-18_11-17-27_753886358.png)

[Burrows-Wheeler transform](https://en.wikipedia.org/wiki/Burrows%E2%80%93Wheeler_transform)

![image2](screenshot_2019-09-18_18-22-56_199063098.png)

[Stanford Lecture Notes - on suffix arrays and Burrows-Wheeler Transform](https://web.stanford.edu/class/cs262/presentations/lecture5.pdf)



> everything we show is examinable, but to varying degrees - can't do everything within a given timeframe
>


## Indexing - Exercises

**Problem:**

An inverted index is an alphabetical list of all the words that appear, together with the line numbers at which they appear.
Write a program to generate this.

Assume at most 10,000 words in the input.
