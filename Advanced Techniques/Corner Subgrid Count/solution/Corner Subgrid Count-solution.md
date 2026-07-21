# Corner Subgrid Count - Solution

**ID:** 2137 | **URL:** https://cses.fi/problemset/task/2137

## Approach

### Problem Restatement

Given an $n \times n$ binary grid, count the number of subgrids of size at least $2 \times 2$ where all four corners are black (value 1). Such subgrids are called *beautiful*.

### Core Idea

A beautiful subgrid is determined by two distinct rows $r_1 < r_2$ and two distinct columns $c_1 < c_2$ such that all four corner positions are 1. Fix a pair of rows $(r_1, r_2)$ and let $S$ be the set of columns where both rows have a 1. Each pair of columns from $S$ yields a beautiful subgrid, contributing $\binom{|S|}{2} = |S|(|S|-1)/2$. Summing over all row pairs gives the total count.

This decomposition is a bijection: every beautiful subgrid has a unique (row pair, column pair) decomposition counted exactly once, and every (row pair, column pair) from $S$ produces a valid beautiful subgrid since all four corners are 1 by definition of $S$.

Computing $|S|$ for each row pair requires counting columns where both rows are 1, which is exactly the bitwise AND of the two row bitmasks. Using 64-bit `long long` and `__builtin_popcountll`, we process 64 columns at once, making each AND-and-count take $O(n/64)$ instead of $O(n)$.

### Algorithm

1. Encode each row as a bitset using an array of 64-bit integers. Bit $j$ of block $k$ is set if cell $(i, j)$ is 1.
2. For each pair of rows $(i, j)$, $i < j$:
   - Compute bitwise AND of each block of the two row bitmasks.
   - Count total 1-bits in the AND result using `__builtin_popcountll`: this gives $|S|$.
   - Add $\binom{|S|}{2}$ to the answer.
3. Output the total.

### Example

Grid:
```
5
00010
11111
00110
11001
00010
```

Non-zero row pair contributions (1-indexed):

| Row pair | AND result | $\|S\|$ | $\binom{\|S\|}{2}$ |
|----------|------------|---------|---------------------|
| (2,3) | 00110 | 2 | 1 |
| (2,4) | 11001 | 3 | 3 |

(All other row pairs have $|S| \le 1$, contributing 0.)

Total: $1 + 3 = 4$.

## Complexity

- **Time:** $O(n^3 / 64)$ — $O(n^2)$ row pairs, each taking $O(n/64)$ for AND and popcount.
- **Memory:** $O(n^2 / 64)$ — storing bitsets.

## Code (C++)

[Solution Code](../code/Corner%20Subgrid%20Count.cpp)
