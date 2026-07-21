# Counting Coprime Pairs - Solution

**ID:** 2417 | **URL:** https://cses.fi/problemset/task/2417

## Approach

### Problem Restatement

Given $n$ positive integers $x_1, x_2, \ldots, x_n$ ($n \leq 10^5$, $x_i \leq 10^6$), count pairs $(i, j)$ with $i < j$ such that $\gcd(x_i, x_j) = 1$.

### Core Idea

Instead of directly counting coprime pairs, count pairs by their GCD divisibility and use a multiple-subtraction sieve to extract pairs with GCD exactly 1.

**Definitions.** Let $f(d)$ = number of pairs with $\gcd$ exactly $d$, and $g(d)$ = number of pairs where both elements are divisible by $d$ (i.e., $d \mid \gcd$). Then:

$$g(d) = \sum_{k=1}^{\lfloor M/d \rfloor} f(k \cdot d) = f(d) + f(2d) + f(3d) + \cdots$$

**Computing $g(d)$.** Let $N(d)$ = number of elements divisible by $d$, obtained by summing the frequency array at multiples of $d$. Then $g(d) = \binom{N(d)}{2}$.

**Recovering $f(d)$.** Rearranging the relation: $f(d) = g(d) - f(2d) - f(3d) - \cdots$. Iterate $d$ from $M$ down to $1$; when computing $f(d)$, all $f(kd)$ for $k \geq 2$ are already known. This is equivalent to Möbius inversion without explicitly computing the Möbius function.

*Correctness (reverse induction).* Base: $f(M) = g(M)$ since no multiples exceed $M$. Inductive step: assuming $f(k) = dp[k]$ for all $k > d$, then $dp[d] = g(d) - \sum_{k \geq 2} f(kd) = g(d) - (g(d) - f(d)) = f(d)$.

The answer is $f(1)$.

### Algorithm

1. Build frequency array $\text{cnt}[v]$ for all input values.
2. For each $d$ from $1$ to $M$: compute $N(d)$ by summing $\text{cnt}[k \cdot d]$, then $g(d) = \binom{N(d)}{2}$.
3. Iterate $d$ from $M$ down to $1$: set $dp[d] = g(d) - \sum_{k=2}^{\lfloor M/d \rfloor} dp[k \cdot d]$.
4. Output $dp[1]$.

### Example

Array $[2, 3, 4, 6]$ ($M = 6$):

| $d$ | Multiples | $N(d)$ | $g(d)$ | Subtraction | $f(d)$ |
|:---:|:---:|:---:|:---:|:---|:---:|
| 6 | $\{6\}$ | 1 | 0 | — | 0 |
| 4 | $\{4\}$ | 1 | 0 | — | 0 |
| 3 | $\{3,6\}$ | 2 | 1 | $1 - f(6) = 1$ | 1 |
| 2 | $\{2,4,6\}$ | 3 | 3 | $3 - f(4) - f(6) = 3$ | 3 |
| 1 | $\{2,3,4,6\}$ | 4 | 6 | $6 - f(2) - f(3) - f(4) - f(5) - f(6) = 2$ | 2 |

$f(1) = 2$. Coprime pairs: $(2, 3)$ and $(3, 4)$. $\checkmark$

## Complexity

- **Time:** $O(n + M \log M)$ — frequency in $O(n)$, sieve in $O(M \log M)$ via harmonic series
- **Memory:** $O(M)$ — $dp$ and frequency arrays
