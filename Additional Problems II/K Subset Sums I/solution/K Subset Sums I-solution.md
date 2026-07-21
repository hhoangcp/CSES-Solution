# K Subset Sums I - Solution

**ID:** 3108 | **URL:** https://cses.fi/problemset/task/3108

## Problem Statement

Given $n$ integers, find the $k$ smallest subset sums (including the empty set with sum 0) in increasing order.

## Approach

### Handling negatives: Reduce to non-negative array

If the array has only non-negative numbers, the smallest sum is the empty set (0). If there are negatives, the subset with the smallest sum will contain **all** negative numbers. Let `min_sum` = sum of all negative elements. Take absolute values of negatives to convert to a **non-negative** array, then add `min_sum` to each subset sum for the final result.

### Enumerating subset sums via Min-Heap

After sorting the non-negative array $a_0 \le a_1 \le \cdots \le a_{n-1}$, use a **min-heap** to extract the $k$ smallest sums. Each state in the heap is a pair `(sum, index)`: current sum and the last index processed.

From state `(s, i)`, two transitions systematically generate larger sums:
1. **Add next element:** `(s + a[i+1], i+1)` — include $a_{i+1}$.
2. **Replace current element:** `(s - a[i] + a[i+1], i+1)` — remove $a_i$, include $a_{i+1}$.

**Completeness:** Every subset is generated via the two transitions. Set $S = \{i_1, i_2, \ldots, i_m\}$ is produced through a chain of add/replace decisions at each index from $i_1$ to $i_m$.

**Optimality:** Since the array is sorted ($a_i \le a_{i+1}$), "add" strictly increases the sum, and "replace" does not decrease it. The min-heap always extracts the next smallest sum.

## Algorithm

1. Compute `min_sum` = sum of negative elements, negate all negatives.
2. Sort the non-negative array in increasing order.
3. First result: `min_sum` (the subset of only the original negatives).
4. Push `(a[0], 0)` into the min-heap.
5. Repeat $k-1$ times:
   - Extract `(s, i)` with the smallest sum.
   - Save `s + min_sum` to results.
   - If `i + 1 < n`, push the two successor states into the heap.
6. Output the $k$ results.

## Example

Array: $[1, 6, 3, -3]$, $k = 9$.

- `min_sum = -3`. Processed array: $[1, 3, 3, 6]$.
- First result: $-3$.
- Heap: `{(1, 0)}`.
- Extract `(1, 0)` → Result: $-3 + 1 = -2$. Push `(1+3, 1)` and `(1-1+3, 1)` → Heap: `{(3, 1), (4, 1)}`.
- Extract `(3, 1)` → Result: $-3 + 3 = 0$. Continue until 9 sums.

Results: $-3, -2, 0, 0, 1, 1, 3, 3, 4$.

## Complexity

- **Time:** $O(n \log n + k \log k)$
- **Memory:** $O(n + k)$

## Code (C++)

[Solution Code](../code/K%20Subset%20Sums%20I.cpp)
