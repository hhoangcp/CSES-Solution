# Finding a Centroid - Solution

**ID:** 2079 | **URL:** https://cses.fi/problemset/task/2079

## Approach

### Problem Restatement

Given a tree with $n$ nodes, find a *centroid*, i.e. a node $c$ such that when $c$ is chosen as the root, every subtree has at most $\lfloor n/2 \rfloor$ nodes.

**Constraints:** $1 \le n \le 2 \cdot 10^5$.

### Core idea

A centroid is a node $c$ such that removing $c$ leaves every connected component with $\le \lfloor n/2 \rfloor$ nodes — equivalently, with $c$ as root every subtree has size $\le \lfloor n/2 \rfloor$.

Two steps:

1. **Compute subtree sizes:** DFS from node $1$ (storing the parent as `lab[v] = u` to avoid walking back up), computing $sz[u]$ = number of nodes in the subtree rooted at $u$: $sz[u] = 1 + \sum_{v \in \text{children}(u)} sz[v]$.
2. **Follow the heavy child:** Starting from node $1$, at each node $u$ if some child $v$ (not the parent) has $sz[v] \cdot 2 > n$, move down to $v$; if no such child exists, $u$ is the centroid.

**Correctness:** At each step there is at most one child with $sz > n/2$, since two such children $v_1, v_2$ would give $sz[v_1] + sz[v_2] > n$, contradicting the fact that the total number of nodes is $n$ (subtrees are disjoint). Hence the downward path is unique. The walk must terminate: each step enters a subtree of size $> n/2$ strictly smaller than the current subtree size, so sizes decrease strictly on a finite tree. When it stops, every child has $sz \le n/2$, and the parent-side piece (if any) has size $n - sz[u] \le n/2$ (because we just arrived from the parent side, meaning $sz[u] > n/2$ at the previous step, so $n - sz[u] < n/2$). Thus $u$ is a centroid.

### Algorithm

1. Read $n$; build the adjacency list from the $n-1$ edges.
2. `DFS(1)` with `lab` initially $0$:
   - $sz[u] = 1$.
   - For each $v \in V[u]$, if $lab[u] \ne v$: set $lab[v] = u$, call `DFS(v)`, then $sz[u] \mathrel{+}= sz[v]$.
3. `Find_Centroid(u)`:
   - For each $v \in V[u]$, if $lab[u] \ne v$ and $sz[v] \cdot 2 > n$, return `Find_Centroid(v)`.
   - Otherwise return $u$.
4. Print `Find_Centroid(1)`.

### Example

The problem statement gives $n = 5$ and edges `1-2, 2-3, 3-4, 3-5`. The tree is a path $1-2-3$ branching at $3$ into $4, 5$.

DFS from node $1$ (parent `lab` shown in parentheses):

| $u$ | $sz[u]$ | Children |
|---|---|---|
| $4$ | $1$ | — |
| $5$ | $1$ | — |
| $3$ | $3$ | $4, 5$ |
| $2$ | $4$ | $3$ |
| $1$ | $5$ | $2$ |

Finding the centroid (threshold $\lfloor n/2 \rfloor = 2$, test $sz[v] \cdot 2 > 5$):

- `Find_Centroid(1)`: child $2$ has $sz[2] \cdot 2 = 8 > 5$ $\to$ move down to $2$.
- `Find_Centroid(2)`: child $3$ has $sz[3] \cdot 2 = 6 > 5$ $\to$ move down to $3$.
- `Find_Centroid(3)`: child $4$ has $sz[4] \cdot 2 = 2 \le 5$, child $5$ has $sz[5] \cdot 2 = 2 \le 5$ $\to$ return $3$.

Result: `3` — matching the problem's example.

## Complexity

- **Time:** $O(n)$ — DFS for $sz$ is $O(n)$; finding the centroid walks a single path, visiting each node at most once.
- **Memory:** $O(n)$ — adjacency list and the $sz$, $lab$ arrays.

## Code (C++)

[Solution Code](../code/Finding%20a%20Centroid.cpp)
