# Hamiltonian Flights - Solution

**ID:** 1690 | **URL:** https://cses.fi/problemset/task/1690

## Approach

### Problem Restatement

Given a directed graph with $n$ cities and $m$ one-way flights, count the number of Hamiltonian paths from city 1 to city $n$ (paths visiting each city exactly once). Output modulo $10^9 + 7$.

### Core Idea

With $n \le 20$, use **bitmask DP**. Define $dp[mask][u]$ = number of ways to be at city $u$ (0-indexed) having visited exactly the set of cities in $mask$ (bit $i$ set means city $i$ visited).

Base case: $dp[1][0] = 1$ (start at city 0, only it visited).

Transition: for each state $(mask, u)$ where bit $u$ is set, and each edge $u \to v$ where bit $v$ is not set in $mask$:

$$dp[mask \mid 2^v][v] \mathrel{+}= dp[mask][u] \pmod{10^9+7}$$

Every Hamiltonian path corresponds to a unique sequence of states with increasing $mask$ values (one new bit per step), so each path is counted exactly once. The path visits all $n$ cities, so the answer is $dp[2^n - 1][n-1]$.

**Optimization:** Since city 0 is always first, bit 0 of $mask$ is always set — only iterate odd $mask$ values. Also, city $n-1$ is always last, so intermediate masks only contain cities $0$ through $n-2$ (at most $n-1$ bits), and the loop bound is $2^{n-1}$.

### Algorithm

1. Convert cities to 0-indexed. Initialize $dp[1][0] = 1$.
2. For each odd $mask$ from 1 to $2^{n-1} - 1$:
   - For each city $u$ where bit $u$ is set in $mask$:
     - For each edge $u \to v$ where bit $v$ is not set in $mask$:
       - $dp[mask \mid 2^v][v] \mathrel{+}= dp[mask][u] \pmod{10^9+7}$.
3. Output $dp[2^n - 1][n-1]$.

### Example

Input:
```
4 6
1 2
1 3
2 3
3 2
2 4
3 4
```

0-indexed edges: $0 \to 1$, $0 \to 2$, $1 \to 2$, $2 \to 1$, $1 \to 3$, $2 \to 3$.

- $dp[\{0\}][0] = 1$
- mask $\{0\}$: $0 \to 1$ → $dp[\{0,1\}][1] = 1$; $0 \to 2$ → $dp[\{0,2\}][2] = 1$
- mask $\{0,1\}$: $1 \to 2$ → $dp[\{0,1,2\}][2] = 1$; $1 \to 3$ → $dp[\{0,1,3\}][3] = 1$
- mask $\{0,2\}$: $2 \to 1$ → $dp[\{0,1,2\}][1] = 1$; $2 \to 3$ → $dp[\{0,2,3\}][3] = 1$
- mask $\{0,1,2\}$: $1 \to 3$ → $dp[\{0,1,2,3\}][3] \mathrel{+}= dp[\{0,1,2\}][1] = 1$; $2 \to 3$ → $dp[\{0,1,2,3\}][3] \mathrel{+}= dp[\{0,1,2\}][2] = 1$. Total: 2.

2 Hamiltonian paths: $1 \to 2 \to 3 \to 4$ and $1 \to 3 \to 2 \to 4$.

Output: `2`

## Complexity

- **Time:** $O(2^n \cdot n^2)$ — $2^n$ masks, each iterating $n$ cities with up to $n$ edges.
- **Space:** $O(2^n \cdot n)$

## Code (C++)

[Solution Code](../code/Hamiltonian%20Flights.cpp)
