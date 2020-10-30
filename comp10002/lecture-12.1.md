# Lecture 12.1

## Assignment 2

25008 submissions - IT staff will ban you for abuse of the uni computer systems!!

## Chapter 12 (Part II)

**abstract data types** - a collection of operations which we want to support in another algorithm

**dictionary** abstract data type

**priority queue**

then also O(n log n) worst-case time sorting

### Dictionary abstract data type

```c
D <-- make_empty()
D' <-- insert(D.key, item)
item_ptr <-- search(D.key)
D' <-- delete(D, key)
```

## Table of data structures

| Structure            | Search                         | Insert           | Delete                                                   | Smallest        | Next smallest                            |
| -------------------- | ------------------------------ | ---------------- | -------------------------------------------------------- | --------------- | ---------------------------------------- |
| Unsorted array       | O(n)                           | O(1)             | O(n)                                                     | O(n)            | O(n)                                     |
| Sorted array         | O(logn)                        | O(n) -worse      | O(n)                                                     | O(1)            | O(1)                                     |
| Unsorted linked list | O(n)                           | O(1)             | Search + O(1)                                            | O(n)            | O(n)                                     |
| Sorted linked list   | O(n)                           | Search + O(1)    | Search + O(1)                                            | O(1)            | O(1)                                     |
| Binary search tree   | O(logn) [avg] (but O(n) worst) | Search + O(1)    | **binary search deletion could turn up in the exam!!??** | O(log(n)) [avg] | O(1) avg. (often the parent, or sibling) |
| Balanced search tree | O(logn)                        | Search + O(logn) | O(logn)                                                  | O(logn)         | O(1) amortized.                          |
| Hashing              | O(1)* avg.                     | O(1)* avg.       | O(1)* avg.                                               | O(n)            | O(n)                                     |
|                      |                                |                  |                                                          |                 |                                          |
|                      |                                |                  |                                                          |                 |                                          |

Hashing - get keys, create a 'random' number from that information

- <img src="svgs/e6cb978bb53700bd518a0342acd83024.svg?invert_in_darkmode" align=middle width=24.657628049999992pt height=21.18721440000001pt/> - collision and fish both hash

Use those hashes to index an array A of size t, putting x in the location A[h(x)]. Works fine until you get a collision.

26th October - hashed to 69

11th August

16th June

24th May 

etc...

after 23 birthdays on average, will get collisions

## How to resolve collisions??

- put in the next available empty slot... but that fills up quickly, and it sucks - **linear advance**

**separate chaining**

instead of an array of `data_t`, we make an array of `list_t`

on average, there are <img src="svgs/491adc330d58784014b9485b1bc0a4d1.svg?invert_in_darkmode" align=middle width=27.161455199999992pt height=24.65753399999998pt/> items per list... as long as we grow <img src="svgs/63bb9849783d01d91403bc9a5fea12a2.svg?invert_in_darkmode" align=middle width=9.075367949999992pt height=22.831056599999986pt/> according to <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> the length, we will get constant time lookup (hash operations..)

## How to calculate hashes?

```c
unsigned hval = 0;
for each character in the string
hval += key[i] * h->values[k]; % uses prime numbers

modulo the table size
```

- don't use a **bad** hash function
  
  - never just add character values, or shift-n-add - isn't enough "randomness"

- if the hash function is good, then we get O(1) behaviour... yay :D


