# Lecture 12 - Mergesort & Quicksort

## Mergesort

- core of mergesort - a function `merge` which merges two already-sorted arrays into one array

*divide and conquer technique*, not *decrease* and conquer

1. split array until base case of length 1
2. merge all arrays togeter
3. O(n) auxiliary space

```pseudocode
function MergeSort(A[0..n-1]):
    if n > 1 then
        // B and C use the same backing array 
        B[..floor(n/2) - 1] <- A[0..floor(n/2)-1]
        C[..floor(n/2)- 1] <- A[floor(n/2)..n-1]

        MergeSort(B[0..floor(n/2)-1])
        MergeSort(C[0..floor(n/2)-1])
        Merge(B, C, A)


function Merge(B[0..p-1, C[0..q-1], A[0..p+q-1]):
    i <- 0, j <- 0, k <- 0
    while i < p and j < q do
        // less than OR equal to - makes the algorithm stable
        if B[i] <= C[j] then
            A[k] <- B[i]; i<-j+1
        else
            A[k] <- C[j] j <- j + 1
    // copy remaining elements of the arrays
    if i == p then
        A[k..p+q-1] <- C[j..q-1]
    else
        A[k..p+q-1] <- B[i..p-1]
```

- in-place? No (requires O(n) auxiliary array + O(log n) stack space for recursion - can do it iteratively though)
- stable? Yes
  - keeps relative order with additional bookkeeping
    - e.g.: 34 and 45
    - need to do 4 from LHS before 4 from RHS

### Complexity analysis

<p align="center"><img src="svgs/0b495a3c53407999eb6d7d5a6c227b24.svg?invert_in_darkmode" align=middle width=222.33739604999997pt height=17.031940199999998pt/></p>

Worst case scenario for <img src="svgs/f95462510c49499c12c1dbfcf88d3ea1.svg?invert_in_darkmode" align=middle width=49.17092894999999pt height=22.465723500000017pt/> - have to go all the way to the end
<p align="center"><img src="svgs/278ace08a8ebc08177d5f9af6ee501c4.svg?invert_in_darkmode" align=middle width=110.08766669999999pt height=20.16618285pt/></p>

<p align="center"><img src="svgs/a47e644425cf92839569f26f7083db21.svg?invert_in_darkmode" align=middle width=175.99762125pt height=16.438356pt/></p>

Apply the master theorem:
<p align="center"><img src="svgs/334deb697d9cd7c86b6dae314294ef26.svg?invert_in_darkmode" align=middle width=178.22645114999997pt height=18.88772655pt/></p>

<p align="center"><img src="svgs/5d2f346fa6d2a00bb6ac318a9dbe69c9.svg?invert_in_darkmode" align=middle width=526.41524265pt height=18.88772655pt/></p>

Best case - <img src="svgs/cb2edb9db5d199474faee4468a61bc3b.svg?invert_in_darkmode" align=middle width=112.29200564999998pt height=27.91243950000002pt/>

- since need to go through and check <img src="svgs/f11950293b5756c0367d21fb42f57c99.svg?invert_in_darkmode" align=middle width=8.126022299999999pt height=22.853275500000024pt/> elements before copying the other half over

Complexity of mergesort = <img src="svgs/5bdc90ce16382c0f8496279da7f0d740.svg?invert_in_darkmode" align=middle width=72.01684874999998pt height=24.65753399999998pt/>

Highly parallelism

Multiway mergesort - excellent for secondary memory (hard drive or something)

- 2/3/4 way split

## Quicksort

- top-down approach whereas mergesort is bottom-up

```pseudocode
function Quicksort(A[l..r])
    if l < r
        # Partition returns the 'pivot'
        s <- Partition(A[l..r])

        Quicksort(A[l..s - 1])
        Quicksort(A[s + 1..r])
```

```pseudocode
function LumotoPartition(A[l..r])
    p <- A[l]
    s <- l
    for i <- l + 1 to r do
        if A[i] < p then
            s <- s + 1
            Swap(A[s], A[i])
    # moves pivot to the middle after everything else
    Swap(A[l], A[s])
    return s
```

- Note: ^ not a good partition function!

- In-place? Yes (but still requires O(logn) memory)

- Stable? No (non-local swaps)

```pseudocode
function HoarePartition(A[l..r])
    # two pointers, one L->R, one R->L
    p <- A[l]
    i <- l, j <- r + 1
    repeat
        repeat i <- i + 1 until A[i] >= p
        repeat j <- j - 1 until A[j] <= p

        # always swap before we check
        Swap(A[i], A[j])
    until i >= j

    # undo the last swap ^ from above
    Swap(A[i], A[j])

    Swap(A[l], A[j])
    return j
```

Why use Hoare partitioning in practice?

- uses 3 times fewer swaps on average, and creates efficient partitions when all values are equal
- but can still exhibit <img src="svgs/3987120c67ed5a9162aa9841b531c3a9.svg?invert_in_darkmode" align=middle width=43.02219404999999pt height=26.76175259999998pt/> behaviour
- 

### Complexity

- Worst case?
- Best case?
- Average case?
  - difficult to solve the recurrence relation

measuring - comparisons

**best-case scenario:**

- number of comparisons to partition a list of <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/>.
- at least <img src="svgs/efcf8d472ecdd2ea56d727b5746100e3.svg?invert_in_darkmode" align=middle width=38.17727759999999pt height=21.18721440000001pt/> to get to middle, plus <img src="svgs/96d974a75b6ae04b43f662af8779ed12.svg?invert_in_darkmode" align=middle width=36.52961069999999pt height=21.18721440000001pt/> for each of them
  - <img src="svgs/41fc4e4011d65a7426ca85be7eafeeab.svg?invert_in_darkmode" align=middle width=93.70615815pt height=24.65753399999998pt/>

<p align="center"><img src="svgs/e3950f26d87093105865890667218950.svg?invert_in_darkmode" align=middle width=323.08493085pt height=16.438356pt/></p>

- assumes the pivot split the array in half each time

**worst-case scenario:**

- pivot is the smallest element, one partition of size 0, one of size <img src="svgs/efcf8d472ecdd2ea56d727b5746100e3.svg?invert_in_darkmode" align=middle width=38.17727759999999pt height=21.18721440000001pt/>.

- new pivot is once again smallest element

- if the array is already sorted, but in reverse

- becomes *decrease* and conquer, not *divide* and conquer

<p align="center"><img src="svgs/5e04eabd73e69feb22820fbdd4913000.svg?invert_in_darkmode" align=middle width=663.0787581pt height=34.7253258pt/></p>

**average-case**
<p align="center"><img src="svgs/977bc6a7fa574639ca6c0a35e7f086a3.svg?invert_in_darkmode" align=middle width=447.89253134999996pt height=14.611878599999999pt/></p>

<p align="center"><img src="svgs/1bbe0727dc80972992f2254378bf8adf.svg?invert_in_darkmode" align=middle width=312.8590641pt height=17.031940199999998pt/></p>

if <img src="svgs/4236303dd0d91e3258b505402feb4280.svg?invert_in_darkmode" align=middle width=39.72173039999999pt height=22.853275500000024pt/> then you get best case, if <img src="svgs/ba312eaad422e9c3fdab5a5f592f1ebb.svg?invert_in_darkmode" align=middle width=37.84231934999999pt height=21.18721440000001pt/> then worst case

<p align="center"><img src="svgs/3fc527ec1b9f33aa480961b4312aa531.svg?invert_in_darkmode" align=middle width=312.93948674999996pt height=49.315569599999996pt/></p>

- "assuming that it is uniform" , can divide by <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/>
  - is this legit maths?
- <img src="svgs/2333193b1aa7871f90b7863c3e08b1c9.svg?invert_in_darkmode" align=middle width=87.54188684999998pt height=24.65753399999998pt/>



### Choice of pivots

- `rand()`
- first element
- median of three
- PRNG

The median of three has you look at the first, middle and last  elements of the array, and choose the median of those three elements as  the pivot.

To get the "full effect" of the median of three, it's also important to *sort* those three items, not just use the median as the pivot -- this doesn't affect what's chosen as the pivot in the current iteration, but  can/will affect what's used as the pivot in the next recursive call,  which helps to limit the bad behavior for a few initial orderings (one  that turns out to be particularly bad in many cases is an array that's  sorted, except for having the smallest element at the high end of the  array (or largest element at the low end). For example:

Compared to picking the pivot randomly:

1. It ensures that one common case (fully sorted data) remains optimal.
2. It's more difficult to manipulate into giving the worst case.
3. A PRNG is often relatively slow.

That second point probably bears a bit more explanation. If you used the obvious (`rand()`) random number generator, it's fairly easy (for many cases, anyway) for  somebody to arrange the elements so it'll continually choose poor  pivots. This can be a serious concern for something like a web server  that may be sorting data that's been entered by a potential attacker,  who could mount a DoS attack by getting your server to waste a lot of  time sorting the data. In a case like this, you *could* use a  truly random seed, or you could include your own PRNG instead of using  rand() -- or you use use Median of three, which also has the other  advantages mentioned.

On the other hand, if you use a sufficiently random generator (e.g., a hardware generator or encryption in counter mode) it's probably *more* difficult to force a bad case than it is for a median of three  selection. At the same time, achieving that level of randomness  typically has quite a bit of overhead of its own, so unless you really  expect to be attacked in this case, it's probably not worthwhile (and if you do, it's probably worth at least considering an alternative that  guarantees O(N log N) worst case, such as a merge sort or heap sort.

[Stackoverflow](https://stackoverflow.com/questions/7559608/median-of-three-values-strategy)

### Quicksort summary

- Used in C (qsort)
- Basis for C++ sort (introsort)
- Usually the fastest