# Weird Algorithm - Solution

**ID:** 1068 | **URL:** https://cses.fi/problemset/task/1068

## Approach

### Problem Restatement

Given $n$ ($1 \le n \le 10^6$), simulate the following rule until $n = 1$: if $n$ is even, replace $n$ with $n/2$; if $n$ is odd, replace $n$ with $3n+1$. Print all values, including the initial and final 1.

### Core Idea

This is the **Collatz conjecture**: for any positive starting integer, the sequence is believed to always reach 1. Though unproven in general, it has been verified for all $n \le 2^{68}$, far exceeding the problem's constraint of $10^6$, so the sequence always terminates within scope.

No closed-form formula predicts the sequence length without running it, so the only approach is **direct simulation**: repeatedly apply the rule and print each value.

**Intermediate values can exceed the input range.** For $n \le 10^6$, the peak intermediate value is $\sim 5.7 \times 10^{10}$ (at $n = 704511$), far exceeding the 32-bit integer limit. A 64-bit integer type is required.

**Sequence characteristics** for some notable starting values:

| $n$ | Steps | Peak value |
|---|---|---|
| 1 | 0 | 1 |
| 3 | 7 | 16 |
| 27 | 111 | 9232 |
| 9663 | 183 | 27114424 |
| 704511 | 525 | 56991483520 |

For $n \le 10^6$, the maximum number of steps is 525, making simulation extremely fast.

### Algorithm

1. Print $n$.
2. While $n > 1$: if $n$ is odd, set $n = 3n+1$; otherwise, set $n = n/2$. Print $n$.

### Example

**Problem example ($n = 3$):** 3 → 10 → 5 → 16 → 8 → 4 → 2 → 1

Output: `3 10 5 16 8 4 2 1`

## Complexity

- **Time:** $O(T)$ where $T$ is the number of steps until reaching 1. For $n \le 10^6$, $T \le 525$.
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Weird%20Algorithm.cpp)
