# Monsters - Solution

**ID:** 1194 | **URL:** https://cses.fi/problemset/task/1194

## Approach

### Problem Restatement

You are in an $n \times m$ maze with some monsters. Each step, you and all monsters move simultaneously (4 directions). Find a path from `A` to any boundary cell such that you never share a cell with a monster at the same time step. The monsters know your path in advance, so the plan must be safe in the worst case.

### Core idea

Let $d_A(v)$ be the BFS distance from `A` to cell $v$, and $d_M(v)$ be the shortest BFS distance from any monster to $v$. You can safely pass through $v$ at step $d_A(v)$ if and only if $d_A(v) < d_M(v)$ — you arrive before the nearest monster. If $d_A(v) \geq d_M(v)$, a monster is already there or arrives simultaneously, so the cell is unsafe.

To enforce this, run a **multi-source BFS** with all monsters and the player in the same queue, but push all monsters first. Since BFS processes vertices layer by layer, monsters at layer $d$ are always processed before the player at the same layer. A cell marked `visited` by a monster blocks the player from entering it, guaranteeing $d_A(v) < d_M(v)$ for every cell the player reaches. If the player reaches a boundary cell, a safe escape exists; if the player runs out of reachable cells, no safe path exists.

### Algorithm

1. Push all monsters into the BFS queue, then push `A`. Mark all initial positions as `visited`.
2. Process the queue: for each cell, expand in 4 directions.
   - If the cell belongs to a monster: mark neighbors `visited` (blocking the player).
   - If the cell belongs to the player and a neighbor is an unvisited boundary cell: **escape found**. Trace back from the boundary cell to `A` via `trace`, collect directions, reverse, and output.
   - If the cell belongs to the player and a neighbor is a valid unvisited cell: mark `visited`, record `trace`, enqueue.
3. If the player has no more reachable cells, output "NO".

### Example

Input:
```
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######
```

Monsters at $(2,2)$, $(3,5)$, $(4,2)$. Player at $(2,5)$. Multi-source BFS: monsters spread first, player only enters cells not yet claimed by monsters. Player reaches boundary cell $(4,8)$ after 5 steps.

Output:
```
YES
5
RRDDR
```

## Complexity

- **Time:** $O(n \cdot m)$
- **Space:** $O(n \cdot m)$

## Code (C++)

[Solution Code](../code/Monsters.cpp)
