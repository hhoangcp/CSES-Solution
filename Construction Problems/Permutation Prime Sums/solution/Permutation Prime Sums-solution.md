# Permutation Prime Sums - Solution

**ID:** 3423 | **URL:** https://cses.fi/problemset/task/3423

## Approach

### Problem Restatement

Given $n$, construct two permutations $a$ and $b$ of size $n$ such that $a_i + b_i$ is prime for all $i = 1, 2, \ldots, n$.

### Core idea

Without loss of generality, set $a_i = i$ (identity permutation). The task reduces to finding permutation $b$ where $i + b_i$ is prime for all $i$. For a prime $p$, the mapping $i \mapsto p - i$ pairs values that sum to $p$ and is its own inverse, forming a bijection. We partition $\{1, \ldots, n\}$ into segments each covered by one such prime.

Recursively build $b$ for range $[1, n]$: find the smallest prime $p > n$, let $m = p - n$, then set $b[i] = p - i$ for $i \in [m, n]$. Since $p - i \in [m, n]$ (as $p - i \ge p - n = m$ and $p - i \le p - m = n$), this maps $[m, n]$ bijectively onto itself with each sum equal to $p$. Recurse on $[1, m - 1]$.

By Bertrand's postulate, for every $n \ge 1$ there exists a prime $p$ with $n < p < 2n$, so $m = p - n < n$ and the subproblem is strictly smaller. The recursion terminates at $n = 0$.

### Algorithm

1. Sieve primes up to $2n$.
2. Call `solve(n)`:
   - If $n \le 0$: return.
   - Find smallest prime $p > n$ (binary search on sieve).
   - Set $m = p - n$.
   - For $i = m$ to $n$: set $b[i] = p - i$.
   - Recurse `solve(m - 1)`.
3. Output $a_i = i$ and $b_i$ for $i = 1, \ldots, n$.

### Example

$n = 5$ (problem example, valid output: `2 1 3 5 4` / `5 1 4 2 3`):

- `solve(5)`: smallest prime $> 5$ is $p = 7$, $m = 7 - 5 = 2$.
  - Range $[2, 5]$: $b[2] = 5, b[3] = 4, b[4] = 3, b[5] = 2$. Sums: all $7$.
- `solve(1)`: smallest prime $> 1$ is $p = 2$, $m = 2 - 1 = 1$.
  - Range $[1, 1]$: $b[1] = 1$. Sum: $1 + 1 = 2$.
- `solve(0)`: done.

Result: $a = [1, 2, 3, 4, 5]$, $b = [1, 5, 4, 3, 2]$. Sums: $2, 7, 7, 7, 7$ — all prime.

## Complexity

- **Time:** $O(n)$ for sieve + $O(n)$ for construction
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Permutation%20Prime%20Sums.cpp)
