# Collecting Numbers - Solution

**ID:** 2216 | **URL:** https://cses.fi/problemset/task/2216

## Approach

### Problem Restatement

Given an array of $n$ integers where each number from $1$ to $n$ appears exactly once, find the minimum number of rounds needed to collect all numbers. In each round, traverse the array left to right and collect numbers in increasing order from $1$.

### Core Idea

Let $\text{pos}[v]$ be the position of value $v$ in the array. In any single round, the collected numbers must have positions in increasing order (since we scan left to right and pick in increasing order). Therefore, if $\text{pos}[i] < \text{pos}[i-1]$, number $i$ appears before $i-1$ — when scanning left to right we encounter $i$ before having collected $i-1$, so we cannot pick $i$ in the same round. Conversely, if $\text{pos}[i] > \text{pos}[i-1]$, we can always collect $i$ right after $i-1$ in the same round. Each maximal consecutive segment with increasing positions forms exactly one round, so the number of rounds equals the number of position decreases plus 1.

Formula: $\text{Round} = 1 + \sum_{i=2}^{n} [\text{pos}[i] < \text{pos}[i-1]]$.

### Algorithm

1. Scan the array, store $\text{pos}[v]$ for each value $v$.
2. Initialize $\text{Round} = 1$.
3. For $i$ from $2$ to $n$: if $\text{pos}[i] < \text{pos}[i-1]$, increment $\text{Round}$.

### Example

Array $[4, 2, 1, 5, 3]$.

| $v$ | 1 | 2 | 3 | 4 | 5 |
|-----|---|---|---|---|---|
| $\text{pos}[v]$ | 3 | 2 | 5 | 1 | 4 |

| $i$ | $\text{pos}[i]$ | $\text{pos}[i-1]$ | $\text{pos}[i] < \text{pos}[i-1]$? | Round |
|-----|------------------|--------------------|-------------------------------------|-------|
| 2 | 2 | 3 | Yes | +1 |
| 3 | 5 | 2 | No | |
| 4 | 1 | 5 | Yes | +1 |
| 5 | 4 | 1 | No | |

Result: $1 + 2 = \mathbf{3}$ rounds. In practice: round 1 collects $\{1\}$, round 2 collects $\{2, 3\}$, round 3 collects $\{4, 5\}$.

## Complexity

- **Time:** $O(n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Collecting%20Numbers.cpp)
