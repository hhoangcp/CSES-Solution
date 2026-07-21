# Book Shop II - Solution

**ID:** 1159 | **URL:** https://cses.fi/problemset/task/1159

## Problem Statement

There are $n$ books, each with price $h_i$, pages $s_i$, and $k_i$ copies. Maximum budget $x$. Find the maximum total pages, buying at most $k_i$ copies of each book.

## Approach

### Bounded knapsack with deque optimization

The transition for book $i$ at capacity $j$ is:

$$dp[i][j] = \max_{0 \leq t \leq k_i} \left( dp[i-1][j - t \cdot h_i] + t \cdot s_i \right)$$

Naively this is $O(n \cdot x \cdot k_i)$. Optimize using the **residue class + deque** technique:

For each book $i$, group capacities by residue $r \in [0, h_i - 1]$. Capacities $r, r + h_i, r + 2h_i, \ldots$ form an arithmetic sequence. Within each group, the transition is a sliding window maximum over at most $k_i + 1$ elements — the deque maintains candidates in decreasing order of their adjusted value $dp[i-1][j'] - j'/h_i \cdot s_i$, removing out-of-window entries from the front and dominated entries from the back.

This reduces each book's processing to $O(x)$ total, giving $O(n \cdot x)$ overall.

### Algorithm

1. Initialize $dp[0][j] = 0$.
2. For each book $i$:
   - If $h_i = 0$: add $k_i \cdot s_i$ pages to all states.
   - Otherwise, for each residue $r \in [0, h_i - 1]$:
     - Process capacities $j = r, r + h_i, r + 2h_i, \ldots$ in order.
     - Deque maintains best candidates; pop front if out of window ($j - \text{front} > k_i \cdot h_i$), pop back if dominated.
     - $dp[i][j] = dp[i-1][\text{front}] + (j - \text{front}) / h_i \cdot s_i$.
3. Answer: $\max_j dp[n][j]$.

### Example

$n = 3$, $x = 10$, prices $[2,6,3]$, pages $[8,5,4]$, copies $[3,5,2]$.

Optimal: 3 copies of book 1 (cost 6, 24 pages) + 1 copy of book 3 (cost 3, 4 pages) = cost 9, **28 pages**.

## Complexity

- **Time:** $O(n \cdot x)$
- **Memory:** $O(n \cdot x)$ (or $O(x)$ with rolling array)

## Code (C++)

[Solution Code](../code/Book%20Shop%20II.cpp)
