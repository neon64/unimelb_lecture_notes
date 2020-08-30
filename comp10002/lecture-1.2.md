# Lecture 1.2

> "there's more to programming than semicolons and square brackets and ... anger"

## Showed an example program - 4 versions, each runs faster than the previous

- 1st implementation: ?
- 2nd implementation: ?
- 3rd implementation: slight increase by switching sorting algorithm
- 4th implementation: parallelization??
    - 100 billion characters => can distribute over nodes and split work up, then combine back together again

## Problem

    Given: A sequence S of n symbols.
    Problem: Determine if there is any value in S that occurs
        more than n/2 times, and if so, what the value is.
    Target: Worst case linear time, constant additional space.

Hint: Boyer-Moore algorithm
