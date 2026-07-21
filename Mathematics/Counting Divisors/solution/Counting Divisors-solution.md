# Counting Divisors - Solution

**ID:** 1713 | **URL:** https://cses.fi/problemset/task/1713

## Approach

### Problem Restatement

Given $n$ positive integers ($1 \le n \le 10^5$, $1 \le x \le 10^6$), for each number $x$, count its positive divisors.

### Core Idea

A naive approach iterates to $\sqrt{x}$ per query, but $O(n\sqrt{\max x}) \approx 10^8$ risks TLE. Instead, **precompute** divisor counts for all numbers up to $M = 10^6$ using a Dirichlet sieve.

Key principle: if $i$ is a divisor of $j$, then $j$ is a multiple of $i$. So for each $i$, increment $\text{DIV}[j]$ for all multiples $j = i, 2i, 3i, \ldots, M$. Each increment at $\text{DIV}[j]$ corresponds to discovering that $i$ divides $j$. After processing all $i$, $\text{DIV}[j]$ equals the number of positive divisors of $j$.

**Correctness.** There is a bijection between increments of $\text{DIV}[j]$ and divisors of $j$: every divisor $d$ of $j$ causes exactly one increment (when $i = d$), and every increment at $i = d$ implies $d \mid j$. So the count is exact.

The total number of iterations is the **harmonic sum**:

$$\sum_{i=1}^{M} \left\lfloor \frac{M}{i} \right\rfloor \approx M \ln M$$

### Algorithm

1. Initialize array $\text{DIV}[1 \ldots M]$ with zeros.
2. For $i = 1$ to $M$: for each multiple $j = i, 2i, 3i, \ldots, M$: increment $\text{DIV}[j]$.
3. For each query $x$: output $\text{DIV}[x]$.

### Example

**Test 1:** $x = 16$. Divisors: $\{1, 2, 4, 8, 16\}$, so $\text{DIV}[16] = 5$.

**Test 2:** $x = 17$. Divisors: $\{1, 17\}$, so $\text{DIV}[17] = 2$.

**Test 3:** $x = 18$. Divisors: $\{1, 2, 3, 6, 9, 18\}$, so $\text{DIV}[18] = 6$.

## Complexity

- **Time:** $O(M \log M)$ precomputation + $O(1)$ per query, with $M = 10^6$
- **Memory:** $O(M)$
