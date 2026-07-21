# Counting Paths - Solution

**ID:** 1136 | **URL:** https://cses.fi/problemset/task/1136

## Approach

### Problem Restatement

Given a tree with $n$ nodes and $m$ paths on the tree, compute for each node the number of paths that contain it.

**Constraints:** $1 \le n, m \le 2 \cdot 10^5$.

### Core idea

Traversing each path to add $+1$ to every node on it costs $O(n)$ per path, totaling $O(nm)$ — too slow. Apply a **difference array on the tree** combined with **LCA** to record each path in $O(\log n)$.

For preprocessing, use binary lifting: a DFS from the root (node $1$) computes $par[u][i]$ (the $2^i$-th ancestor) and $depth[u]$, with transition $par[u][i] = par[par[u][i-1]][i-1]$; set $LOG = 18$ since $n \le 2 \cdot 10^5$.

For each path from $u$ to $v$, let $p = \text{LCA}(u, v)$. The path has the form $u \to p \to v$. Record four difference updates:

- $++ans[u]$ and $++ans[v]$: mark both endpoints.
- $--ans[p]$: at $p$ the two branches $u \to p$ and $v \to p$ each contribute $+1$ after propagation ($+2$ total), so subtract $1$ to give $p$ exactly $+1$.
- $--ans[par[p]]$ (only when $p \ne 1$): cancel the $+1$ flow that would otherwise leak above $p$ beyond the path.

After recording all $m$ paths, propagate with a post-order DFS: each node accumulates its children's values, $ans[u] \mathrel{+}= \sum_{v \in \text{children}(u)} ans[v]$.

**Correctness:** Consider the contribution of a single path $a \to b$ with $p = \text{LCA}(a,b)$ to $val[u]$ after propagation. Propagation goes leaves to root, so $val[u] = \text{init}[u] + \sum_{\text{children}} val[\text{child}]$. Nodes on the $a \to p$ branch (except $p$) receive $+1$ from a child along the path and propagate $+1$ up; same for the $b \to p$ branch. At $p$: it receives $+1$ from each branch ($+2$) plus initial $-1$, giving $1$, and propagates $+1$ up. At $par[p]$: it receives $+1$ from $p$ plus initial $-1$, giving $0$, and propagates $0$ up — this stops the flow beyond the path. Nodes not on the path receive no contribution. Hence $val[u] = 1$ exactly when $u$ lies on the path, and $0$ otherwise.

### Algorithm

1. Read $n, m$; build the adjacency list from the $n-1$ edges. Set $par[1][0] = 0$, $depth[1] = 0$.
2. DFS from the root $1$: for each $i$ from $1$ to $18$, $par[u][i] = par[par[u][i-1]][i-1]$; for each child $v$ of $u$ (excluding the parent) set $par[v][0] = u$, $depth[v] = depth[u] + 1$, DFS($v$).
3. LCA$(u, v)$: equalize depths (swap so $depth[u] \le depth[v]$, lift $v$ by $h = depth[v] - depth[u]$ steps along binary bits); if $u = v$ return $u$; otherwise iterate $i$ from $18$ down to $0$, and if $par[u][i] \ne par[v][i]$ lift both; return $par[u][0]$.
4. For each path $(u, v)$: $p = \text{LCA}(u, v)$; do $++ans[u],\ ++ans[v],\ --ans[p]$; if $p \ne 1$, also $--ans[par[p][0]]$.
5. Post-order `DFS2` from the root: for each child $v$ of $u$, call `DFS2(v)` then $ans[u] \mathrel{+}= ans[v]$.
6. Print $ans[1..n]$.

### Example

The problem statement gives $n = 5$, $m = 3$; edges `1-2, 1-3, 3-4, 3-5`; paths `1→3, 2→5, 1→4`. The root is $1$.

Tree: children of $1$ are $\{2, 3\}$; children of $3$ are $\{4, 5\}$.

$depth$: $depth[1]=0,\ depth[2]=1,\ depth[3]=1,\ depth[4]=2,\ depth[5]=2$.

$par[\cdot][0]$: $par[1][0]=0,\ par[2][0]=1,\ par[3][0]=1,\ par[4][0]=3,\ par[5][0]=3$.

Compute LCA for each path:

- $\text{LCA}(1, 3) = 1$ (node $1$ is an ancestor of $3$).
- $\text{LCA}(2, 5) = 1$ (path $2 \to 1 \to 3 \to 5$, meeting at $1$).
- $\text{LCA}(1, 4) = 1$ (node $1$ is an ancestor of $4$).

Difference updates (initially $ans \equiv 0$):

| Path | $p$ | Updates | Net per cell |
|---|---|---|---|
| $1 \to 3$ | $1$ | $+1[1],\ +1[3],\ -1[1]$ ($p=1$ so drop $-1[par]$) | $ans[1]\mathrel{+}=0,\ ans[3]\mathrel{+}=1$ |
| $2 \to 5$ | $1$ | $+1[2],\ +1[5],\ -1[1]$ ($p=1$) | $ans[1]\mathrel{+}=-1,\ ans[2]\mathrel{+}=1,\ ans[5]\mathrel{+}=1$ |
| $1 \to 4$ | $1$ | $+1[1],\ +1[4],\ -1[1]$ ($p=1$) | $ans[1]\mathrel{+}=0,\ ans[4]\mathrel{+}=1$ |

After updates: $ans[1]=-1,\ ans[2]=1,\ ans[3]=1,\ ans[4]=1,\ ans[5]=1$.

Post-order propagation:

- $ans[4] = 1$ (no children).
- $ans[5] = 1$ (no children).
- $ans[3] \mathrel{+}= ans[4] + ans[5] = 1 + 1 + 1 = 3$.
- $ans[2] = 1$ (no children).
- $ans[1] \mathrel{+}= ans[2] + ans[3] = -1 + 1 + 3 = 3$.

Result: `3 1 3 1 1` — matching the problem's example.

## Complexity

- **Time:** $O((n + m) \log n)$ — LCA preprocessing $O(n \log n)$, $m$ LCA queries $O(m \log n)$, propagation $O(n)$.
- **Memory:** $O(n \log n)$ — binary lifting table $par$ of size $n \times (LOG + 1)$, plus $depth$ and $ans$ arrays.

## Code (C++)

[Solution Code](../code/Counting%20Paths.cpp)
