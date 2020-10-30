# Naive pattern searching

[[back to pattern search]](./README.md)

Algorithm:

```pseudocode

for each starting character in the text:
    for each character in the pattern:
        check if the pattern character matches up with the character in the text
```

The complexity is <img src="svgs/27bab83a05e94a7c15a396201e3dcd57.svg?invert_in_darkmode" align=middle width=50.080834649999986pt height=24.65753399999998pt/>.

Average case is O(n) (because usually rejected on the first char).

However, using a different algorithm, is linear time worst-case possible? Or even sub-linear? Hint: yes.
