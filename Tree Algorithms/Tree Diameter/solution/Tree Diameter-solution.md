# Tree Diameter - Solution

**ID:** 1131 | **URL:** https://cses.fi/problemset/task/1131

## Approach

### Problem Restatement

Given a tree with $n$ nodes. The *diameter* is the maximum distance between any two nodes. Compute the diameter.

**Constraints:** $1 \le n \le 2 \cdot 10^5$.

### Core idea

Use the **two-DFS algorithm**:

1. First DFS from any node (pick node $1$): compute $depth[u]$ and track the node $s$ with maximum $depth$ — the node farthest from $1$.
2. Second DFS from $s$: recompute $depth[u]$ and track the node $t$ farthest from $s$. Then $depth[t]$ is the diameter.

Each DFS uses `lab[v] = u` to avoid walking back to the parent, sets $depth[v] = depth[u] + 1$, and updates `(ans, s)` whenever it sees a larger $depth[v]$.

**Correctness:** Let $a \to b$ be a diameter (length $D$). With $x$ the start node and $s$ the node farthest from $x$, we show $s$ is an endpoint of some diameter. Let $c$ be the branching point where the paths $x \to a$ and $x \to b$ diverge, and $p$ the point where path $s \to x$ meets path $a \to b$. Since $s$ is farthest from $x$, $d(x, s) \ge d(x, a)$ and $d(x, s) \ge d(x, b)$. If $s$ lies on the $a$ side (the $b$ side is symmetric), then $d(s, b) = d(s, p) + d(p, c) + d(c, b) \ge d(a, p) + d(p, c) + d(c, b) \ge d(a, b) = D$ (since $d(s, p) \ge d(a, p)$ because $s$ is farther from $x$ than $a$). But $D$ is the diameter (the maximum possible), so $d(s, b) = D$, hence $s$ is an endpoint of the diameter $s \to b$. Corollary: from the endpoint $s$, the farthest distance is exactly the diameter $D$, so the second DFS from $s$ yields $D$.

### Algorithm

1. Read $n$; build the adjacency list from the $n-1$ edges.
2. Initialize `depth`, `lab` to all $0$; `ans = 0`, `s = 0`.
3. `DFS(u)`: for each $v \in V[u]$ with $lab[u] \ne v$: set $lab[v] = u$, $depth[v] = depth[u] + 1$, call `DFS(v)`; if $ans < depth[v]$, set $ans = depth[v]$, $s = v$.
4. Call `DFS(1)`.
5. Reset `depth[u] = lab[u] = 0` for every $u$ (no need to reset `ans`; the second pass yields a larger value).
6. Call `DFS(s)`.
7. Print `ans`.

### Example

The problem statement gives $n = 5$, edges `1-2, 1-3, 3-4, 3-5`. Tree: $1 \to \{2, 3\}$; $3 \to \{4, 5\}$.

**First DFS (from node $1$)** — depths:

| $u$ | $1$ | $2$ | $3$ | $4$ | $5$ |
|---|---|---|---|---|---|
| $depth[u]$ | $0$ | $1$ | $1$ | $2$ | $2$ |

Farthest node: $depth_{\max} = 2$; pick $s = 4$ (node $5$ is equally far).

**Second DFS (from $s = 4$)** — recomputed depths:

| $u$ | $1$ | $2$ | $3$ | $4$ | $5$ |
|---|---|---|---|---|---|
| $depth[u]$ | $2$ | $3$ | $1$ | $0$ | $2$ |

The node farthest from $4$ is $2$ with $depth = 3$. The diameter is the path $2 \to 1 \to 3 \to 4$ (or $2 \to 1 \to 3 \to 5$), length $3$.

Result: `3` — matching the problem's example.

## Complexity

- **Time:** $O(n)$ — two DFS passes, each visiting every node and edge exactly once.
- **Memory:** $O(n)$ — adjacency list and the $depth$, $lab$ arrays.

## Code (C++)

[Solution Code](../code/Tree%20Diameter.cpp)
