# Tree Matching - Solution

**ID:** 1130 | **URL:** https://cses.fi/problemset/task/1130

## Approach

### Problem Restatement

Given a tree with $n$ nodes. A *matching* is a set of edges where each node is an endpoint of at most one edge. Find the maximum number of edges in a matching.

**Constraints:** $1 \le n \le 2 \cdot 10^5$.

### Core idea

Use tree DP. Pick node $1$ as a temporary root. For each $u$, define two states:

- $dp[u][0]$: maximum matching size in the subtree of $u$ when $u$ is **not** matched with any child.
- $dp[u][1]$: maximum matching size in the subtree of $u$ when $u$ **is** matched with exactly one child.

Transitions (post-order DFS):

- $dp[u][0] = \sum_{v \in \text{children}(u)} \max(dp[v][0], dp[v][1])$ — $u$ matches no child, so each subtree $v$ is independent; pick the better state.
- $dp[u][1] = \max_{w \in \text{children}(u)} \bigl(1 + dp[w][0] + \sum_{v \ne w} \max(dp[v][0], dp[v][1])\bigr)$ — pick exactly one child $w$ to match; $w$ cannot match its own children ($dp[w][0]$), the others are free.

Computing $dp[u][1]$ directly costs $O(\deg(u)^2)$. Let $S = dp[u][0] = \sum_v \max(dp[v][0], dp[v][1])$ and $f[v] = \max(dp[v][0], dp[v][1])$, then:

$$dp[u][1] = 1 + S + \max_{w \in \text{children}(u)} \bigl(dp[w][0] - f[w]\bigr)$$

since $1 + dp[w][0] + (S - f[w]) = 1 + S + (dp[w][0] - f[w])$. The code uses prefix/suffix arrays to obtain $\sum_{v \ne w} f[v] = S - f[w]$ in $O(1)$ per $w$, bringing the total time to $O(n)$. The answer is $\max(dp[1][0], dp[1][1])$.

**Correctness (induction on subtree height):** Leaf: $dp[u][0]=dp[u][1]=0$ is correct. Assume correct for all children $v$. If $u$ matches no child, the subtrees are independent, so the optimum is exactly $\sum_v \max(dp[v][0],dp[v][1])=dp[u][0]$. If $u$ matches exactly one child $w$, edge $(u,w)$ uses $1$ edge, $w$ must not match its children ($dp[w][0]$), and the other subtrees are independent contributing $\sum_{v\ne w}\max(dp[v][0],dp[v][1])$; taking the max over $w$ yields $dp[u][1]$. At the root, picking the better of "matched" and "unmatched" gives $\max(dp[1][0], dp[1][1])$.

### Algorithm

1. Read $n$; build the adjacency list from the $n-1$ edges.
2. `DFS(u)` (using `lab` to avoid walking back to the parent): $dp[u][0] = dp[u][1] = 0$.
   - For each child $v$ (`lab[u] != v`): set $lab[v] = u$, call `DFS(v)`, then $dp[u][0] \mathrel{+}= \max(dp[v][0], dp[v][1])$.
   - Build a prefix array $Left$ over $V[u]$: for each non-parent $v = V[u][i]$, $Left[i] = \max(dp[v][0], dp[v][1])$; if $i>0$, $Left[i] \mathrel{+}= Left[i-1]$ (skip the parent, carrying the previous value).
   - Iterate $i$ from $|V[u]|-1$ down to $0$, maintaining $Right$ = sum of $\max(dp[v][0], dp[v][1])$ for children to the right of $i$: for each child $v = V[u][i]$, update $dp[u][1] = \max\bigl(dp[u][1],\ 1 + dp[v][0] + Right + Left[i-1]\bigr)$ (or $1 + dp[v][0] + Right$ if $i=0$); then $Right \mathrel{+}= \max(dp[v][0], dp[v][1])$.
3. Call `DFS(1)`; print $\max(dp[1][0], dp[1][1])$.

### Example

The problem statement gives $n = 5$, edges `1-2, 1-3, 3-4, 3-5`. Tree: $1 \to \{2, 3\}$; $3 \to \{4, 5\}$.

Post-order DFS computing $dp$:

| $u$ | $dp[u][0]$ | $dp[u][1]$ | Notes |
|---|---|---|---|
| $2$ (leaf) | $0$ | $0$ | no children |
| $4$ (leaf) | $0$ | $0$ | no children |
| $5$ (leaf) | $0$ | $0$ | no children |
| $3$ | $\max(0,0)+\max(0,0)=0$ | $\max(1+dp[4][0],\ 1+dp[5][0])=1$ | match $3$ with $4$ or $5$ |
| $1$ | $\max(0,0)+\max(0,1)=1$ | $\max\bigl(1+dp[2][0]+(S-f[2]),\ 1+dp[3][0]+(S-f[3])\bigr) = \max(1+0+1,\ 1+0+0)=2$ | match $1$ with $2$; the $3$-branch contributes $\max(0,1)=1$ (match $3$ with $4$) |

Detail of $dp[1][1]$: $S = dp[1][0] = 1$, $f[2]=\max(0,0)=0$, $f[3]=\max(0,1)=1$.

- Match $1$ with $2$: $1 + dp[2][0] + (S - f[2]) = 1 + 0 + (1 - 0) = 2$.
- Match $1$ with $3$: $1 + dp[3][0] + (S - f[3]) = 1 + 0 + (1 - 1) = 1$.

$\max = 2$ (match $1$ with $2$; the $3$-branch freely matches $3$ with $4$).

Result: $\max(dp[1][0], dp[1][1]) = \max(1, 2) = 2$. Optimal matching: $(1,2)$ and $(3,4)$. Matches the problem's example.

## Complexity

- **Time:** $O(n)$ — each node $u$ processes $O(\deg(u))$ (building $Left$ and the $Right$ sweep), summing to $O(n)$.
- **Memory:** $O(n)$ — adjacency list, `lab` array, the two-state $dp$ table, and the temporary $Left$ array inside DFS.

## Code (C++)

[Solution Code](../code/Tree%20Matching.cpp)
