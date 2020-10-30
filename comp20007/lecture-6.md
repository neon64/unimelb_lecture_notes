# Lecture 3.2 19/03/2020

## Brute Force:

### Brute-Forcing String Matching

- not that bad for a large alphabet

### Brute-Forcing Geometric Algorithms: Closest Pair

- machine learning - which item is the most similar?

- basic computation: square root operation

<img src="svgs/7f673488709d91c2cf326d97e5a437c3.svg?invert_in_darkmode" align=middle width=42.81220349999999pt height=26.76175259999998pt/>

- but since the square root function is a monotonic function, we don't actually need to take the square root!
  
  - makes it much much faster on a real machine
  - doesn't change complexity - just changed a constant factor

- other techniques:
  
  - sort data across x axis, then y- axis
  - can find the closest distance in <img src="svgs/5bdc90ce16382c0f8496279da7f0d740.svg?invert_in_darkmode" align=middle width=72.01684874999998pt height=24.65753399999998pt/>

- Verdict: use brute-force for prototyping, or when inputs are small

## Exhaustive search:

- generate all possible options,
- test them all
- get the best one

### Travelling salesperson problem (TSP):

becomes <img src="svgs/c867a046b8ce7ad2c5c3370855e47270.svg?invert_in_darkmode" align=middle width=81.30979229999998pt height=24.65753399999998pt/> to brute force

- we call this a <img src="svgs/aa1bd49a4578d83ef6f508fb0a9e7289.svg?invert_in_darkmode" align=middle width=27.83674409999999pt height=22.465723500000017pt/> hard problem because can't be solved in polynomial time

e.g.: 4 points: <img src="svgs/13886bb7fe37d92c2e18ed5499093252.svg?invert_in_darkmode" align=middle width=78.53843249999998pt height=21.18721440000001pt/> possibilities

can also achieve <img src="svgs/92bb3d0bacc352ddc4d4d707f9e11af6.svg?invert_in_darkmode" align=middle width=21.00464354999999pt height=21.18721440000001pt/> speed-up by eliminating pairs, but this still remains <img src="svgs/c867a046b8ce7ad2c5c3370855e47270.svg?invert_in_darkmode" align=middle width=81.30979229999998pt height=24.65753399999998pt/>

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

<p align="center"><img src="svgs/378708616d7261cc8e346963e61145e9.svg?invert_in_darkmode" align=middle width=78.5180649pt height=16.438356pt/></p>

- <img src="svgs/a9a3a4a202d80326bda413b5562d5cd1.svg?invert_in_darkmode" align=middle width=13.242037049999992pt height=22.465723500000017pt/> set of nodes or vertices

- <img src="svgs/84df98c65d88c6adf15d4645ffa25e47.svg?invert_in_darkmode" align=middle width=13.08219659999999pt height=22.465723500000017pt/> set of edges

- if the edges have no arrows, then the graph is **undirected**

- <p align="center"><img src="svgs/d9c71485a33e33f6b45e8f1346291551.svg?invert_in_darkmode" align=middle width=590.3368779pt height=16.438356pt/></p>

- if the edges have arrows, you can only go one-way by default, then the graph is **directed**

- **connected** - one whole entity, has a path between any two nodes

- **not connected** - two or more components

- **degree** - how many edges attached to one node
  
  - what does it mean for a directed graph?
    - **in degree**, **out degree**

A *path* in <img src="svgs/7f9788a766333e7788d765c793bd664d.svg?invert_in_darkmode" align=middle width=43.67579039999999pt height=24.65753399999998pt/> is a sequence of nodes <img src="svgs/636d9f1aaa8a777b1ab61d39f561776f.svg?invert_in_darkmode" align=middle width=89.75444774999998pt height=14.15524440000002pt/> from V so that <img src="svgs/4e64ffb455da0ef8d29c549804b1ecc9.svg?invert_in_darkmode" align=middle width=96.79028699999999pt height=24.65753399999998pt/>

- has length <img src="svgs/63bb9849783d01d91403bc9a5fea12a2.svg?invert_in_darkmode" align=middle width=9.075367949999992pt height=22.831056599999986pt/>

- a **simple path** has no repeated nodes

- a **cycle** is a simple path except that <img src="svgs/b9b1e086b65f62eea06927eb75234ee5.svg?invert_in_darkmode" align=middle width=52.494253349999994pt height=14.15524440000002pt/>

- **unweighted** - no weights on each edge

- **weighted** - each edge has a weight

- **complete** - every node connected to every other node

- **dense** - has a lot of edges relative to the number of nodes
  
  - if the number of edges relative to number of nodes is <img src="svgs/7f673488709d91c2cf326d97e5a437c3.svg?invert_in_darkmode" align=middle width=42.81220349999999pt height=26.76175259999998pt/> then can say it is dense (i.e.: a complete graph or almost complete)
  - 

- **sparse** - less edges relative to the number of nodes
  
  - if the number of edges is <img src="svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.64773519999999pt height=24.65753399999998pt/>
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
- <img src="svgs/63bb9849783d01d91403bc9a5fea12a2.svg?invert_in_darkmode" align=middle width=9.075367949999992pt height=22.831056599999986pt/> colouring problem - if the graph is planar then we know it has a solution

## Graph representations

### Adjacency matrix:

![](Capture.PNG)

When is an adjacency matrix a good choice? When the graph is dense.. Most entries are meaningful (contains 1s)

### Adjacency list:

- keep pointers to all nodes which you can get to from a given node <img src="svgs/eaf0887cdc4cb5f8e69a7796f143c3eb.svg?invert_in_darkmode" align=middle width=15.23409524999999pt height=14.15524440000002pt/>.
- can use a dictionary - faster than linked-list
- good if its a sparse graph
- if dense, a matrix gives faster lookup time
