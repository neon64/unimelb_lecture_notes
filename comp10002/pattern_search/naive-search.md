# Naive pattern searching

[[back to pattern search]](./README.md)

Algorithm:

```pseudocode

for each starting character in the text:
    for each character in the pattern:
        check if the pattern character matches up with the character in the text
```

The complexity is $O(nm)$.

Average case is O(n) (because usually rejected on the first char).

However, using a different algorithm, is linear time worst-case possible? Or even sub-linear? Hint: yes.
