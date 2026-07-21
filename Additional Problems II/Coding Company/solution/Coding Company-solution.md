# Coding Company - Solution

**ID:** 1665 | **URL:** https://cses.fi/problemset/task/1665

## Problem Statement

Given $n$ programmers with skill levels, partition them into groups (any partition) such that the total penalty is at most $x$. A group's penalty is the difference between the highest and lowest skill in the group. Count the number of valid partitions modulo $10^9 + 7$.

## Approach

### Sorting + open groups

Sort skills: $a_1 \leq a_2 \leq \cdots \leq a_n$. After sorting, every group in an optimal partition consists of consecutive elements (if a group skips $a_k$ between $a_i$ and $a_j$, moving $a_k$ into the group doesn't increase the penalty since $a_k$ lies between $a_i$ and $a_j$).

Process elements in order. An **open group** has a minimum element but no maximum yet. When advancing from $a_{i-1}$ to $a_i$, every open group's range widens by $a_i - a_{i-1}$, so the total penalty increases by $j \cdot (a_i - a_{i-1})$ where $j$ is the number of open groups.

### DP state and transitions

$dp[j][k]$ = number of ways with $j$ open groups and total penalty $k$ (offset by 5000). When adding programmer $i$:

1. **Open new group** ($j \to j+1$): $a_i$ starts a new group. $dp[j+1][k + j \cdot d] \mathrel{+}= dp[j][k]$.
2. **Join open group** ($j$ unchanged): $a_i$ joins one of $j$ groups without closing. $dp[j][k + j \cdot d] \mathrel{+}= j \cdot dp[j][k]$.
3. **Close group** ($j \to j-1$): $a_i$ closes one of $j$ groups. $dp[j-1][k + j \cdot d] \mathrel{+}= j \cdot dp[j][k]$.
4. **Singleton** ($j$ unchanged): $a_i$ is a group by itself (open and close). $dp[j][k + j \cdot d] \mathrel{+}= dp[j][k]$.

Where $d = a_i - a_{i-1}$. Cases 2+4 can be combined as $(j + 1) \cdot dp[j][k]$.

Answer: $\sum_{t=0}^{x} dp[0][5000 + t]$ (0 open groups = all closed, penalty $\leq x$).

### Example

$n = 3, x = 2$, skills: $[2, 3, 5]$. Valid partitions:

- $\{2, 3\}, \{5\}$: penalty = $(3-2) + 0 = 1$
- $\{2\}, \{3, 5\}$: penalty = $0 + (5-3) = 2$
- $\{2\}, \{3\}, \{5\}$: penalty = $0$

Total: **3** ways.

## Complexity

- **Time:** $O(n^2 \cdot x)$
- **Memory:** $O(n \cdot x)$ (or $O(n \cdot x)$ with rolling array)

## Code (C++)

[Solution Code](../code/Coding%20Company.cpp)
