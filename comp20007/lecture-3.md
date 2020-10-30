# Lecture 3 - 10/03/2020

Introduction to two *abstract data structures* - this means that we only define particular operations which are supported by these data structures - the specific implementation under the hood is left undefined.

- i.e.: doesn't say *you must use an array*, or *you must use a linked-list*. Instead implementations can decide.

## Stack

`LIFO` - last in, first out

Implemented as an array:

```pseudocode
int A[h]
top = -1
push(value):
    top <- top + 1
    A[top] = value

pop():
    top <- top - 1
```

Implemented as a linked-list:

- push and pop from the *front* - then you get `O(1)` push and pop

## Queue

```pseudocode
int A[h]
top = -1
push(value):
    top <- top + 1
    A[top] = value

pop():
    top <- top - 1
```

Implemented as a linked-list:

- push and pop from the *front* - then you get `O(1)` push and pop

`FIFO` - first in, first out

Operations:

- `CreateQueue`
- `Enqueue`
- `Dequeue`
- `Head`
- `EmptyQueue?`
- ...

# Algorithm analysis

- Time and space

- Efficiency as a function of input size

- Space is now reasonably cheap - so we mostly care about time.

Options:

- Mathematical vs empirical assessment
- Average case vs worst-case

What we ignore:

- Underlying machine, including memory architecture
- Language / compiler / operating system

Use a natural number `n` to measure the size of the input.

Division is more expensive on most CPUs - but we assume all 'basic operations' take the same amount of time.

## 

| Problem                          | Size measure   | Basic operation      |
| -------------------------------- | -------------- | -------------------- |
| Search in a list of n items      | n              | Key comparison       |
| Multiply two matricies of floats | rows * columns | float multiplication |
| Graph problem                    | ...            | ...                  |
|                                  |                |                      |
|                                  |                |                      |

**Worst-case** - most adverse assumptions about the input

**Best-case** - optimistic assumptions about structure of the input

**Average-case** - aims to find the *expected* running time across all possible inputs of size <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/>. (importantly, not necessarily an average of the best and worst case complexities)

**Amortised** - takes the complexity over many runs of input, not just  asingle run

### Sequential search

**Best case:** O(1) if its the first element

**Worst-case:** O(n)

**Average-case:** O(n)

If the probability of a successful search is equal to p (<img src="svgs/587c49fb1eb1319359be1f4ca114cc25.svg?invert_in_darkmode" align=middle width=68.54424719999999pt height=21.18721440000001pt/>),  then the average number of average number of key comparisons <img src="svgs/52c0078295a19e4824aed82133ed57dd.svg?invert_in_darkmode" align=middle width=56.16765824999998pt height=24.65753399999998pt/> is

<p align="center"><img src="svgs/1f4b1f2977a59d3e6ca5ed0a3fbddc28.svg?invert_in_darkmode" align=middle width=153.4614576pt height=32.990165999999995pt/></p>

Probability of finding in the first, second, third etc... position:

<p align="center"><img src="svgs/c7d06ae428cc08f341e248d280a280f5.svg?invert_in_darkmode" align=middle width=438.1455705pt height=47.5572042pt/></p>

<p align="center"><img src="svgs/ec6031197e499534345d7b861013122f.svg?invert_in_darkmode" align=middle width=63.86133105pt height=32.990165999999995pt/></p>

> "Large input is what matters"
> 
> - Lars' wise words, 2020
