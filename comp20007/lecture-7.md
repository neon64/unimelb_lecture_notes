# Lecture 4.1 - 31/3/20 - Graph Traversal

Questions which require graph traversal:

- find out whether all nodes are connected
- find out whether there are cycles

## Depth-first search

- Explore $x$ first, but then, before exploring $y$ and $z$ we keep going deeper and deeper into the

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

- using an adjacency **matrix** we consider each entry for each $w$ in $V$, here, the complexity of graph traversal is $\Theta(|V|^2)$
- using an adjacency **list** we traverse the list, complexity is $\Theta(|V| + |E|)$
  
  - have to look at each vertex in the adjacency list
- notation: we have used $\Theta$ instead of $O$ because this is a lower bound as well



- A directed graph $G$ contains no cycles if and only if a depth first search of $G$ yields no back edges. -> is a DAG
- If a DFS yields all nodes on the first try, then the graph is **connected**
- **In terms of DFS forests, how can we tell if we have traversed a DAG?**
  - only get one DFS forest?



- DFS classifies the types of edges
  - **Tree edges** - part of the initial exploration
  - **Back edges** - found leading back to a node that has already been explored
  - **Forward edges** - skips to a deeper edge - only found once you go back up the stack and start looking again
  - **Cross edges** - any other sort of edge (e.g.: between siblings)



- in a DFS of an <u>undirected graph</u> you can only get tree edges, or back edges
  - since $(u,v)$ implies $(v, u)$ in an undirected graph, one could argue that forward edges and back edges are really the same thing. While this is true, one tends to classify edges by the <u>first</u> definition encountered above ^^

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
- **Example problem:** given a graph and two nodes $a$ and $b$, how to find the fewest number of edges between two nodes?
  - Start a BFS from $a$, stop as soon as you find $b$.
  - This will find the *fewest* number of edges

## Topological sorting

- Scheduling problems

- Assume an edge from $a$ to $b$ means $b$ depends on $a$ in order to start.

- Then the graph must be a dag (directed acyclic graph)

- Task: try to linearize the graph, i.e.: order the nodes in a sequence such that the dependencies are met

- There are different ways to linearize different graphs

#### Algorithms for topological sorting

1. Perform a DFS and note the order in which the nodes are popped *off* the stack
2. List the nodes in the reverse of that order

Why is this algorithm correct?

Consider an edge (u, v). Then $u$ is sitting below $v$ on the stack. $v$ is popped off first, then $u$

So in our list $u$ will be listed before $v$ (because reverse order)

#### Another algorithm

- Repeatedly select a random source in the graph (that is, a node with no incoming events)

- List that node down, then remove it from the graph

- very natural approach, but means you have to keep scanning the graph for a source

- uses the principle of *decrease-and-conquer*