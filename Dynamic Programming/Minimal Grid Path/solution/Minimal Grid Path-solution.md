# Minimal Grid Path - Solution

**ID:** 3359 | **URL:** https://cses.fi/problemset/task/3359

## Approach

### Problem Restatement

Given an $n \times n$ grid of uppercase letters, find the lexicographically smallest string on any path from $(0,0)$ to $(n-1, n-1)$ moving only right or down.

### Core Idea

Every such path has exactly $2n - 1$ cells. Since each move (right or down) increases $i + j$ by exactly 1, the $k$-th character (0-indexed) always comes from a cell on anti-diagonal $i + j = k$. This means we can decide the string character-by-character, diagonal by diagonal.

**Greedy strategy:** At each diagonal $k$, choose the smallest character among all **reachable** cells. A cell $(i, j)$ is reachable if it is $(0,0)$, or has a reachable neighbor above $(i-1, j)$ or left $(i, j-1)$. After choosing the minimum character $c^*$, mark only the cells with character $c^*$ that have a reachable neighbor — this ensures path continuity.

**Why greedy is optimal:** Suppose two paths first differ at diagonal $k$. The one choosing the smaller character at $k$ is lexicographically smaller, regardless of what follows. So we must pick the smallest possible character at each diagonal. Note that not every cell with character $c^*$ on diagonal $k$ is reachable — only those with a reachable neighbor qualify, which maintains valid path structure.

### Algorithm

1. Group cells by anti-diagonal: `P[i+j]` contains all cells $(i,j)$ with $i+j = k$.
2. For each diagonal $k = 0, 1, \ldots, 2n-2$:
   - Find the minimum character $c^*$ among reachable cells in `P[k]`.
   - Output $c^*$.
   - Mark cell $(i,j) \in P[k]$ as reachable if $a[i][j] = c^*$ and (used$(i-1,j)$ or used$(i,j-1)$).

### Example

Input grid:

```
A A C A
B A B C
A B D A
A A C A
```

| $k$ | Reachable cells on diagonal | Smallest char | Reachable after |
|-----|------------------------------|---------------|-----------------|
| 0 | $(0,0)$: A | **A** | $(0,0)$ |
| 1 | $(0,1)$: A, $(1,0)$: B | **A** | $(0,1)$ |
| 2 | $(1,1)$: A | **A** | $(1,1)$ |
| 3 | $(1,2)$: B, $(2,1)$: B | **B** | $(1,2)$, $(2,1)$ |
| 4 | $(3,1)$: A | **A** | $(3,1)$ |
| 5 | $(3,2)$: C | **C** | $(3,2)$ |
| 6 | $(3,3)$: A | **A** | $(3,3)$ |

Result: `AAABACA`.

Note: at $k=2$, cell $(2,0)$ also has 'A' but is unreachable (no reachable neighbor). At $k=3$, cells $(0,3)$ and $(3,0)$ both have 'A' but are unreachable for the same reason — so the minimum reachable character is 'B'.

## Complexity

- **Time:** $O(n^2)$ — each cell is processed once per diagonal, $O(1)$ per cell
- **Space:** $O(n^2)$ — for the grid and reachability array

## Code (C++)

[Solution Code](../code/Minimal%20Grid%20Path.cpp)
