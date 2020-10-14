# Boyer-Moore-Horspool (BMH) pattern search

[[back to pattern search]](./README.md)

Code examples:

- [bmh.c](bmh.c) - my implementation of BMH pattern search

## Algorithm

1. construct a 'bad match table'

   - for each letter in the pattern:
     `value = length_of_pattern - last_index_in_pattern - 1`
   - every other letter: `value = length_of_pattern`

    - algorithm to construct the shift vector:
      ```matlab
      for v <- 0 to o - 1
          L[v] <- m
          for i <- 0 to m - 2 // ignore the last one
                L[P[i]] = m - i - 1
      ```

2. perform matching using this table
    - characters are compared starting from RHS, working to the left.

    - algorithm to search the string:
      ```matlab
      s <- 0
      i <- m - 1

      while s <= n - 1
          if T[s + i] != P[i]
              s <- s + L[T[s + m - 1]]
              i <- m - 1
          else if i = 0
              # this is where we found the pattern
              return s
          else
              i <- i - 1
      return NOT_FOUND
        ```



### Example from lecture

```

Given the pattern `she shells`
we construct a shift vector

every char = length(pattern)

then walk through each char in the pattern (except for the last one),
S[char] = length - index_of_char_in_pattern - 1

e.g.: if there are multiple `s` values in the pattern,
then the last one (not including the final char in the pattern) will count,
the rest will just have their values overwritten)


Shift vector:
-------------
S[e] = 3
S[h] = 4
S[l] = 1
S[s] = 5
// every other char in the alphabet
S[*] = 10

she shlls she shella by the she shells shore
she shells
         |
         x

space doesn't match, shift by 10

she shlls she shella by the she shells shore
          she shells
                   |
                   x

a doesn't match, shift by 10

she shlls she shella by the she shells shore
                    she shells
                             |
                             x

h doesn't match, shift by 4

she shlls she shella by the she shells shore
                        she shells
                                 |
                                 x

h doesn't match, shift by 4

she shlls she shella by the she shells shore
                            she shells
                                     |
                                     ^
matches!


`"she#shells"`

array is the size of the alphabet of all symbols in pattern

L[a] = 10
L[#] = 10, 6
L[s] = 10, 9, 5
L[h] = 10, 8, 4
L[e] = 10, 7,
L[l] = 10, 2, 1

for she sells sea shells example, only 12 character comparisons were done!!

```
