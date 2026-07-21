# Labyrinth - Solution

**ID:** 1193 | **URL:** https://cses.fi/problemset/task/1193

## Approach

### Problem Restatement

Given an $n \times m$ maze with start `A` and end `B`, find the shortest path from `A` to `B` moving in 4 directions through floor cells (`.`). Output the path length and direction string, or "NO" if no path exists.

### Core idea

Model the maze as an unweighted grid graph: each floor cell is a vertex, adjacent cells in 4 directions share an edge. BFS on an unweighted graph always finds the shortest path — when a vertex is first discovered, it is reached via the minimum number of edges from the source. If `A` is never visited, it is unreachable from `B`.

BFS runs **from `B` toward `A`**. The `trace` array stores each cell's parent (closer to `B`) in the BFS tree, so tracing from `A` to `B` via `trace` pointers produces direction characters in forward order (from `A` to `B`) without needing to reverse the string.

### Algorithm

1. Read the maze. Locate cells `A` and `B`.
2. Run BFS from `B`. For each discovered cell, store its parent (`trace`) and distance from `B` (`depth`).
3. If `A` was never visited, print "NO".
4. Otherwise, print "YES" and `depth[A]`. Trace from `A` to `B` via `trace`: at each step from current cell $t$ to parent $p$, output the direction based on their relative positions ($t.y > p.y \to$ `L`, $t.y < p.y \to$ `R`, $t.x > p.x \to$ `U`, $t.x < p.x \to$ `D`).

### Example

```
5 8
########
#.A#...#
#.##.#B#
#......#
########
```

BFS from $B = (3,7)$ discovers $A = (2,3)$ at distance 9. Tracing from $A$ to $B$:

$(2,3) \xrightarrow{L} (2,2) \xrightarrow{D} (3,2) \xrightarrow{D} (4,2) \xrightarrow{R} (4,3) \xrightarrow{R} (4,4) \xrightarrow{R} (4,5) \xrightarrow{R} (4,6) \xrightarrow{R} (4,7) \xrightarrow{U} (3,7)$

Output:
```
YES
9
LDDRRRRRU
```

## Complexity

- **Time:** $O(n \cdot m)$
- **Space:** $O(n \cdot m)$

## Code (C++)

[Solution Code](../code/Labyrinth.cpp)
