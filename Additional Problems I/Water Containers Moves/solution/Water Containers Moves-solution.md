# Water Containers Moves - Solution

**ID:** 3213 | **URL:** https://cses.fi/problemset/task/3213

## Problem Statement

Two water containers of capacities $a$ and $b$. Find a sequence of operations to obtain exactly $x$ units in container $A$, minimizing the total amount of water moved. If impossible, output -1.

## Approach

### Dijkstra on state graph

State: $(u_a, u_b)$. Initial: $(0, 0)$. Each edge weight = amount of water moved.

| Operation | New State | Cost |
|-----------|-----------|------|
| FILL A | $(a, u_b)$ | $a - u_a$ |
| FILL B | $(u_a, b)$ | $b - u_b$ |
| EMPTY A | $(0, u_b)$ | $u_a$ |
| EMPTY B | $(u_a, 0)$ | $u_b$ |
| MOVE A→B | $(u_a - m, u_b + m)$ | $m = \min(u_a, b - u_b)$ |
| MOVE B→A | $(u_a + m, u_b - m)$ | $m = \min(u_b, a - u_a)$ |

Since all edge weights are non-negative, Dijkstra finds the minimum total water moved. Stop when $u_a = x$. Trace back to reconstruct the operation sequence.

### Example

$a = 5, b = 3, x = 4$:

| Step | Operation | State | Cost |
|------|-----------|-------|------|
| 1 | FILL A | (5, 0) | 5 |
| 2 | MOVE A→B | (2, 3) | 3 |
| 3 | EMPTY B | (2, 0) | 3 |
| 4 | MOVE A→B | (0, 2) | 2 |
| 5 | FILL A | (5, 2) | 5 |
| 6 | MOVE A→B | (4, 3) | 1 |

Total: **6 steps, 19 units of water moved**.

## Complexity

- **Time:** $O(ab \log(ab))$ — at most $(a+1)(b+1)$ states
- **Memory:** $O(ab)$ for distance and trace arrays

## Code (C++)

[Solution Code](../code/Water%20Containers%20Moves.cpp)
