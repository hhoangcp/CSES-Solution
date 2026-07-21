# Minimum Cost Pairs - Solution

**ID:** 3402 | **URL:** https://cses.fi/problemset/task/3402

## Problem Statement

Given $n$ integers, for each $k$ from 1 to $\lfloor n/2 \rfloor$, find the minimum total cost to form $k$ pairs, where the cost of pair $(a,b)$ is $|a-b|$ and each number belongs to at most 1 pair.

## Approach

### Pair adjacent elements in the sorted array

Sort the array. In an optimal solution, each pair always consists of adjacent elements: if a pair $(a_i, a_j)$ has $j > i+1$ and $a_m$ between them is unpaired, swapping to $(a_i, a_m)$ is no worse (since $|a_i - a_m| \le |a_i - a_j|$); if $a_m$ is paired with $a_k$, exchanging to $(a_i, a_m)$ and $(a_j, a_k)$ is also no worse. Repeating yields an optimal solution with only adjacent pairs.

The problem reduces to: on difference array $D[i] = a[i+1] - a[i]$, select $k$ differences with no two adjacent, minimizing the sum.

### Merging technique (Wiers-Johnson): Allow "regret"

Pick the smallest difference $D[i]$, but later we may want to switch to $D[i-1]$ and $D[i+1]$ instead of $D[i]$. Then:

- Exchange cost = remove pair $i$ (save $D[i]$), add pairs $l$ and $r$ (cost $D[l] + D[r]$).
- Marginal cost = $D[l] + D[r] - D[i]$.

The merged node carries this value, representing the alternative choice. The greedy algorithm picks the smallest difference from the heap at each step, merges adjacent nodes, and repeats $k$ times — this is exactly minimum-weight matching on a path, solved correctly by greedy with merging.

## Algorithm

1. Sort the array.
2. Compute $D[i] = a[i+1] - a[i]$, build a doubly-linked list (`L[]`, `R[]`) and min-heap.
3. For $k$ from 1 to $\lfloor n/2 \rfloor$:
   - Extract the smallest valid difference $(val, i)$ from the heap (skip merged nodes via `removed[]`).
   - Add `val` to accumulated cost, store result.
   - Merge: $l = L[i]$, $r = R[i]$. Update $D[i] = D[l] + D[r] - D[i]$, push to heap. Mark `removed[l] = removed[r] = true`, update links.
4. Output the cost sequence.

## Example

Array: $[3, 1, 2, 7, 9, 3, 4, 7]$ → sorted: $[1, 2, 3, 3, 4, 7, 7, 9]$.

Differences: $[1, 1, 0, 1, 3, 0, 2]$.

| $k$ | Pick | Accumulated cost |
|:---:|:---:|:---:|
| 1 | 0 (pair 3,3) | 0 |
| 2 | 0 (pair 7,7) | 0 |
| 3 | 1 (pair 1,2) | 1 |
| 4 | continue | 6 |

Result: `0 0 1 6`

## Complexity

- **Time:** $O(n \log n)$ — sorting + at most $n$ heap operations
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Minimum%20Cost%20Pairs.cpp)
