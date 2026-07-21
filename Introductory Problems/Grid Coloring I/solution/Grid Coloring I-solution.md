# Grid Coloring I - Solution

**ID:** 3311 | **URL:** https://cses.fi/problemset/task/3311

## Approach

### Problem Restatement

Given an $n \times m$ grid where each cell is colored with one of four colors (A, B, C, D), recolor the grid such that:
1. No two adjacent cells (sharing an edge) have the same color.
2. The new color of each cell must differ from its original color.

### Core Idea

Each cell $(i, j)$ has at most **3 constraints**: the cell above $(i-1, j)$, the cell to the left $(i, j-1)$, and its own original color. By the Pigeonhole Principle, 4 colors minus 3 constraints always leaves at least 1 valid choice, so a solution always exists.

Processing the grid in row-major order and choosing the first available color (from A, B, C, D) always yields a valid solution. By induction: the top-left cell has at most 1 constraint (3+ choices). For any subsequent cell, the colors above and left are already fixed, so at most 3 out of 4 colors are forbidden. The greedy choice at $(i, j)$ only adds constraints for cells below and to the right, which still have at most 3 constraints each, so backtracking is never needed.

### Algorithm

1. Iterate through the grid row by row, left to right.
2. For each cell $(i, j)$:
   - Identify forbidden colors: the original color, the color above (if $i > 0$), and the color to the left (if $j > 0$).
   - Select the first color from {A, B, C, D} not in the forbidden set.

### Example

Input: $3 \times 4$ grid `AAAA / BBBB / CCDD`.

| Cell | Original | Above | Left | Forbidden | Chosen |
|------|----------|-------|------|-----------|--------|
| (0,0) | A | — | — | {A} | B |
| (0,1) | A | — | B | {A,B} | C |
| (0,2) | A | — | C | {A,C} | B |
| (0,3) | A | — | B | {A,B} | C |
| (1,0) | B | B | — | {B} | A |
| (1,1) | B | C | A | {B,C,A} | D |
| (1,2) | B | B | D | {B,D} | A |
| (1,3) | B | C | A | {B,C,A} | D |
| (2,0) | C | A | — | {C,A} | B |
| (2,1) | C | D | B | {C,D,B} | A |
| (2,2) | D | A | A | {D,A} | B |
| (2,3) | D | D | B | {D,B} | A |

Output:
```
BCBC
ADAD
BABA
```

## Complexity

- **Time:** $O(n \cdot m)$
- **Space:** $O(n \cdot m)$

## Code (C++)

[Solution Code](../code/Grid%20Coloring%20I.cpp)
