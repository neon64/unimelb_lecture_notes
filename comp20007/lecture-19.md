# Lecture 19 - Dynamic Programming

Transitive Closure - which nodes can you reach from which particular node

- e.g.: formula which refers to other cells which has a formula which refers to other cells



- can accomplish with simple BFS from each starting node
  - but that is repeating a whole lot of work over and over again



## Warshall's Algorithm

#### Goal: find all node pairs with path between them



- can the solution be broken into solutions to subproblems?
  - if there's a path between two nodes i and j which are not directly connected, that path has to go through at least another node k
    - can then ask if (i, k) and (k, j) have paths instead
- do the subproblems overlap?
  - if pairs (i, j_1), (i, j_2) have paths which go through $k$, finding if the pair (i, k) has a path is part of the solutions to both problems.



1. number nodes 1 to A
   1. adjacency matrix A

$$
R_{ij}^{0} = A[i,j] \\
R_{ij}^{k} = R_{ij}^{k-1} \or (R_{ik}^{k-1} \and R_{kj}^{k-1})
$$



```pseudocode
function Warshall(A[1..n, 1..n])
	R^{0} = A
	for k <- 1 to n do
		for i <- 1 to n do
			for j <- 1 to n do
				R^k[i, j] <- R^{k-1}[i,j] or (....) # same as in relation above
```



- we can allow input A to be used for the output, simplifying things
  - values only go 0->1, but never the other way around



faster version (also in-place):

```function
for k <- 1 to n do
	for i <-1 to n do
		if A[i, k] then
			for j <- 1 to n do
				if A[k, j] then
					A[i, j] <- 1
```





- the matrix approach is O(n^2) per matrix, times $n$ nodes -> $O(n^3)$ overall



- $\Theta(n^3)$ in all cases
- ideal for dense graphs
- not the best for sparse graphs
  - DFS from each node tends to perform better



## Floyd's Algorithm

finding the shortest path between all pairs

- sounds a lot like Dijkstra!!
  - except solves for all-pairs, not just from one starting node
- solves the **all-pairs shortest-path** for weighted graphs with **positive weights**



- pseudocode super similar to the Warshall algorithm..

$$
D_{ij}^{0} = W[i, j] \\
D_{ij}^{k} = min(D_{ij}^{k-1}, D_{ik}^{k-1} + D_{kj}^{k-1})
$$



- also $\Theta(n^3)$
- negative weights aren't necessarily problem
  - but negative **cycles** are a problem
    - trigger arbitrarily low values for the involved paths

- Floyd can be adapted to detect negative cycles

  - by looking if the diagonal values become negative

  



## DP on Fibonacci Numbers

$$
F(n) = F(n-1) + F(n-2), n > 1 \\
F(0) = 1, \; F(1)=1
$$

Recursive solution:

```pseudocode
function Fib(n):
	if n == 0 or n == 1: return 1
	else: return Fib(n-1) + Fib(n-2)
```



- complexity is $O(2^n)$



```pseudocode
function FibDP(n):
	F[0] <- 1
	F[1] <- 1
	for i=2 to n do
		F[i] = F[i-1] + F[i-2]
    return F[n]
```



1. overlapping subproblems
2. exponential to linear complexity
3. can we use space more efficiently?



## Conditions for using Dynamic Programming

- subproblems
- overlapping
  - allocates extra memory to store solutions to subproblems
- DP is mostly related to optimisation problems (not always though)
  - should be obtained from optimal solutions to subproblems.

- reuse solutions in order to get a solution for the full problem



## Transitive Closure of a Graph

**Definition:** a transitive closure of a graph $G$ is a new graph $G'$ such that $(u, v)$ is an edge in $G'$ iff there's a path from $u$ to $v$ in $G$

