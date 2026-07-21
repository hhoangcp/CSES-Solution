# Distinct Values Subsequences - Solution

**ID:** 3421 | **URL:** https://cses.fi/problemset/task/3421

## Approach

### Problem Restatement

Given an array of $n$ integers, count the number of subsequences where all elements are distinct. Print the result modulo $10^9 + 7$.

### Core Idea

In a distinct subsequence, each value $v$ appears at most once. If $v$ appears $c_v$ times in the array, there are $c_v + 1$ choices: don't select $v$, or select exactly one of its $c_v$ occurrences. Choices for distinct values are independent, so by the multiplication principle the count (including the empty subsequence) is $\prod_v (c_v + 1)$. There is a bijection between distinct subsequences and the Cartesian product $\prod_v \{0, 1, \dots, c_v\}$: a selection $(s_{v_1}, \dots, s_{v_d})$ uniquely determines the subsequence (pick the $s_{v_i}$-th occurrence if $s_{v_i} > 0$, skip if $s_{v_i} = 0$), and vice versa. Subtract 1 for the empty subsequence (all $s_v = 0$).

### Algorithm

1. Count frequency $c_v$ of each value using a map.
2. Initialize `ans = 1`.
3. Traverse the map: `ans = ans * (c_v + 1) mod (10^9 + 7)`.
4. Output `(ans - 1 + mod) mod (10^9 + 7)`.

### Example

Array $[1, 2, 1, 3]$, $n = 4$.

| Value $v$ | $c_v$ | $c_v + 1$ |
|-----------|-------|-----------|
| 1 | 2 | 3 |
| 2 | 1 | 2 |
| 3 | 1 | 2 |

Product: $3 \times 2 \times 2 = 12$. Subtract empty: $12 - 1 = \mathbf{11}$.

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Distinct%20Values%20Subsequences.cpp)
