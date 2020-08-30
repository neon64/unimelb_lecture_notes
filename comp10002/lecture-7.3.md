# Lecture 7.3

suffice array construction is an active area of algorithmic research - best methods are O(n) overall, but take a lot of space.

## Indexing - Exercises

**Problem:**

An inverted index is an alphabetical list of all the words that appear, together with the line numbers at which they appear.
Write a program to generate this.

Assume at most 10,000 words in the input.

## Suffix Array v2

What is the L[i] column?

- character which just precedes that suffix

![image1](screenshot_2019-09-18_11-17-27_753886358.png)

[Burrows-Wheeler transform](https://en.wikipedia.org/wiki/Burrows%E2%80%93Wheeler_transform)

![image2](screenshot_2019-09-18_18-22-56_199063098.png)

[suffix arrays and btw](https://web.stanford.edu/class/cs262/presentations/lecture5.pdf)

> everything we show is examinable, but to varying degrees - can't do everything within a given timeframe