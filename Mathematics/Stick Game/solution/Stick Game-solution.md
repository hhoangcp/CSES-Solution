# Stick Game - Solution

**ID:** 1729 | **URL:** https://cses.fi/problemset/task/1729

## Approach

### Problem Restatement

A two-player game where players alternate removing sticks from one pile. A move set $P = \{p_1, p_2, \ldots, p_k\}$ specifies the exact number of sticks that can be removed per turn. The player taking the last stick wins. For each number of sticks from $1$ to $n$, determine if the starting position is winning (W) or losing (L).

### Core idea

In impartial combinatorial game theory:
- **Losing position (L):** Every move leads to a winning position for the opponent.
- **Winning position (W):** At least one move leads to a losing position for the opponent.

Let $dp[i]$ = true if $i$ sticks is a winning position. Then:

$$dp[i] = \bigvee_{j : p_j \le i} \neg dp[i - p_j]$$

Base case: $dp[0] = \text{false}$ (no sticks, no moves, current player loses).

**Proof by induction:** Base $i=0$: no valid moves, player loses. Inductive step: if $dp[i] = \text{true}$, some $p_j$ gives $dp[i-p_j] = \text{false}$, so the current player can move to a losing position for the opponent. If $dp[i] = \text{false}$, every $dp[i-p_j] = \text{true}$, so all moves leave the opponent in a winning position.

### Algorithm

1. Set $dp[0] = \text{false}$.
2. For $i = 1, \ldots, n$: $dp[i] = \text{true}$ iff there exists $p_j \le i$ with $dp[i - p_j] = \text{false}$.
3. Output 'W' if $dp[i] = \text{true}$, 'L' otherwise.

### Example

$n = 10$, $P = \{1, 3, 4\}$.

| $i$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|-----|---|---|---|---|---|---|---|---|---|---|---|
| $dp$ | L | W | L | W | W | W | W | L | W | L | W |

- $dp[1]$: take 1 $\to$ $dp[0] = L$ → W
- $dp[2]$: only take 1 $\to$ $dp[1] = W$ → L
- $dp[7]$: take 1 $\to$ $dp[6]=W$, take 3 $\to$ $dp[4]=W$, take 4 $\to$ $dp[3]=W$ → L

Result: `WLWWWWLWLW` $\checkmark$

## Complexity

- **Time:** $O(n \cdot k)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Stick%20Game.cpp)
