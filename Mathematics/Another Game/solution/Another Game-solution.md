# Another Game - Solution

**ID:** 2208 | **URL:** https://cses.fi/problemset/task/2208

## Approach

### Problem Restatement

There are $n$ piles of coins and two players alternate turns. On each turn, a player chooses a non-empty subset of piles and removes exactly one coin from each chosen pile. The player taking the last coin wins. Determine the winner when both play optimally.

### Core Idea

Consider the parity of each pile. A state is **all-even** when every pile has an even number of coins.

**Case 1: All piles are even.** This is a losing position for the current player. Any move must choose a non-empty subset $T$ and decrement each pile in $T$, making those piles odd. The opponent then mirrors by choosing the same subset $T$, returning all piles to even. Since the total number of coins decreases by $2|T| \geq 2$ per pair of moves, the game terminates, and the opponent always takes the last coin.

**Case 2: At least one pile is odd.** The first player removes one coin from every odd pile. After this move, all piles become even, pushing the second player into Case 1 — a losing position.

**Corollary:** First player wins $\iff$ at least one pile is odd.

### Algorithm

1. For each test case, scan all piles.
2. If any pile is odd, output "first"; otherwise, output "second".

### Example

**Test 1:** $n = 3$, piles = $\{1, 2, 3\}$. Piles 1 and 3 are odd → first player removes from those → $\{0, 2, 2\}$ (all even). Second player is now in a losing position. Output: `first`.

**Test 2:** $n = 2$, piles = $\{2, 2\}$. Both even → first player loses. Whatever subset the first player chooses creates odd piles, and the second player mirrors. Output: `second`.

**Test 3:** $n = 4$, piles = $\{5, 5, 4, 5\}$. Piles 1, 2, and 4 are odd → first player removes from those three → $\{4, 4, 4, 4\}$ (all even). Second player is in a losing position. Output: `first`.

## Complexity

- **Time:** $O(n)$ per test case
- **Memory:** $O(1)$

## Code (C++)

[Solution Code](../code/Another%20Game.cpp)
