# Sum of Four Squares - Solution

**ID:** 3355 | **URL:** https://cses.fi/problemset/task/3355

## Approach

### Problem Restatement

Given a non-negative integer $n$ ($0 \le n \le 10^7$), find four non-negative integers $a, b, c, d$ such that $n = a^2 + b^2 + c^2 + d^2$. There are up to $t = 1000$ test cases, with the sum of all $n$ at most $10^7$.

### Core idea

**Lagrange's Four-Square Theorem (1770):** Every non-negative integer can be represented as the sum of four squares. This guarantees a solution always exists.

Decompose $n = s_1 + s_2$ where both $s_1$ and $s_2$ are sums of two squares. If $s_1 = a^2 + b^2$ and $s_2 = c^2 + d^2$, then $n = a^2 + b^2 + c^2 + d^2$.

**Why a valid split always exists:** By Lagrange's theorem, $n = a^2 + b^2 + c^2 + d^2$. Setting $s_1 = a^2 + b^2$ and $s_2 = c^2 + d^2$ gives $n = s_1 + s_2$ where both are sums of two squares. The linear scan from $0$ to $n$ will find this split.

**Precomputation:** For all $s \le 10^7$, compute $avail[s]$ (whether $s$ is a sum of two squares) and $sum[s]$ (a pair $(a, b)$ with $s = a^2 + b^2$). Iterate $i, j \ge 0$ with $i^2 + j^2 \le 10^7$, marking $avail[i^2 + j^2] = \text{true}$ and storing $sum[i^2 + j^2] = (i, j)$.

### Algorithm

1. **Precompute:** For all $i, j \ge 0$ with $i^2 + j^2 \le 10^7$: set $avail[i^2+j^2] = \text{true}$, $sum[i^2+j^2] = (i, j)$.
2. **Query:** For each $n$, iterate $i$ from $0$ to $n$. If $avail[i]$ and $avail[n-i]$ are both true, output $sum[i]$ and $sum[n-i]$.

### Example

$n = 30$: scan finds $i = 1$ with $avail[1] = \text{true}$ ($1 = 1^2 + 0^2$) and $avail[29] = \text{true}$ ($29 = 5^2 + 2^2$). Result: $1, 0, 5, 2$ ($1 + 0 + 25 + 4 = 30$) $\checkmark$.

$n = 5$: scan finds $i = 0$ with $avail[0] = \text{true}$ and $avail[5] = \text{true}$ ($5 = 2^2 + 1^2$). Result: $0, 0, 2, 1$ $\checkmark$.

## Complexity

- **Time:** $O(N)$ precomputation ($N = 10^7$), $O(n)$ per query (finds split quickly in practice)
- **Space:** $O(N)$

## Code (C++)

[Solution Code](../code/Sum%20of%20Four%20Squares.cpp)
