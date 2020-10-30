# Lecture 17 - Counting Sort



- O(n) to put objects in "bowls"

- <p align="center"><img src="svgs/e6fbec341f615214f9034aa5620afa91.svg?invert_in_darkmode" align=middle width=265.7311305pt height=14.611878599999999pt/></p>

- trading memory for speed - need memory for each 'bucket'



- this allows us to get faster than the theoretical <img src="svgs/ff514eba41c59f90c20d895e80719763.svg?invert_in_darkmode" align=middle width=72.2268393pt height=24.65753399999998pt/> limit for comparison-based sorting algorithms





## Distribution Sorting



#### Simple Distribution Sort

e.g.: sorting 1 4 0 6 5 3 2

can put each element into a new array, with the position given by its value

- `0 1 2 3 4 5 6`



however, with the array: `10 41 02 64 53 39 27` - it isn't so great

will need a 65-element long array.

- also need to zero the array - <img src="svgs/1c8ca3cc214952a67b2f68bfaf0225aa.svg?invert_in_darkmode" align=middle width=34.85622029999999pt height=24.65753399999998pt/>

<p align="center"><img src="svgs/025707bd488fe0a7f03caaa8936d522b.svg?invert_in_darkmode" align=middle width=143.82822629999998pt height=16.438356pt/></p>

- in the above example, had <img src="svgs/ca0d99776494868e5b810c84fd0fea1d.svg?invert_in_darkmode" align=middle width=34.64622974999999pt height=24.65753399999998pt/> which was bad



### Counting Sort

- if we count the number of elements, can keep track of repeated elements



shift the counts one to the right

then accumulate

indices then tell you the starting positions


<p align="center"><img src="svgs/fff944e63ea6b946659f728233236b33.svg?invert_in_darkmode" align=middle width=200.4415182pt height=16.438356pt/></p>
=> <img src="svgs/272e3ab168729ac17efd78e4c03be40f.svg?invert_in_darkmode" align=middle width=35.43774299999999pt height=24.65753399999998pt/> if k < n



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
- Split into <img src="svgs/63bb9849783d01d91403bc9a5fea12a2.svg?invert_in_darkmode" align=middle width=9.075367949999992pt height=22.831056599999986pt/> buckets
- Sort each separately
- Concatenate results



if you have one bucket per key, then have counting sort.



- how to sort each of the buckets?
  - you can choose



- Stable? depends on auxsort
- Worst-case complexity (assuming k = <img src="svgs/272e3ab168729ac17efd78e4c03be40f.svg?invert_in_darkmode" align=middle width=35.43774299999999pt height=24.65753399999998pt/>)
  - worst case is the worst case of your choice of `auxsort`
  - to work well, need uniformly distributed keys so buckets are evenly full I guess
- average case: <img src="svgs/93056131625594d5f6f74eaa395de7f6.svg?invert_in_darkmode" align=middle width=103.18231769999998pt height=33.45973289999998pt/> 
  - ^ assumes insertion sort is auxsort?
  - Linear if <img src="svgs/b34411a36b637081654dfda02c52993e.svg?invert_in_darkmode" align=middle width=66.43073579999998pt height=24.65753399999998pt/>



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
- <img src="svgs/272e3ab168729ac17efd78e4c03be40f.svg?invert_in_darkmode" align=middle width=35.43774299999999pt height=24.65753399999998pt/> - per pass
- <img src="svgs/b922b3602b5d7476d7be10777821d75b.svg?invert_in_darkmode" align=middle width=100.13908904999998pt height=24.65753399999998pt/>



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



- in practice, good sorting algorithms can be very close to <img src="svgs/272e3ab168729ac17efd78e4c03be40f.svg?invert_in_darkmode" align=middle width=35.43774299999999pt height=24.65753399999998pt/> already (e.g.: Timsort)



- these routines can be very useful as part of a more complex algorithm
  - radix sort used to construct suffix arrays
  - controlled environment with guaranteed short key size
- 