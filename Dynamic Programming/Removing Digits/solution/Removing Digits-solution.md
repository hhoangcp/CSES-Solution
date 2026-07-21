# Removing Digits - Solution

**ID:** 1637 | **URL:** https://cses.fi/problemset/task/1637

## Code (C++)

### Problem Restatement

Given a positive integer $n$ ($1 \le n \le 10^6$), find the minimum number of steps to reduce $n$ to 0, where each step subtracts a nonzero digit of the current number.

### Method 1: BFS on Implicit Graph

**Core idea:** Model each integer as a node, with edges $u \to u-d$ for each nonzero digit $d$ of $u$. Since all edges have cost 1, BFS from $n$ finds the shortest path to 0. Let $dist[u]$ be the shortest distance from $n$ to $u$.

**Correctness:** BFS on an unweighted graph always finds shortest paths. Each step subtracting a digit corresponds to an edge, so the BFS path length equals the minimum number of steps.

**Algorithm:**
1. Initialize $dist[n] = 0$, mark $n$ as visited, enqueue $n$.
2. Dequeue node $u$. If $u = 0$, stop.
3. For each nonzero digit $d$ of $u$: if $v = u - d$ is unvisited, set $dist[v] = dist[u] + 1$, mark visited, enqueue $v$.
4. Output $dist[0]$.

### Method 2: Bottom-up DP

**Core idea:** Let $dp[u]$ be the minimum steps to reduce $u$ to 0. Since each subtraction reduces the number (digits $\ge 1$), all subproblems $dp[u-d]$ are solved before $dp[u]$ when computing bottom-up from 0 to $n$:

$$dp[u] = 1 + \min_{d \in \text{digits}(u), d \neq 0} dp[u - d]$$

Base case: $dp[0] = 0$.

**Correctness (optimal substructure):** If the optimal first step subtracts $d^*$, then $dp[u - d^*]$ must be optimal — otherwise combining $d^*$ with a better solution for $u - d^*$ gives fewer steps for $u$, contradicting optimality. Taking the min over all digit choices yields the true optimum.

**Algorithm:**
1. Initialize $dp[0] = 0$, $dp[u] = +\infty$ for $u \ge 1$.
2. For $u = 1$ to $n$: extract digits of $u$, set $dp[u] = 1 + \min(dp[u-d])$ over all nonzero digits $d$.
3. Output $dp[n]$.

### Examples

**BFS example:** $n = 27$. Optimal path: $27 \xrightarrow{-7} 20 \xrightarrow{-2} 18 \xrightarrow{-8} 10 \xrightarrow{-1} 9 \xrightarrow{-9} 0$.

BFS distances from $n = 27$:

| $u$ | Edge | $dist[u]$ |
|-----|------|------|
| 27 | start | 0 |
| 20 | $27 - 7$ | 1 |
| 18 | $20 - 2$ | 2 |
| 10 | $18 - 8$ | 3 |
| 9 | $10 - 1$ | 4 |
| 0 | $9 - 9$ | 5 |

Result: $dist[0] = 5$.

**DP example:** $n = 27$. Compute bottom-up from 0.

Key DP values:

| $u$ | Digits | Best $d$ | $dp[u]$ |
|-----|--------|----------|---------|
| 0 | — | — | 0 |
| 1–9 | itself | itself | 1 |
| 10 | 1 | 1 | $1 + dp[9] = 2$ |
| 18 | 1, 8 | 8 | $1 + dp[10] = 3$ |
| 20 | 2 | 2 | $1 + dp[18] = 4$ |
| 27 | 2, 7 | 7 | $1 + dp[20] = 5$ |

Result: $dp[27] = 5$.

### Comparison

| | BFS | Bottom-up DP |
|---|---|---|
| **Time** | $O(n \log n)$ | $O(n \log n)$ |
| **Space** | $O(n)$ | $O(n)$ |
| **Strength** | Early termination at 0 | Simpler code, no queue needed |
| **Code** | [C++ (BFS)](../code/Removing%20Digits%20-%20BFS.cpp) | [C++ (DP)](../code/Removing%20Digits%20-%20DP.cpp) |

## Complexity

- **Method 1:** $O(n \log n)$ time, $O(n)$ space
- **Method 2:** $O(n \log n)$ time, $O(n)$ space
