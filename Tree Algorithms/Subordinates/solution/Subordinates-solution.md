# Subordinates - Solution

**ID:** 1674 | **URL:** https://cses.fi/problemset/task/1674

## Approach

### Problem Restatement

Given the structure of a company with $n$ employees, where employee $1$ is the general director. For each employee $i$ ($2 \le i \le n$) you are given their direct boss. Compute for each employee the number of their subordinates (direct and indirect).

**Constraints:** $1 \le n \le 2 \cdot 10^5$.

### Core idea

The company structure is a **rooted tree** with employee $1$ as root (every non-root employee has exactly one direct boss). The number of subordinates of employee $u$ is exactly the **subtree size of $u$ minus 1** (excluding $u$ itself).

Define $sz[u]$ = number of nodes in the subtree rooted at $u$ (including $u$). Compute $sz$ with a post-order DFS:

$$sz[u] = 1 + \sum_{v \in \text{children}(u)} sz[v]$$

since the subtree of $u$ consists of $u$ plus the (disjoint) union of the subtrees of its children $v$. The answer for employee $u$ is $sz[u] - 1$.

**Correctness (induction on subtree height):** A leaf has no children, so $sz = 1$, correctly counting only itself. For an internal node, assume the claim holds for every child $v$; since every node other than $u$ has exactly one parent, the child subtrees are disjoint, so $|T_u| = 1 + \sum_v |T_v| = 1 + \sum_v sz[v] = sz[u]$. Hence $sz[u]$ equals the number of nodes in the subtree of $u$, and the subordinate count of $u$ is $sz[u] - 1$.

### Algorithm

1. Read $n$; for each employee $i$ from $2$ to $n$, read their boss $p$ and add a directed edge $p \to i$ to the adjacency list (only the parent-to-child direction is needed).
2. `DFS(u)`: set $sz[u] = 1$; for each child $v \in V[u]$, call `DFS(v)` then $sz[u] \mathrel{+}= sz[v]$.
3. Call `DFS(1)`; print $sz[i] - 1$ for $i = 1 \dots n$.

### Example

The problem statement gives $n = 5$, with the bosses of employees $2..5$ being `1 1 2 3`.

Tree (parent $\to$ child): $1 \to \{2, 3\}$; $2 \to \{4\}$; $3 \to \{5\}$.

Post-order DFS computing $sz$:

| $u$ | Computation of $sz[u]$ | $sz[u]$ | Subordinates $sz[u]-1$ |
|---|---|---|---|
| $4$ (leaf) | $1$ | $1$ | $0$ |
| $5$ (leaf) | $1$ | $1$ | $0$ |
| $2$ | $1 + sz[4] = 1 + 1$ | $2$ | $1$ |
| $3$ | $1 + sz[5] = 1 + 1$ | $2$ | $1$ |
| $1$ | $1 + sz[2] + sz[3] = 1 + 2 + 2$ | $5$ | $4$ |

Result for employees $1..5$: `4 1 1 0 0` — matching the problem's example.

## Complexity

- **Time:** $O(n)$ — every node and edge is visited exactly once by the DFS.
- **Memory:** $O(n)$ — adjacency list and the $sz$ array.

## Code (C++)

[Solution Code](../code/Subordinates.cpp)
