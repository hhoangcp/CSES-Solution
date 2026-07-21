# Counting Bishops - Solution

**ID:** 2176 | **URL:** https://cses.fi/problemset/task/2176

## Approach

### Problem Restatement

Count the number of ways to place $k$ bishops on an $n \times n$ chessboard such that no two bishops attack each other (i.e., no two share a diagonal). Result modulo $10^9 + 7$.

### Color independence

On a chessboard, each cell has one of two colors. A bishop moves along diagonals, and every diagonal consists entirely of one color. Therefore, bishops on dark squares and bishops on light squares are completely independent — they can never attack each other across colors.

Split the problem: let $B_i$ = ways to place $i$ non-attacking bishops on dark squares, and $W_j$ = ways to place $j$ non-attacking bishops on light squares. The answer is:

$$\text{ans} = \sum_{i=0}^{k} B_i \cdot W_{k-i}$$

### Reduction to rook placement on a staircase board

After rotating the board $45^\circ$, the diagonals of one direction become "rows" and the diagonals of the other direction become "columns." Placing a non-attacking bishop (no two share any diagonal) becomes placing a non-attacking rook (no two share a row or column) on the resulting board.

This rotated board has a staircase shape: for each color, the diagonal sizes sorted in non-decreasing order form a staircase. The key property of a staircase is that each row's columns are a superset of all previous rows' columns. This means when processing rows in non-decreasing order, each previously placed rook blocks exactly one column in the current row.

### Diagonal sizes

For an $n \times n$ board, the diagonals of each color (indexed $p = 1, 2, \ldots, 2n-1$) have sizes given by:

$$\text{Squares}(p) = \begin{cases} \lfloor p/4 \rfloor \cdot 2 + 1 & \text{if } p \text{ is odd} \\ \lfloor (p-1)/4 \rfloor \cdot 2 + 2 & \text{if } p \text{ is even} \end{cases}$$

This enumeration processes diagonals in non-decreasing order of size within each color: odd indices $1, 3, 5, \ldots$ for one color and even indices $2, 4, 6, \ldots$ for the other. For $n = 5$: dark sizes are $\{1, 1, 3, 3, 5\}$ (sum 13), light sizes are $\{2, 2, 4, 4\}$ (sum 12).

### DP recurrence

Let $\text{dp}[i][j]$ = number of ways to place $j$ non-attacking bishops on the first $i$ same-colored diagonals. The recurrence steps by 2 (consecutive same-colored diagonals are separated by one of the other color):

$$\text{dp}[i][j] = \text{dp}[i-2][j] + \text{dp}[i-2][j-1] \cdot (\text{Squares}(i) - j + 1)$$

- **First term:** Don't place a bishop on diagonal $i$.
- **Second term:** Place one bishop on diagonal $i$. There are $\text{Squares}(i)$ cells, but $j-1$ columns (i.e., perpendicular diagonals) are already occupied by previously placed bishops. Each such bishop blocks exactly one cell on diagonal $i$ (since perpendicular diagonals intersect in exactly one cell). So $\text{Squares}(i) - (j-1)$ cells are available.

The staircase property guarantees this count is correct: processing diagonals in non-decreasing size order ensures that all $j-1$ occupied perpendicular diagonals do intersect diagonal $i$.

### Examples

**Problem example:** $n = 5$, $k = 4$.

**Light squares** (even indices, sizes $\{2, 2, 4, 4\}$):

| $i$ | Size | $j{=}0$ | $j{=}1$ | $j{=}2$ | $j{=}3$ | $j{=}4$ |
|-----|------|---------|---------|---------|---------|---------|
| 0 | — | 1 | | | | |
| 2 | 2 | 1 | 2 | | | |
| 4 | 2 | 1 | 4 | 2 | | |
| 6 | 4 | 1 | 8 | 14 | 4 | |
| 8 | 4 | 1 | 12 | 38 | 32 | 4 |

E.g., $\text{dp}[6][2] = \text{dp}[4][2] + \text{dp}[4][1] \cdot (4 - 2 + 1) = 2 + 4 \cdot 3 = 14$.

**Dark squares** (odd indices, sizes $\{1, 1, 3, 3, 5\}$): similarly, $\text{dp}[9]$ gives $B_0{=}1, B_1{=}13, B_2{=}46, B_3{=}46, B_4{=}8$.

**Combining:** $\sum_{i=0}^{4} B_i \cdot W_{4-i} = 1{\cdot}4 + 13{\cdot}32 + 46{\cdot}38 + 46{\cdot}12 + 8{\cdot}1 = 2728$. ✓

## Complexity

- **Time:** $O(nk)$ — two DP passes over diagonals, each with $O(k)$ work per diagonal.
- **Space:** $O(nk)$ — for the DP table.

## Code (C++)

[Solution Code](../code/Counting%20Bishops.cpp)
