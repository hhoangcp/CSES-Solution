# Border Subgrid Count II - Solution

**ID:** 3418 | **URL:** https://cses.fi/problemset/task/3418

## Approach

### Problem Restatement

Given an $n \times n$ grid where each cell contains one of the first $k$ uppercase letters, count—for each letter $c$—the number of sub-**rectangles** whose entire border consists of letter $c$.

### Enumerate row pairs with column homogeneity tracking

A rectangle with rows $[u, v]$ and columns $[L, R]$ has border letter $c$ iff:
- Top row $u$, columns $L$ to $R$: all $c$.
- Bottom row $v$, columns $L$ to $R$: all $c$.
- Left column $L$, rows $u$ to $v$: all $c$.
- Right column $R$, rows $u$ to $v$: all $c$.

Enumerate all $O(n^2)$ row pairs $(u, v)$. For each pair, maintain `colS[i]` tracking whether column $i$ is **homogeneous** from row $u$ to $v$:

- If all cells in column $i$ from row $u$ to $v$ are the same letter $c$, then `colS[i] = c`.
- Otherwise, `colS[i] = -1` (not homogeneous, so column $i$ cannot serve as a left or right border).

When extending the bottom row from $v-1$ to $v$, update `colS[i]` in $O(n)$: if `colS[i] != -1` and `a[v][i]` differs from the stored letter, set `colS[i] = -1`. For $u = v$, initialize `colS[i] = a[u][i]`.

### Count rectangles by scanning columns

For a fixed row pair $(u, v)$, scan columns left to right. A column $i$ can serve as a left or right border iff:
1. `a[u][i] == a[v][i]` — the top and bottom cells match (same letter on both horizontal edges).
2. `colS[i] == a[u][i]` — the entire column from $u$ to $v$ is homogeneous with that letter (both vertical edges are the same letter).

These two conditions together guarantee that all four borders of any rectangle using column $i$ as a side are the same letter. The column interior (between left and right borders) does not affect the border, so only the border cells matter.

**Counting technique:** Track consecutive columns where conditions hold for the same letter. Maintain `num` = count of valid border columns in the current run. When the letter changes or conditions break, reset `num = 0`. For each valid column, `ans[c] += ++num`. This counts all rectangles with right border at column $i$: the left border can be any of the `num` valid columns in the run.

The key insight: if columns $p$ and $i$ (with $p \le i$) both satisfy the conditions for letter $c$, then the rectangle with columns $[p, i]$ and rows $[u, v]$ has all four borders consisting of letter $c$. The top and bottom rows are all $c$ between columns $p$ and $i$ (because all columns in the run have $c$ on both rows), and the left/right columns are all $c$ from row $u$ to $v$ (by the `colS` condition).

### Examples

**Problem example:** $n = 5$, $k = 3$, grid:

```
A B B B C
A B A B C
A B B B C
A B B B C
C C C C C
```

**Row pair $(u, v) = (0, 2)$:**

Column homogeneity after extending to row 2: `colS = [A, B, -1, B, C]` (column 2 is non-homogeneous: A at row 1 differs from B at rows 0, 2).

| $i$ | `a[0][i]` | `a[2][i]` | Match? | `colS[i]` | Valid? | `num` | `ans[c] +=` |
|-----|-----------|-----------|--------|-----------|--------|-------|-------------|
| 0 | A | A | ✓ | A | ✓ | 1 | A += 1 |
| 1 | B | B | ✓ | B | ✓ | 1 | B += 1 |
| 2 | B | B | ✓ | -1 | ✗ | 1 | — |
| 3 | B | B | ✓ | B | ✓ | 2 | B += 2 |
| 4 | C | C | ✓ | C | ✓ | 1 | C += 1 |

At $i = 3$ with `num = 2`: the two B-bordered rectangles ending at column 3 are (cols 1–3 and cols 3–3). Column 2 cannot be a left border because `colS[2] = -1`.

**Row pair $(u, v) = (4, 4)$:** `colS = [C, C, C, C, C]`, all valid. `num` reaches 5 → $C += 1 + 2 + 3 + 4 + 5 = 15$.

**Full result:** Summing over all 15 row pairs: **11, 38, 29**. ✓

## Complexity

- **Time:** $O(n^3)$ — $O(n^2)$ row pairs, each scanning $O(n)$ columns.
- **Space:** $O(n)$ — for the `colS` array and answer accumulation.

## Code (C++)

[Solution Code](../code/Border%20Subgrid%20Count%20II.cpp)
