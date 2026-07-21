# Subtree Queries - Solution

**ID:** 1137 | **URL:** https://cses.fi/problemset/task/1137

## Approach

### Problem Restatement

Given a rooted tree with $n$ nodes (root is node $1$), each node $u$ having a value $w[u]$. Process $q$ queries:

1. `1 s x`: change the value of node $s$ to $x$.
2. `2 s`: compute the sum of values in the subtree of node $s$.

**Constraints:** $1 \le n, q \le 2 \cdot 10^5$, $1 \le v_i, x \le 10^9$.

### Core idea

Flatten the tree with an Euler tour: DFS from the root, assign $Start[u] = ++Time$ on entry; after visiting all children, assign $End[u] = Time$. The subtree of $u$ then occupies exactly the contiguous segment $[Start[u], End[u]]$ in the visit order.

Build a BIT (Fenwick tree) on the linear array indexed by $Start$ to support **point update — range query**:

- Initialize: for each node $u$, `Update(Start[u], w[u])`.
- Update node $s$ to $x$: `Update(Start[s], x - w[s])`; set $w[s] = x$.
- Query subtree sum of $s$: `Query(End[s]) - Query(Start[s] - 1)`.

**Correctness:** DFS visits $u$ at time $Start[u]$, then traverses its child subtrees one after another (each a contiguous segment), visiting no node outside the subtree of $u$ until it leaves $u$ at $End[u]$. Hence exactly the nodes in the subtree of $u$ have $Start$ inside $[Start[u], End[u]]$, and nodes outside have $Start$ outside this range. Since each node $v$ places its value at position $Start[v]$, the range sum over $[Start[s], End[s]]$ equals the subtree sum of $s$.

### Algorithm

1. Read $n, q$; the value array $w[1..n]$; build the adjacency list (array `lab` to avoid walking back to the parent).
2. `DFS(1)`: $Start[u] = ++Time$; for each child $v$ (`lab[u] != v`), set $lab[v] = u$ and recurse; finally $End[u] = Time$.
3. Initialize the BIT: for each $u$, `Update(Start[u], w[u])`.
4. For each query:
   - Type `1 s x`: `Update(Start[s], x - w[s])`; set $w[s] = x$.
   - Type `2 s`: print `Query(End[s]) - Query(Start[s] - 1)`.

### Example

The problem statement gives $n = 5$, $q = 3$, values $\{4, 2, 5, 2, 1\}$ (nodes $1..5$), edges `1-2, 1-3, 3-4, 3-5`. The root is $1$.

Tree: $1 \to \{2, 3\}$; $3 \to \{4, 5\}$.

DFS assigning $Start/End$:

| $u$ | $Start[u]$ | $End[u]$ | $w[u]$ |
|---|---|---|---|
| $1$ | $1$ | $5$ | $4$ |
| $2$ | $2$ | $2$ | $2$ |
| $3$ | $3$ | $5$ | $5$ |
| $4$ | $4$ | $4$ | $2$ |
| $5$ | $5$ | $5$ | $1$ |

Initialize the BIT: place $w[u]$ at position $Start[u]$, giving the linear array by $Start$: $A[1..5] = [4, 2, 5, 2, 1]$.

- Query `2 3` (subtree of $3$ is $\{3,4,5\}$): `Query(End[3]=5) - Query(Start[3]-1=2)` $= (4+2+5+2+1) - (4+2) = 14 - 6 = 8$. Print `8`.
- Query `1 5 3`: $\Delta = 3 - 1 = 2$; `Update(Start[5]=5, +2)`; $w[5] = 3$. New linear array: $A[5]=3$.
- Query `2 3`: `Query(5) - Query(2)` $= (4+2+5+2+3) - (4+2) = 16 - 6 = 10$. Print `10`.

Output: `8`, `10` — matching the problem's example.

## Complexity

- **Time:** $O(n + q \log n)$ — DFS $O(n)$; BIT initialization $O(n \log n)$; each query $O(\log n)$.
- **Memory:** $O(n)$ — adjacency list, $Start/End/w/lab$ arrays, and the BIT.

## Code (C++)

[Solution Code](../code/Subtree%20Queries.cpp)
