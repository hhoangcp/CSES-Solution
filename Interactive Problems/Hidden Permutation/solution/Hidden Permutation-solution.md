# Hidden Permutation - Solution

**ID:** 3139 | **URL:** https://cses.fi/problemset/task/3139

## Approach

### Problem Restatement

There is a hidden permutation $P[1], P[2], \dots, P[n]$ of the integers $1, 2, \dots, n$. Find this permutation by asking whether $P[i] < P[j]$, using at most $10^4$ queries.

### Core Idea

Each query "? $i$ $j$" compares two hidden values. To fully determine the permutation, we need the relative order of all $n$ values — this is exactly **comparison-based sorting**.

We sort an array of indices $a = [1, 2, \ldots, n]$ by their hidden values, using queries as comparisons. After sorting, $a[k]$ is the index of the $k$-th smallest value, i.e., $P[a[k]] = k$. A reverse mapping then recovers the full permutation.

Merge sort guarantees $O(n \log n)$ comparisons. For $n = 1000$: $1000 \times \lceil\log_2 1000\rceil \approx 10000$, within the query limit. The information-theoretic lower bound is $\log_2(n!) \approx 8530$ for $n = 1000$, so merge sort is near-optimal.

### Algorithm

1. Initialize $a[i] = i$ for all $i \in [1, n]$.
2. Perform merge sort on $a[1 \ldots n]$:
   - In the merge step, to compare $a[i]$ and $a[j]$, ask "? $a[i]$ $a[j]$" (i.e., is $P[a[i]] < P[a[j]]$?).
   - If `YES`, take $a[i]$; otherwise take $a[j]$.
3. After sorting, $a[k]$ is the index of the $k$-th smallest value. Set $b[a[i]] = i$ for all $i$.
4. Output "! $b[1]\ b[2]\ \ldots\ b[n]$".

### Example

$n = 3$, hidden permutation $P = [3, 1, 2]$ (matching the problem statement's example):

- Initialize: $a = [1, 2, 3]$.
- Merge sort on $a$:
  - Merge $[1]$ and $[2]$: ask "? 1 2" → is $P[1]=3 < P[2]=1$? **NO** → order: $[2, 1]$. Now $a = [2, 1, 3]$.
  - Merge $[2, 1]$ and $[3]$: ask "? 2 3" → is $P[2]=1 < P[3]=2$? **YES** → take 2. Ask "? 1 3" → is $P[1]=3 < P[3]=2$? **NO** → take 3. Take remaining 1. Now $a = [2, 3, 1]$.
- Reverse mapping: $b[a[1]] = b[2] = 1$, $b[a[2]] = b[3] = 2$, $b[a[3]] = b[1] = 3$.
- Result: $b = [3, 1, 2]$. Output "! 3 1 2".

## Complexity

- **Time:** $O(n \log n)$ queries
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Hidden%20Permutation.cpp)
