# Prefix Sum Queries - Solution

**ID:** 2166 | **URL:** https://cses.fi/problemset/task/2166

## Approach

### Problem Restatement

Given an array of $n$ integers, process $q$ queries:
1. Update the value at position $k$ to $u$.
2. Find the maximum prefix sum in range $[a, b]$. Empty prefixes (sum 0) are allowed.

### Core idea

Let $P[i] = x_1 + x_2 + \cdots + x_i$ (with $P[0] = 0$). The sum of a subarray starting at $a$ and ending at $j$ is $P[j] - P[a-1]$. Since $P[a-1]$ is constant for a given query:

$$\max_{a \le j \le b}(P[j] - P[a-1]) = \max_{j \in [a, b]} P[j] - P[a-1]$$

Extend the range to include $j = a-1$. If the maximum is at $j = a-1$, the result is $P[a-1] - P[a-1] = 0$, which naturally handles the empty prefix case without an explicit $\max(0, \ldots)$:

$$\text{answer} = \max_{j \in [a-1, b]} P[j] - P[a-1]$$

Now maintain array $P$ directly. When updating $x_k = u$ with $\delta = u - x_k^{\text{old}}$, every $P[i]$ for $i \ge k$ changes by $\delta$, so a point update on $x$ becomes a range add $[k, n]$ on $P$. Build a segment tree on $P$ (size $n+1$, indices $0$ to $n$) supporting range add (lazy propagation) and range maximum query.

### Algorithm

1. **Build** a segment tree on $P[0..n]$, supporting range add and range max.
2. **Update** $x_k = u$: compute $\delta = u - x_k$, call `Update(k, n, delta)`, set $a[k] = u$.
3. **Query** $[a, b]$:
   - $M = \text{Query}(a-1, b)$ — maximum of $P$ on $[a-1, b]$.
   - $P_{a-1} = \text{Query}(a-1, a-1)$ — value of $P[a-1]$.
   - Answer $= M - P_{a-1}$.

### Example

Input:
```
8 4
1 2 -1 3 1 -5 1 4
2 2 6
1 4 -2
2 2 6
2 3 4
```

Array: $[1, 2, -1, 3, 1, -5, 1, 4]$. $P = [0, 1, 3, 2, 5, 6, 1, 2, 6]$.

- Query $[2, 6]$: $\max(P[1..6]) = \max(1, 3, 2, 5, 6, 1) = 6$. $P[1] = 1$. Answer $= 6 - 1 = 5$.
- Update $x_4 = -2$: $\delta = -2 - 3 = -5$. Add $-5$ to $P[4..8]$. New $P$: $[0, 1, 3, 2, 0, 1, -4, -3, 1]$.
- Query $[2, 6]$: $\max(P[1..6]) = \max(1, 3, 2, 0, 1, -4) = 3$. $P[1] = 1$. Answer $= 3 - 1 = 2$.
- Query $[3, 4]$: $\max(P[2..4]) = \max(3, 2, 0) = 3$. $P[2] = 3$. Answer $= 3 - 3 = 0$ (empty prefix).

Output:
```
5
2
0
```

## Complexity

- **Time:** $O((n + q) \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Prefix%20Sum%20Queries.cpp)
