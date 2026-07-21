# Fixed-Length Paths II - Solution

**ID:** 2081 | **URL:** https://cses.fi/problemset/task/2081

## Approach

### Problem Restatement

Given a tree with $n$ nodes, count the number of simple paths whose length (number of edges) lies in $[k_1, k_2]$.

**Constraints:** $1 \le k_1 \le k_2 \le n \le 2 \cdot 10^5$.

### Core idea

Use post-order DFS combined with **deque merging** and the **small-to-large** technique. For each node $u$, DFS returns a `deque<int> res` storing **suffix sums by depth**: $res[i]$ = number of nodes in the subtree of $u$ at depth $\ge i$ from $u$ (so $res[0]$ = total nodes; $u$ itself is at depth $0$). Initialize $res = \{1\}$.

Thanks to suffix sums, the number of nodes at depth $\le t$ is computed in $O(1)$:

$$\text{Prefix}(res, t) = \begin{cases} 0 & t < 0 \\ res[0] & t+1 \ge |res| \\ res[0] - res[t+1] & \text{otherwise} \end{cases}$$

and the number of nodes at exactly depth $i$ is $res[i] - res[i+1]$ (with $res[|res|]=0$).

When processing child $v$ of $u$: get $up = \text{DFS}(v)$, then `up.push_front(up.front())` to shift all depths by $1$ (adding the edge $v \to u$); the new element at position $0$ equals the total count in $v$'s subtree, so suffix sums are preserved. Then count and merge:

- **Count:** convert $up$ from suffix sums to exact per-depth counts ($up[i] \mathrel{-}= up[i+1]$). For each depth $i$, the number of valid paths pairing a node at depth $i$ (via $v$) with a node at depth $[k_1-i,\ k_2-i]$ in previously processed subtrees (i.e. in $res$) is:

$$ans \mathrel{+}= up[i] \times \bigl(\text{Prefix}(res,\ k_2 - i) - \text{Prefix}(res,\ k_1 - i - 1)\bigr)$$

- **Merge:** convert $up$ back to suffix sums ($up[i] \mathrel{+}= up[i+1]$), then if $|up| > |res|$ `swap(res, up)` (small-to-large), and finally $res[i] \mathrel{+}= up[i]$.

**Correctness:** Each pair $(p, q)$ with LCA $u$ is counted exactly once: pairs with both endpoints in the same child-subtree of $u$ are counted inside the recursive `DFS(v)` call (their LCA is lower); pairs with endpoints in two different child-subtrees (or one endpoint being $u$ itself) are counted when merging the child containing $q$ — at that point $res$ already holds the child containing $p$ plus $u$ itself (at depth $0$). The "query-before-update" order guarantees the two endpoints are always in different subtrees, so no pair is double counted. The `push_front` is correct because it only inserts a new depth-$0$ entry (node $v$ itself, one node) while every old depth shifts by $1$; the suffix sum is preserved since the new element equals the old $up[0]$.

### Algorithm

1. Read $n, k_1, k_2$; build the adjacency list; array `lab` stores the parent to avoid walking back.
2. `Prefix(p, t)`: return $0$ if $t<0$; $p[0]$ if $t+1 \ge |p|$; otherwise $p[0] - p[t+1]$.
3. `Merging(res, up)`:
   - If $|res| < |up|$, `swap(res, up)`.
   - For $i = 0 \dots |up|-2$: $up[i] \mathrel{-}= up[i+1]$ (convert to exact per-depth counts).
   - For $i = 0 \dots |up|-1$: $ans \mathrel{+}= up[i] \cdot (\text{Prefix}(res, k_2 - i) - \text{Prefix}(res, k_1 - i - 1))$.
   - For $i = |up|-2 \dots 0$: $up[i] \mathrel{+}= up[i+1]$ (convert back to suffix sums).
   - For $i = 0 \dots |up|-1$: $res[i] \mathrel{+}= up[i]$.
4. `DFS(u)`:
   - $res = \{1\}$.
   - For each $v \in V[u]$ with $lab[u] \ne v$: set $lab[v] = u$; $up = \text{DFS}(v)$; `up.push_front(up.front())`; `Merging(res, up)`.
   - Return $res$.
5. Call `DFS(1)`, print `ans`.

### Example

The problem statement gives $n = 5$, $k_1 = 2$, $k_2 = 3$, edges `1-2, 2-3, 3-4, 3-5`. The tree is the path $1-2-3$ branching at $3$ into $4, 5$.

The deques store suffix sums ($res[i]$ = number of nodes at depth $\ge i$ from the deque's root). Tracing the code:

> **Note on the order of `swap`:** The table below illustrates the counting formula using `res` **before `swap`** (the currently accumulated, smaller deque) and `up` **after `push_front`** (the deque to be merged, larger) — i.e. "each depth $i$ in `up` pairs with the depth range $[k_1-i,\ k_2-i]$ in $res$". In the code, `Merging` performs `swap(res, up)` **before** counting, so `up` becomes the smaller deque and `res` the larger one; the counting formula then runs the other way: "each depth $i$ in (the now smaller) `up` pairs with the range $[k_1-i,\ k_2-i]$ in (the now larger) $res$". The two formulations give **the same result** because the pair-counting is symmetric (each pair $(p,q)$ is counted once regardless of which side we iterate). The `res before` / `res after` columns in the table refer to the deque named `res` immediately before/after the full `Merging` step (after `swap` and the additive merge).

| Step | `res` before | `up` (after `push_front`) | Count `ans +=` | `res` after |
|---|---|---|---|---|
| `DFS(4)` | — | — | — | $\{1\}$ |
| `DFS(5)` | — | — | — | $\{1\}$ |
| `DFS(3)`, merge child $4$ | $\{1\}$ | $\{1,1\}$ | $0 \cdot (\text{Pref}(\{1\},3)-\text{Pref}(\{1\},1)) + 1 \cdot (\text{Pref}(\{1\},2)-\text{Pref}(\{1\},0)) = 0$ | $\{2,1\}$ |
| `DFS(3)`, merge child $5$ | $\{2,1\}$ | $\{1,1\}$ | $0 \cdot \ldots + 1 \cdot (\text{Pref}(\{2,1\},2)-\text{Pref}(\{2,1\},0)) = 1$ (path $5\leftrightarrow4$) | $\{3,2\}$ |
| `DFS(2)`, merge child $3$ | $\{1\}$ | $\{3,3,2\}$ | $1 \cdot (\text{Pref}(\{3,3,2\},3)-\text{Pref}(\{3,3,2\},1)) = 2$ (paths $2\leftrightarrow4,\ 2\leftrightarrow5$) | $\{4,3,2\}$ |
| `DFS(1)`, merge child $2$ | $\{1\}$ | $\{4,4,3,2\}$ | $1 \cdot (\text{Pref}(\{4,4,3,2\},3)-\text{Pref}(\{4,4,3,2\},1)) = 3$ (paths $1\leftrightarrow3,\ 1\leftrightarrow4,\ 1\leftrightarrow5$) | $\{5,4,3,2\}$ |

Total $ans = 0 + 1 + 2 + 3 = 6$. (Note: at `DFS(3)` merging child $4$, depth $i=1$ pairs with depths $[k_1-1, k_2-1]=[1,2]$ in $res=\{1\}$, which holds only node $3$ at depth $0$, so there are no nodes at depth $1$ or $2$ and the contribution is $0$ — the path $4\leftrightarrow3$ has length $1$, outside $[2,3]$.)

Result: `6` — matching the problem's example.

## Complexity

- **Time:** $O(n \log n)$ — by small-to-large, each time a deque is poured into a larger one the containing deque at least doubles, so each node is copied at most $O(\log n)$ times.
- **Memory:** $O(n)$ — at any moment only the deques along the active DFS path exist.

## Code (C++)

[Solution Code](../code/Fixed-Length%20Paths%20II.cpp)
