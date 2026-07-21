# Pizzeria Queries - Solution

**ID:** 2206 | **URL:** https://cses.fi/problemset/task/2206

## Approach

### Problem Restatement

There are $n$ buildings on a street. Pizza price at building $a$ is $p_a$. Ordering from building $a$ delivered to building $b$ costs $p_a + |a - b|$. Process $q$ queries:
1. Update $p_k$ to $x$.
2. Find the minimum cost to order a pizza delivered to building $k$.

### Core idea

A brute-force query (type 2) costs $O(n)$, giving $O(nq)$ total — too slow. The bottleneck is the absolute value $|a - k|$. Remove it by splitting based on relative position:

- **$a \le k$** (left side): $|a - k| = k - a$, so cost $= (p_a - a) + k$. Since $k$ is constant, $\min_{1 \le a \le k}(p_a + |a - k|) = \min_{1 \le a \le k}(p_a - a) + k$.
- **$a \ge k$** (right side): $|a - k| = a - k$, so cost $= (p_a + a) - k$. Since $k$ is constant, $\min_{k \le a \le n}(p_a + |a - k|) = \min_{k \le a \le n}(p_a + a) - k$.

Every building belongs to at least one range (building $k$ is in both), so $\{1, \dots, n\} = \{a \mid 1 \le a \le k\} \cup \{a \mid k \le a \le n\}$. By distributivity of $\min$ over union:

$$\min_{a} (p_a + |a - k|) = \min\left(\min_{1 \le a \le k}(p_a - a) + k,\min_{k \le a \le n}(p_a + a) - k\right)$$

Both $(p_a - a)$ and $(p_a + a)$ depend only on building $a$, not on $k$, so build two min segment trees: **Down** stores $d_i = p_i - i$ (for the left range); **Up** stores $u_i = p_i + i$ (for the right range). Updates are straightforward since changing $p_k$ only affects position $k$ in both trees.

### Algorithm

1. **Build** two min segment trees: Down with $d_i = p_i - i$, Up with $u_i = p_i + i$.
2. **Update** (type 1): Set Down[$k$] $= x - k$ and Up[$k$] $= x + k$.
3. **Query** (type 2): Return $\min(\text{Down.query}(1, k) + k,\text{Up.query}(k, n) - k)$.

### Example

Input:
```
6 3
8 6 4 5 7 5
2 2
1 5 1
2 2
```

Prices: $[8, 6, 4, 5, 7, 5]$. Down: $[7, 4, 1, 1, 2, -1]$. Up: $[9, 8, 7, 9, 12, 11]$.

- Query building 2: Down.query(1,2) $= 4$, cost_left $= 4 + 2 = 6$; Up.query(2,6) $= 7$, cost_right $= 7 - 2 = 5$. Answer $= \min(6, 5) = 5$ (order from building 3: $4 + |3-2| = 5$).
- Update building 5 to price 1: Down[5] $= 1 - 5 = -4$; Up[5] $= 1 + 5 = 6$.
- Query building 2: Down.query(1,2) $= 4$, cost_left $= 6$; Up.query(2,6) $= \min(8,7,9,6,11) = 6$, cost_right $= 6 - 2 = 4$. Answer $= \min(6, 4) = 4$ (order from building 5: $1 + |5-2| = 4$).

Output:
```
5
4
```

## Complexity

- **Time:** $O((n + q) \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Pizzeria%20Queries.cpp)
