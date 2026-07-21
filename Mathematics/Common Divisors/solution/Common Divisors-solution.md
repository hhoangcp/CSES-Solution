# Common Divisors - Solution

**ID:** 1081 | **URL:** https://cses.fi/problemset/task/1081

## Approach

### Problem Restatement

Given $n$ positive integers $x_1, x_2, \ldots, x_n$ ($n \leq 2 \cdot 10^5$, $x_i \leq 10^6$), find $\max_{i \neq j} \gcd(x_i, x_j)$.

### Core Idea

Instead of checking all $O(n^2)$ pairs, reverse the perspective: for each value $d$, ask "how many elements are divisible by $d$?" If at least 2 elements are divisible by $d$, then a pair exists with $\gcd \geq d$. The largest such $d$ is the answer.

**Correctness.** Let $d^* = \max\{d : N(d) \geq 2\}$. If the optimal pair has $\gcd = g$, then both elements are divisible by $g$, so $N(g) \geq 2$ and $d^* \geq g$. Conversely, since $N(d^*) \geq 2$, two elements $x_i, x_j$ are divisible by $d^*$, so $\gcd(x_i, x_j) \geq d^*$. Hence $d^* = \max_{i \neq j} \gcd(x_i, x_j)$.

**Counting multiples.** Build a frequency array $\text{cnt}[v]$. For each $d$, the count of multiples is:

$$N(d) = \sum_{k=1}^{\lfloor M/d \rfloor} \text{cnt}[k \cdot d]$$

where $M = 10^6$. Scan $d$ from $M$ down to $1$; the first $d$ with $N(d) \geq 2$ is the answer.

### Algorithm

1. Build frequency array $\text{cnt}[v]$ for all input values.
2. For $d = M$ down to $1$: compute $N(d)$ by summing $\text{cnt}[k \cdot d]$ for all multiples $k \cdot d \leq M$.
3. The first $d$ with $N(d) \geq 2$ is the answer.

### Example

Array $[3, 14, 15, 7, 9]$:

| $d$ | Multiples in array | $N(d)$ | $\geq 2$? |
|:---:|:---:|:---:|:---:|
| 15 | $\{15\}$ | 1 | No |
| 14 | $\{14\}$ | 1 | No |
| 9 | $\{9\}$ | 1 | No |
| 7 | $\{7, 14\}$ | 2 | **Yes** |

$d = 7$ is the first with $N(d) \geq 2$. Indeed, $\gcd(14, 7) = 7$ is the maximum GCD.

## Complexity

- **Time:** $O(n + M \log M)$ — frequency in $O(n)$, sieve in $O(M \log M)$ via harmonic series
- **Memory:** $O(M)$ — frequency array
