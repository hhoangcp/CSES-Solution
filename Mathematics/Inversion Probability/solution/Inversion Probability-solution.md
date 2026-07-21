# Inversion Probability - Solution

**ID:** 1728 | **URL:** https://cses.fi/problemset/task/1728

## Approach

### Problem Restatement

Given $n$ integers $x_1, x_2, \ldots, x_n$, each $x_i$ chosen uniformly at random from $[1, r_i]$. An inversion is a pair $(a, b)$ with $a < b$ and $x_a > x_b$. Compute the expected number of inversions, rounded to 6 decimal places (banker's rounding).

### Core idea

By **linearity of expectation**, the expected number of inversions equals the sum of inversion probabilities over all pairs, regardless of independence:

$$E[\text{inversions}] = \sum_{1 \le i < j \le n} P(x_i > x_j)$$

So the problem reduces to computing $P(x_i > x_j)$ for each pair $(i, j)$.

**Case $r_i \le r_j$:** For each value $a$ of $x_i$ ($1 \le a \le r_i$), there are $a - 1$ values of $x_j$ less than $a$. Summing over all $a$:

$$P(x_i > x_j) = \frac{1}{r_i \cdot r_j} \sum_{a=1}^{r_i}(a-1) = \frac{r_i(r_i-1)}{2 \cdot r_i \cdot r_j} = \frac{r_i - 1}{2r_j}$$

**Case $r_i > r_j$:** When $x_i > r_j$ (probability $\frac{r_i - r_j}{r_i}$), $x_i$ certainly exceeds $x_j$. When $x_i \le r_j$, we reduce to the equal-range case with bound $r_j$:

$$P(x_i > x_j) = \frac{r_i - r_j}{r_i} + \frac{r_j}{r_i} \cdot \frac{r_j - 1}{2r_j} = \frac{2r_i - r_j - 1}{2r_i}$$

**Unified formula:**

$$P(x_i > x_j) = \frac{\max(0, r_i - r_j) \cdot r_j + \frac{\min(r_i, r_j)(\min(r_i, r_j) - 1)}{2}}{r_i \cdot r_j}$$

### Algorithm

1. Read $n$ and the array $r$.
2. For each pair $(i, j)$ with $i < j$, compute $P(x_i > x_j)$ using the formula above.
3. Sum all probabilities and output the result rounded to 6 decimal places.

### Example

$n = 3$, $r = [5, 2, 7]$.

| Pair | $r_i, r_j$ | Case | $P(x_i > x_j)$ |
|------|-----------|------|-----------------|
| (1,2) | 5, 2 | $r_i > r_j$ | $\frac{2 \cdot 5 - 2 - 1}{2 \cdot 5} = \frac{7}{10}$ |
| (1,3) | 5, 7 | $r_i \le r_j$ | $\frac{5-1}{2 \cdot 7} = \frac{2}{7}$ |
| (2,3) | 2, 7 | $r_i \le r_j$ | $\frac{2-1}{2 \cdot 7} = \frac{1}{14}$ |

$$E = \frac{7}{10} + \frac{2}{7} + \frac{1}{14} = \frac{37}{35} \approx 1.057143$$

## Complexity

- **Time:** $O(n^2)$
- **Space:** $O(n)$

## Code (Python)

[Solution Code](../code/Inversion%20Probability.py)
