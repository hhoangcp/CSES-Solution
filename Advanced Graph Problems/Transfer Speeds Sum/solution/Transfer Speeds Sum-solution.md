# Transfer Speeds Sum - Solution

**ID:** 3111 | **URL:** https://cses.fi/problemset/task/3111

## Approach

### Problem Restatement

Given a tree with $n$ nodes where each edge has a transfer speed, let $d(a,b)$ be the minimum edge weight on the path from $a$ to $b$. Compute $\sum_{1 \leq a < b \leq n} d(a,b)$.

### Core idea

Sort edges by weight in decreasing order and process with union-find. When edge $e = (u, v, w)$ connects two components of sizes $|A|$ and $|B|$, exactly $|A| \times |B|$ new pairs become connected, and each has $d(a,b) = w$: since all heavier edges were already added, $e$ is the lightest (bottleneck) on every newly-connected path. Each pair $(a,b)$ is counted exactly once — at the step where its bottleneck edge is processed (the lightest edge on its path), because before that step $a$ and $b$ are in separate components, and after that step they are already joined. Total sum $= \sum_e |A_e| \times |B_e| \times w_e$.

### Algorithm

1. Sort all $n-1$ edges by weight in decreasing order.
2. Initialize union-find: each node is its own component of size 1.
3. For each edge $(u, v, w)$ in sorted order:
   - $|A|$ = size of $u$'s component, $|B|$ = size of $v$'s component.
   - Add $|A| \times |B| \times w$ to the answer.
   - Union $u$ and $v$.
4. Output the answer.

### Example

$n=4$, edges: (1,2,5), (2,3,1), (2,4,2). Sort decreasing: (1,2,5), (2,4,2), (2,3,1).

- (1,2,5): $|A|=1, |B|=1$, contribution $5$. Component: {1,2}.
- (2,4,2): $|A|=2, |B|=1$, contribution $4$. Component: {1,2,4}.
- (2,3,1): $|A|=3, |B|=1$, contribution $3$. Component: {1,2,3,4}.

Total: $5 + 4 + 3 = 12$.

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Transfer%20Speeds%20Sum.cpp)
