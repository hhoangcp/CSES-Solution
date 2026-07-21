# Tree Distances II - Solution

**ID:** 1133 | **URL:** https://cses.fi/problemset/task/1133

## Approach

### Problem Restatement

Given a tree with $n$ nodes, compute for each node the sum of distances from it to all other nodes.

**Constraints:** $1 \le n \le 2 \cdot 10^5$.

### Core idea

Use rerooting DP in two DFS passes.

**First DFS (compute at temporary root $1$):** For each $u$:

- $sz[u] = 1 + \sum_{v \in \text{children}(u)} sz[v]$ — number of nodes in the subtree of $u$.
- $dp[u] = \sum_{v \in \text{children}(u)} (dp[v] + sz[v])$ — sum of distances from $u$ to all nodes in its subtree.

Explanation of $dp[u]$: for each child $v$, every node $w$ in $v$'s subtree has $d(u, w) = d(v, w) + 1$, so the contribution of $v$'s subtree to $dp[u]$ is $dp[v] + sz[v]$.

**Second DFS (rerooting):** When rerooting from $u$ to child $v$ (making $v$ the new root of the whole tree), the distance from $v$ to each node in $v$'s subtree (under root $1$) **decreases by $1$**, and to each node outside **increases by $1$**. Hence:

$$ans[v] = ans[u] - sz[v] + (n - sz[v])$$

where $sz[v]$ is the size of $v$'s subtree under root $1$ (the original, unchanged value). At each $u$, record $ans[u]$, then apply the formula to compute its children.

**Correctness:** Lemma 1 (induction): $dp[u]$ correctly equals the sum of distances within the subtree of $u$ — every node $w$ in a child $v$'s subtree has $d(u,w)=d(v,w)+1$, contributing exactly $dp[v]+sz[v]$. Lemma 2: when rerooting $u \to v$, exactly $sz[v]$ nodes (inside $v$'s subtree) get closer by $1$, and $n - sz[v]$ nodes (outside) get farther by $1$, so the total changes by $-sz[v] + (n - sz[v])$. Thus $ans[v]$ from the formula equals the sum of distances from $v$ to every node in the tree.

### Algorithm

1. Read $n$; build the adjacency list from the $n-1$ edges.
2. `DFS(u)` (using `lab` to avoid walking back to the parent): $dp[u] = 0,\ sz[u] = 1$; for each child $v$ (`lab[u] != v`): set $lab[v] = u$, call `DFS(v)`, then $dp[u] \mathrel{+}= dp[v] + sz[v]$, $sz[u] \mathrel{+}= sz[v]$.
3. `Rotate(u)`: set $ans[u] = dp[u]$; for each child $v$ (`lab[u] != v`), simulate rerooting by temporarily adjusting then restoring:
   - Remove $v$ from $u$: $dp[u] \mathrel{-}= dp[v] + sz[v]$; $sz[u] \mathrel{-}= sz[v]$ (now $sz[u] = n - sz[v]$, and $dp[u]$ is the sum of distances from $u$ to nodes outside $v$'s subtree).
   - Add $u$ (new) into $v$: $sz[v] \mathrel{+}= sz[u]$; $dp[v] \mathrel{+}= dp[u] + sz[u]$ (each node outside $v$'s subtree is one farther from $v$ than from $u$).
   - Call `Rotate(v)`.
   - Restore: $sz[v] \mathrel{-}= sz[u]$; $dp[v] \mathrel{-}= dp[u] + sz[u]$; $dp[u] \mathrel{+}= dp[v] + sz[v]$; $sz[u] \mathrel{+}= sz[v]$.
4. Call `DFS(1)`, then `Rotate(1)`; print $ans[1..n]$.

### Example

The problem statement gives $n = 5$, edges `1-2, 1-3, 3-4, 3-5`. Tree: $1 \to \{2, 3\}$; $3 \to \{4, 5\}$.

**First DFS (root $1$)** — computing $sz$ and $dp$:

| $u$ | $1$ | $2$ | $3$ | $4$ | $5$ |
|---|---|---|---|---|---|
| $sz[u]$ | $5$ | $1$ | $3$ | $1$ | $1$ |
| $dp[u]$ | $6$ | $0$ | $2$ | $0$ | $0$ |

Check $dp[1] = (dp[2]+sz[2]) + (dp[3]+sz[3]) = (0+1) + (2+3) = 6$ $= 0+1+1+2+2$. ✓

**Second DFS (rerooting)** — applying $ans[v] = ans[u] - sz[v] + (n - sz[v])$:

| Step | $u$ | $v$ | $sz[v]$ | $ans[v] = ans[u] - sz[v] + (5 - sz[v])$ |
|---|---|---|---|---|
| root | — | $1$ | — | $ans[1] = dp[1] = 6$ |
| $1 \to 2$ | $1$ | $2$ | $1$ | $6 - 1 + 4 = 9$ |
| $1 \to 3$ | $1$ | $3$ | $3$ | $6 - 3 + 2 = 5$ |
| $3 \to 4$ | $3$ | $4$ | $1$ | $5 - 1 + 4 = 8$ |
| $3 \to 5$ | $3$ | $5$ | $1$ | $5 - 1 + 4 = 8$ |

Result for nodes $1..5$: `6 9 5 8 8` — matching the problem's example.

## Complexity

- **Time:** $O(n)$ — two DFS passes, each visiting every node and edge exactly once.
- **Memory:** $O(n)$ — adjacency list and the $sz$, $dp$, $ans$, $lab$ arrays.

## Code (C++)

[Solution Code](../code/Tree%20Distances%20II.cpp)
