# Knight Moves Grid - Solution

**ID:** 3217 | **URL:** https://cses.fi/problemset/task/3217

## Approach

### Problem Restatement

Given an $n \times n$ chessboard ($4 \le n \le 1000$), compute for each cell the minimum number of knight moves from $(0,0)$. A knight moves in an "L" shape: 2 squares in one direction and 1 square perpendicular.

### Core Idea

Model the grid as an unweighted graph where each cell is a vertex and edges connect cells separated by one knight move (8 neighbors per cell: $(r \pm 2, c \pm 1)$ and $(r \pm 1, c \pm 2)$). BFS finds shortest paths on unweighted graphs by exploring vertices in layers of increasing distance — the first time a vertex is reached, the shortest path to it is guaranteed. If a shorter path existed, its predecessor would have been processed earlier, discovering the vertex sooner, a contradiction.

**Mark on enqueue:** Mark a cell visited when pushing it to the queue, not when popping. Otherwise, the same cell can be enqueued by multiple neighbors in the same layer, causing queue bloat. Since the first discovery always yields the optimal distance, skipping duplicates is safe.

**Reachability:** For $n \ge 5$, all cells are reachable from $(0,0)$. For $n \le 4$, some cells may be unreachable and retain distance 0.

### Algorithm

1. Initialize distance grid to 0, mark $(0,0)$ as visited with distance 0, enqueue it.
2. While the queue is not empty:
   - Dequeue $(r, c)$.
   - For each of 8 knight moves to $(nr, nc)$: if in bounds and unvisited, set distance $= d[r][c] + 1$, mark visited, and enqueue.
3. Output the distance grid.

### Example

$n = 8$:

```
0 3 2 3 2 3 4 5
3 4 1 2 3 4 3 4
2 1 4 3 2 3 4 5
3 2 3 2 3 4 3 4
2 3 2 3 4 3 4 5
3 4 3 4 3 4 5 4
4 3 4 3 4 5 4 5
5 4 5 4 5 4 5 6
```

Check: $(0,0) = 0$, $(1,2) = 1$ (one knight move), $(0,1) = 3$.

## Complexity

- **Time:** $O(n^2)$
- **Space:** $O(n^2)$

## Code (C++)

[Solution Code](../code/Knight%20Moves%20Grid.cpp)
