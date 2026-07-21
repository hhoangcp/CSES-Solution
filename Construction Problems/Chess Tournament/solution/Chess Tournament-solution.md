# Chess Tournament - Solution

**ID:** 1697 | **URL:** https://cses.fi/problemset/task/1697

## Approach

### Problem Restatement

Given $n$ players where player $i$ wants to play exactly $x_i$ games, and each pair of players can play at most one game, find a valid set of games or report that it is impossible.

### Core idea

Model the problem as **graph realization**: each player is a vertex, their desired game count is the degree, and each game is an edge. The constraint "each pair plays at most one game" means we need a simple graph (no multi-edges, no self-loops). So the problem reduces to: given degree sequence $x_1, x_2, \ldots, x_n$, construct a simple graph with the corresponding degrees.

Use the **Havel-Hakimi algorithm** implemented with a max-heap. The key insight is: if a degree sequence is graphical, we can always pair the highest-degree vertex with the next-highest-degree vertices without loss of generality.

The max-heap implements this greedily based on the Havel-Hakimi theorem: always pair the most constrained player first, which exactly corresponds to extracting the maximum degree and reducing the next $d_1$ largest degrees.

### Algorithm

1. Insert all players into a max-heap keyed by remaining game count.
2. Extract the player $u$ with the highest remaining game count.
3. Extract the top $x_u$ players from the heap. Pair each $v$ with $u$ and decrement $v$'s count by 1.
4. If the heap has fewer than $x_u$ players, or any extracted $v$ has count 0, output `IMPOSSIBLE`.
5. Push the paired players back into the heap with updated counts.
6. Repeat until the heap is empty.

### Example

$n = 5$, $x = [1, 3, 2, 0, 2]$ (players numbered $1 \ldots 5$):

- **Round 1:** Extract player 2 (needs 3 games). Heap has $\{(3, P1), (2, P3), (2, P5), (0, P4)\}$. Extract top 3: players 1, 3, 5. Pair $(2,1)$, $(2,3)$, $(2,5)$. Update: P1→0, P3→1, P5→1.
- **Round 2:** Extract player 3 (needs 1 game). Heap has $\{(1, P5), (0, P4), (0, P1)\}$. Extract top 1: player 5. Pair $(3,5)$. Update: P5→0.
- All remaining players have count 0. Done.

Result: 4 games $\{(1,2), (2,3), (2,5), (3,5)\}$, matching the expected output.

## Complexity

- **Time:** $O((n + S) \log n)$ where $S = \sum x_i$
- **Space:** $O(n + S)$

## Code (C++)

[Solution Code](../code/Chess%20Tournament.cpp)
