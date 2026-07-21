# Writing Numbers - Solution

**ID:** 1086 | **URL:** https://cses.fi/problemset/task/1086

## Problem Statement

Write the numbers $1, 2, 3, \ldots$ and each digit key (0-9) can be pressed at most $n$ times. Find the last number that can be written.

## Approach

### Key insight

One might expect $x \approx n$ for large $n$, but writing a single 18-digit number already costs 18 key presses. The "budget" $n$ is consumed faster as numbers grow, so the answer is always significantly less than $n$ when $n$ is large (e.g., $n = 10^{18}$).

### Counting digit occurrences

We need `count(x)` = the maximum number of times any single digit appears from 1 to $x$. Sum over each digit position $h \in \{1, 10, 100, \ldots\}$, with $d = 10h$:

$$\text{count\_pos}(x, h) = \left\lfloor \frac{x}{d} \right\rfloor \cdot h + \min\left(\max\left(x \bmod d - h + 1, 0\right), h\right)$$

- **Complete cycles:** $\lfloor x/d \rfloor$ groups of $d$ numbers, each contributing $h$ occurrences per digit.
- **Remainder:** the partial group contributes up to $h$ additional occurrences.

Since `count(x)` is monotonically increasing, binary search finds the largest $x$ with `count(x) ≤ n`.

### Example

$n = 5$, checking $x = 12$:

- Position $h = 1$: $\lfloor 12/10 \rfloor \cdot 1 + \min(\max(2 - 1 + 1, 0), 1) = 1 + 1 = 2$ (digits 1, 11)
- Position $h = 10$: $\lfloor 12/100 \rfloor \cdot 10 + \min(\max(12 - 10 + 1, 0), 10) = 0 + 3 = 3$ (digits 10, 11, 12)
- Digit 1 total: $2 + 3 = 5 = n$. Writing 13 would need a 6th press of digit 1.

Result: **12**.

## Complexity

- **Time:** $O(\log r \cdot \log_{10} r)$ where $r = 9 \times 10^{17}$
- **Memory:** $O(1)$

## Code (C++)

[Solution Code](../code/Writing%20Numbers.cpp)
