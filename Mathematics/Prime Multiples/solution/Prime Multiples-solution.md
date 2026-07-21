# Prime Multiples - Solution

**ID:** 2185 | **URL:** https://cses.fi/problemset/task/2185

## Approach

### Problem Restatement

Given $n$ ($n \le 10^{18}$) and $k$ distinct primes $a_1, a_2, \ldots, a_k$ ($k \le 20$), count integers in $[1, n]$ divisible by at least one of the given primes.

### Core idea

Let $A_i$ be the set of integers in $[1, n]$ divisible by $a_i$. By **inclusion-exclusion**:

$$\left|\bigcup_{i=1}^{k} A_i\right| = \sum_{\emptyset \neq S \subseteq \{1,\ldots,k\}} (-1)^{|S|+1} \left\lfloor \frac{n}{\prod_{i \in S} a_i} \right\rfloor$$

Since the $a_i$ are distinct primes, $\text{lcm}(S) = \prod_{i \in S} a_i$, and $\lfloor n / \text{lcm}(S) \rfloor$ counts multiples of all $a_i \in S$.

**Why it works:** An element $x$ divisible by exactly $t$ of the primes appears in all $\binom{t}{j}$ subsets of size $j$ formed from those $t$ primes. Its total contribution is $\sum_{j=1}^{t} (-1)^{j+1} \binom{t}{j} = 1 - (1-1)^t = 1$, so each qualifying element is counted exactly once.

Since $k \le 20$, enumerate all $2^k - 1$ non-empty subsets by bitmask. **Overflow prevention:** before multiplying the next prime $a_{\text{next}}$ into the current product $P$, check if $P > n / a_{\text{next}}$; if so, $P \cdot a_{\text{next}} > n$ and the contribution is 0.

### Algorithm

1. Read $n$, $k$, and the $k$ primes.
2. For each bitmask from $1$ to $2^k - 1$: compute the product of selected primes (with overflow check), then add $(-1)^{|S|+1} \cdot \lfloor n / P \rfloor$ to the result.
3. Output the result.

### Example

$n = 20$, $k = 2$, primes $= [2, 5]$.

| $S$ | $|S|$ | Sign | $\prod a_i$ | $\lfloor 20/P \rfloor$ | Contribution |
|-----|-------|------|-------------|------------------------|--------------|
| $\{1\}$ | 1 | $+$ | 2 | 10 | $+10$ |
| $\{2\}$ | 1 | $+$ | 5 | 4 | $+4$ |
| $\{1,2\}$ | 2 | $-$ | 10 | 2 | $-2$ |

Answer $= 10 + 4 - 2 = 12$ $\checkmark$.

The 12 numbers: $\{2, 4, 5, 6, 8, 10, 12, 14, 15, 16, 18, 20\}$.

## Complexity

- **Time:** $O(k \cdot 2^k)$
- **Space:** $O(k)$

## Code (C++)

[Solution Code](../code/Prime%20Multiples.cpp)
