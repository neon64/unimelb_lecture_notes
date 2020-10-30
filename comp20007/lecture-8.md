# Lecture 8 - Greedy Algorithms (Prim, Dijkstra's) (2/4/20)

- looking two **Greedy Algorithms** - Prim's and Dijkstra's algorithm

- a natural strategy to make decisions on what is the **locally** best choice.

- in general though, a locally optimal algorithm is not always globally optimal
  
  - e.g.: consider the coin denominations problem
    - greedy works for 25, 10, 5, and 1 to get to 30
    - doesn't work for 25, 10, 1

- sometimes a problem is 'hard' (computationally expensive), and greedy can provide a good approximation

## Priority queue

A set or pool of elements

Each element is paired with a priority

Operations (ordered by some linear order):

- **find** an item with maximal priority
- **insert** a new item with associated priority
- test whether a priority queue is empty
- **eject** the **largest element**

#### Example: CPU scheduling

When we use *time* for the priority

- if "large" priority means "late" - we obtain the **stack**
  - latest to arrive is the first to be ejected
- if "large" priority means "early" - we obtain the **queue**

#### Other implementations

Priority = Key

|                      | Inject(e)                                                                                  | Eject()                         |
| -------------------- | ------------------------------------------------------------------------------------------ | ------------------------------- |
| Unsorted array/list  | **O(1)** - could just put the item anywhere                                                | O(n) - linear search over array |
| Sorted array or list | O(log(n)) - to find the position<br />O(n) - to rearrange the array<br />Overall: **O(n)** | O(1)                            |
|                      |                                                                                            |                                 |

## Prim's algorithm for minimum spanning trees

What is a spanning tree?

- a connected graph with no cycle

A spanning tree of graph $\langle V,E \rangle$ is a tree $\langle V, E' \rangle$ with $E' \subseteq E$

Minimum spanning tree - each edge has a weight or cost associate with it

- We want to minimise the total cost of that spanning tree
- Some spanning trees will thus be better than others

![](/home/chris/drive/Uni/COMP20007 Design of Algorithms/screenshot_2020-04-02_14-56-32_224903522.png)

Prim's algorithm is an example of a greedy algorithm.

- in each step it picks a closest node and adds that

**Initial version of Prim's algorithm:**

```pseudocode
function Prim((V, E))
    V_T <- { v_0 }
    E_T <- empty_set
    for i <- 1 to |V| - 1 do
        find a minimum-weight edge (v, u) \in V_T \times (V \ V_T)
        V_T <- union(V_T , u)
        E_T <- union(E_T, (v, u))
    return E_T
```

- in each iteration, the tree grows by one edge

- how do we find this minimum-weight edge (v, u)

- a standard way to do this is to organise the nodes that are not yet included in the spanning tree T as a *priority queue* organised by **edge cost.**

- we want to later be able to unravel the minimum spanning tree
  
  - can have an array `prev` indexed by `V`.
    
    - so when `(v, u)` is included, `prev[u] = v`
  
  - can ultimately unravel all the way back to find edges

```pseudocode
function Prim((V, E))
    for each v in V do
        cost[v] <- infinity
        prev[v] <- nil
    pick initial node v_0
    cost[v0] <- 0
    Q <- InitPriorityQueue(V) // priorities are cost values
    while Q is non-empty do
        u <- EjectMin(Q)
        // for all the neighbours of u
        for each (u, w) in E do
            if w in Q and weight(u,w) < cost[w] then
                cost[w] <- weight(u, w)
                prev[w] <- u
                Update(Q, w, cost[w]) // rearranges the priority queue
```

#### Analysis

- crude analysis - for each node we look through all edges to pick the best edge (linear search)
  
  - $O(|V| \cdot |E|)$ (adjacency list)
  - $O(|V|^2)$ (adjacency matrix)

- However can do better, using a *min-heap* as a priority queue

- however can get down to $O((|V| + |E|)\log |V|)$ with a binary heap and adjacency list

## Dijkstra's Algorithm for Shortest Path

- Shortest path algorithm for (directed or undirected) weighted graphs
  - finds all shortest paths to all nodes
- Complexity is the same as Prim's algorithm

```pseudocode
function Dijkstra((V,E), v_0)
    for each v in V do
        dist[v] <- infinity
        prev[v] <- nil
    dist[v0] <- 0
    Q <- InitPriorityQueue(V)  // priorities are distances
    while Q is non-empty do
        u <- EjectMin(Q)
        for each (u, w) in E do
            if w in Q and dist[u] + weight(u, w) < dist[w] then
                dist[w]<- dist[u] + weight(u, w)
                prev[w] <- u
                Update(Q, w, dist[w])     // rearranges the priority queue
```

- Very very similar structure to Prim's algorithm

- `prev` isn't really needed, but allows us to retrace the shortest paths from `v0`

- as long as the edges have positive weights, Dijkstra's algorithm is globally optimal

Complexity analysis:

$$
\Theta((|V| + |E|) \log(|V|))
$$

- original algorithm, as shown in lectures, with a min-priority queue



but 
$$
\Theta(|E| + |V| \log |V|)
$$

- with a fibonacci heap min priority queue