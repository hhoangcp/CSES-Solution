# Company Queries II - Solution

**ID:** 1688 | **URL:** https://cses.fi/problemset/task/1688

## Approach

### Problem Restatement

A company has $n$ employees forming a tree hierarchy, with employee $1$ as the general director (root). Every other employee has exactly one direct boss. Process $q$ queries, each $(a, b)$ asking for the lowest common boss (Lowest Common Ancestor — LCA) of employees $a$ and $b$.

**Constraints:** $1 \le n, q \le 2 \cdot 10^5$.

### Core idea

Use **binary lifting**: preprocess with a DFS from the root to compute:

- $par[u][i]$: the $2^i$-th ancestor of $u$, with transition $par[u][i] = par[par[u][i-1]][i-1]$, base case $par[u][0]$ being the direct parent.
- $depth[u]$: depth of $u$ from the root.

Set $LOG = 18$ since $n \le 2 \cdot 10^5$.

For an LCA$(u, v)$ query, perform three steps: (1) **equalize depths** — ensure $depth[u] \le depth[v]$ (swap if needed), then lift $v$ up by exactly $h = depth[v] - depth[u]$ steps by jumping along the binary bits of $h$; (2) if now $u = v$, it is already the LCA; (3) otherwise, **binary search for the LCA** — iterate $i$ from $LOG$ down to $0$, and whenever $par[u][i] \ne par[v][i]$, lift both $u$ and $v$ to $par[u][i]$. After the loop $u$ and $v$ sit just below the LCA, so the answer is $par[u][0]$.

**Correctness:** Depth equalization lifts only $v$ (or $u$) toward the root by exactly the depth difference; since $v$ only moves up and never past the LCA (any common ancestor has depth $\le \min(depth[u], depth[v])$), the LCA is unchanged. After this, $u$ and $v$ share the same depth. Let $L = \text{LCA}(u,v)$. In the step-3 loop, if $par[u][i] \ne par[v][i]$ then a $2^i$-step jump has not yet reached a common ancestor (the two results differ), so jumping is safe and does not overshoot $L$; if $par[u][i] = par[v][i]$, jumping might overshoot $L$, so we do not jump. Scanning bits from high to low guarantees that after the loop $u, v$ are at the highest position where they still differ, i.e. just below $L$, hence their parent $par[u][0] = par[v][0] = L$ is the LCA.

### Algorithm

1. Read $n, q$; build the tree's adjacency list from the $n-1$ direct bosses. Set $par[1][0] = 0$, $depth[1] = 0$.
2. DFS from the root $1$:
   - For each $i$ from $1$ to $18$: $par[u][i] = par[par[u][i-1]][i-1]$.
   - For each child $v$ of $u$ (excluding the parent): set $par[v][0] = u$, $depth[v] = depth[u] + 1$, then DFS($v$).
3. For each query $(a, b)$, call LCA$(u, v)$ with $u = a, v = b$:
   - If $depth[u] > depth[v]$, swap $u, v$. Compute $h = depth[v] - depth[u]$; iterate $i$ from $18$ down to $0$, and if bit $i$ of $h$ is set, set $v = par[v][i]$.
   - If $u = v$, return $u$.
   - Iterate $i$ from $18$ down to $0$: if $par[u][i] \ne par[v][i]$, set $u = par[u][i]$, $v = par[v][i]$.
   - Return $par[u][0]$.

### Example

The problem statement gives $n = 5$, $q = 3$, with bosses $e_2 = 1,\ e_3 = 1,\ e_4 = 3,\ e_5 = 3$. Tree: node $1$ is the root; children of $1$ are $\{2, 3\}$; children of $3$ are $\{4, 5\}$.

$depth$: $depth[1]=0,\ depth[2]=1,\ depth[3]=1,\ depth[4]=2,\ depth[5]=2$.

$par[\cdot][0]$: $par[1][0]=0,\ par[2][0]=1,\ par[3][0]=1,\ par[4][0]=3,\ par[5][0]=3$.

$par[\cdot][1]$: $par[1][1]=0,\ par[2][1]=0,\ par[3][1]=0,\ par[4][1]=1,\ par[5][1]=1$.

- Query LCA$(4, 5)$: $depth[4] = depth[5] = 2$, $h = 0$ (no lift). $4 \ne 5$.
  - $i = 1$: $par[4][1] = par[5][1] = 1$, equal $\to$ don't jump.
  - $i = 0$: $par[4][0] = par[5][0] = 3$, equal $\to$ don't jump.
  - Result $par[4][0] = 3$. Print $3$.
- Query LCA$(2, 5)$: $depth[2] = 1 \le depth[5] = 2$, $h = 1$. Lift $v = 5$ by $1$ step: $v = par[5][0] = 3$. $2 \ne 3$.
  - $i = 0$: $par[2][0] = par[3][0] = 1$, equal $\to$ don't jump.
  - Result $par[2][0] = 1$. Print $1$.
- Query LCA$(1, 4)$: $depth[1] = 0 \le depth[4] = 2$, $h = 2 = 2^1$. Lift $v = 4$ by $2$ steps: $v = par[4][1] = 1$. $u = v = 1 \to$ return $1$. Print $1$.

Output: `3`, `1`, `1` — matching the problem's example.

## Complexity

- **Time:** $O((n + q) \log n)$ — preprocessing $O(n \log n)$, each LCA query $O(\log n)$.
- **Memory:** $O(n \log n)$ — the $par$ table of size $n \times (LOG + 1)$ plus the $depth$ array.

## Code (C++)

[Solution Code](../code/Company%20Queries%20II.cpp)
