# Grid Path Construction - Solution

**ID:** 2418 | **URL:** https://cses.fi/problemset/task/2418

## Approach

### Problem Restatement

Given an $R \times C$ grid and two cells $A = (sr, sc)$ and $B = (er, ec)$, construct a Hamiltonian path from $A$ to $B$ (visiting every cell exactly once), or report that none exists.

### Feasibility check (`feasible`)

The function `feasible` determines whether a Hamiltonian path exists in $O(1)$ by applying necessary and sufficient conditions. Itai et al. [1] proved that these conditions completely characterize the existence of Hamiltonian paths in rectangular grid graphs.

**Parity rule (chessboard coloring).** Color cell $(r, c)$ white if $(r+c) \bmod 2 = 0$, black otherwise. A path must alternate colors, so:

- **$RC$ even:** Both colors have equal count. A Hamiltonian path requires $A$ and $B$ to have **different** colors.
- **$RC$ odd:** White cells outnumber black by 1. A Hamiltonian path requires $A$ and $B$ to both be **white** (the majority color).

**Geometric forbidden configurations** (assuming $R \le C$ after swapping):

- **$R = 1$:** The path is a straight line, so $A$ and $B$ must be at opposite endpoints (column 1 or column $C$).
- **$R = 2$, same column, non-boundary:** If $sc = ec$ and $1 < sc < C$, then $A$ and $B$ form a "wall" that splits the grid into two disconnected regions — the path cannot visit both.
- **$R = 3$, $C$ even, different colors:** A "dead corner" configuration exists when $A$ has color 1 and $B$ has color 0, and either ($A$ is in the middle row and $x_A < x_B$) or ($A$ is not in the middle row and $x_A < x_B - 1$). This must also be checked after horizontal flip and swapping $A \leftrightarrow B$.

These conditions are both necessary and sufficient: whenever `feasible` returns true, a Hamiltonian path can always be constructed.

### Geometric normalization

The algorithm uses three transformations to reduce cases:

- **`rotate`:** 90° clockwise rotation. Maps $(r, c) \to (c, R+1-r)$ and swaps dimensions. Also remaps direction characters (U↔L, D↔R, etc.).
- **`transpose`:** Swap rows and columns, mapping $(r, c) \to (c, r)$.
- **`flip_horizontal` / `flip_vertical`:** Mirror the grid, swapping direction characters accordingly.

By applying these, the algorithm can always assume a canonical orientation (e.g., $R \le C$, $sc \le ec$) and handle all symmetric cases with a single code path.

### Divide-and-conquer construction (`build`)

The `build` function constructs the path using two complementary strategies:

**Strategy 1 — Strip and splice.** Try all 4 rotations. If both $A$ and $B$ are at least 3 rows from the top edge (i.e., $sr \ge 3$ and $er \ge 3$), strip 2 rows from the top and recursively solve the core $(R-2) \times C$ grid. Then `splice` extends the core path into the stripped region:

1. Walk along the core path until finding two adjacent cells in row 3 (the boundary between core and strip).
2. At that point, insert a 2-row Hamiltonian path (via `build(2, C, ...)`) covering the stripped rows.
3. The even-area strip always contains a Hamiltonian cycle, so splicing is always possible when `feasible` holds.

**Strategy 2 — Split.** If stripping fails (one of $A, B$ is too close to every edge), normalize to $R \le C$ and $sc \le ec$, then try cutting off 2 columns from the left. Search for a junction row `cut_r` such that both halves are feasible:

$$\texttt{feasible}(R, 2, sr, sc, cut\_r, 2) \wedge \texttt{feasible}(R, C{-}2, cut\_r, 1, er, ec{-}2)$$

If found, recursively build both halves and join them with a single `R` step.

**Fallback — `solve_4x5`.** The only grid that resists both strip and split is $4 \times 5$ with $A$ and $B$ both near the left edge. This single special case is handled by either splitting it into two sub-grids or using a hardcoded 19-step path.

### Base cases

- **`solve_2xC` ($C \le 3$):** Constructs a U-shaped or zigzag path for 2-row grids. The path traverses the top row right, drops down, then traverses the bottom row left.
- **`solve_3x3`:** Hardcoded paths for the 9 possible $(A, B)$ configurations (up to rotation).
- **$1 \times C$:** A straight horizontal line `string(C-1, 'R')`.

### Example

For the problem's example: $4 \times 7$ grid, $A = (1, 3)$, $B = (3, 6)$:

- `feasible(4, 7, 1, 3, 3, 6) = true` (even area, different colors).
- Strip fails ($A$ is on row 1). After normalization, split at column 2 finds a valid junction.
- Output: `RDLLULDDDRURDRURDRRUUULLDRD` (27 steps visiting all 28 cells).

For $1 \times 3$, $A = (1, 2)$, $B = (1, 3)$: $A$ is not at an endpoint (column 2), so `feasible` returns false → `NO`.

## Complexity

- **Time:** $O(RC \cdot \max(R, C))$ per test case.
  - Each `feasible` call is $O(1)$.
  - The strip phase tries 4 rotations per call ($O(1)$). The `splice` function iterates through the entire core path string (length $O(RC)$) to find the insertion point and build the result.
  - The split phase searches $O(R)$ junction rows, each checked in $O(1)$ via `feasible`. String concatenation of the two sub-paths takes $O(RC)$.
  - Each strip reduces rows by 2; each split reduces columns by 2. The recursion depth is $O(\max(R, C))$.
  - At each level, the string operations cost $O(RC)$, giving $O(RC \cdot \max(R, C))$ total.
- **Space:** $O(RC)$ for the output string and $O(\max(R, C))$ recursion depth.

## References

- [1] A. Itai, C. H. Papadimitriou, J. L. Szwarcfiter. [Hamilton Paths in Grid Graphs](https://www.ibr.cs.tu-bs.de/courses/ws2223/ag/papers/Ch8/1982-Itai_GridGraphs.pdf). *SIAM Journal on Computing*, 11(4):676–686, 1982. — Proves the necessary and sufficient conditions for Hamiltonian paths in grid graphs.

## Code (C++)

[Solution Code](../code/Grid%20Path%20Construction.cpp)
