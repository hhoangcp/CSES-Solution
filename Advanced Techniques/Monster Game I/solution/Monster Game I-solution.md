# Monster Game I - Solution

**ID:** 2084 | **URL:** https://cses.fi/problemset/task/2084

## Approach

### Problem Restatement

You are playing a game with $n$ levels. Each level has a monster. On levels $1, \ldots, n-1$, you can kill or escape the monster. On level $n$, you must kill the final monster. Killing a monster takes $s \cdot f$ time ($s$ = strength, $f$ = skill factor). After killing, you receive a new skill factor. Find the minimum total time to win.

### Core Idea

Define $dp[i]$ = minimum time to have just killed monster $i$ (factor updated to $f_i$). The transition:

$$dp[i] = \min_{j < i} \left( dp[j] + s_i \cdot f_j \right)$$

where $j=0$ represents the initial state with $dp[0]=0$, $f_0 = C$. This has the form $\min_j (f_j \cdot x + dp[j])$ evaluated at $x = s_i$ — a minimum of lines, solvable with **Convex Hull Trick (CHT)**.

**Why deque-based CHT works:** The problem guarantees slopes $f_j$ are non-increasing and queries $s_i$ are non-decreasing. Non-increasing slopes mean new lines are inserted at the back of the deque. Non-decreasing queries mean the optimal line only shifts forward — if the front line is worse than the next line at $x = s_i$, it will be worse for all future queries, so it can be safely popped.

When inserting a new line $P$ at the back, we remove the previous back line $B$ if it becomes useless: three consecutive lines $A, B, P$ make $B$ useless when the intersection of $A, P$ is at or left of the intersection of $A, B$ (checked via cross-product to avoid floating point).

### Algorithm

1. Insert initial line $y = C \cdot x + 0$ into deque.
2. For each monster $i$ from 1 to $n$:
   - **Query:** while deque has $\ge 2$ lines and the front gives $\ge$ the second at $x = s_i$, pop front. Set $dp[i] = \text{front}.get\_Y(s_i)$.
   - **Insert:** while deque has $\ge 2$ lines and cross-product of last 3 lines indicates the second-to-last is useless, pop back. Insert line $y = f_i \cdot x + dp[i]$.
3. Output $dp[n]$.

### Example

$n = 5$, $C = 100$. Strengths: $[20, 30, 30, 50, 90]$. Factors: $[90, 60, 20, 20, 10]$.

| $i$ | $s_i$ | Deque lines (before query) | $dp[i]$ | Line added |
|-----|--------|---------------------------|---------|------------|
| 1 | 20 | $(100, 0)$ | $100 \cdot 20 = 2000$ | $(90, 2000)$ |
| 2 | 30 | $(100, 0), (90, 2000)$ | $\min(3000, 4700) = 3000$ | $(60, 3000)$ |
| 3 | 30 | $(100, 0), (60, 3000)$ | $\min(3000, 4800) = 3000$ | $(20, 3000)$ |
| 4 | 50 | $(100, 0), (20, 3000)$ | $\min(5000, 4000) = 4000$ | $(20, 4000)$ |
| 5 | 90 | $(20, 3000), (20, 4000)$ | $20 \cdot 90 + 3000 = 4800$ | — |

Note: at $i=2$, line $(90,2000)$ is popped because $(60,3000)$ dominates it. At $i=3$, line $(60,3000)$ is popped similarly. At $i=4$, line $(100,0)$ is popped from front since $(20,3000)$ is better at $x=50$.

Answer: 4800 (kill monster 3, then monster 5).

## Complexity

- **Time:** $O(n)$ — each line inserted and removed at most once.
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Monster%20Game%20I.cpp)
