# Static Range Sum Queries - Solution

**ID:** 1646 | **URL:** https://cses.fi/problemset/task/1646

## Approach

### Problem Restatement

Given a static array of $n$ integers, process $q$ queries: what is the sum of values in range $[a, b]$?

### Core idea

Use **prefix sums**. Build array $S$ with $S[0] = 0$ and $S[i] = S[i-1] + x_i$. The sum of range $[a, b]$ is:

$$S[b] - S[a-1] = (x_1 + \cdots + x_{a-1} + x_a + \cdots + x_b) - (x_1 + \cdots + x_{a-1}) = x_a + \cdots + x_b$$

The elements $x_1, \ldots, x_{a-1}$ cancel out, leaving exactly the desired range sum.

Note: with $n \le 2 \cdot 10^5$ and $x_i \le 10^9$, prefix sums can reach $2 \cdot 10^{14}$, exceeding 32-bit range. Use 64-bit integers.

### Algorithm

1. Build prefix sum array: $S[0] = 0$, $S[i] = S[i-1] + x_i$ for $i = 1, \ldots, n$.
2. For each query on range $[a, b]$, output $S[b] - S[a-1]$.

### Example

Input:
```
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
```

Array: $[3, 2, 4, 5, 1, 1, 5, 3]$. Prefix sum: $S = [0, 3, 5, 9, 14, 15, 16, 21, 24]$.

- Sum $[2, 4]$: $S[4] - S[1] = 14 - 3 = 11$.
- Sum $[5, 6]$: $S[6] - S[4] = 16 - 14 = 2$.
- Sum $[1, 8]$: $S[8] - S[0] = 24 - 0 = 24$.
- Sum $[3, 3]$: $S[3] - S[2] = 9 - 5 = 4$.

Output:
```
11
2
24
4
```

## Complexity

- **Time:** $O(n + q)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Static%20Range%20Sum%20Queries.cpp)
