# Swap Game - Solution

**ID:** 1670 | **URL:** https://cses.fi/problemset/task/1670

## Problem Statement

Given a $3 \times 3$ grid containing numbers 1-9, find the minimum number of adjacent swaps (horizontal or vertical) to reach the target state $\begin{pmatrix} 1&2&3\\4&5&6\\7&8&9 \end{pmatrix}$.

## Approach

### State space

There are $9! = 362880$ possible states (permutations of 9 numbers). This is small enough to enumerate all states and store them in memory.

### State encoding

Encode each grid as an integer in base 9: $\text{state} = \sum_{i=0}^{8} (grid[i] - 1) \times 9^i$. Each permutation maps 1-1 to an integer, allowing a 1D `visited` array. To save memory, offset by the minimum encoded value.

### BFS

Since each swap has cost 1, BFS finds the shortest path:

1. Push the initial state into the queue with distance 0.
2. For each state, try all 12 valid adjacent swaps (6 horizontal: positions where $i \bmod 3 < 2$, and 6 vertical: positions where $i < 6$).
3. Mark visited on first discovery; BFS guarantees shortest distance.
4. Stop when the target state is reached.

### Example

```
2 1 3        1 2 3
7 5 9   →    4 5 6
8 4 6        7 8 9
```

BFS finds the minimum: **4 steps**.

## Complexity

- **Time:** $O(9!) = O(362880)$ — worst case visits all permutations
- **Memory:** $O(9!)$ for the visited array

## Code (C++)

[Solution Code](../code/Swap%20Game.cpp)
