# Nim Game II - Solution

**ID:** 1098 | **URL:** https://cses.fi/problemset/task/1098

## Approach

### Problem Restatement

There are $n$ piles of sticks. Two players alternate turns. Each turn, a player chooses a non-empty pile and removes **exactly 1, 2, or 3** sticks. The player taking the last stick wins. Determine the winner when both play optimally.

### Core idea

This is a constrained Nim variant (impartial game), so **Sprague-Grundy theory** applies. For a single pile of $x$ sticks where 1–3 can be removed, the Grundy value is:

$$G(x) = \text{mex}\{G(x-1), G(x-2), G(x-3)\}, \quad G(0) = 0$$

Computing the first few values reveals a periodic pattern:

| $x$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|-----|---|---|---|---|---|---|---|---|---|
| $G(x)$ | 0 | 1 | 2 | 3 | 0 | 1 | 2 | 3 | 0 |

**Claim:** $G(x) = x \bmod 4$.

**Proof by induction.** Base cases $x = 0, 1, 2, 3$ verify directly. For the inductive step, assume $G(y) = y \bmod 4$ for all $y < x$, and consider $x \bmod 4$:

- $x \equiv 0$: neighbors have Grundy values $\{3, 2, 1\}$, so $\text{mex}\{1, 2, 3\} = 0$.
- $x \equiv 1$: neighbors have $\{0, 3, 2\}$, so $\text{mex}\{0, 2, 3\} = 1$.
- $x \equiv 2$: neighbors have $\{1, 0, 3\}$, so $\text{mex}\{0, 1, 3\} = 2$.
- $x \equiv 3$: neighbors have $\{2, 1, 0\}$, so $\text{mex}\{0, 1, 2\} = 3$.

By Sprague-Grundy theory, multiple independent piles combine via XOR. The overall Grundy value is:

$$S = \bigoplus_{i=1}^{n} (x_i \bmod 4)$$

The first player wins if $S \neq 0$, and loses if $S = 0$.

### Algorithm

For each test case, compute the XOR of all $x_i \bmod 4$. If nonzero, output "first"; otherwise "second".

### Example

| Piles | $x_i \bmod 4$ | XOR | Winner |
|-------|---------------|-----|--------|
| $\{5, 7, 2, 5\}$ | $\{1, 3, 2, 1\}$ | $1 \oplus 3 \oplus 2 \oplus 1 = 1 \neq 0$ | first |
| $\{4, 1\}$ | $\{0, 1\}$ | $0 \oplus 1 = 1 \neq 0$ | first |
| $\{4, 4, 4\}$ | $\{0, 0, 0\}$ | $0 \oplus 0 \oplus 0 = 0$ | second |

## Complexity

- **Time:** $O(n)$ per test case
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Nim%20Game%20II.cpp)
