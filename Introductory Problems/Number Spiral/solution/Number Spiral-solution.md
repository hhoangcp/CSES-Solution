# Number Spiral - Solution

**ID:** 1071 | **URL:** https://cses.fi/problemset/task/1071

## Approach

### Problem Restatement

A number spiral is an infinite grid starting with 1 at the top-left corner:

```
 1   2   9  10  25
 4   3   8  11  24
 5   6   7  12  23
16  15  14  13  22
17  18  19  20  21
```

Given $t$ queries ($1 \le t \le 10^5$), each with coordinates $(x, y)$ ($1 \le x, y \le 10^9$, $x$ = row, $y$ = column), find the value at that cell.

### Core Idea

Let $m = \max(x, y)$. Cell $(x, y)$ lies on layer $m$, the outer boundary of an $m \times m$ square. The diagonal cell $(m, m)$ serves as an anchor point with value $\text{base} = m(m-1) + 1$ (since layer $m$ starts at $(m-1)^2 + 1$, and $(m, m)$ is the $m$-th cell in the layer).

Other cells in the same layer are offset from base by $|m - x|$ or $|m - y|$, with the offset direction determined by layer parity:

| Condition | Formula |
|-----------|---------|
| $x = y$ | base |
| $x < y$, $y$ odd | base $+ (y - x)$ |
| $x < y$, $y$ even | base $- (y - x)$ |
| $x > y$, $x$ odd | base $- (x - y)$ |
| $x > y$, $x$ even | base $+ (x - y)$ |

**Intuition:** Layer $m$ odd — the spiral descends along column $m$ then goes left along row $m$, so moving up from the diagonal increases value and moving left decreases it. Layer $m$ even — the spiral goes right along row $m$ then up along column $m$, so the directions are reversed.

### Algorithm

1. Compute $m = \max(x, y)$ and $\text{base} = m(m-1) + 1$.
2. Apply the appropriate offset from the table above.
3. Output the result.

### Example

From the sample:
- $(x, y) = (2, 3)$: $m = 3$, base $= 7$. $x < y$, $y$ odd $\to 7 + 1 = \mathbf{8}$.
- $(x, y) = (1, 1)$: $m = 1$, base $= 1$. $x = y$ $\to \mathbf{1}$.
- $(x, y) = (4, 2)$: $m = 4$, base $= 13$. $x > y$, $x$ even $\to 13 + 2 = \mathbf{15}$.

## Complexity

- **Time:** $O(1)$ per query
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Number%20Spiral.cpp)
