# Lecture 3.2 19/03/2020

## Brute Force:

### Brute-Forcing String Matching

- not that bad for a large alphabet

### Brute-Forcing Geometric Algorithms: Closest Pair

- machine learning - which item is the most similar?

- basic computation: square root operation

$\Theta(n^2)$

- but since the square root function is a monotonic function, we don't actually need to take the square root!
  
  - makes it much much faster on a real machine
  - doesn't change complexity - just changed a constant factor

- other techniques:
  
  - sort data across x axis, then y- axis
  - can find the closest distance in $\Theta(n \log n)$

- Verdict: use brute-force for prototyping, or when inputs are small

## Exhaustive search:

- generate all possible options,
- test them all
- get the best one

### Travelling salesperson problem (TSP):

becomes $O((n-1)!)$ to brute force

- we call this a $NP$ hard problem because can't be solved in polynomial time

e.g.: 4 points: $3\cdot 2 \cdot 1 = 6$ possibilities

can also achieve $2\times$ speed-up by eliminating pairs, but this still remains $O((n-1)!)$

### Knapsack problem:

- can get a better algorithm based upon *dynamic programming*
- will see later in Semester!

## NP-complete problems

- There is a large class of important problems, *it appears* that there is no better alternative, but there is no proof either way.

- should try to find *approximation algorithms* which are close to the optimal solution

## Hamiltonian Tours

- simpler than travelling-salesman problem

- a simple tour (a path which visits each node exactly once, returns to the starting graph)

## Eulerian Tour

- undirected graph, is there a path which visits each *edge* exactly once
  - for this one there isn't

# Graphs & Graph Concepts

- *depth-first*

- *breadth-first*

- useful for network design, flow design, planning, scheduling, route finding etc...

$$
G = \langle V, E \rangle
$$

- $V$ set of nodes or vertices

- $E$ set of edges

- if the edges have no arrows, then the graph is **undirected**

- $$
  E = \text{symmetric closure of } \{ (a,b), (a,c), (a,d), (a,e), (b,d), (b,e), (c,f), (d,e), (f,g) \}
  $$

- if the edges have arrows, you can only go one-way by default, then the graph is **directed**

- **connected** - one whole entity, has a path between any two nodes

- **not connected** - two or more components

- **degree** - how many edges attached to one node
  
  - what does it mean for a directed graph?
    - **in degree**, **out degree**

A *path* in $\langle V, E \rangle$ is a sequence of nodes $v_0, v_1, \dots, v_k$ from V so that $(v_i, v_{i+1}) \in E$

- has length $k$

- a **simple path** has no repeated nodes

- a **cycle** is a simple path except that $v_0 = v_k$

- **unweighted** - no weights on each edge

- **weighted** - each edge has a weight

- **complete** - every node connected to every other node

- **dense** - has a lot of edges relative to the number of nodes
  
  - if the number of edges relative to number of nodes is $\Theta(n^2)$ then can say it is dense (i.e.: a complete graph or almost complete)
  - 

- **sparse** - less edges relative to the number of nodes
  
  - if the number of edges is $O(n)$
  - not a hard definition

- **cyclic** - there exists cycles

- **acyclic** - a *tree*, contains not cycles
  
  - edges = nodes - 1
  - a **rooted tree** - has one node identified as special - every other node is reachable from the root node.

- **directed cyclic**

- **directed acyclic** (a **dag**)

directed graphs are central in scheduling problems...

## Graph k-colouring problem

- people don't want to sit with each other - put an edge between two people
- $k$ colouring problem - if the graph is planar then we know it has a solution

## Graph representations

### Adjacency matrix:

![](Capture.PNG)

When is an adjacency matrix a good choice? When the graph is dense.. Most entries are meaningful (contains 1s)

### Adjacency list:

- keep pointers to all nodes which you can get to from a given node $v_k$.
- can use a dictionary - faster than linked-list
- good if its a sparse graph
- if dense, a matrix gives faster lookup time
