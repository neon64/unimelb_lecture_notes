# Lecture 1.1

## Tips

0. have friends in class
1. everything important is on the LMS
2. workshops start week 2
3. textbook
4. we are going to fit in a 500-seat lecture theatre (after first week)

## Quotes

>  "many of you will have the same relationship with your computer, because you didn't make friends when I asked you to"

> "Python is like an automatic car, C is like a manual car"

> "there's more to programming than semicolons and square brackets and ... anger"

## Showed an example program - 4 versions, each runs faster than the previous

- 1st implementation: ?
- 2nd implementation: ?
- 3rd implementation: slight increase by switching sorting algorithm
- 4th implementation: parallelization??
    - 100 billion characters => can distribute over nodes and split work up, then combine back together again

## Sneak-Peek Problem

    Given: A sequence S of n symbols.
    Problem: Determine if there is any value in S that occurs
        more than n/2 times, and if so, what the value is.
    Target: Worst case linear time, constant additional space.

Hint: Boyer-Moore Horspool algorithm
