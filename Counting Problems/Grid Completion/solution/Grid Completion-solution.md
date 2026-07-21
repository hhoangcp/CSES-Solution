# Grid Completion - Solution

**ID:** 2429 | **URL:** https://cses.fi/problemset/task/2429

## Approach

### Problem Restatement

Given an $n \times n$ grid with some cells pre-filled with A or B, count the number of ways to fill the remaining cells so that each row and column has exactly one A and one B. Result modulo $10^9 + 7$.

### Decomposition into two assignment problems

If we ignore the constraint that each cell holds at most one character, the problem decomposes into two independent tasks:

- **Place A's:** Assign A to each row missing A, choosing a column that also lacks A. This is a bijection from rows missing A to columns missing A — $c_4!$ ways.
- **Place B's:** Assign B to each row missing B, choosing a column that also lacks B. This is a bijection from rows missing B to columns missing B — $c_5!$ ways.

The only constraint that couples these two assignments is: **A and B in the same row must not land in the same column** (a cell can hold at most one character). Inclusion-exclusion removes these conflicts.

### Row and column classification

For each row $i$, let $A[i]$ and $B[i]$ be the columns of the existing A and B (or $-1$ if missing). Let $\text{markA}[j]$, $\text{markB}[j]$ indicate whether column $j$ already has A or B.

- $c_0$: rows missing both A and B.
- $c_1$: rows missing A but having B, where B's column also lacks A.
- $c_2$: rows having A but missing B, where A's column also lacks B.
- $c_3$: columns missing both A and B.
- $c_4$: total rows missing A ($= c_0 + c_1$).
- $c_5$: total rows missing B ($= c_0 + c_2$).

**Why the extra conditions on $c_1$ and $c_2$?** A row missing A (having B at column $j$) can only cause a conflict if A could actually be placed in column $j$ — which requires that column $j$ doesn't already have an A. If $\text{markA}[j]$ is true, A can't go in column $j$ anyway, so no conflict is possible from this row. Similarly for $c_2$: B can only conflict with A's column if that column still lacks B.

**Why can only $c_3$-type columns receive both A and B from a $c_0$-type row?** For a column to potentially receive both characters, it must lack both A and B — exactly the $c_3$ type. If a column already has A (or B), the other character cannot be placed there, eliminating the conflict.

### Inclusion-exclusion on column conflicts

Three types of conflicts can occur:

1. **$c_0$-type rows ($i$ conflicts):** A row missing both A and B has both placed in the same $c_3$-type column. Variable $i$ counts such rows.
2. **$c_1$-type rows ($j$ conflicts):** A row missing A (having B in a column lacking A) has A placed in B's column. Variable $j$ counts such rows.
3. **$c_2$-type rows ($k$ conflicts):** A row missing B (having A in a column lacking B) has B placed in A's column. Variable $k$ counts such rows.

These are the only possible conflicts. No other row type can produce a same-column conflict because the column constraints prevent it.

For each $(i, j, k)$, the contribution with alternating sign $(-1)^{i+j+k}$:

$$(-1)^{i+j+k} \cdot \binom{c_0}{i}\binom{c_3}{i} \cdot i! \cdot \binom{c_1}{j} \cdot \binom{c_2}{k} \cdot (c_4 - i - j)! \cdot (c_5 - i - k)!$$

- $\binom{c_0}{i}\binom{c_3}{i} \cdot i!$: choose $i$ rows of type $c_0$ and $i$ columns of type $c_3$, match them bijectively — each matched pair $(r, c)$ forces both A and B of row $r$ into column $c$.
- $\binom{c_1}{j}$: choose $j$ rows of type $c_1$ where A is forced into B's column.
- $\binom{c_2}{k}$: choose $k$ rows of type $c_2$ where B is forced into A's column.
- $(c_4 - i - j)!$: remaining A's freely assigned to remaining A-less columns (bijection). The $i$ conflicts from type-$c_0$ rows each consume one A-column, and the $j$ conflicts from type-$c_1$ rows each consume one A-column (B's column, which lacked A).
- $(c_5 - i - k)!$: remaining B's freely assigned to remaining B-less columns (bijection). Analogous reasoning with $i$ and $k$.

### Example

**Problem example:** $n = 5$, grid:
```
.....
..AB.
.....
B....
...A.
```

Classification: $c_0 = 2$ (rows 1,3), $c_1 = 1$ (row 4: has B in col 1 which lacks A), $c_2 = 0$ (row 5 has A in col 4 which already has B), $c_3 = 2$ (cols 2,5), $c_4 = 3$, $c_5 = 3$.

| $(i,j,k)$ | sign | formula | value |
|------------|------|---------|-------|
| (0,0,0) | $+$ | $1 \cdot 1 \cdot 1 \cdot 1 \cdot 3! \cdot 3!$ | 36 |
| (0,1,0) | $-$ | $1 \cdot 1 \cdot 1 \cdot 1 \cdot 2! \cdot 3!$ | $-12$ |
| (1,0,0) | $-$ | $\binom{2}{1}^2 \cdot 1 \cdot 1 \cdot 1! \cdot 2! \cdot 2!$ | $-16$ |
| (1,1,0) | $+$ | $\binom{2}{1}^2 \cdot 1 \cdot 1 \cdot 1! \cdot 1! \cdot 2!$ | $+8$ |
| (2,0,0) | $+$ | $1 \cdot 1 \cdot 1 \cdot 1 \cdot 2! \cdot 0! \cdot 1!$ | $+2$ |
| (2,1,0) | $-$ | $1 \cdot 1 \cdot 1 \cdot 1 \cdot 2! \cdot 0! \cdot 1!$ | $-2$ |

**Total:** $36 - 12 - 16 + 8 + 2 - 2 = \mathbf{16}$. ✓

## Complexity

- **Time:** $O(n^3)$ — triple loop over $(i, j, k)$.
- **Space:** $O(n)$ — for factorials and marking arrays.

## Code (C++)

[Solution Code](../code/Grid%20Completion.cpp)
