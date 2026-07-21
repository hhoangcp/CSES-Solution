# Sliding Window Xor - Solution

**ID:** 3426 | **URL:** https://cses.fi/problemset/task/3426

## Approach

### Problem Restatement

Given an array of $n$ integers (generated via $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$), compute the bitwise XOR of each sliding window of $k$ elements. Output the XOR of all window XOR results. Note: $n$ can be up to $10^7$, requiring $O(n)$ time.

### Core Idea

XOR is self-inverse ($a \oplus a = 0$), so removing an element from a running XOR is done by XORing it again — no subtraction needed. Maintain a running XOR and update it in $O(1)$ per step by XORing in the new element and XORing out the departing one.

### Algorithm

**Step 1: Generate the array.** Compute $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$ for $i \ge 2$. Store the full array to allow removing departing elements later.

**Step 2: Running XOR.** Iterate $i$ from 1 to $n$:
1. XOR $x[i]$ into `sum`.
2. When $i \ge k$: XOR $x[i-k]$ into `sum` (removes the departing element since $a \oplus a = 0$), then XOR `sum` into `ans`.

This works because when the window slides from $[i{-}k{+}1, i]$ to $[i{-}k{+}2, i{+}1]$: `new sum` = `old sum` $\oplus\ x[i{+}1] \oplus\ x[i{-}k{+}1]$. The departing element $x[i{-}k{+}1]$ appears twice and cancels to 0.

### Example

With $n=8$, $k=5$, generator $x=3, a=7, b=1, c=11$:

Generated array: $[3, 0, 1, 8, 2, 4, 7, 6]$.

- $i=5$: sum $= 3 \oplus 0 \oplus 1 \oplus 8 \oplus 2 = 8$. ans $= 8$
- $i=6$: sum $= 8 \oplus 4 \oplus 3 = 15$. ans $= 8 \oplus 15 = 7$
- $i=7$: sum $= 15 \oplus 7 \oplus 0 = 8$. ans $= 7 \oplus 8 = 15$
- $i=8$: sum $= 8 \oplus 6 \oplus 1 = 15$. ans $= 15 \oplus 15 = 0$

Answer: `0`

## Complexity

- **Time:** $O(n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Sliding%20Window%20Xor.cpp)
