# Subarray Sums II - Solution

**ID:** 1661 | **URL:** https://cses.fi/problemset/task/1661

## Problem Statement

Given an array of $n$ integers $a_1, a_2, \ldots, a_n$ (possibly negative, positive, or zero) and an integer $x$, count the number of contiguous subarrays whose element sum equals $x$.

## Approach

### 1. Transform using prefix sums

Let $S_k$ be the prefix sum from the first element up to position $k$:

- $S_0 = 0$
- $S_k = a_1 + a_2 + \cdots + a_k$ for $1 \le k \le n$

The sum of subarray $[l, r]$ is:

$$\text{Sum}(l, r) = S_r - S_{l-1}$$

This subarray has sum $x$ if and only if:

$$S_r - S_{l-1} = x \iff S_{l-1} = S_r - x$$

So, for each ending position $r$, we must count the start positions $l-1$ ($0 \le l-1 < r$) with $S_{l-1} = S_r - x$.

### 2. Key difference from Subarray Sums I

Since the array may contain any integers (including negatives):

- **Prefix sums are no longer strictly increasing:** values $S_k$ may coincide at several positions (the subarray between them then has sum $0$), so for a given $r$ there can be multiple valid $l-1$. Two pointers (as in Subarray Sums I) no longer work; we must count frequencies.
- **A larger data type is needed:** $S_k$ can be very large or very negative, so `long long` must be used as the key of the counting structure.

### 3. Optimize with a frequency map

Maintain a map (or hash map) $M$ storing the frequency of each prefix-sum value seen so far. Traverse $r$ from $1$ to $n$:

1. Update $S_r = S_{r-1} + a_r$.
2. If $S_r - x$ is in $M$, add $M[S_r - x]$ to the result — each occurrence corresponds to one valid position $l-1$.
3. Increment $M[S_r]$ by $1$.

**Initialization:** set $M[0] = 1$ before the loop, so that valid subarrays starting at the first position ($l = 1$, i.e., $S_{l-1} = S_0 = 0$) are counted.

## Example

Consider $n = 5$, $x = 7$, array $a = [2, -1, 3, 5, -2]$.

Prefix sums: $S_0 = 0,\ S_1 = 2,\ S_2 = 1,\ S_3 = 4,\ S_4 = 9,\ S_5 = 7$.

Initialize $M = \{0: 1\}$, $\text{res} = 0$.

- **$r = 1$ ($a_1 = 2$):** $S_1 = 2$, need $S_1 - 7 = -5 \notin M$. Update $M = \{0:1, 2:1\}$.
- **$r = 2$ ($a_2 = -1$):** $S_2 = 1$, need $S_2 - 7 = -6 \notin M$. Update $M = \{0:1, 1:1, 2:1\}$.
- **$r = 3$ ($a_3 = 3$):** $S_3 = 4$, need $S_3 - 7 = -3 \notin M$. Update $M = \{0:1, 1:1, 2:1, 4:1\}$.
- **$r = 4$ ($a_4 = 5$):** $S_4 = 9$, need $S_4 - 7 = 2 \in M$ (frequency $1$) $\to$ $\text{res} = 1$. Update $M = \{0:1, 1:1, 2:1, 4:1, 9:1\}$. *(Subarray $[2,4]$: $-1+3+5=7$)*.
- **$r = 5$ ($a_5 = -2$):** $S_5 = 7$, need $S_5 - 7 = 0 \in M$ (frequency $1$) $\to$ $\text{res} = 2$. Update $M = \{0:1, 1:1, 2:1, 4:1, 7:1, 9:1\}$. *(Subarray $[1,5]$: $2-1+3+5-2=7$)*.

Result: $2$.

## Complexity

- **Time:** $O(n \log n)$ with `std::map` (each step $O(\log n)$ for lookup and update), or $O(n)$ with `std::unordered_map` (each step averages $O(1)$).
- **Memory:** $O(n)$ to store at most $n+1$ prefix-sum values.
