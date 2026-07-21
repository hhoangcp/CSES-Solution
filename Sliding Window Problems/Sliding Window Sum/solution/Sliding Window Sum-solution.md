# Sliding Window Sum - Solution

**ID:** 3220 | **URL:** https://cses.fi/problemset/task/3220

## Approach

### Problem Restatement

Given an array of $n$ integers (generated via $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$), compute the sum of each sliding window of $k$ elements. Output the XOR of all sums. Note: $n$ can be up to $10^7$, and window sums can reach $\sim 10^{16}$, so `long long` is required.

### Core Idea

Maintain a running sum of the current window. When the window slides right, add the new element and subtract the departing one. This updates the sum in $O(1)$ per step.

### Algorithm

**Step 1: Generate the array.** Compute $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$ for $i \ge 2$. Store the full array to allow subtracting departing elements later.

**Step 2: Running sum.** Iterate $i$ from 1 to $n$:
1. Add $x[i]$ to `sum`.
2. When $i \ge k$: subtract $x[i-k]$ (the element leaving the window), then XOR `sum` into `ans`.

The running sum is correct because sliding from window $[i{-}k, i{-}1]$ to $[i{-}k{+}1, i]$ changes the sum by exactly $x[i] - x[i-k]$. Use `long long` for `sum` and `ans` to avoid overflow.

### Example

With $n=8$, $k=5$, generator $x=3, a=7, b=1, c=11$:

Generated array: $[3, 0, 1, 8, 2, 4, 7, 6]$.

- $i=5$: sum $= 3+0+1+8+2 = 14$. ans $= 14$
- $i=6$: sum $= 14 + 4 - 3 = 15$. ans $= 14 \oplus 15 = 1$
- $i=7$: sum $= 15 + 7 - 0 = 22$. ans $= 1 \oplus 22 = 23$
- $i=8$: sum $= 22 + 6 - 1 = 27$. ans $= 23 \oplus 27 = 12$

Answer: `12`

## Complexity

- **Time:** $O(n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Sliding%20Window%20Sum.cpp)
