# Sum of Divisors - Solution

**ID:** 1082 | **URL:** https://cses.fi/problemset/task/1082

## Approach

### Problem Restatement

Given $n$ ($1 \le n \le 10^{12}$), compute $\sum_{i=1}^{n} \sigma(i) \pmod{10^9+7}$, where $\sigma(i)$ is the sum of all positive divisors of $i$.

### Core idea

Swap the summation order: instead of summing divisors for each $i$, count how many times each divisor $d$ contributes. Divisor $d$ appears as a divisor of every multiple of $d$ in $[1, n]$, i.e., $\lfloor n/d \rfloor$ times:

$$\sum_{i=1}^{n} \sigma(i) = \sum_{i=1}^{n} \sum_{d \mid i} d = \sum_{d=1}^{n} d \cdot \left\lfloor \frac{n}{d} \right\rfloor$$

This still has $O(n)$ terms. However, $\lfloor n/d \rfloor$ takes only $O(\sqrt{n})$ distinct values: for $d \le \sqrt{n}$ there are at most $\sqrt{n}$ values of $d$, and for $d > \sqrt{n}$ we have $\lfloor n/d \rfloor < \sqrt{n}$, giving at most $\sqrt{n}$ distinct quotient values. Total: $O(\sqrt{n})$ blocks.

**Block computation:** Group consecutive values of $d$ sharing the same $q = \lfloor n/d \rfloor$ into a block $[l, r]$ where $r = \lfloor n/q \rfloor$. The contribution of block $[l, r]$ is:

$$q \cdot \sum_{d=l}^{r} d = q \cdot \frac{(l+r)(r-l+1)}{2}$$

Division by 2 is done via modular inverse ($5 \cdot 10^8 + 4 \pmod{10^9+7}$). After processing each block, advance $l \gets r + 1$.

### Algorithm

1. For $d = 1, 2, \ldots, \lfloor\sqrt{n}\rfloor$: add $d \cdot \lfloor n/d \rfloor$ directly.
2. For each quotient $q$ from $1$ to $\lfloor\sqrt{n}\rfloor$: find the block $[l, r]$ where $l > \lfloor\sqrt{n}\rfloor$ and $\lfloor n/d \rfloor = q$, compute the block sum, and add $q \cdot \text{block\_sum}$.
3. Output the result modulo $10^9+7$.

### Example

$n = 5$.

| Block | $d$ range | $q = \lfloor 5/d \rfloor$ | Contribution |
|-------|-----------|---------------------------|--------------|
| 1 | $[1, 1]$ | 5 | $5 \cdot 1 = 5$ |
| 2 | $[2, 2]$ | 2 | $2 \cdot 2 = 4$ |
| 3 | $[3, 5]$ | 1 | $1 \cdot \frac{8 \cdot 3}{2} = 12$ |

Total = $5 + 4 + 12 = 21$ $\checkmark$.

Direct check: $\sigma(1){+}\sigma(2){+}\sigma(3){+}\sigma(4){+}\sigma(5) = 1{+}3{+}4{+}7{+}6 = 21$.

## Complexity

- **Time:** $O(\sqrt{n})$
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Sum%20of%20Divisors.cpp)
