# Lecture 18 - String searching with Horspool

- longer shifts are possible if we know more about the pattern

- shifts the pattern until the last occurrence of the character

- Case 1: last char is not in the pattern
  
  - shift the whole pattern

- Case 2: last char does not match but is in the pattern
  
  - shift the pattern until the last occurence of the char 

- Case 3: last character matches but one of the <img src="svgs/aac03c299a5a829c1f94d55c54791cc4.svg?invert_in_darkmode" align=middle width=42.743500799999985pt height=21.18721440000001pt/> characters does not match and the last character is unique.
  
  - shift hte whole pattern

- Case 4: last character matches but one of the <img src="svgs/aac03c299a5a829c1f94d55c54791cc4.svg?invert_in_darkmode" align=middle width=42.743500799999985pt height=21.18721440000001pt/> characters does not match and the last character is not unique
  
  - shift the pattern until the last occurrence of the pattern

**Number of allowed shifts depends on the character type only**

map from characters to shifts

<img src="svgs/94a3a5eced33ba33ae571960d621b678.svg?invert_in_darkmode" align=middle width=58.519739849999986pt height=24.65753399999998pt/>

## Find shifts

- ignore the last char, last char's shift amount remains as len of pattern
  
  - why?
  
  - if last char doesn't match, then apply Case 1 or Case 2
    
    - e.g.: consider the pattern `SEESAW`
    
    - none previous chars match, can shift 6 along

Worst case - <img src="svgs/74ff9597b56d1e5ba834cc5569819dd1.svg?invert_in_darkmode" align=middle width=50.080834649999986pt height=24.65753399999998pt/>

    - but for random strings, its linear and faster in practice compared to a brute force version

```javascript
function FindShifts(P[0..m-1])
    for i <- 0 to a do
            Shift[i] <- m
       for j <- 0 to m-2 do
           Shift[P[j]] <- m - (j+1)
          
function Horspool(P[0..m-1], T[0..n-1])
    shift <- FindShifts(P)
    i <- m - 1
    while i < n do
        k <- 0
        while k < m and P[m - 1 - k] = T[i-k] do
            k <- k+1
        if k = m then
            return i - m + 1 % found match
        else
            i <- i + Shift[T[i]] % shift pattern along
    return -1
```

## Alternative string searching algorithms:

- Boyer-Moore: extends Hoorspool to allow shifts based upon <u>suffixes</u>
  
  - a bunch more cases which are covered - makes it faster in practice

- Knuth-Morris-Pratt: builds a <u>finite-state-automaton</u>
  
  - (in Models of Computation)

- Rabin-Karp - uses hash functions to filter negative matches
  
  - needs a<u> rolling hash function</u> to be efficient
    
    - so you don't need to recompute hashes from scratch?

- if you have a good hash function, then hashes won't be the same unless the pattern actually matches
  
  - becomes roughly ~O(n)

- extra memory to preprocess the pattern

- Horspool uses a dictionary of shifts

- Boyer-Moore is one of the most used algorithms - e.g.: in `grep` (also uses regular expressions)

trade memory for speed by storing intermediate solutions (dynamic programming)
