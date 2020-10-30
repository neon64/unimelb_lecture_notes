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

$$
C(n) = 2 \cdot C(n/2) + C_{merge}(n)
$$

Worst case scenario for $C_{merge}$ - have to go all the way to the end
$$
C_{merge}^{worst} = n-1
$$

$$
C(n) = 2C(n/2) + n-1
$$

Apply the master theorem:
$$
T(n) = aT(n/b) + F(n^d)
$$

$$
a = 2, b = 2, d = 1 \\
a = b^d \implies 2 = 2^1 \\
\implies \Theta(n^d \log(n)) \\
\implies \Theta(n \log(n))
$$

Best case - $C_{merge}^{best} = \frac{n}{2}-1$

- since need to go through and check $\frac{n}{2}$ elements before copying the other half over

Complexity of mergesort = $\Theta(n \log n)$

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
- but can still exhibit $O(n^2)$ behaviour
- 

### Complexity

- Worst case?
- Best case?
- Average case?
  - difficult to solve the recurrence relation

measuring - comparisons

**best-case scenario:**

- number of comparisons to partition a list of $n$.
- at least $n-1$ to get to middle, plus $1+1$ for each of them
  - $n+1 \in \Theta(n)$

$$
C_{best} = 2C_{best}(n/2) + \Theta(n) \implies\Theta(n\log(n))
$$

- assumes the pivot split the array in half each time

**worst-case scenario:**

- pivot is the smallest element, one partition of size 0, one of size $n-1$.

- new pivot is once again smallest element

- if the array is already sorted, but in reverse

- becomes *decrease* and conquer, not *divide* and conquer

$$
C_{worst} = (n+1) + n (n-1) + \dots .. 3 \\
       = \frac{(n+1)(n+2)}{2} - 2 - 1 \\
       = \frac{(n+1)(n+2)}{2} - 3 \\
       \in \Theta(n^2)
$$

**average-case**
$$
s \gets \text{size of first partition} \\
\text{Let } n+1 \text{ be the cost of the partition}
$$

$$
C_{avg} = (n+1) + C_{avg}(s) + C_{avg}(n - 1 - s)
$$

if $s = \frac{n}{2}$ then you get best case, if $s=0$ then worst case

$$
\frac{1}{n} \left(\sum_{s=0}^{n-1} n+1 + C_{avg}(s) + C_{avg}(n-1-s) \right)
$$

- "assuming that it is uniform" , can divide by $n$
  - is this legit maths?
- $\in \Theta(n \log n)$



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