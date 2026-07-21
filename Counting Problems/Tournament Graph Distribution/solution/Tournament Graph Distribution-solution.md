# Tournament Graph Distribution - Solution

**ID:** 3232 | **URL:** https://cses.fi/problemset/task/3232

## Approach

### Problem Restatement

For each $k = 1 \ldots n$, count the number of tournament graphs on $n$ vertices with exactly $k$ strongly connected components. A tournament graph has exactly one directed edge between each pair of vertices. Result modulo $10^9 + 7$.

### Counting strongly connected tournament graphs $T[i]$

The total number of tournament graphs on $i$ vertices is $2^{\binom{i}{2}}$ (each of $\binom{i}{2}$ pairs independently chooses one of two directions). To count only the strongly connected ones, subtract the non-strongly-connected cases:

$$T[i] = 2^{\binom{i}{2}} - \sum_{j=1}^{i-1} \binom{i}{j} \cdot T[j] \cdot 2^{\binom{i-j}{2}}$$

**Why this formula is correct:** A tournament graph fails to be strongly connected if and only if some proper subset $S$ of vertices forms a "sink SCC" — all edges between $S$ and $V \setminus S$ point into $S$. To avoid overcounting, we fix $S$ to contain the vertex with the smallest index. Then:

- $\binom{i}{j}$: choose $j$ vertices for $S$ (including the smallest-indexed vertex — but actually, we don't constrain this in the formula; instead, the formula counts all possible $S$ of size $j$, and each non-strongly-connected tournament has a unique sink SCC, so it's subtracted exactly once).
- $T[j]$: $S$ must form a strongly connected tournament internally.
- $2^{\binom{i-j}{2}}$: the remaining $i - j$ vertices form any tournament (the inter-SCC edges are all forced in one direction, contributing no additional choices).

**No overcounting:** Each non-strongly-connected tournament has exactly one sink SCC (the condensation graph of a tournament is always a DAG, and every DAG has a unique sink). So each graph is subtracted exactly once.

### DP on SCC decomposition

Given $T[s]$, compute $\text{dp}[i][k]$ = number of ways to partition $i$ labeled vertices into $k$ **ordered** groups where the first group contains vertex 1, and each group forms a strongly connected tournament:

$$\text{dp}[i][k] = \sum_{s=1}^{i} \text{dp}[i-s][k-1] \cdot \binom{i-1}{s-1} \cdot T[s]$$

The first group has size $s$ and must contain vertex 1, so we choose $s-1$ additional vertices from the remaining $i-1$.

### Why multiply by $k!$

In a general directed graph, the SCCs form a DAG. But in a tournament, the condensation DAG is itself a tournament — between any two SCCs, all edges point in one direction. An acyclic tournament has a **unique topological order** (Hamiltonian path). So the $k$ SCCs can be arranged in $k!$ orderings, and each ordering uniquely determines all inter-SCC edges (edges always point from earlier to later in topological order). Each ordering produces a distinct graph, so we multiply by $k!$.

$$\text{ans}(k) = \text{dp}[n][k] \cdot k!$$

### Example

**Problem example:** $n = 3$.

$T[1] = 1$, $T[2] = 2^1 - \binom{2}{1} \cdot 1 \cdot 1 = 0$, $T[3] = 2^3 - \binom{3}{1} \cdot 1 \cdot 2 = 2$.

DP table:

| $(i, k)$ | computation | value |
|----------|-------------|-------|
| (3, 1) | $\text{dp}[0][0] \cdot \binom{2}{2} \cdot T[3] = 1 \cdot 1 \cdot 2$ | 2 |
| (3, 2) | all terms 0 (involve $T[2] = 0$) | 0 |
| (3, 3) | $\text{dp}[2][2] \cdot \binom{2}{0} \cdot T[1] = 1 \cdot 1 \cdot 1$ | 1 |

Final results: $k{=}1$: $2 \cdot 1! = \mathbf{2}$, $k{=}2$: $0 \cdot 2! = \mathbf{0}$, $k{=}3$: $1 \cdot 3! = \mathbf{6}$. ✓

Note: $T[2] = 0$ because on 2 vertices, the only tournament with a "sink" is both directions — but a 2-vertex tournament always has a winner and loser, forming a DAG with 2 SCCs.

## Complexity

- **Time:** $O(n^3)$ — $O(n^2)$ for computing $T[i]$ and $O(n^3)$ for the DP.
- **Space:** $O(n^2)$ — for binomial coefficients, powers of 2, $T$, and the DP table.

## Code (C++)

[Solution Code](../code/Tournament%20Graph%20Distribution.cpp)
