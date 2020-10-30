# Lecture 17 - Counting Sort



- O(n) to put objects in "bowls"

- $$
  k \log k \text{ to sort the different 'colours'?}
  $$

- trading memory for speed - need memory for each 'bucket'



- this allows us to get faster than the theoretical $O(n \log n)$ limit for comparison-based sorting algorithms





## Distribution Sorting



#### Simple Distribution Sort

e.g.: sorting 1 4 0 6 5 3 2

can put each element into a new array, with the position given by its value

- `0 1 2 3 4 5 6`



however, with the array: `10 41 02 64 53 39 27` - it isn't so great

will need a 65-element long array.

- also need to zero the array - $O(k)$

$$
\Theta(n + k) \text{ worst case}
$$

- in the above example, had $\Theta(k)$ which was bad



### Counting Sort

- if we count the number of elements, can keep track of repeated elements



shift the counts one to the right

then accumulate

indices then tell you the starting positions


$$
\Theta(n) + \Theta(k) + \Theta(k) + \Theta(n)
$$
=> $\Theta(n)$ if k < n



```pseudocode
function CountingSort(A[0..n-1])
	for j <- 0 to k do
		C[j] <- 0
	for i <- 0 to n - 1 do
		C[A[i] + 1] <- C[A[i]+1]+1 # shift
	for j<-1 to k do
		C[j] = C[j] + C[j-1] # cumulate
    for i <- 0 to n-1 do
    	B[C[A[i]]] <- A[i]
    	C[A[i] <- C[A[i]] + 1
    return B[0..n-1]
```



Stable? yes, but depends how implemented

​	- this one is stable ^

In-place? No!



**only works for int keys, and works best when the key range is small**

### Bucket sort

- Generalisation
- Split into $k$ buckets
- Sort each separately
- Concatenate results



if you have one bucket per key, then have counting sort.



- how to sort each of the buckets?
  - you can choose



- Stable? depends on auxsort
- Worst-case complexity (assuming k = $\Theta(n)$)
  - worst case is the worst case of your choice of `auxsort`
  - to work well, need uniformly distributed keys so buckets are evenly full I guess
- average case: $\Theta(n + \frac{n^2}{k} + k)$ 
  - ^ assumes insertion sort is auxsort?
  - Linear if $k = \Theta(n)$



Compared to counting sort - can limit memory usage, but can be slower in the worst-case.

### Radix sort

- one of Daniel's favourite algorithms :)

- use binary representations of these numbers



- **DON'T** sort the buckets, instead just concatenate them again



- assumptions
  - maximum key length known in advance
  - keys can be sorted in **lexographical** order (e.g.: strings)
    - can also sort with ascii strings
  - sort from least to most significant digit
- $\Theta(n)$ - per pass
- $\Theta(n \times len(k))$



```pseudocode
function RadixSort(A[0..n-1], k)
	for j <- 0 to len(k) do
		A <- AuxSort(A, k[j])
```

- AuxSort is typically bucket sort
  - but can use any algorithm so long as it is stable



- radix can be faster than radix sort if keys are short.



## Summary

- make more assumptions
- counting, bucket sort - positive integer keys
- radix sort - max key length must be known



- in practice, good sorting algorithms can be very close to $\Theta(n)$ already (e.g.: Timsort)



- these routines can be very useful as part of a more complex algorithm
  - radix sort used to construct suffix arrays
  - controlled environment with guaranteed short key size
- 