# String Reorder - Solution

**ID:** 1743 | **URL:** https://cses.fi/problemset/task/1743

## Approach

### Problem Restatement

Reorder a string of uppercase letters A–Z so that no two adjacent characters are identical, and the result is the lexicographically smallest among all valid rearrangements. If impossible, output $-1$.

### Core Idea

We combine a **feasibility check** with a **greedy strategy that detects forced characters**.

**Feasibility.** A valid rearrangement exists iff no character appears more than $\lceil n/2 \rceil$ times, equivalently $\text{cnt}[c] \times 2 \le n + 1$ for all $c$. *Necessity:* character $c$ can occupy at most all alternating positions ($\lceil n/2 \rceil$ slots); exceeding this forces two copies to be adjacent by the Pigeonhole Principle. *Sufficiency:* if every $\text{cnt}[c] \le \lceil n/2 \rceil$, always choosing the highest-frequency character different from the previous one produces a valid arrangement — no character ever exceeds half the remaining positions at any step.

**Forced characters.** A simple greedy that always picks the smallest character different from the previous one can fail: it may leave a high-frequency character with too few slots, creating a dead end. Instead, at each step with `remaining` positions left, character $c$ is **forced** when $\text{cnt}[c] > \text{remaining}/2$ (equivalently, $\text{cnt}[c] \times 2 - \text{remaining} > 0$). If $c$ is forced and we place a different character instead, the remaining positions shrink to $\text{remaining}-1$ while $\text{cnt}[c]$ stays the same, making the subproblem infeasible — hence $c$ must be placed immediately. Since we start from a feasible state and each step maintains feasibility, $\text{cnt}[c] \times 2 - \text{remaining}$ is always exactly $1$ when a character is forced, so the check simplifies to $\text{cnt}[c] \times 2 - \text{remaining} = 1$.

**Greedy choice.** When no character is forced, we scan from A to Z and pick the first character $c$ satisfying: (1) $c \neq \text{last}$, (2) $\text{cnt}[c] > 0$, and (3) $\text{cnt}[c] \times 2 - \text{remaining} < 1$ (placing $c$ keeps the subproblem feasible — for the placed character this means its remaining count after placement stays within half the remaining slots; for other characters, the forced scan already guarantees feasibility). Since we scan alphabetically, the first valid $c$ is the smallest character that preserves feasibility, guaranteeing lexicographic optimality.

### Algorithm

1. **Count** the frequency of each character.
2. **Check feasibility:** if any $\text{cnt}[c] \times 2 > n + 1$, output $-1$.
3. **Build the result** character by character, with `remaining = n` and `last = -`:
   - **Forced scan:** find character $c \neq \text{last}$ with $\text{cnt}[c] \times 2 - \text{remaining} = 1$. If found, place $c$.
   - **Greedy scan:** otherwise, find the first character $c$ from A to Z such that $c \neq \text{last}$, $\text{cnt}[c] > 0$, and $\text{cnt}[c] \times 2 - \text{remaining} < 1$. Place $c$.
   - Decrement $\text{cnt}[c]$, set $\text{last} = c$, decrement `remaining`.

### Example

**Input:** `HATTIVATTI` ($n = 10$, frequencies: A=2, H=1, I=2, T=4, V=1)

| remaining | last | Forced? | Choose | Remaining counts |
|---|---|---|---|---|
| 10 | - | T: 8−10 < 0 → none | A (smallest, safe) | A=1, H=1, I=2, T=4, V=1 |
| 9 | A | T: 8−9 < 0 → none | H (smallest ≠ A, safe) | A=1, H=0, I=2, T=4, V=1 |
| 8 | H | T: 8−8 = 0 → none | A (smallest ≠ H, safe) | A=0, H=0, I=2, T=4, V=1 |
| 7 | A | **T: 8−7 = 1** → forced | T | A=0, H=0, I=2, T=3, V=1 |
| 6 | T | none | I (smallest ≠ T, safe) | A=0, H=0, I=1, T=3, V=1 |
| 5 | I | **T: 6−5 = 1** → forced | T | A=0, H=0, I=1, T=2, V=1 |
| 4 | T | none | I (smallest ≠ T, safe) | A=0, H=0, I=0, T=2, V=1 |
| 3 | I | **T: 4−3 = 1** → forced | T | A=0, H=0, I=0, T=1, V=1 |
| 2 | T | none | V (smallest ≠ T, safe) | A=0, H=0, I=0, T=1, V=0 |
| 1 | V | **T: 2−1 = 1** → forced | T | A=0, H=0, I=0, T=0, V=0 |

**Output:** `AHATITITVT` ✓

## Complexity

- **Time:** $O(n \times |\Sigma|) = O(n)$, where $|\Sigma| = 26$ — for each of $n$ positions, we scan at most 26 characters twice (forced + greedy).
- **Space:** $O(|\Sigma|) = O(1)$ — a fixed-size frequency array of 26 integers.

## Code (C++)

[Solution Code](../code/String%20Reorder.cpp)
