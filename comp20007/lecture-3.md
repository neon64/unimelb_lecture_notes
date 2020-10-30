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

**Average-case** - aims to find the *expected* running time across all possible inputs of size $n$. (importantly, not necessarily an average of the best and worst case complexities)

**Amortised** - takes the complexity over many runs of input, not just  asingle run

### Sequential search

**Best case:** O(1) if its the first element

**Worst-case:** O(n)

**Average-case:** O(n)

If the probability of a successful search is equal to p ($0 \leq p \leq 1$),  then the average number of average number of key comparisons $C_{avg}(n)$ is

$$
p \cdot \frac{n+1}{2} + n \cdot (1-p)
$$

Probability of finding in the first, second, third etc... position:

$$
1 \cdot \frac{p}{n} + 2 \cdot \frac{p}{n} + 3 \cdot \frac{p}{n} + \dots \\
= \frac{p}{n} \sum_{i=1}^{i}i \\
= \frac{p}{n} \frac{(n+1)n}{2} \\
= \frac{p(n+1)}{2}
$$

$$
\frac{p}{n}\cdot \frac{n+1}{2}
$$

> "Large input is what matters"
> 
> - Lars' wise words, 2020
