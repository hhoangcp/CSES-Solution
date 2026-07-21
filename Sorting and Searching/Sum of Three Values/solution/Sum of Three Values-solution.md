# Sum of Three Values - Solution

**ID:** 1641 | **URL:** https://cses.fi/problemset/task/1641

## Problem Statement

Given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and a target value $x$, find three distinct indices $i, j, k$ such that $a_i + a_j + a_k = x$. If several solutions exist, output any; if none exists, output `IMPOSSIBLE`.

## Approach

### 1. Sort the array, preserving original positions

Since the answer must be original positions, we attach the original index to each element as a pair $(\text{value}, \text{original position})$ and sort by value in increasing order. Call the sorted array $A$.

### 2. Fix one element, two pointers for the other two

The core idea is to reduce the 3-sum to a 2-sum (two pointers). We sweep $l$ from $1$ to $n$ to fix the first element $A[l]$; the other two must then sum to:

$$X = x - A[l].a$$

Since $A$ is sorted increasingly, we set two pointers `mid = l + 1` and $r = n$ on the range $[l+1, n]$ and narrow the window:

- If $A[mid].a + A[r].a > X$: the sum is too large, decrease $r$ (`--r`).
- If $A[mid].a + A[r].a < X$: the sum is too small, increase `mid` (`++mid`).
- If $A[mid].a + A[r].a = X$: found the triple; output the original positions of $A[l]$, $A[mid]$, $A[r]$ and stop.
- Stop when `mid >= r`.

Keeping `mid` and $r$ strictly behind $l$ (starting `mid = l + 1`) ensures the three elements occupy three distinct positions in the sorted array, ruling out reuse.

## Example

Consider $n = 5$, $x = 9$, array $a = [2, 1, 5, 3, 7]$.

After sorting increasingly with original positions:

$$A = [(1, 2),\ (2, 1),\ (3, 4),\ (5, 3),\ (7, 5)]$$

*(each pair is $(\text{value}, \text{original position})$)*.

- **$l = 1$ ($A[1] = (1, 2)$):** the other two must sum to $X = 9 - 1 = 8$. Initialize `mid = 2` (value $2$), $r = 5$ (value $7$).
  - $2 + 7 = 9 > 8$ $\to$ decrease $r$ to $4$.
  - `mid = 2` (value $2$), $r = 4$ (value $5$): $2 + 5 = 7 < 8$ $\to$ increase `mid` to $3$.
  - `mid = 3` (value $3$), $r = 4$ (value $5$): $3 + 5 = 8 = X$.
- **Result:** found the triple; original positions $2,\ 4,\ 3$ (i.e., $a_2 + a_4 + a_3 = 1 + 3 + 5 = 9$).

## Complexity

- **Time:** $O(n^2)$. Sorting takes $O(n \log n)$; the outer loop fixing $l$ runs $n$ times, and each run moves the two pointers in one direction only (`mid` increases or $r$ decreases), so at most $O(n)$ steps. Total $O(n \log n) + O(n^2) = O(n^2)$, fitting $n \le 5000$.
- **Memory:** $O(n)$ to store the array of (value, original position) pairs.
