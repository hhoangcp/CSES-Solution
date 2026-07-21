# Counting Permutations - Solution

**ID:** 1075 | **URL:** https://cses.fi/problemset/task/1075

## Approach

### Problem Restatement

Count the number of "beautiful" permutations of $\{1, 2, \ldots, n\}$ where no two adjacent elements differ by 1 (i.e., $|p_i - p_{i+1}| \neq 1$ for all $i$). Result modulo $10^9 + 7$.

### Inclusion-exclusion and the degree-4 recurrence

This sequence is OEIS A002464. Let $A_i$ be the set of permutations where $i$ and $i+1$ are adjacent. We need to count permutations not in $A_1 \cup A_2 \cup \cdots \cup A_{n-1}$.

Applying inclusion-exclusion over these forbidden sets, and using the technique of merging each adjacent pair $(i, i+1)$ into a single "super-element," yields a degree-4 linear recurrence (see Shar, 1968; Kaplansky & Riordan, 1946):

$$f(n) = (n+1) \cdot f(n-1) - (n-2) \cdot f(n-2) - (n-5) \cdot f(n-3) + (n-3) \cdot f(n-4)$$

**Interpretation of terms** (inserting element $n$ into a permutation of $\{1, \ldots, n-1\}$):

- $(n+1) \cdot f(n-1)$: Insert $n$ into a beautiful permutation of size $n-1$. There are $n$ possible positions, and the total count overcounts by including permutations where $n$ creates a new forbidden adjacency.
- $-(n-2) \cdot f(n-2)$: Subtract cases where inserting $n$ creates the adjacency $(n-1, n)$.
- $-(n-5) \cdot f(n-3)$ and $+(n-3) \cdot f(n-4)$: Adjust for higher-order interactions — cases where multiple adjacencies are created or destroyed simultaneously.

### Base cases

| $n$ | $f(n)$ | Explanation |
|-----|---------|-------------|
| 0 | 1 | Empty permutation |
| 1 | 1 | Only $[1]$ |
| 2 | 0 | $[1,2]$ and $[2,1]$ both have adjacent pair |
| 3 | 0 | Every permutation of $\{1,2,3\}$ has an adjacent pair |
| 4 | 2 | Only $[2,4,1,3]$ and $[3,1,4,2]$ |

### Examples

**Problem example:** $n = 5$.

$$f(5) = 6 \cdot f(4) - 3 \cdot f(3) - 0 \cdot f(2) + 2 \cdot f(1) = 6 \cdot 2 - 3 \cdot 0 - 0 \cdot 0 + 2 \cdot 1 = 14$$

**Verifying $f(4) = 2$:** $f(4) = 5 \cdot f(3) - 2 \cdot f(2) - (-1) \cdot f(1) + 1 \cdot f(0) = 0 - 0 + 1 + 1 = 2$. ✓

## Complexity

- **Time:** $O(n)$ — single pass computing the recurrence.
- **Space:** $O(n)$ — for the DP array.

## Code (C++)

[Solution Code](../code/Counting%20Permutations.cpp)
