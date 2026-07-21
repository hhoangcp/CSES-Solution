# Permutations - Solution

**ID:** 1070 | **URL:** https://cses.fi/problemset/task/1070

## Approach

### Problem Restatement

Construct a permutation of $\{1, 2, \ldots, n\}$ ($1 \le n \le 10^6$) such that $|p_i - p_{i+1}| \neq 1$ for all adjacent pairs. If impossible, print "NO SOLUTION".

### Core Idea

Consecutive odd numbers differ by exactly 2, as do consecutive even numbers. By grouping all odds together and all evens together, no adjacent difference of 1 can occur *within* either group. The only concern is the boundary between the two groups.

**Construction:** Print all odd numbers in decreasing order, then all even numbers in decreasing order.

**Correctness for $n \ge 4$:**
- Within the odd segment: adjacent odds differ by exactly 2. $\checkmark$
- Within the even segment: adjacent evens differ by exactly 2. $\checkmark$
- At the boundary: the last odd is always 1. If $n$ is even, the first even is $n$, giving $|1 - n| = n - 1 \ge 3$. If $n$ is odd, the first even is $n - 1$, giving $|1 - (n-1)| = n - 2 \ge 3$. $\checkmark$

**No solution for $n = 2, 3$:** For $n = 2$, both permutations [1,2] and [2,1] have adjacent difference 1. For $n = 3$, the number 2 must appear somewhere — whether in the middle or at an end, at least one neighbor differs from 2 by exactly 1.

### Algorithm

- If $n = 1$: output `1`.
- If $n = 2$ or $n = 3$: output `NO SOLUTION`.
- If $n \ge 4$: output odd numbers from largest down to 1, then even numbers from largest down to 2.

### Example

From the sample:
- $n = 5$: output `5 3 1 4 2`. Check: $|5-3|=2$, $|3-1|=2$, $|1-4|=3$, $|4-2|=2$. All $\neq 1$. $\checkmark$
- $n = 3$: `NO SOLUTION`.

## Complexity

- **Time:** $O(n)$
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Permutations.cpp)
