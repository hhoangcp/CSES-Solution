# High Score - Solution

**ID:** 1673 | **URL:** https://cses.fi/problemset/task/1673

## Approach

### Problem Restatement

Given a directed graph with $n$ vertices and $m$ edges with arbitrary weights (positive or negative), find the maximum-score path from vertex 1 to vertex $n$ (score = sum of edge weights). Edges may be traversed multiple times. If the score can increase without bound, output $-1$.

### Core Idea

Negate all edge weights: $c' = -c$. A maximum-weight path on the original graph becomes a minimum-weight (shortest) path on the negated graph. A positive cycle on the original graph ($\sum c_i > 0$) becomes a negative cycle on the negated graph ($\sum c'_i < 0$). If a negative cycle exists that is reachable from vertex 1 and can reach vertex $n$, the score is unbounded (loop the positive cycle arbitrarily many times, then proceed to $n$).

Only negative cycles on a path from 1 to $n$ matter. To filter irrelevant cycles, run DFS from vertex $n$ on the **reversed graph** to mark all vertices that can reach $n$. Only consider edges to marked vertices in SPFA — this avoids false detection of negative cycles that cannot affect the 1-to-$n$ path.

If no relevant negative cycle exists, SPFA converges and the answer is $-dist[n]$ (negate back). Otherwise, output $-1$.

### Algorithm

1. **Negate weights** when reading input: store $c' = -c$ for each edge.
2. **DFS from $n$ on reversed graph:** Mark `visited[u] = true` for every vertex that can reach $n$.
3. **SPFA from vertex 1:** Only relax edges to vertices with `visited[v] = true`. Maintain `cnt[v]` (number of times $v$ enters the queue). If `cnt[v] > n`, a relevant negative cycle exists — output $-1$.
4. If SPFA converges, output $-dist[n]$.

### Example

Input:
```
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4
```

Negated weights: $1\to2\ (-3)$, $2\to4\ (1)$, $1\to3\ (2)$, $3\to4\ (-7)$, $1\to4\ (-4)$.

DFS from 4 on reversed graph: all vertices can reach 4, so `visited = {1,2,3,4}`.

SPFA: $dist[1]=0$. Process 1: $dist[2]=-3$, $dist[3]=2$, $dist[4]=-4$. Process 2: $2\to4$ gives $-3+1=-2 > -4$, no update. Process 3: $3\to4$ gives $2+(-7)=-5 < -4$, update $dist[4]=-5$.

No vertex enters queue more than $n$ times. Answer: $-dist[4] = -(-5) = 5$ (path $1\to3\to4$ with original score $-2+7=5$).

Output: `5`

## Complexity

- **Time:** $O(n \cdot m)$ — SPFA worst case.
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/High%20Score.cpp)
