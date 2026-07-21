# Nim Game I - Solution

**ID:** 1730 | **URL:** https://cses.fi/problemset/task/1730

## Approach

### Problem Restatement

There are $n$ piles of sticks. Two players alternate turns. Each turn, a player chooses a non-empty pile and removes any positive number of sticks. The player taking the last stick wins. Determine the winner when both play optimally.

### Core idea

**Bouton's theorem (1901):** The first player wins if and only if $S = x_1 \oplus x_2 \oplus \cdots \oplus x_n \neq 0$.

**Proof.** We verify three properties:

1. **Terminal position:** All piles empty → $S = 0$. This is a losing position (no moves).

2. **From $S = 0$, every move leads to $S' \neq 0$:** Reducing $x_i$ to $x_i'$ gives $S' = 0 \oplus x_i \oplus x_i' = x_i \oplus x_i'$. Since $x_i' < x_i$, two different numbers always have nonzero XOR.

3. **From $S \neq 0$, there exists a move to $S' = 0$:** Let bit $d$ be the highest set bit of $S$. Some pile $x_i$ must have bit $d$ set (odd number of piles contribute). Set $x_i' = x_i \oplus S$. Since bit $d$ is set in both $x_i$ and $S$, it clears in $x_i'$, so $x_i' < x_i$. This gives $S' = S \oplus x_i \oplus x_i' = S \oplus x_i \oplus (x_i \oplus S) = 0$.

These properties establish that $S = 0$ positions form the losing set: from $S = 0$ you can only reach $S \neq 0$, and from $S \neq 0$ you can always reach $S = 0$. Since the game is finite, the first player wins iff $S \neq 0$.

### Algorithm

For each test case, compute the XOR of all pile sizes. If nonzero, output "first"; otherwise "second".

### Example

| Piles | XOR | Winner |
|-------|-----|--------|
| $\{5, 7, 2, 5\}$ | $5 \oplus 7 \oplus 2 \oplus 5 = 7 \neq 0$ | first |
| $\{4, 1\}$ | $4 \oplus 1 = 5 \neq 0$ | first |
| $\{3, 5, 6\}$ | $3 \oplus 5 \oplus 6 = 0$ | second |

## Complexity

- **Time:** $O(n)$ per test case
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Nim%20Game%20I.cpp)
