# Replace with Difference - Solution

**ID:** 3159 | **URL:** https://cses.fi/problemset/task/3159

## Problem Statement

Given $n$ integers, perform $n-1$ operations: each operation selects two numbers $a, b$, deletes both, and inserts $|a-b|$. Find a sequence of operations yielding a final result of 0, or $-1$ if impossible.

## Approach

### Necessary and sufficient conditions
Result 0 is achievable if and only if:
1. **Total is even:** After each operation, the total sum mod 2 is unchanged since $a+b \equiv |a-b| \pmod{2}$. This is an invariant, so the initial total must be even. If odd $\to$ $-1$.
2. **Equal-sum partition exists:** Each valid operation sequence corresponds to assigning $+$/$-$ signs to each number ($+$ for the kept value, $-$ for the subtracted). Result 0 means the $+$ group sum equals the $-$ group sum. Conversely, if a partition exists, greedy merging (taking max from each group, difference belongs to the correct group) reduces to 0 since both groups have equal sums.

### Algorithm
1. Check if total is even. If odd $\to$ $-1$.
2. Run subset sum DP with bitset: `dp[i+1] = dp[i] | (dp[i] << a[i])`. If no subset with sum = total/2 $\to$ $-1$.
3. Trace back to find the partition into two groups $P$ (sum = total/2) and $N$ (the rest).
4. Place elements into two max-heaps `pq_P` and `pq_N`.
5. Repeatedly: extract max from each heap, output the pair, push the difference into the appropriate heap (if $p \ge n$ push to `pq_P`, otherwise push to `pq_N`).
6. If one heap is empty: extract two elements from the other heap, output the pair, push the difference back.

### Example

$[2,7,4,12,1]$. Total = 26. Partition: $\{2,4,7\}$ and $\{12,1\}$ (each sum 13).

## Complexity

- **Time:** $O(n \cdot S / 64)$ for bitset DP + $O(n \log n)$ merging
- **Memory:** $O(n \cdot S / 64)$

## Code (C++)

[Solution Code](../code/Replace%20with%20Difference.cpp)
