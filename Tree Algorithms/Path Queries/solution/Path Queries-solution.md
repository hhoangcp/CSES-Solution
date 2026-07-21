# Path Queries - Solution

**ID:** 1138 | **URL:** https://cses.fi/problemset/task/1138

## Approach

### Problem Restatement

Given a rooted tree with $n$ nodes (root is node $1$), each node $u$ having a value $w[u]$. Process $q$ queries:

1. `1 s x`: change the value of node $s$ to $x$.
2. `2 s`: compute the sum of values on the path from the root to $s$.

**Constraints:** $1 \le n, q \le 2 \cdot 10^5$, $1 \le v_i, x \le 10^9$.

### Core idea

The sum on the path root $\to v$ is the sum of the values of all ancestors of $v$ (including $v$). So the value $w[u]$ of a node $u$ affects the path sum of **every node in the subtree** of $u$ (since $u$ is their ancestor). Treating the root $\to v$ query as a point query at $v$, updating $w[u]$ becomes a range update over the subtree of $u$.

Flatten the tree with an Euler tour: DFS from the root, assigning $Start[u]$ (entry time) and $End[u]$ (exit time); the subtree of $u$ occupies $[Start[u], End[u]]$. Use a difference BIT for **range update — point query**: when $w[u]$ changes by $\Delta$, do `Update(Start[u], +Δ)` and `Update(End[u]+1, -Δ)`. The prefix sum at position $Start[v]$, i.e. `Query(Start[v])`, then equals the sum of values of all ancestors of $v$.

**Correctness:** $w[u]$ is added at $Start[u]$ and subtracted at $End[u]+1$, so it contributes to the prefix sum at position $p$ iff $Start[u] \le p \le End[u]$. Setting $p = Start[v]$, this condition holds exactly when $v$ lies in the subtree of $u$, i.e. $u$ is an ancestor of $v$. Hence `Query(Start[v])` adds exactly the contributions of the ancestors (including $v$); a non-ancestor node either has $Start[u] > Start[v]$ (not yet added) or $End[u]+1 \le Start[v]$ (already subtracted).

### Algorithm

1. Read $n, q$; the value array $w[1..n]$; build the adjacency list (array `lab` to avoid walking back to the parent).
2. `DFS(1)`: $Start[u] = ++Time$; for each child $v$ (`lab[u] != v`), set $lab[v] = u$ and recurse; finally $End[u] = Time$.
3. Initialize the BIT: for each $u$, `Update(Start[u], w[u])` and `Update(End[u]+1, -w[u])`.
4. For each query:
   - Type `1 s x`: $\Delta = x - w[s]$; `Update(Start[s], Δ)`; `Update(End[s]+1, -Δ)`; set $w[s] = x$.
   - Type `2 s`: print `Query(Start[s])`.

### Example

The problem statement gives $n = 5$, $q = 3$, values $\{4, 2, 5, 2, 1\}$ (nodes $1..5$), edges `1-2, 1-3, 3-4, 3-5`. The root is $1$.

DFS (with adjacency order `V[1]=[2,3]`, `V[3]=[1,4,5]`):

| $u$ | $Start[u]$ | $End[u]$ | $w[u]$ |
|---|---|---|---|
| $1$ | $1$ | $5$ | $4$ |
| $2$ | $2$ | $2$ | $2$ |
| $3$ | $3$ | $5$ | $5$ |
| $4$ | $4$ | $4$ | $2$ |
| $5$ | $5$ | $5$ | $1$ |

Initialize the BIT (add at $Start[u]$, subtract at $End[u]+1$):

| $u$ | $+w[u]$ at | $-w[u]$ at |
|---|---|---|
| $1$ | $1$ | $6$ |
| $2$ | $2$ | $3$ |
| $3$ | $3$ | $6$ |
| $4$ | $4$ | $5$ |
| $5$ | $5$ | $6$ |

Difference array $d[1..6]$: $[+4,\ +2,\ +3(=5-2),\ +2,\ -1(=1-2),\ -10(=-4-5-1)]$.

- Query `2 4`: `Query(Start[4]=4)` $= 4+2+3+2 = 11$ $= w[1]+w[3]+w[4] = 4+5+2$. Print `11`.
- Query `1 3 2`: $\Delta = 2 - 5 = -3$; `Update(3, -3)`, `Update(6, +3)`; $w[3] = 2$. New difference array: $d[3]=0$, $d[6]=-7$.
- Query `2 4`: `Query(4)` $= 4+2+0+2 = 8$ $= w[1]+w[3]+w[4] = 4+2+2$. Print `8`.

Output: `11`, `8` — matching the problem's example.

## Complexity

- **Time:** $O(n + q \log n)$ — DFS $O(n)$; BIT initialization $O(n \log n)$; each query $O(\log n)$.
- **Memory:** $O(n)$ — adjacency list, $Start/End/w/lab$ arrays, and the BIT.

## Code (C++)

[Solution Code](../code/Path%20Queries.cpp)
