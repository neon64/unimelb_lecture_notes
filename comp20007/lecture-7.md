# Lecture 4.1 - 31/3/20 - Graph Traversal

Questions which require graph traversal:

- find out whether all nodes are connected
- find out whether there are cycles

## Depth-first search

- Explore <img src="svgs/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode" align=middle width=9.39498779999999pt height=14.15524440000002pt/> first, but then, before exploring <img src="svgs/deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode" align=middle width=8.649225749999989pt height=14.15524440000002pt/> and <img src="svgs/f93ce33e511096ed626b4719d50f17d2.svg?invert_in_darkmode" align=middle width=8.367621899999993pt height=14.15524440000002pt/> we keep going deeper and deeper into the

- Need to mark nodes to avoid revisiting the same nodes
  
  - Based upon backtracking
  - Actual order of visiting nodes will be determined by the underlying data structure, rarely something predictable like e.g.: 'alphabetical order'

- Use a **traversal stack**

- Once stack is empty - can choose another unvisited node in from some order
  
  - This way we visit the whole graph even if it is not connected

Levetin's more compact notation for stack history:

```
e_{4,1}
d_{3,2}
b_{2,3}   c_{5,4}    g{7,6}
a_{1,5}   a_{1,5}    f{6,7}
```

- DFS tree (or more generally - get a DFS forest if the graph is not connected)
  - black lines - visiting
  - blue dashed lines - back edge, for backtracking

```pseudocode
function DFS({V, E})
    mark each node in V with 0
    count <- 0
    for each v in V do
        if v is marked 0 then
            DFSExplore(v)

function DFSExplore(v)
    count <- count + 1
    mark v with count
    for each edge (v, w) do
        if w is marked with 0 then
            DFSExplore(w)
```

- this works for both directed and undirected graphs

The "marking" of nodes is usually done by maintaining a separate array, `mark`, indexed by `V`.

How do we find adjacent nodes?

- using an adjacency **matrix** we consider each entry for each <img src="svgs/31fae8b8b78ebe01cbfbe2fe53832624.svg?invert_in_darkmode" align=middle width=12.210846449999991pt height=14.15524440000002pt/> in <img src="svgs/a9a3a4a202d80326bda413b5562d5cd1.svg?invert_in_darkmode" align=middle width=13.242037049999992pt height=22.465723500000017pt/>, here, the complexity of graph traversal is <img src="svgs/c155bc8304ac0e3bca4b096a6ed42dca.svg?invert_in_darkmode" align=middle width=55.319805749999986pt height=26.76175259999998pt/>
- using an adjacency **list** we traverse the list, complexity is <img src="svgs/747f03346f55b417c0a809b94dc5da56.svg?invert_in_darkmode" align=middle width=90.25116209999999pt height=24.65753399999998pt/>
  
  - have to look at each vertex in the adjacency list
- notation: we have used <img src="svgs/b35e24d8a08c0ab01195f2ad2a78fab7.svg?invert_in_darkmode" align=middle width=12.785434199999989pt height=22.465723500000017pt/> instead of <img src="svgs/9afe6a256a9817c76b579e6f5db9a578.svg?invert_in_darkmode" align=middle width=12.99542474999999pt height=22.465723500000017pt/> because this is a lower bound as well



- A directed graph <img src="svgs/5201385589993766eea584cd3aa6fa13.svg?invert_in_darkmode" align=middle width=12.92464304999999pt height=22.465723500000017pt/> contains no cycles if and only if a depth first search of <img src="svgs/5201385589993766eea584cd3aa6fa13.svg?invert_in_darkmode" align=middle width=12.92464304999999pt height=22.465723500000017pt/> yields no back edges. -> is a DAG
- If a DFS yields all nodes on the first try, then the graph is **connected**
- **In terms of DFS forests, how can we tell if we have traversed a DAG?**
  - only get one DFS forest?



- DFS classifies the types of edges
  - **Tree edges** - part of the initial exploration
  - **Back edges** - found leading back to a node that has already been explored
  - **Forward edges** - skips to a deeper edge - only found once you go back up the stack and start looking again
  - **Cross edges** - any other sort of edge (e.g.: between siblings)



- in a DFS of an <u>undirected graph</u> you can only get tree edges, or back edges
  - since <img src="svgs/2c4a788685c5c98364a6d234f540b9eb.svg?invert_in_darkmode" align=middle width=38.05943129999999pt height=24.65753399999998pt/> implies <img src="svgs/dbc3b5eafd5c3a7d21c1c26a294aec30.svg?invert_in_darkmode" align=middle width=38.05943129999999pt height=24.65753399999998pt/> in an undirected graph, one could argue that forward edges and back edges are really the same thing. While this is true, one tends to classify edges by the <u>first</u> definition encountered above ^^

## Breath-first search

- Start from node v, v has neighbouring nodes x, y, z
  - Explore x,y,z before exploring any of their neighbouring nodes

Useful to use a **queue**

- enqueue / inject

- dequeue / eject

- Can also create a BFS forest
  
  - cross edges? blue dashed line - not really part of the forest
    - connected in the graph, but neither is a parent or ancestor

```pseudocode
function BFS({V, E})
    mark each node in V with 0
    count <- 0, init(queue)
    for each v in V do
        if v is marked 0 then
            count <- count + 1
            mark v with count
            inject(queue, v)
            while queue is non-empty do
                u <- eject(queue) # dequeues u
                for each edge (u, w) adjacent to u do
                    if w is marked with0 then
                    count <- count + 1
                    mark w with count    
                    inject(queue, w) # enqueues w
```

- BFS has the same complexity as DFS
- **Example problem:** given a graph and two nodes <img src="svgs/44bc9d542a92714cac84e01cbbb7fd61.svg?invert_in_darkmode" align=middle width=8.68915409999999pt height=14.15524440000002pt/> and <img src="svgs/4bdc8d9bcfb35e1c9bfb51fc69687dfc.svg?invert_in_darkmode" align=middle width=7.054796099999991pt height=22.831056599999986pt/>, how to find the fewest number of edges between two nodes?
  - Start a BFS from <img src="svgs/44bc9d542a92714cac84e01cbbb7fd61.svg?invert_in_darkmode" align=middle width=8.68915409999999pt height=14.15524440000002pt/>, stop as soon as you find <img src="svgs/4bdc8d9bcfb35e1c9bfb51fc69687dfc.svg?invert_in_darkmode" align=middle width=7.054796099999991pt height=22.831056599999986pt/>.
  - This will find the *fewest* number of edges

## Topological sorting

- Scheduling problems

- Assume an edge from <img src="svgs/44bc9d542a92714cac84e01cbbb7fd61.svg?invert_in_darkmode" align=middle width=8.68915409999999pt height=14.15524440000002pt/> to <img src="svgs/4bdc8d9bcfb35e1c9bfb51fc69687dfc.svg?invert_in_darkmode" align=middle width=7.054796099999991pt height=22.831056599999986pt/> means <img src="svgs/4bdc8d9bcfb35e1c9bfb51fc69687dfc.svg?invert_in_darkmode" align=middle width=7.054796099999991pt height=22.831056599999986pt/> depends on <img src="svgs/44bc9d542a92714cac84e01cbbb7fd61.svg?invert_in_darkmode" align=middle width=8.68915409999999pt height=14.15524440000002pt/> in order to start.

- Then the graph must be a dag (directed acyclic graph)

- Task: try to linearize the graph, i.e.: order the nodes in a sequence such that the dependencies are met

- There are different ways to linearize different graphs

#### Algorithms for topological sorting

1. Perform a DFS and note the order in which the nodes are popped *off* the stack
2. List the nodes in the reverse of that order

Why is this algorithm correct?

Consider an edge (u, v). Then <img src="svgs/6dbb78540bd76da3f1625782d42d6d16.svg?invert_in_darkmode" align=middle width=9.41027339999999pt height=14.15524440000002pt/> is sitting below <img src="svgs/6c4adbc36120d62b98deef2a20d5d303.svg?invert_in_darkmode" align=middle width=8.55786029999999pt height=14.15524440000002pt/> on the stack. <img src="svgs/6c4adbc36120d62b98deef2a20d5d303.svg?invert_in_darkmode" align=middle width=8.55786029999999pt height=14.15524440000002pt/> is popped off first, then <img src="svgs/6dbb78540bd76da3f1625782d42d6d16.svg?invert_in_darkmode" align=middle width=9.41027339999999pt height=14.15524440000002pt/>

So in our list <img src="svgs/6dbb78540bd76da3f1625782d42d6d16.svg?invert_in_darkmode" align=middle width=9.41027339999999pt height=14.15524440000002pt/> will be listed before <img src="svgs/6c4adbc36120d62b98deef2a20d5d303.svg?invert_in_darkmode" align=middle width=8.55786029999999pt height=14.15524440000002pt/> (because reverse order)

#### Another algorithm

- Repeatedly select a random source in the graph (that is, a node with no incoming events)

- List that node down, then remove it from the graph

- very natural approach, but means you have to keep scanning the graph for a source

- uses the principle of *decrease-and-conquer*