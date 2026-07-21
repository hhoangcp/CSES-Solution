# Counting Rooms - Solution

**ID:** 1192 | **URL:** https://cses.fi/problemset/task/1192

## Approach

### Problem Restatement

Given an $n \times m$ grid where each cell is either floor (`.`) or wall (`#`). Two floor cells are in the same room if connected by up/down/left/right moves through floor cells. Count the number of rooms.

### Core Idea

Model each floor cell as a vertex in a graph, with edges between adjacent floor cells. Each room is a **connected component** of this graph. Counting rooms is equivalent to counting connected components.

Run BFS/DFS flood-fill from each unvisited floor cell: each new BFS discovers one entire room and marks all its cells as visited. This is correct because:
- **No double counting:** BFS from cell $u$ marks all cells in the same room as visited, so they won't trigger another increment.
- **No missing rooms:** Every floor cell is examined; if unvisited, it belongs to a room not yet counted, so we increment and run BFS.

### Algorithm

1. Iterate over all $n \times m$ cells.
2. When encountering an unvisited floor cell: increment the room counter and run BFS from that cell.
3. BFS: enqueue the starting cell, mark visited. Dequeue a cell, examine its 4 neighbors — if a neighbor is within bounds, is a floor cell, and is unvisited, mark it visited and enqueue it.
4. When BFS ends, all cells in that room are marked. Continue scanning.

### Example

Input:
```
5 8
########
#..#...#
####.#.#
#..#...#
########
```

Scanning row by row:
- Cell $(2,2)$: unvisited floor → count = 1, BFS marks $(2,2), (2,3)$.
- Cell $(2,5)$: unvisited floor → count = 2, BFS marks $(2,5), (2,6), (2,7), (3,6), (4,6), (4,7)$.
- Cell $(4,2)$: unvisited floor → count = 3, BFS marks $(4,2), (4,3)$.

Output: `3`

## Complexity

- **Time:** $O(n \cdot m)$ — each cell is visited exactly once.
- **Space:** $O(n \cdot m)$ — `visited` array and BFS queue.

## Code (C++)

[Solution Code](../code/Counting%20Rooms.cpp)
