# Lecture 2 - 5/03/2020

## Greatest Common Divisor

`gcd(m, n)`

**Step 1:** if <img src="svgs/73736f8725b398dd13e17ef7c1d0a94a.svg?invert_in_darkmode" align=middle width=40.00371704999999pt height=21.18721440000001pt/> return the value of <img src="svgs/0e51a2dede42189d77627c4d742822c3.svg?invert_in_darkmode" align=middle width=14.433101099999991pt height=14.15524440000002pt/> and stop

**Step 2:** Divide m by n and assign the value of the remainder to r

**Step 3:** Assign the value of n to m and the value of r to <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/>, go to step 1.

`gcd(m, 0) = m` - our stopping condition

```pseudocode
Euclid(m, n)

while n != 0 do
    r <- m mod n
    m <- n
    n <- r

return m
```

#### Why does it terminate?

1. because the value of <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> is always decreasing
2. <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> is always decreasing because the remainder can be from 0 to <img src="svgs/efcf8d472ecdd2ea56d727b5746100e3.svg?invert_in_darkmode" align=middle width=38.17727759999999pt height=21.18721440000001pt/>

#### Another option: use prime factorisation to compute GCD

<p align="center"><img src="svgs/ba5def3bd77374c0a1e24849bb298f0a.svg?invert_in_darkmode" align=middle width=300.45530625pt height=10.5936072pt/></p>

Problems:

- shifted lots of work to finding prime factors
- how do we even know which numbers are prime?

#### Faster identification of primes: Sieve of Eratosthenes

- only need to do <img src="svgs/4fd78aba72015f7697ab298a89ec8a9c.svg?invert_in_darkmode" align=middle width=23.565549149999992pt height=24.995338500000003pt/> calculations to find which numbers up to <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> are prime

## Computability

- discussed more in the 3rd-year subject *Models of Computation*
- Alan Turing showed that - some problems don't have algorithmic solutions, some just don't have efficient solutions
  - travelling salesman problem is NP hard <img src="svgs/dd346d5af971e1d1e1f87f86bb18597c.svg?invert_in_darkmode" align=middle width=10.95894029999999pt height=22.758598499999987pt/>  it can be proven that you can't find an efficient solution
  - halting problem for Turing machines is undecidable - you cannot compute it
- Turing award = equivalent to Nobel prize for computer science

## *"time puzzle"*

- something you can prove that can't be parallelized thus must take e.g.: <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> years minimum

## Approximation techniques

- approximate solutions, with error bounds - sometimes more useful than exact solutions

- randomisation - avoid worst case by randomising inputs

## Types of algorithms

- Sorting
- Searching
- String processing
- Graph algorithms

Approaches to algorithm design:

- Brute force, decrease and conquer, divide and conquer, transform and conquer

## Graph Colouring

Planar graphs only need 4 colours max to 'colour' the graph - the same is *not* true for non-planar graphs

## Mutilated checkerboard problem

If you colour the squares - more blue squares than white squares on the board. 32 vs 30 - whereas we need 31 on each.

- So by colouring this board, making it into a different representation, it is really easy to prove it doesn't work.

![](screenshot_2020-06-28_17-35-45_904346138.png)

![](screenshot_2020-06-28_17-35-49_004584317.png)

# Types of data structures

- Linear data structures: stacks and queues
- Trees and graph
- Dictionaries
- Tries
1. How to insert
2. How to find an item
3. How to handle duplicate items

Sorting:

- does the relative order get maintained between items with the same key value? then it is called a 'stable' sort

## Arrays

- locating, storing/retrieval is super fast.
  
  implemented as a contiguous block of memory

## Linked-list

- Dummy head node
- Special 'null' object which represents the empty list
- Insertion + deletion is fast
- Finding the nth element is time consuming

Iterative method:

```pseudo
p := head
while p != null
    if p.val == x
        return p
    p := p.next
return null
```

Finding item in an array (recursive method)

```pseudocode
function find(A, x, lo, hi)
    if lo > hi
        return null
    else if A[lo] == x
        return lo
    else
        return find(A, x, lo + 1, hi)
```

## Abstract Data Types

- a *promise* that a data type will behave in a certain way
- e.g.: the below abstract data types could be either implemented as arrays or linked lists - there are likely other options too
