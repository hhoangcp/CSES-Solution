# Raab Game I - Solution

**ID:** 3399 | **URL:** https://cses.fi/problemset/task/3399

## Approach

### Problem Restatement

Two players each have cards numbered $1, 2, \ldots, n$. Each round, both reveal a card — the higher card scores 1 point (equal = draw). Given final scores $a$ and $b$, construct a valid match, or determine if impossible.

### Core Idea

A valid match exists if and only if:
1. $a + b \leq n$ (at most 1 winner per round, so total wins can't exceed $n$).
2. Either both $a$ and $b$ are positive, or both are zero. If $a = 0$ and $b > 0$, after all draws (both play the same card), both players have identical remaining decks — making it impossible for one to always win without the other ever winning.

**Construction** (when valid): Let $h = n - a - b$ (draw rounds). Partition into 3 phases:
1. **Draws** ($h$ rounds): Both play cards $1, 2, \ldots, h$.
2. **Player 1 wins** ($a$ rounds): Player 1 plays their highest cards ($n{-}a{+}1$ to $n$), Player 2 plays middle cards ($h{+}1$ to $h{+}a$).
3. **Player 2 wins** ($b$ rounds): Player 2 plays their highest cards ($n{-}b{+}1$ to $n$), Player 1 plays middle cards ($h{+}1$ to $h{+}b$).

Each paired card in Player 1's win phase differs by exactly $b > 0$ (since $A[i] - B[i] = n - a - h = b$), so Player 1 always wins. By symmetry, Player 2 always wins in their phase. Since $h + a + b = n$, all card intervals are disjoint and cover every card exactly once.

### Algorithm

1. If $(a = 0 \neq b)$ or $(b = 0 \neq a)$ or $(a + b > n)$: output `NO`.
2. Otherwise, output `YES` and the three-phase construction above.

### Example

From the sample:
- $n=4, a=1, b=2$: $h=1$. Draw: P1=1, P2=1. P1 wins: P1=4, P2=2. P2 wins: P1=2, P2=3 and P1=3, P2=4. P1: [1,4,2,3], P2: [1,2,3,4]. ✓
- $n=2, a=0, b=1$: $a=0$ but $b>0$ → `NO`.
- $n=3, a=0, b=0$: all draws → `YES`.
- $n=2, a=1, b=1$: $h=0$. P1 wins: (2,1). P2 wins: (1,2). P1: [2,1], P2: [1,2]. ✓
- $n=4, a=4, b=1$: $a+b=5>4$ → `NO`.

## Complexity

- **Time:** $O(n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Raab%20Game%20I.cpp)
