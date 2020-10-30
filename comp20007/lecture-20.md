# Lecture 20 - More on Dynamic Programming

## Knapsack problem

- brute-force would enumerate all possible subsets
  - $2^n$ possible subsets
  - exponential complexity - Not Good

Given $n$ items with

- weights $w_1, w_2, \dots w_n$ (all positive integers)
- values $v_1, v_2, \dots, v_n$ (all positive integers)
- knapsack of capacity $W$

Find the **most valuable selection of items that will fit in the knapsack**.

Need to use **two variables** for this particular dynamic programming problem.

- $i$ - index into the weights/values array
- $j$ capacity left

Express the solution recursively:
$$
K(i, j) = 0 \text{ if } i = 0 \text{ or } j = 0
$$


Otherwise
$$
K(i, j) = \begin{cases}
max(K(i-1, j), K(i-1, j-w_i) + v_i) & \text {if } j \geq w_i \\
K(i-1, j) & \text{if } j < w_i
\end{cases}
$$
- if the $i$th item could fit in the knapsack, return the highest value between including it in the knapsack, and not including it in the knapsack.
- otherwise if the $i$th item could not possibly fit in the knapsack ($j < w_i$), then value is the problem skipping the $ith$ item.



Bottom-up solution: fill in the rows and columns of an $n+1$ rows and $W+1$ columns

-  but lots of wasted calculations

Top-down, with *memoing* (memoization?)

Can make the memo table small by using a hash-table

$$
\Theta(nW) -
$$


- $n$ - number of items 
- $W$ - max capacity of the knapsack

called pseudopolynomial time - the algorithm is polynomial in the *value* of the input, not its length

- is really $O(n \times 2^{\text{bits to represent W}})$
- counting sort is another example
- pseudopolynomial is not in general polynomial because it is exponential in the number of bits.

[pseudo-polynomial on StackOverflow](https://stackoverflow.com/questions/19647658/what-is-pseudopolynomial-time-how-does-it-differ-from-polynomial-time)





Actual definition of time complexity: *amount of time it takes for an algorithm to run, as a function of the **length** of its input in bits*.



e.g.:

```pseudocode
function doSomething(n):
	for 1 to n:
		print(n)
		
doSomething(4) // length of input is 3, but runs 4 times
doSomething(8) // length of input is 4, but runs 8 times
doSomething(16) // length of input is 5, but runs 16 times
```

- this algorithm has exponential time complexity - $O(2^{\text{bits to represent n}})$
- 