# Candy Lottery - Solution

**ID:** 1727 | **URL:** https://cses.fi/problemset/task/1727

## Approach

### Problem Restatement

There are $n$ children, each independently receiving a random integer number of candies from $1$ to $k$. Compute the expected value of the maximum number of candies any child receives, rounded to 6 decimal places (banker's rounding).

### Core Idea

Let $X_1, X_2, \ldots, X_n$ be the candies each child receives, i.i.d. uniform on $\{1, 2, \ldots, k\}$. We need $E[\max(X_1, \ldots, X_n)]$.

**CDF approach.** The event $\max \leq i$ is equivalent to all $X_j \leq i$. By independence:

$$P(\max \leq i) = \left(\frac{i}{k}\right)^n$$

The exact probability $P(\max = i)$ follows from the CDF difference:

$$P(\max = i) = P(\max \leq i) - P(\max \leq i-1) = \left(\frac{i}{k}\right)^n - \left(\frac{i-1}{k}\right)^n$$

**Two equivalent formulas.** Substituting into the definition $E[\max] = \sum_{i=1}^{k} i \cdot P(\max = i)$:

$$E[\max] = \sum_{i=1}^{k} i \cdot \left[\left(\frac{i}{k}\right)^n - \left(\frac{i-1}{k}\right)^n\right]$$

By summation by parts (let $a_i = (i/k)^n$):

$$E[\max] = \sum_{i=1}^{k} i(a_i - a_{i-1}) = k \cdot a_k - \sum_{i=0}^{k-1} a_i = k - \sum_{i=1}^{k-1} \left(\frac{i}{k}\right)^n$$

### Algorithm

1. For $i = 1$ to $k-1$: accumulate $\left(\frac{i}{k}\right)^n$.
2. Output $k - \text{sum}$, rounded to 6 decimal places.

### Example

$n = 2$, $k = 3$:

| $i$ | $P(\max \leq i)$ | $P(\max = i)$ |
|:---:|:---:|:---:|
| 1 | $1/9$ | $1/9$ |
| 2 | $4/9$ | $3/9$ |
| 3 | $1$ | $5/9$ |

$E[\max] = 1 \cdot \frac{1}{9} + 2 \cdot \frac{3}{9} + 3 \cdot \frac{5}{9} = \frac{22}{9} \approx 2.444444$

Verification via simplified formula: $3 - (1/3)^2 - (2/3)^2 = 3 - \frac{1}{9} - \frac{4}{9} = \frac{22}{9} \approx 2.444444$.

## Complexity

- **Time:** $O(nk)$ — iterate $k$ times, each computing an $n$-th power
- **Memory:** $O(1)$
