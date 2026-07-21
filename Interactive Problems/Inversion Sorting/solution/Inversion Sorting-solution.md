# Inversion Sorting - Solution

**ID:** 3140 | **URL:** https://cses.fi/problemset/task/3140

## Approach

### Problem Restatement

There is a hidden permutation $a_1, a_2, \dots, a_n$ of integers $1, 2, \dots, n$. On each turn, you reverse a subarray $[i, j]$ and receive the current number of inversions. If the number of inversions equals 0, you win. At most $4n$ operations.

### Core Idea

**Strategy:** First determine the hidden permutation, then sort it.

Let $inv[i]$ denote the number of inversions in the prefix $a[1 \ldots i]$, i.e., pairs $(p, q)$ with $1 \le p < q \le i$ and $a_p > a_q$. We compute $inv[i]$ for all $i$, then reconstruct the permutation, and finally sort it.

**Deriving $inv[i]$:** Reverse $[1, i]$ twice. Let `pre` be the inversion count after the first reversal and `cur` after the second (which undoes the first).

When reversing $[1, i]$, the total inversion count decomposes into three parts:
- **Within** $[1, i]$: changes from $inv[i]$ to $\binom{i}{2} - inv[i]$ (reversal flips every pair).
- **Within** $[i+1, n]$: unchanged (call it $out$).
- **Cross** (one endpoint in $[1, i]$, one in $[i+1, n]$): **also unchanged**, because the set of values in $[1, i]$ is preserved — only their order changes, so for any fixed element in $[i+1, n]$, the count of elements in $[1, i]$ greater than it stays the same.

Let $cross$ denote the (unchanged) cross count. Then:

$$pre = \left(\binom{i}{2} - inv[i]\right) + out + cross, \quad cur = inv[i] + out + cross$$

Subtracting: $cur - pre = 2 \cdot inv[i] - \binom{i}{2}$, so:

$$inv[i] = \frac{cur - pre + \binom{i}{2}}{2}$$

### Algorithm

**Phase 1 — Compute prefix inversion counts:** For each $i$ from 2 to $n$, reverse $[1, i]$ (get `pre`), then reverse $[1, i]$ again (get `cur`). Compute $inv[i]$ from the formula. If at any point the inversion count is 0, terminate immediately. Total: $2(n-1)$ operations.

**Phase 2 — Reconstruct the permutation:** For each value $v$ from 1 to $n$, find position $pos$ such that $a[pos] = v$. At position $i$ (not yet assigned), the number of elements before $i$ greater than $v$ is $inv[i] - inv[i-1]$, and the number of already-assigned smaller values before $i$ is $\text{cnt}$. The condition $a[i] = v$ is equivalent to:

$$inv[i] - inv[i-1] + \text{cnt} = i - 1$$

Take the **last** position satisfying this (smaller values occupy earlier valid positions). Total: $O(n^2)$, no queries.

**Phase 3 — Sort by selection sort with reversals:** For each $i$ from 1 to $n$, find the minimum element in $a[i \ldots n]$, at position $pos$. Reverse $[i, pos]$ to bring it to position $i$. If the inversion count is 0, terminate. Total: at most $n - 1$ operations.

**Total operations:** $2(n-1) + (n-1) = 3n - 3 < 4n$.

### Example

$n = 3$, hidden permutation $[3, 1, 2]$ (matching the problem statement's example):

**Phase 1:** $inv[1] = 0$.

- $i = 2$: Reverse $[1, 2]$ → $[1, 3, 2]$, $pre = 1$. Reverse $[1, 2]$ → $[3, 1, 2]$, $cur = 2$. $inv[2] = (2 - 1 + 1) / 2 = 1$.
- $i = 3$: Reverse $[1, 3]$ → $[2, 1, 3]$, $pre = 1$. Reverse $[1, 3]$ → $[3, 1, 2]$, $cur = 2$. $inv[3] = (2 - 1 + 3) / 2 = 2$.

**Phase 2:** $inv = [0, 1, 2]$. Reconstruct:

- $v = 1$: $i=1$: $0 - 0 + 0 = 0 = 0$ ✓. $i=2$: $1 - 0 + 0 = 1 = 1$ ✓. $i=3$: $2 - 1 + 0 = 1 \neq 2$. Last match: $pos = 2$. $a[2] = 1$.
- $v = 2$: $i=1$: $0 - 0 + 0 = 0 = 0$ ✓. $i=3$: $2 - 1 + 1 = 2 = 2$ ✓. Last match: $pos = 3$. $a[3] = 2$.
- $v = 3$: $i=1$: $0 - 0 + 0 = 0 = 0$ ✓. Last match: $pos = 1$. $a[1] = 3$.

Result: $a = [3, 1, 2]$. ✓

**Phase 3:** Sort $[3, 1, 2]$:

- $i = 1$: min in $[1, 3]$ is 1 at $pos = 2$. Reverse $[1, 2]$ → $[1, 3, 2]$, inversions $= 1$.
- $i = 2$: min in $[2, 3]$ is 2 at $pos = 3$. Reverse $[2, 3]$ → $[1, 2, 3]$, inversions $= 0$. Done!

## Complexity

- **Time:** $O(n^2)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Inversion%20Sorting.cpp)
