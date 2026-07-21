# Distance Queries - Solution

**ID:** 1135 | **URL:** https://cses.fi/problemset/task/1135

## Approach

### Problem Restatement

Given a tree with $n$ nodes, process $q$ queries, each asking for the distance (number of edges on the shortest path) between two nodes $a$ and $b$.

**Constraints:** $1 \le n, q \le 2 \cdot 10^5$.

### Core idea

In a tree the unique path between $u$ and $v$ has the form $u \to \text{LCA}(u,v) \to v$: go up from $u$ to the lowest common ancestor $p = \text{LCA}(u,v)$, then go down to $v$. Counting edges:

- Segment $u \to p$: $depth[u] - depth[p]$.
- Segment $p \to v$: $depth[v] - depth[p]$.

Total:

$$\text{dist}(u, v) = depth[u] + depth[v] - 2 \cdot depth[\text{LCA}(u, v)]$$

So the task reduces to computing the LCA quickly. Use **binary lifting**: a DFS from the root (node $1$) computes $par[u][i]$ (the $2^i$-th ancestor) with transition $par[u][i] = par[par[u][i-1]][i-1]$ and $depth[u]$; set $LOG = 18$ since $n \le 2 \cdot 10^5$. Each LCA query costs $O(\log n)$.

**Correctness:** The path in a tree is unique, so $\text{dist}(u,v)$ equals the number of edges on $u \to v$. This path must pass through $p = \text{LCA}(u,v)$: going through a higher ancestor adds an extra up-down detour and makes the path longer (a tree has no cycle to shortcut it), while a lower ancestor is not a common ancestor of both $u$ and $v$ and cannot lead from $u$ to $v$. Hence the path has the form $u \to p \to v$, and the total edge count is exactly $depth[u] + depth[v] - 2 \cdot depth[p]$.

### Algorithm

1. Read $n, q$; build the adjacency list from the $n-1$ edges. Set $par[1][0] = 0$, $depth[1] = 0$.
2. DFS from the root $1$:
   - For each $i$ from $1$ to $18$: $par[u][i] = par[par[u][i-1]][i-1]$.
   - For each child $v$ of $u$ (excluding the parent): set $par[v][0] = u$, $depth[v] = depth[u] + 1$, then DFS($v$).
3. LCA$(u, v)$:
   - If $depth[u] > depth[v]$, swap $u, v$. Compute $h = depth[v] - depth[u]$; iterate $i$ from $18$ down to $0$, and if bit $i$ of $h$ is set, set $v = par[v][i]$.
   - If $u = v$, return $u$.
   - Iterate $i$ from $18$ down to $0$: if $par[u][i] \ne par[v][i]$, set $u = par[u][i]$, $v = par[v][i]$.
   - Return $par[u][0]$.
4. For each query $(a, b)$: print $depth[a] + depth[b] - 2 \cdot depth[\text{LCA}(a, b)]$.

### Example

The problem statement gives $n = 5$, $q = 3$; edges `1-2, 1-3, 3-4, 3-5`. The root is $1$.

Tree: children of $1$ are $\{2, 3\}$; children of $3$ are $\{4, 5\}$.

$depth$: $depth[1]=0,\ depth[2]=1,\ depth[3]=1,\ depth[4]=2,\ depth[5]=2$.

$par[\cdot][0]$: $par[1][0]=0,\ par[2][0]=1,\ par[3][0]=1,\ par[4][0]=3,\ par[5][0]=3$.

| Query | $p = \text{LCA}$ | Computation | Result |
|---|---|---|---|
| $\text{dist}(1, 3)$ | $\text{LCA}(1,3)=1$ | $0 + 1 - 2 \cdot 0 = 1$ | $1$ |
| $\text{dist}(2, 5)$ | $\text{LCA}(2,5)=1$ | $1 + 2 - 2 \cdot 0 = 3$ | $3$ |
| $\text{dist}(1, 4)$ | $\text{LCA}(1,4)=1$ | $0 + 2 - 2 \cdot 0 = 2$ | $2$ |

Output: `1`, `3`, `2` — matching the problem's example.

## Complexity

- **Time:** $O((n + q) \log n)$ — preprocessing $O(n \log n)$, each LCA query $O(\log n)$.
- **Memory:** $O(n \log n)$ — binary lifting table $par$ of size $n \times (LOG + 1)$ plus the $depth$ array.

## Code (C++)

[Solution Code](../code/Distance%20Queries.cpp)
