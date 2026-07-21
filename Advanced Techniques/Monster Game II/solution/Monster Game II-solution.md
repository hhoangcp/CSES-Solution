# Monster Game II - Solution

**ID:** 2085 | **URL:** https://cses.fi/problemset/task/2085

## Approach

### Problem Restatement

Same as Monster Game I: $n$ levels, killing a monster takes $s_i \cdot f$ time, after which you receive a new skill factor. However, the strengths $s_i$ and factors $f_i$ are **not necessarily sorted** — no monotonicity guarantees. Find the minimum total time to win.

### Core Idea

The DP formula is the same as Monster Game I:

$$dp[i] = \min_{j < i} \left( dp[j] + s_i \cdot f_j \right)$$

This is again a minimum of lines $y = f_j \cdot x + dp[j]$ evaluated at $x = s_i$. However, since both slopes $f_j$ and query points $s_i$ can be in any order, deque-based CHT cannot be applied. Instead, we use a **Li Chao Tree**, which supports line insertion and minimum query at any point in $O(\log C)$, without requiring monotonicity.

**Li Chao Tree principle:** A segment tree over domain $[1, C]$ where each node stores one line. When inserting line $P$ into node $[l, r]$ (currently storing $Q$): compare at midpoint $mid$. If $P(mid) < Q(mid)$, swap — the better line at $mid$ stays. The displaced line may still be better on one half: check which side and recurse. For queries, traverse root to leaf and take the minimum over all lines on the path. This works because a line better at $x$ but displaced from a node will be found in the child containing $x$.

### Algorithm

1. Build Li Chao tree over $[1, 10^6]$.
2. Insert initial line $y = C \cdot x + 0$.
3. For each monster $i$:
   - Query at $x = s_i$ → $dp[i]$.
   - Insert line $y = f_i \cdot x + dp[i]$.
4. Output $dp[n]$.

### Example

$n = 5$, $C = 100$. Strengths: $[50, 20, 30, 90, 30]$. Factors: $[60, 20, 20, 10, 90]$.

| $i$ | $s_i$ | $f_i$ | $dp[i]$ | Line added |
|-----|--------|--------|----------|------------|
| 1 | 50 | 60 | $0 + 50 \cdot 100 = 5000$ | $60x + 5000$ |
| 2 | 20 | 20 | $\min(2000, 6200) = 2000$ | $20x + 2000$ |
| 3 | 30 | 20 | $\min(3000, 6800, 2600) = 2600$ | $20x + 2600$ |
| 4 | 90 | 10 | $\min(9000, 10400, 3800, 4400) = 3800$ | $10x + 3800$ |
| 5 | 30 | 90 | $\min(3000, 6800, 2600, 3200, 4100) = 2600$ | — |

Answer: 2600 (kill monster 2 at cost 2000, then monster 5 at cost 600).

## Complexity

- **Time:** $O(n \log C)$ with $C = 10^6$
- **Memory:** $O(C)$ — segment tree with $4 \cdot MAX$ nodes

## Code (C++)

[Solution Code](../code/Monster%20Game%20II.cpp)
