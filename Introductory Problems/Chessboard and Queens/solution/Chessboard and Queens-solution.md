# Chessboard and Queens - Solution

**ID:** 1624 | **URL:** https://cses.fi/problemset/task/1624

## Approach

### Problem Restatement

Count the number of ways to place 8 queens on an $8 \times 8$ chessboard with some reserved squares (`*`), such that no two queens attack each other and no queen is placed on a reserved square.

### Core Idea

Since each row must contain exactly one queen, we place queens row by row. At each row, we try all columns and check whether the column and both diagonals are unoccupied and the square is not reserved. Backtracking explores all valid configurations.

**Diagonal indexing:** Two squares $(r_1, c_1)$ and $(r_2, c_2)$ share a diagonal iff:
- Left diagonal (top-left to bottom-right): $r_1 - c_1 = r_2 - c_2$ (each step down-right increments both $r$ and $c$ by 1).
- Right diagonal (top-right to bottom-left): $r_1 + c_1 = r_2 + c_2$ (each step down-left increments $r$ by 1 and decrements $c$ by 1).

Using boolean arrays indexed by these values gives $O(1)$ conflict checking per square, instead of scanning all previously placed queens in $O(n)$.

**Correctness:** The recursion tries all 8 columns for each row, exploring every valid placement. The three boolean arrays (`col`, `ld`, `rd`) guarantee no two queens share a column or diagonal; `board[r][c] == '.'` guarantees no queen sits on a reserved square. Each placement is uniquely determined by the column choice per row, so no placement is counted twice.

### Algorithm

1. Read the $8 \times 8$ board. Initialize `col[1..8]`, `ld[1..15]`, `rd[2..16]` as `false`, `count = 0`.
2. Recurse on row $r$:
   - If $r > 8$: increment `count`.
   - For each column $c$ from 1 to 8: if `col[c]`, `ld[r-c+8]`, `rd[r+c]` are all `false` and `board[r][c] == '.'`:
     - Mark them `true`, recurse on row $r+1$, then mark them `false` (backtrack).
3. Output `count`.

### Example

The sample board has 4 reserved squares (at positions (3,3), (6,6), (6,7), (7,4)). Without reserved squares, there are 92 valid placements for 8 queens. With these squares blocked, the answer is 65.

For instance, placing a queen at $(1,4)$: left diagonal index $= 1-4+8 = 5$, right diagonal index $= 1+4 = 5$. These arrays are marked, so no future queen can share either diagonal.

## Complexity

- **Time:** $O(n!)$ worst case, but pruning reduces this drastically — for $n=8$, fewer than 40320 nodes are explored
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Chessboard%20and%20Queens.cpp)
