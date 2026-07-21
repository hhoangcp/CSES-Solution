# Path Queries II - Solution

**ID:** 2134 | **URL:** https://cses.fi/problemset/task/2134

## Approach

### Problem Restatement

Given a tree with $n$ nodes, each node $u$ having a value $w[u]$. Process $q$ queries:

1. `1 s x`: change the value of node $s$ to $x$.
2. `2 a b`: find the maximum value on the simple path between $a$ and $b$.

**Constraints:** $1 \le n, q \le 2 \cdot 10^5$, $1 \le v_i, x \le 10^9$.

### Core idea

Use **Heavy-Light Decomposition (HLD)** combined with a **segment tree**.

HLD partitions the tree's nodes into **chains** so that the path from any node to the root crosses at most $O(\log n)$ chains. The **heavy child** of a node $u$ is the child with the largest $sz$ (subtree size); the edge to it is a **heavy edge**, the others are **light edges**. Chains run along heavy edges; a light child starts a new chain.

Two DFS passes:

1. First DFS computes $sz[u]$, $depth[u]$, parent $lab[u]$, and reorders the adjacency list so the heavy child is first (it continues the parent's chain).
2. Second DFS (HLD) assigns $chain[u]$ and a linear position $pos[u]$: the heavy child inherits $chain[u]$ ($chain[v]=chain[u]$), a light child starts a new chain ($chain[v]=v$). Nodes on the same chain get contiguous $pos$, so each chain occupies a contiguous segment in the linear array.

Build a segment tree over the $pos$ array supporting point update and range-max query, both $O(\log n)$.

Path-max query $u \to v$: while $u, v$ are on different chains, jump the chain whose **head is deeper** — assuming $depth[chain[v]] \ge depth[chain[u]]$, take the max over $[pos[chain[v]], pos[v]]$ then set $v = lab[chain[v]]$; repeat until they share a chain, then take the max over $[pos[u], pos[v]]$ (with $u$ shallower). Each query crosses $\le O(\log n)$ chains, each range query $O(\log n)$, totaling $O(\log^2 n)$.

**Correctness:** Each jump across a light edge enters a light child, so its $sz \le sz[parent]/2$, i.e. the subtree size containing the current node at least doubles; since $sz \le n$, there are at most $\log_2 n$ light-edge jumps — so the path to the root crosses $\le O(\log n)$ chains. The query algorithm jumps the chain with the deeper head, which moves both $u$ and $v$ up toward the LCA: each step takes the max over the correct segment from the chain head to the current node (lying on the upward path to the LCA); once both are on the same chain, the remaining segment from the shallower to the deeper node is the final piece of the path. Hence the whole path is covered, without overlap or gaps.

### Algorithm

1. Read $n, q$; the array $w[1..n]$; build the adjacency list.
2. `DFS(1)`: $sz[u]=1$; for each $v \in V[u]$ that is not the parent, set $lab[v]=u$, $depth[v]=depth[u]+1$, recurse, then $sz[u] \mathrel{+}= sz[v]$; track the heavy child (index of the child with the largest $sz$); finally `swap` the heavy child to $V[u][0]$.
3. `HLD(u, c)`: $chain[u]=c$; $pos[u] = ++pos[0]$; if $V[u][0]$ is not the parent, `HLD(V[u][0], c)` (continue the chain); for each light child $V[u][i]$ ($i \ge 1$) that is not the parent, call `HLD(v, v)`.
4. Initialize the segment tree: for each $u$, `Update(pos[u], w[u])`.
5. For each query:
   - Type `1 s x`: `Update(pos[s], x)`.
   - Type `2 a b`: while $chain[u] \ne chain[v]$: if $depth[chain[u]] > depth[chain[v]]$, `swap(u, v)`; `mmax = max(mmax, Query(pos[chain[v]], pos[v]))`; $v = lab[chain[v]]$. After the loop, if $depth[u] > depth[v]$, `swap(u, v)`; `mmax = max(mmax, Query(pos[u], pos[v]))`; print `mmax`.

### Example

The problem statement gives $n = 5$, $q = 3$, values $\{2, 4, 1, 3, 3\}$ (nodes $1..5$), edges `1-2, 1-3, 2-4, 2-5`. The root is $1$.

Tree: $1 \to \{2, 3\}$; $2 \to \{4, 5\}$.

DFS computes $sz$: $sz[1]=5,\ sz[2]=3,\ sz[3]=1,\ sz[4]=1,\ sz[5]=1$. The heavy child of $1$ is $2$, the heavy child of $2$ is $4$ (the child with the largest $sz$, pick $4$). $depth$: $0,1,1,2,2$.

HLD assigns chains and positions:

| $u$ | $chain[u]$ | $pos[u]$ | $w[u]$ |
|---|---|---|---|
| $1$ | $1$ | $1$ | $2$ |
| $2$ | $1$ | $2$ | $4$ |
| $4$ | $1$ | $3$ | $3$ |
| $5$ | $5$ | $4$ | $3$ |
| $3$ | $3$ | $5$ | $1$ |

Three chains: $\{1,2,4\}$ (segment $pos\ [1,3]$), $\{3\}$ ($pos\ 5$), $\{5\}$ ($pos\ 4$). Linear array by $pos$: $A[1..5] = [2, 4, 3, 3, 1]$.

Query `2 3 5` (max on path $3 \to 1 \to 2 \to 5$):

| Step | $u$ | $v$ | $chain[u], chain[v]$ | Action | `mmax` |
|---|---|---|---|---|---|
| 1 | $3$ | $5$ | $3,\ 5$ (different; $depth[chain[5]]=2 > depth[chain[3]]=1$) | `Query(pos[5], pos[5]) = A[4]=3`; $v = lab[5] = 2$ | $3$ |
| 2 | $3$ | $2$ | $3,\ 1$ (different; $depth[chain[3]]=1 > depth[chain[2]]=0$ $\Rightarrow$ swap) | `Query(pos[3], pos[3]) = A[5]=1`; $v = lab[3] = 1$ | $3$ |
| 3 | $2$ | $1$ | $1,\ 1$ (same chain; $depth[2] > depth[1]$ $\Rightarrow$ swap) | `Query(pos[1], pos[2]) = max(A[1],A[2]) = max(2,4) = 4` | $4$ |

Result of `2 3 5` $= 4$.

Query `1 2 2`: `Update(pos[2]=2, 2)` $\Rightarrow$ $A[2]=2$.

Query `2 3 5` (path $3 \to 1 \to 2 \to 5$, now $w[2]=2$): same steps give `Query(pos[5],pos[5])=3`, `Query(pos[3],pos[3])=1`, `Query(pos[1],pos[2])=max(2,2)=2`; `mmax = max(3,1,2) = 3`. Result $= 3$.

Output: `4 3` — matching the problem's example.

## Complexity

- **Time:** $O(n + q \log^2 n)$ — building HLD and the segment tree $O(n)$; point update $O(\log n)$; each path query crosses $\le O(\log n)$ chains $\times$ $O(\log n)$ per segment.
- **Memory:** $O(n)$ — adjacency list, HLD arrays ($sz$, $depth$, $chain$, $lab$, $pos$), and the segment tree.

## Code (C++)

[Solution Code](../code/Path%20Queries%20II.cpp)
