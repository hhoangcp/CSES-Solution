# Coin Arrangement - Solution

**ID:** 2180 | **URL:** https://cses.fi/problemset/task/2180

## Problem Statement

A $2 \times n$ grid has some coins in each cell, total $2n$ coins. Each cell must have exactly 1 coin. Each move transfers 1 coin by 1 cell (left, right, up, down). Find the minimum total number of moves.

## Approach

Process columns greedily from left to right. At each column, two steps — both forced and optimal:

1. **Balance vertically first (optimal — reduces horizontal cost):** If one cell has surplus and the other has deficit, transfer directly within the column. Any alternative that moves horizontally first then vertically/diagonally costs $\geq$ transferring directly $(1,i) \to (2,i)$, since each extra horizontal step is wasteful. Balancing vertically first reduces the number of coins that must move horizontally, minimizing global cost.

2. **Push surplus right (forced — no other recipient in column):** After vertical balancing, remaining surplus/deficit must go to the next column. Since total is exactly $2n$, every surplus coin left of column $i$ must pass through $i$ to go right, and every deficit must be filled from the right. Horizontal cost is 1 per cell, so transferring immediately to the next column never increases total cost. The last column auto-balances due to total $2n$.

$\Rightarrow$ Every step is forced, no action is redundant, so total cost is minimum.

## Algorithm

For each column $i$ from 1 to $n$:
1. **Vertical balancing:** If $a[i] < 1$ and $b[i] > 1$: transfer $\Delta = \min(1-a[i], b[i]-1)$ from bottom to top, add $\Delta$ to answer. If $a[i] > 1$ and $b[i] < 1$: transfer $\Delta = \min(a[i]-1, 1-b[i])$ from top to bottom, add $\Delta$ to answer.
2. **Horizontal cost:** Add $|a[i]-1| + |b[i]-1|$ to answer.
3. **Update next column:** $a[i+1] \mathrel{+}= (a[i]-1)$, $b[i+1] \mathrel{+}= (b[i]-1)$.

## Example

$n = 4$, top $[0,1,0,1]$, bottom $[2,0,1,3]$.

- **Column 1:** Bottom (2) transfers 1 to Top (0). Cost +1. Column 1: `[1,1]`.
- **Column 2:** Top 1, Bottom 0. Bottom deficit 1, shift to column 3. Cost +1.
- **Column 3:** Top 0, Bottom 0 (already gave to column 2). Both deficit 2 coins, take from column 4. Cost +2.
- **Column 4:** Bottom has 2, Top 0. Transfer 1 from bottom to top. Cost +1.
- **Total:** $1 + 1 + 2 + 1 = 5$.

## Complexity

- **Time:** $O(n)$
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Coin%20Arrangement.cpp)
