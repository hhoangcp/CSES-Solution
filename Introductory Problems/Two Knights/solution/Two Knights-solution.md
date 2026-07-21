# Two Knights - Solution

**ID:** 1072 | **URL:** https://cses.fi/problemset/task/1072

## Approach

### Problem Restatement

For each $k$ from 1 to $n$ ($1 \le n \le 10000$), count the number of ways to place two knights on a $k \times k$ chessboard such that they do **not** attack each other.

### Core Idea

Use complementary counting: valid placements = total placements − attacking placements.

**Total placements.** The board has $k^2$ squares. Choosing 2 distinct squares (order irrelevant):

$$\binom{k^2}{2} = \frac{k^2(k^2 - 1)}{2}$$

**Attacking placements.** A knight moves in an "L" shape (2 squares in one direction, 1 perpendicular). Two knights attack each other iff they occupy opposite corners of a $2 \times 3$ or $3 \times 2$ rectangle. This follows because the coordinate difference between the two squares must be $(\pm 1, \pm 2)$ or $(\pm 2, \pm 1)$, which exactly describes opposite corners of such rectangles.

Each $2 \times 3$ rectangle: the top-left corner has $(k-1)$ row choices and $(k-2)$ column choices → $(k-1)(k-2)$ rectangles. Each has exactly 2 pairs of opposite corners. Similarly, each $3 \times 2$ rectangle gives $(k-2)(k-1)$ rectangles with 2 attacking pairs each. Total:

$$\text{Attacking} = 2(k-1)(k-2) + 2(k-2)(k-1) = 4(k-1)(k-2)$$

**Final formula:**

$$\text{Result} = \frac{k^2(k^2 - 1)}{2} - 4(k-1)(k-2)$$

### Algorithm

For each $k$ from 1 to $n$, compute the formula above and print the result.

### Example

**Problem example ($n = 8$):**

| $k$ | $\binom{k^2}{2}$ | $4(k-1)(k-2)$ | Result |
|---|---|---|---|
| 1 | 0 | 0 | 0 |
| 2 | 6 | 0 | 6 |
| 3 | 36 | 8 | 28 |
| 4 | 120 | 24 | 96 |
| 5 | 300 | 48 | 252 |
| 6 | 630 | 80 | 550 |
| 7 | 1176 | 120 | 1056 |
| 8 | 2016 | 168 | 1848 |

## Complexity

- **Time:** $O(n)$ — $O(1)$ per value of $k$
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Two%20Knights.cpp)
