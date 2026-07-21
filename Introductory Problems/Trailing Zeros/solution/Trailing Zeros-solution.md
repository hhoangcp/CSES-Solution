# Trailing Zeros - Solution

**ID:** 1618 | **URL:** https://cses.fi/problemset/task/1618

## Approach

### Problem Restatement

Given $n$ ($1 \le n \le 10^9$), calculate the number of trailing zeros in $n!$.

### Core Idea

Each trailing zero corresponds to a factor of 10 in $n!$. Since $10 = 2 \times 5$, the number of trailing zeros equals $\min(v_2(n!), v_5(n!))$, where $v_p(n!)$ is the exponent of prime $p$ in the factorization of $n!$.

**Why $v_5$ is the deciding factor.** Among $\{1, \ldots, n\}$, multiples of 2 are at least as frequent as multiples of 5 ($\lfloor n/2 \rfloor \ge \lfloor n/5 \rfloor$), and the same holds for every power ($\lfloor n/2^k \rfloor \ge \lfloor n/5^k \rfloor$). Summing over all $k$ gives $v_2(n!) \ge v_5(n!)$. Therefore, the number of trailing zeros is simply $v_5(n!)$.

**Computing $v_5(n!)$ via Legendre's formula:**

$$v_p(n!) = \left\lfloor \frac{n}{p} \right\rfloor + \left\lfloor \frac{n}{p^2} \right\rfloor + \left\lfloor \frac{n}{p^3} \right\rfloor + \cdots$$

The term $\lfloor n/p^k \rfloor$ counts how many integers in $[1, n]$ are multiples of $p^k$, each contributing one additional factor of $p$ beyond those already counted at lower powers. A number divisible by $p^k$ is counted exactly $k$ times across the terms $p^1, p^2, \ldots, p^k$, matching its total contribution of $k$ factors of $p$.

### Algorithm

Set $p = 5$. Repeatedly divide $n$ by 5 and accumulate the quotients until $n$ becomes 0:
1. Initialize $\text{ans} = 0$.
2. While $n > 0$: set $n = \lfloor n/5 \rfloor$, then $\text{ans} \mathrel{+}= n$.
3. Output $\text{ans}$.

This loop computes exactly $\lfloor n/5 \rfloor + \lfloor n/25 \rfloor + \cdots$, which is $v_5(n!)$.

### Example

**Problem example ($n = 20$):** $\lfloor 20/5 \rfloor = 4$, $\lfloor 20/25 \rfloor = 0$. Answer: 4.

$20! = 2432902008176640000$ has exactly 4 trailing zeros. ✓

**Additional example ($n = 125$):** $25 + 5 + 1 = 31$. The number $125 = 5^3$ contributes 3 factors of 5 across the three iterations.

## Complexity

- **Time:** $O(\log_5 n)$ — at most 13 iterations for $n \le 10^9$
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Trailing%20Zeros.cpp)
