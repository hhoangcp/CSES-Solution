# Next Prime - Solution

**ID:** 3396 | **URL:** https://cses.fi/problemset/task/3396

## Approach

### Problem Restatement

Given a positive integer $n$ ($1 \le n \le 10^{12}$), find the smallest prime greater than $n$. There are up to $t = 20$ test cases.

### Core idea

By the Prime Number Theorem, the average gap between consecutive primes near $n$ is about $\ln n$. For $n \le 10^{12}$, the maximum prime gap is known to be less than 1500. So simply checking each number from $n+1$ onward until finding a prime is efficient.

For primality testing, use trial division optimized by the $6k \pm 1$ rule: every integer $> 3$ is of the form $6k, 6k+1, \ldots, 6k+5$. Since $6k, 6k+2, 6k+4$ are even and $6k+3$ is divisible by 3, any prime $> 3$ must be of the form $6k \pm 1$. So after checking divisibility by 2 and 3, we only test divisors of the form $6k-1$ and $6k+1$ up to $\sqrt{m}$, alternating the step between 2 and 4.

### Algorithm

For each query $n$:
1. Increment $n$ by 1.
2. Check if $n$ is prime: reject if $n < 2$, accept if $n \in \{2, 3\}$, reject if divisible by 2 or 3, then try divisors $i = 5, 7, 11, 13, \ldots$ (alternating $+2, +4$) up to $i^2 > n$.
3. If not prime, increment $n$ and repeat.

### Example

From the problem's sample:

| $n$ | Next prime | Steps |
|-----|-----------|-------|
| 1 | 2 | 2 is prime |
| 2 | 3 | 3 is prime |
| 3 | 5 | 4 is even, 5 is prime |
| 42 | 43 | 43 not divisible by 2, 3; $5^2 > 43$? No but $43 \bmod 5 \neq 0$ and $7^2 = 49 > 43$ → prime |
| 1337 | 1361 | 1338 even, 1339 $= 13 \times 103$, ..., 1361 passes all checks |

## Complexity

- **Time:** $O(g \cdot \sqrt{n})$ per query, where $g$ is the prime gap (empirically $g < 1500$)
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Next%20Prime.cpp)
