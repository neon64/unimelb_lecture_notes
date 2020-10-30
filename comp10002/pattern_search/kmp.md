# Knuth-Morris-Pratt (KMP) pattern search

[[back to pattern search]](./README.md)

An algorithm named after Knuth, Morris, Pratt, invented it in 1974.

**Question:** under what conditions can you skip ahead the full length of the pattern when searching?

**Answer:** must move back until prefixes match...

## KMP algorithm description

- Let <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> be the length of the text (the haystack), and <img src="svgs/0e51a2dede42189d77627c4d742822c3.svg?invert_in_darkmode" align=middle width=14.433101099999991pt height=14.15524440000002pt/> be the length of the pattern (the needle)

- Construct a failure vector <img src="svgs/b8bc815b5e9d5177af01fd4d3d3c2f10.svg?invert_in_darkmode" align=middle width=12.85392569999999pt height=22.465723500000017pt/>, by defining <img src="svgs/3bbb91e6bcff27ff0e7b8533ec9d149a.svg?invert_in_darkmode" align=middle width=27.649596149999986pt height=24.65753399999998pt/> to be the maximum <img src="svgs/3654c63ccfc2e93429f9485199d2e970.svg?invert_in_darkmode" align=middle width=36.65622014999999pt height=22.831056599999986pt/> such that <img src="svgs/00499ad65bc387dfafec171022ccff1e.svg?invert_in_darkmode" align=middle width=61.181673299999986pt height=24.65753399999998pt/>
matches <img src="svgs/f5498d772aabbbf691460bb874232f0f.svg?invert_in_darkmode" align=middle width=64.28891699999998pt height=24.65753399999998pt/>, with <img src="svgs/fa626948f3c85f740bdca6a2158581a8.svg?invert_in_darkmode" align=middle width=30.205579799999988pt height=24.65753399999998pt/> set (forced) to be <img src="svgs/34783f45562ec306e4eeb27b87aae4c5.svg?invert_in_darkmode" align=middle width=8.219209349999991pt height=21.18721440000001pt/>.

- A more intuitive explanation involves the terms "proper prefix" and "proper suffix"
  - example: proper prefixes of `Snape` are `S`, `Sn`, `Sna`, `Snap` (note: `Snape` note included)
  - example: proper suffixes of `Hagrid` are `agrid`, `grid`, `rid`, `id`, `d`

  - We define each value of the lookup table to be equal to *"the length of the longest proper prefix that matches a proper suffix in the same subpattern"*.

```
P:  s h e # s h e l l s
I:  0 1 2 3 4 5 6 7 8 9
F: -1 0 0 0 0 1 2 3 0 0
```

- at each position, can shift right by <img src="svgs/99ff42b4f4a9dc05c41f676ecf024f4a.svg?invert_in_darkmode" align=middle width=53.40401384999999pt height=24.65753399999998pt/> where <img src="svgs/3bbb91e6bcff27ff0e7b8533ec9d149a.svg?invert_in_darkmode" align=middle width=27.649596149999986pt height=24.65753399999998pt/> accounts for 'pattern self-overlap'.
  - if <img src="svgs/3bbb91e6bcff27ff0e7b8533ec9d149a.svg?invert_in_darkmode" align=middle width=27.649596149999986pt height=24.65753399999998pt/> is zero (quite common), then we resume from location <img src="svgs/70249cc97433521ff34391177d30a447.svg?invert_in_darkmode" align=middle width=33.459896249999986pt height=21.68300969999999pt/>, rather than <img src="svgs/f811eec8c2d05282f04277341ccbc6a8.svg?invert_in_darkmode" align=middle width=36.01587989999999pt height=21.18721440000001pt/> (with naive pattern search).
  - the example above, "she shells" is an outlier since there is so much repetiton

## Code examples

```c
void construct_failure_array(char *str, int n, int *F) {
    // start with s=2, c=0
    int pos = 2, cnd = 0;
    F[0] = -1;
    F[1] = 0;
    while (pos < n) {
        // if `str[s-1] == str[c] `, then we increment `c`, set `F[s] = c`, and then increment `s`.
        if (str[pos-1] == str[cnd]) {
            cnd += 1;
            F[pos] = cnd;
            pos += 1;
        // otherwise, if `c > 0`, then we take `c = F[c]` (decrementing it).
        } else if (cnd > 0) {
            cnd = F[cnd];
        // finally, if they aren't equal and `c == 0`, we set `F[s] = 0` and increment `s`.
        } else {
            F[pos] = 0;
            pos += 1;
        }
    }
}
```

Performing the search itself:

```matlab
s <- 0
i <- 0
while s <= n - m
    if T[s + i] = P[i]
        i <- i + 1
        if i = m
            return s
    else
        s <- s + i - F[i]
        i <- max(F[i], 0)
    return NOT_FOUND
```

### Analysis

- either <img src="svgs/77a3b857d53fb44e33b53e4c8b68351a.svg?invert_in_darkmode" align=middle width=5.663225699999989pt height=21.68300969999999pt/> goes up by one, <img src="svgs/6f9bad7347b91ceebebd3ad7e6f6f2d1.svg?invert_in_darkmode" align=middle width=7.7054801999999905pt height=14.15524440000002pt/> is unchanged
- <img src="svgs/6f9bad7347b91ceebebd3ad7e6f6f2d1.svg?invert_in_darkmode" align=middle width=7.7054801999999905pt height=14.15524440000002pt/> goes up by the same as <img src="svgs/77a3b857d53fb44e33b53e4c8b68351a.svg?invert_in_darkmode" align=middle width=5.663225699999989pt height=21.68300969999999pt/> decreases
- <img src="svgs/6f9bad7347b91ceebebd3ad7e6f6f2d1.svg?invert_in_darkmode" align=middle width=7.7054801999999905pt height=14.15524440000002pt/> goes up by 1 and <img src="svgs/77a3b857d53fb44e33b53e4c8b68351a.svg?invert_in_darkmode" align=middle width=5.663225699999989pt height=21.68300969999999pt/> remains 0

<img src="svgs/6f9bad7347b91ceebebd3ad7e6f6f2d1.svg?invert_in_darkmode" align=middle width=7.7054801999999905pt height=14.15524440000002pt/> will never go beyond <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/>, <img src="svgs/77a3b857d53fb44e33b53e4c8b68351a.svg?invert_in_darkmode" align=middle width=5.663225699999989pt height=21.68300969999999pt/> never go beyond <img src="svgs/0e51a2dede42189d77627c4d742822c3.svg?invert_in_darkmode" align=middle width=14.433101099999991pt height=14.15524440000002pt/>

worst case <img src="svgs/e7f9ccc1ad00f78901514c73554f534a.svg?invert_in_darkmode" align=middle width=175.75018559999998pt height=24.65753399999998pt/> so linear time.

The preprocessing phase does not dominate.

The difficult part is also to construct the failure vector F in linear time.


### KMP example from lecture

```

TEXT:
she shlls she shella by the she shells shore

PATTERN:
she shells

Construct an additional vector F in advance as follows:

P:  s h e   s h e l l s
F: -1 0 0 0 0 1 2 3 0 0

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