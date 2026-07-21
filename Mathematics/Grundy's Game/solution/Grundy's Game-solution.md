# Grundy's Game - Solution

**ID:** 2207 | **URL:** https://cses.fi/problemset/task/2207

## Approach

### Problem Restatement

There is a heap of $n$ coins. Two players alternate turns, each choosing a heap with at least 3 coins and splitting it into two non-empty heaps of **different** sizes. The last player to move wins. Determine the winner when both play optimally.

### Core idea

This is an impartial combinatorial game, so **Sprague-Grundy theory** applies. A pile of size $n$ can be split into $(j, n-j)$ where $1 \le j < n/2$ and $j \neq n-j$. After splitting, the two piles form a **disjunctive sum** of independent subgames. The Grundy value is:

$$G(n) = \text{mex}\{G(j) \oplus G(n-j) : 1 \le j < n/2\}$$

Base cases: $G(0) = G(1) = G(2) = 0$ (no valid splits). The first player wins if and only if $G(n) \neq 0$.

**Empirical observation:** $G(n) = 0$ occurs only for finitely many small values of $n$. The last losing position is $n = 1222$; for all $n > 1222$, $G(n) > 0$. This happens because for large $n$, the number of possible splits grows rapidly, producing a rich set of Nim-sums that always includes 0, so $\text{mex}$ never returns 0.

Therefore, we precompute $G(n)$ for $n < 2000$ (a safe upper bound above 1222) and conclude the first player always wins for $n \geq 2000$.

### Algorithm

1. Precompute $G(n)$ for $n = 0, 1, \ldots, 1999$ using the mex definition.
2. For each query $n$: if $n \geq 2000$ or $G(n) \neq 0$, output "first"; otherwise output "second".

### Example

Computing the first few Grundy values:

| $n$ | Splits | Nim-sums | $G(n)$ |
|-----|--------|----------|--------|
| 3 | $(1,2)$ | $\{0\}$ | 1 |
| 4 | $(1,3)$ | $\{1\}$ | 0 |
| 5 | $(1,4),(2,3)$ | $\{0,1\}$ | 2 |
| 6 | $(1,5),(2,4)$ | $\{2,0\}$ | 1 |
| 7 | $(1,6),(2,5),(3,4)$ | $\{1,2\}$ | 0 |
| 8 | $(1,7),(2,6),(3,5)$ | $\{0,1,3\}$ | 2 |

From the problem's sample: $n = 6, 7, 8$.

- $G(6) = 1 \neq 0$ → "first"
- $G(7) = 0$ → "second"
- $G(8) = 2 \neq 0$ → "first"

## Complexity

- **Time:** $O(N^2)$ precomputation where $N = 2000$, $O(1)$ per query
- **Space:** $O(N)$

## Code (C++)

[Solution Code](../code/Grundy%27s%20Game.cpp)
