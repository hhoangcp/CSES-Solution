# Removing Digits II - Solution

**ID:** 2174 | **URL:** https://cses.fi/problemset/task/2174

## Problem Statement

Given integer $n$ (up to $10^{18}$), at each step subtract a digit present in the decimal representation. Find the minimum number of steps to reach 0.

## Approach

### Divide and conquer by digit blocks + Memoization

With $n \le 10^{18}$, step-by-step subtraction is infeasible. Decompose the number into leading digit $d$ and suffix $s$, process via two-phase recursion with memoization.

**State:** `(upper_max, number)` — `upper_max` is the largest digit from higher positions (outside the current block), `number` is the current block. Two numbers sharing the same `upper_max` and `number` have the same set of feasible next steps — the state is sufficient.

### Function `compute(upper_max, number)` → `{steps, remainder}`

- **`steps`**: number of steps until `number` is reduced to the point where borrowing from a higher position is needed.
- **`remainder`**: value remaining after borrowing (negative, will be subtracted from the higher position).

### Two-phase recursion

Split `number` into $d$ (leading digit) and $s$ (suffix). E.g., $27 \Rightarrow d = 2, s = 7$.

**Phase 1 (suffix):** Call `compute(max(upper_max, d), s)`. Process the suffix with the context that the largest available digit includes $d$. Count steps until the suffix needs to borrow from $d$.

**Phase 2 (update + continue):** Update `new_number = d * power + remainder`. Now $d$ has decreased (due to borrowing), call `compute(upper_max, new_number)` to process the remainder.

**Why correct:** Each subtraction step only affects the suffix until a borrow occurs. When borrowing happens, the leading digit decreases and the suffix changes completely. Splitting into two phases — before borrowing (suffix only) and after borrowing (full update) — avoids missing or double-counting steps.

**Base case:** When `number < 10`, return `{1, number - max(upper_max, number)}` (one step subtracting the largest digit, remainder may be negative if borrowing is needed).

## Algorithm

1. Define `compute({upper_max, number})`:
   - If `number < 10`: base case.
   - Split into $d$, $s$. Phase 1: `compute({max(upper_max, d), s})`. Phase 2: `compute({upper_max, d*power + remainder})`.
   - Return total steps and final remainder.
2. Answer = `compute({0, n}).first`.

## Example: $n = 27$

| Call | Phase 1 | delta | Phase 2 | Result |
|:---|:---|:---|:---|:---|
| `compute({0, 27})` | `compute({2, 7})` → `{1, 0}` | 1 | `compute({0, 20})` → `{4, 0}` | `{5, 0}` |
| `compute({0, 20})` | `compute({2, 0})` → `{1, -2}` | 1 | `compute({0, 18})` → `{3, 0}` | `{4, 0}` |
| `compute({0, 18})` | `compute({1, 8})` → `{1, 0}` | 1 | `compute({0, 10})` → `{2, 0}` | `{3, 0}` |
| `compute({0, 10})` | `compute({1, 0})` → `{1, -1}` | 1 | `compute({0, 9})` → `{1, 0}` | `{2, 0}` |
| `compute({0, 9})` | base → `{1, 0}` | — | — | `{1, 0}` |

Total: 5 steps. Path: $27 \to 20 \to 18 \to 10 \to 9 \to 0$.

## Complexity

- **Number of states:** $O(\log n)$ — `upper_max` only takes values from 0 or digits of $n$ (at most 10 values). For each fixed `upper_max`, at each tier $10^k$:
  - There is 1 original value (the original suffix of $n$).
  - When borrowing occurs, `new_number = d \cdot 10^k + remainder` with `remainder ∈ [-9, 0]`. The suffix (length $k$) has the form $\underbrace{99\ldots9}_{k-1}x$ (if $k \ge 2$) or simply $x$ (if $k = 1$), where $x$ depends on `remainder`. The number of suffix variants due to borrowing at each tier ≤ 10.
  - There are $O(\log n)$ tiers, each with ≤ 11 distinct `number` values → total distinct `number` values = $O(\log n)$.
  - Total states $\le 10 \times O(\log n) = O(\log n)$.
- **Per-state cost:** $O(\log n)$ — the `while` loop finding `power` and division/modulo operations.
- **Time:** $O(\log^2 n)$
- **Memory:** $O(\log n)$

## Code (C++)

[Solution Code](../code/Removing%20Digits%20II.cpp)
