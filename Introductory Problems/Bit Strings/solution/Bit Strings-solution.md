# Bit Strings - Solution

**ID:** 1617 | **URL:** https://cses.fi/problemset/task/1617

## Approach

### Problem Restatement

Count the number of bit strings of length $n$ ($1 \le n \le 10^6$), modulo $10^9 + 7$.

### Core Idea

Each of the $n$ positions independently holds 0 or 1. By the multiplication principle, the total count is $2^n$. Since each position doubles the number of possible strings, this is the unique answer — no string is missed, and no string is double-counted.

To compute $2^n \bmod (10^9+7)$, use the property $(a \cdot b) \bmod m = ((a \bmod m) \cdot (b \bmod m)) \bmod m$. Taking modulo at each multiplication step keeps values small without changing the final result. This guarantees correctness: after $k$ steps, the accumulator holds $2^k \bmod m$ (by induction — base $k=0$: value = 1 = $2^0$; step: $2^k \bmod m \cdot 2 \bmod m = 2^{k+1} \bmod m$).

### Algorithm

**Iterative multiplication (used in code):** Initialize `power = 1`. Loop $n$ times: `power = power * 2 % mod`. Time: $O(n)$.

**Binary exponentiation (for much larger $n$):** $2^n = (2^{n/2})^2$ if $n$ is even, $2 \cdot 2^{n-1}$ if odd. Each step halves $n$, giving $O(\log n)$ time. For $n \le 10^6$, iterative multiplication is sufficient and simpler.

### Example

$n = 3$: $2^3 = 8$. The 8 bit strings are 000, 001, 010, 011, 100, 101, 110, 111.

## Complexity

- **Time:** $O(n)$ (iterative) / $O(\log n)$ (binary exponentiation)
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Bit%20Strings.cpp)
