# Knight's Tour - Solution

**ID:** 1689 | **URL:** https://cses.fi/problemset/task/1689

## Approach

### Problem Restatement

Given a starting position on an $8 \times 8$ chessboard, find a sequence of knight moves that visits every square exactly once. The knight moves in an L-shape: two squares in one direction and one square in the perpendicular direction.

### Core idea

The problem is equivalent to finding a Hamiltonian path on the knight's move graph. Brute-force backtracking is infeasible due to the large branching factor, so we use **Warnsdorff's heuristic** — a greedy strategy that almost always finds a solution on the first attempt:

> From the current square, always move to the unvisited neighbor with the **fewest unvisited neighbors** (minimum degree).

This works because squares with few entry points (corners, edges) become inaccessible if left for late stages — their remaining exits get consumed by earlier visits to adjacent squares. By visiting them early, central squares (which have many entry points) stay reachable. On an $8 \times 8$ board, this heuristic succeeds with very high probability.

When multiple neighbors share the same minimum degree, random tie-breaking ensures different iteration orders across attempts. If the algorithm gets stuck before visiting all 64 squares, it restarts. In practice, convergence takes only 1–3 attempts.

### Algorithm

1. Initialize all squares as unvisited. Mark the starting square as step 1.
2. For each of the 63 remaining steps:
   - For each of the 8 knight-move directions (starting from a random offset), compute the degree of the resulting square — the count of its unvisited neighbors.
   - Move to the unvisited neighbor with the minimum degree.
3. If no valid move exists before completing 64 squares, clear the board and restart from step 1.

### Example

Input: `2 1` (starting at row 1, column 2).

One valid output:

```
 8  1 10 13  6  3 20 17
11 14  7  2 19 16 23  4
26  9 12 15 24  5 18 21
49 58 25 28 51 22 33 30
40 27 50 59 32 29 52 35
57 48 41 44 37 34 31 62
42 39 46 55 60 63 36 53
47 56 43 38 45 54 61 64
```

At the starting square $(1,2)$, the knight has 3 valid neighbors:

| Neighbor | Degree |
|----------|--------|
| $(3,3)$  | 7      |
| $(2,4)$  | 5      |
| $(3,1)$  | 3      |

Warnsdorff selects $(3,1)$ with the minimum degree of 3. The process repeats at each step until all 64 squares are visited.

## Complexity

- **Time:** $O(N^2)$ expected, where $N$ is the board dimension
- **Space:** $O(N^2)$

## Code (C++)

[Solution Code](../code/Knight%27s%20Tour.cpp)
