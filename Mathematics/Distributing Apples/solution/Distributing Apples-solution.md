# Distributing Apples - Solution

**ID:** 1716 | **URL:** https://cses.fi/problemset/task/1716

## Approach

### Problem Restatement

There are $n$ children and $m$ identical apples ($1 \le n, m \le 10^6$). Each apple must be given to a child; a child may receive 0 apples. Count the number of distributions modulo $10^9+7$.

### Core Idea

This is the **Stars and Bars** problem: distributing $m$ identical objects into $n$ groups, allowing empty groups.

Represent each distribution as a sequence of $m$ stars ($\star$) and $n-1$ bars ($|$). The stars before bar 1 belong to child 1, stars between bars 1 and 2 belong to child 2, and so on. There is a bijection between distributions and sequences of $n+m-1$ characters with $n-1$ bars, so the count is:

$$\binom{n + m - 1}{n - 1} = \binom{n + m - 1}{m}$$

*Alternative proof.* Each distribution is a non-negative integer solution to $x_1 + x_2 + \cdots + x_n = m$. Substituting $y_i = x_i + 1$ transforms it into $y_1 + y_2 + \cdots + y_n = m + n$ with $y_i \ge 1$, which has $\binom{m+n-1}{n-1}$ positive integer solutions.

**Modular computation.** With $p = 10^9+7$ prime:

$$\binom{n+m-1}{m} \equiv (n+m-1)! \cdot ((n-1)!)^{-1} \cdot (m!)^{-1} \pmod{p}$$

Precompute factorials and inverse factorials up to $n + m - 1$.

### Algorithm

1. Precompute $fact[i] = i! \bmod p$ and $inv\_f[i] = (i!)^{-1} \bmod p$ up to $n + m - 1$.
2. Output $fact[n+m-1] \cdot inv\_f[n-1] \cdot inv\_f[m] \bmod p$.

### Example

$n = 3$, $m = 2$: $\binom{4}{2} = 6$.

| Distribution | $x_1$ | $x_2$ | $x_3$ |
|:---:|:---:|:---:|:---:|
| $\star\star\mid\mid$ | 2 | 0 | 0 |
| $\star\mid\star\mid$ | 1 | 1 | 0 |
| $\star\mid\mid\star$ | 1 | 0 | 1 |
| $\mid\star\star\mid$ | 0 | 2 | 0 |
| $\mid\star\mid\star$ | 0 | 1 | 1 |
| $\mid\mid\star\star$ | 0 | 0 | 2 |

## Complexity

- **Time:** $O(n + m)$ — precompute factorials
- **Memory:** $O(n + m)$
