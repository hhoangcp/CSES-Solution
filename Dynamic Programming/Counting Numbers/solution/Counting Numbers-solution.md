# Counting Numbers - Solution

**ID:** 2220 | **URL:** https://cses.fi/problemset/task/2220

## Approach

### Problem Restatement

Count the number of integers in $[a, b]$ where no two adjacent digits are the same ($0 \le a \le b \le 10^{18}$).

### Core idea

Use **digit DP** with the standard range technique: $Cal(b) - Cal(a - 1)$, where $Cal(X)$ counts valid integers in $[0, X]$.

Let $DP(cur, e, tight)$ be the number of valid completions when $cur$ digits remain to choose, the last placed digit is $e$, and $tight$ indicates whether the placed prefix equals the prefix of $X$:

- $tight = 0$ (free): prefix is strictly less, so remaining digits choose freely from 0–9 (only constraint: $i \neq e$).
- $tight = 1$ (tight): prefix equals $X$'s prefix, so the next digit is at most $C[cur]$ (the corresponding digit of $X$).

$$DP(cur, e, 0) = \sum_{\substack{i=0 \\ i \neq e}}^{9} DP(cur-1, i, 0)$$

$$DP(cur, e, 1) = \sum_{\substack{i=0 \\ i \neq e}}^{C[cur]} DP(cur-1, i, [i = C[cur]])$$

When $i < C[cur]$, the prefix becomes strictly less, switching to free mode. When $i = C[cur]$, we stay tight. Base case: $DP(0, e, \cdot) = 1$. By induction on $cur$, each valid digit choice leads to a correct subproblem, and different choices produce different numbers at position $cur$, so no overlap.

When $tight = 0$, the result depends only on $cur$ and $e$ (not on $X$), so we memoize these states — at most $18 \times 10$ states, each iterating 10 digits.

### Algorithm

$Cal(X)$ — count valid integers in $[0, X]$:

1. If $X < 10$: return $X$.
2. Express $X$ as $d$ digits $C[1], \ldots, C[d]$.
3. Count numbers with **fewer than $d$ digits**: for each length $\ell$ from 1 to $d-1$, first digit 1–9 (no leading zero), rest free: $\sum_{\ell=1}^{d-1} \sum_{j=1}^{9} DP(\ell-1, j, 0)$.
4. Count numbers with **exactly $d$ digits** and $\le X$: first digit from 1 to $C[d]$: $\sum_{j=1}^{C[d]} DP(d-1, j, [j = C[d]])$.

Answer: $Cal(b) - Cal(a-1)$. (When $a = 0$, $Cal(-1) = -1$, so the result is $Cal(b) + 1$, correctly including 0.)

### Example

Input: $a = 123$, $b = 321$. Output: $Cal(321) - Cal(122)$.

**$Cal(321)$:** $d = 3$, digits $C = [3, 2, 1]$.

- 1-digit numbers: $9$.
- 2-digit numbers: $9 \times 9 = 81$ (first digit 1–9, second digit any of the 9 digits different from the first).
- 3-digit numbers $\le 321$:
  - First digit $= 1$ (free, since $1 < 3$): $DP(2, 1, 0) = 9 \times 9 = 81$.
  - First digit $= 2$ (free, since $2 < 3$): $DP(2, 2, 0) = 81$.
  - First digit $= 3$ (tight): $DP(2, 3, 1)$. Second digit $\le C[2] = 2$ and $\neq 3$: choices are 0, 1, 2.
    - Digit 0 (free): $DP(1, 0, 0) = 9$.
    - Digit 1 (free): $DP(1, 1, 0) = 9$.
    - Digit 2 (tight, since $2 = C[2]$): $DP(1, 2, 1)$. Third digit $\le C[1] = 1$ and $\neq 2$: choices 0, 1 → $2$.
  - Total for first digit 3: $9 + 9 + 2 = 20$.

$Cal(321) = 9 + 81 + 81 + 81 + 20 = 272$.

**$Cal(122)$:** $d = 3$, digits $C = [1, 2, 2]$.

- 1-digit: $9$. 2-digit: $81$.
- 3-digit numbers $\le 122$:
  - First digit $= 1$ (tight): $DP(2, 1, 1)$. Second digit $\le C[2] = 2$ and $\neq 1$: choices 0, 2.
    - Digit 0 (free): $DP(1, 0, 0) = 9$.
    - Digit 2 (tight): $DP(1, 2, 1)$. Third digit $\le C[1] = 2$ and $\neq 2$: choices 0, 1 → $2$.
  - Total: $9 + 2 = 11$.

$Cal(122) = 9 + 81 + 11 = 101$.

Result: $272 - 101 = 171$.

## Complexity

- **Time:** $O(\log_{10} b \times 10)$ per $Cal$ call after memoization
- **Space:** $O(\log_{10} b \times 10)$ for the memoization table

## Code (C++)

[Solution Code](../code/Counting%20Numbers.cpp)
