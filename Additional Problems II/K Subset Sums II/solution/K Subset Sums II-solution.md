# K Subset Sums II - Solution

**ID:** 3109 | **URL:** https://cses.fi/problemset/task/3109

## Problem Statement

Given $n$ integers, find the $k$ smallest sums of subsets with *exactly* $m$ elements, in increasing order.

## Approach

### Difference from K Subset Sums I: Only "upgrade" allowed

In problem I, we could freely add or replace elements. Here, we must maintain exactly $m$ elements, so we can only **upgrade**: replace $a_j$ with $a_k$ ($k > j$). The base set is the $m$ smallest elements $\{a_0, a_1, \ldots, a_{m-1}\}$.

### State and two transitions

Each state in the min-heap is $(s, k, p, \text{limit})$:
- **$s$**: current sum.
- **$k$**: position being upgraded.
- **$p$**: current index of the element at position $k$.
- **$\text{limit}$**: upper bound on the index to avoid "stepping on" the element after it.

Two transitions:
1. **Extend:** Replace $a[p]$ with $a[p+1]$: $s' = s - a[p] + a[p+1]$, $p' = p+1$. Continue upgrading the same position $k$.
2. **Branch:** Go back to upgrade position $k-1$: replace $a[k-1]$ with $a[k]$, reset $p$ and $\text{limit}$.

**Completeness:** Every $m$-element subset $S = \{i_1, \ldots, i_m\}$ is obtained from the base set by an upgrade chain: upgrade position 0 from $a_0$ to $a_{i_1}$ (repeated extends), then branch to position 1, upgrade to $a_{i_2}$, etc.

**No duplicates:** The rule "upgrade the highest position first, only branch to lower positions" creates a unique order for each subset — at each step, knowing $k$ and $p$, the next decision is uniquely determined.

## Algorithm

1. Sort the array in increasing order.
2. Compute `current_sum` = sum of the first $m$ elements.
3. Push initial state `(current_sum, m-1, m-1, n)` into the min-heap.
4. Repeat $k$ times:
   - Extract the state with the smallest `sum`.
   - Save `sum` to results.
   - If $p + 1 < \text{limit}$, push the extend state.
   - If $k > 0$ and $k < p$, push the branch state.
5. Output results.

## Example

$n = 5$, $m = 3$, $k = 9$, array $[-3, 1, 5, 2, 0]$.

- Sorted array: $[-3, 0, 1, 2, 5]$.
- Sum of $m$ smallest: $-3 + 0 + 1 = -2$.

Results: $-2, -1, 0, 2, 3, 3, 4, 6, 7$.

## Complexity

- **Time:** $O(n \log n + k \log k)$
- **Memory:** $O(n + k)$

## Code (C++)

[Solution Code](../code/K%20Subset%20Sums%20II.cpp)
