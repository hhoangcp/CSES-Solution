# Stair Game - Solution

**ID:** 1099 | **URL:** https://cses.fi/problemset/task/1099

## Approach

### Problem Restatement

There are $n$ stairs numbered $1, 2, \ldots, n$, each with some balls. Two players alternate turns. Each turn, a player chooses stair $k \neq 1$ with at least one ball and moves any number of balls from stair $k$ to stair $k-1$. The last player to move wins. Determine the winner when both play optimally.

### Core idea

Moving balls from step $k$ to $k-1$ resembles Nim, but balls don't disappear — they transfer downward. Balls at step 1 are terminal (cannot be moved further since $k \neq 1$).

**Key observation:** The game is equivalent to Nim played on **even-positioned steps**. The first player wins iff the XOR of balls on even steps is nonzero.

**Why odd steps don't matter:** Moving $m$ balls from an odd step $2j+1$ to the even step $2j$ below increases the "Nim pile" at step $2j$ by $m$. But the opponent can then move those same $m$ balls from step $2j$ to step $2j-1$ (odd), restoring the original state. So moves from odd steps can always be neutralized.

**Proof of equivalence:**
- From $S = 0$ (XOR of even steps), every move makes $S \neq 0$: moving from even step $2j$ changes $p_{2j}$; moving from odd step $2j+1$ changes $p_{2j}$. Either way, the XOR of even steps changes.
- From $S \neq 0$, there exists a move to $S' = 0$: find an even step $2j$ contributing to the highest bit of $S$, and move $p_{2j} - (p_{2j} \oplus S)$ balls from step $2j$ to step $2j-1$. This is valid since $p_{2j} \oplus S < p_{2j}$.
- Terminal position: all balls at step 1, all even steps empty, $S = 0$. This is a losing position.

### Algorithm

For each test case, compute the XOR of $p_i$ for all even indices $i$. If nonzero, output "first"; otherwise "second".

### Example

| Balls | Even-step values | XOR | Winner |
|-------|-----------------|-----|--------|
| $[0, 2, 1]$ | $p_2 = 2$ | $2 \neq 0$ | first |
| $[1, 1, 1, 1]$ | $p_2 = 1, p_4 = 1$ | $1 \oplus 1 = 0$ | second |
| $[5, 3]$ | $p_2 = 3$ | $3 \neq 0$ | first |

## Complexity

- **Time:** $O(n)$ per test case
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Stair%20Game.cpp)
