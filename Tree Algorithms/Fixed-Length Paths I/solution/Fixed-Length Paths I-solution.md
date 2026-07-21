# Fixed-Length Paths I - Solution

**ID:** 2080 | **URL:** https://cses.fi/problemset/task/2080

## Approach

### Problem Restatement

Given a tree with $n$ nodes, count the number of simple paths whose length is exactly $k$ edges.

**Constraints:** $1 \le k \le n \le 2 \cdot 10^5$.

### Core idea

Use **centroid decomposition**: at each step find the centroid $c$ of the current component, count length-$k$ paths passing through $c$, then recurse on the components left after removing $c$. Every path falls into exactly one of two categories — passing through the centroid $c$ of the current step, or lying entirely inside a component after removing $c$ (the latter is handled by recursion). So counting only the first category gives no double counting or omissions.

A path through $c$ splits into $u \to c$ (length $d_1$) and $c \to v$ (length $d_2$) with $d_1 + d_2 = k$, and $u, v$ must lie in **different subtrees** of $c$ (or one endpoint is $c$ itself). To count without duplication, process the subtrees of $c$ one by one while maintaining `cnt[d]` = number of nodes at depth $d$ from $c$ in subtrees **already processed**; for each new subtree we **query first, then update**:

- Query: for each node at depth $d \le k$ in the subtree, add `cnt[k - d]` to the answer.
- Update: increment `cnt[d]` for nodes at depth $d$ in the subtree.

Initialize `cnt[0] = 1` ($c$ itself at depth $0$), so a path with one endpoint at $c$ is captured via `cnt[k - d] = cnt[0]`.

**Correctness:** Each path has a unique centroid $c$ lying on it — the centroid at the highest decomposition level whose component still contains the whole path. At that level $c$ is on the path so it is counted; at deeper levels the path is split when $c$ is removed, so it is never recounted. For a path $u \to v$ through $c$ (with $u, v$ in different subtrees), when processing the subtree containing $v$, `cnt` already holds the contribution from the subtree containing $u$ (processed earlier), so `cnt[k - d(v,c)] = cnt[d(u,c)] \ge 1` and the path is added exactly once. The "query-before-update" order guarantees the two endpoints are always in different subtrees, so no path is double counted.

### Algorithm

1. Read $n, k$; build the adjacency list. Initialize `cnt[0] = 1` and the removal marker array `cnode[]`.
2. `DFS_sz(u, par)`: compute `subtree_sz[u]`, only traversing nodes not yet removed (`!cnode[v]`).
3. `Find_Centroid(sz, u, par)`: descend into the child $v$ with `subtree_sz[v] * 2 > sz`; return the stopping node.
4. `Get_cnt(u, par, add, depth=1)`: stop when `depth > k`.
   - `add = false` (query): `ans += cnt[k - depth]`.
   - `add = true` (update): `++cnt[depth]`.
   - Update `max_depth = max(max_depth, depth)`, then recurse into non-removed children.
5. `Centroid_Decomposition(u = 1)`:
   - `centroid = Find_Centroid(DFS_sz(u, 0), u, 0)`; mark `cnode[centroid] = true`.
   - `max_depth = 0`. For each non-removed child $v$ of `centroid`: call `Get_cnt(v, centroid, false)` then `Get_cnt(v, centroid, true)`.
   - Clear `cnt` from `max_depth` down to $1$ (avoids resetting the whole array), then recurse `Centroid_Decomposition(v)` on each non-removed child.
6. Print `ans`.

### Example

The problem statement gives $n = 5$, $k = 2$, edges `1-2, 2-3, 3-4, 3-5`. The tree is the path $1-2-3$ branching at $3$ into $4, 5$.

The first centroid is $c = 3$. Set `cnt[0] = 1` (node $3$ itself).

| Subtree (via child of $3$) | Nodes (depth) | Query `ans += cnt[k-d]` | Update `cnt` |
|---|---|---|---|
| via $2$ | $2(d{=}1)$, $1(d{=}2)$ | $d{=}1$: `cnt[1]=0`; $d{=}2$: `cnt[0]=1` $\Rightarrow$ `ans=1` (path $1\leftrightarrow 3$: $1-2-3$) | `cnt[1]+=1`, `cnt[2]+=1` |
| via $4$ | $4(d{=}1)$ | $d{=}1$: `cnt[1]=1` $\Rightarrow$ `ans=2` (path $4\leftrightarrow 2$: $4-3-2$) | `cnt[1]+=1` |
| via $5$ | $5(d{=}1)$ | $d{=}1$: `cnt[1]=2` $\Rightarrow$ `ans=4` (paths $5\leftrightarrow 2$: $5-3-2$ and $5\leftrightarrow 4$: $5-3-4$) | `cnt[1]+=1` |

Final `cnt`: `cnt[0]=1, cnt[1]=3, cnt[2]=1`. Total through centroid $3$ is $4$.

Recurse into the components after removing $3$: $\{1, 2\}$ (the only distance is $1$), and singletons $\{4\}, \{5\}$ — none contribute a length-$2$ path.

Result: `4` — matching the problem's example.

## Complexity

- **Time:** $O(n \log n)$ — centroid decomposition has height $O(\log n)$; each node appears in $O(\log n)$ levels and is DFSed once per level, with each `cnt` operation $O(1)$.
- **Memory:** $O(n)$ — adjacency list and the `subtree_sz`, `cnt`, `cnode` arrays.

## Code (C++)

[Solution Code](../code/Fixed-Length%20Paths%20I.cpp)
