# Repetitions - Solution

**ID:** 1069 | **URL:** https://cses.fi/problemset/task/1069

## Problem Statement

Given a DNA string of length $n$ ($1 \le n \le 10^6$) consisting of characters A, C, G, T, find the length of the longest substring consisting of identical consecutive characters.

## Approach

### Key Observation

The problem asks for the longest consecutive run of identical characters. This is a basic string processing problem solvable with a linear scan.

### Idea: Linear Scan with Run Counter

Traverse the string, maintaining two variables:
- `len`: the length of the current run (consecutive identical characters).
- `res`: the answer -- the maximum run length found.

When the current character differs from the next character (or is the last character), the current run ends -- update `res = max(res, len)` and reset `len = 0`.

### Detailed Algorithm

1. Initialize `res = 0` and `len = 0`.
2. Traverse the string from position 1 to $n$:
   - Increment `len` by 1.
   - If `i == n` or `S[i] != S[i+1]`: the current run ends at position $i$:
     - Update `res = max(res, len)`.
     - Reset `len = 0`.
3. Print `res`.

### Proof of Correctness

We prove that after processing position $i$, the variable `res` stores the length of the longest run in prefix $S[1..i]$.

**Induction on $i$:**

- **Base ($i = 1$):** If $n = 1$, `len = 1`, $S[1]$ is the last character $\to$ `res = 1`. Correct since the string has only 1 character.
- **Inductive step:** Assume correct up to position $i-1$. Consider position $i$:
  - If `S[i] == S[i+1]` (same run): `len` increases but `res` is not updated. No runs in $S[1..i]$ end at $i$, so `res` remains correct.
  - If `S[i] != S[i+1]` or $i = n$ (run ends at $i$): `len` is exactly the length of the run ending at $i$. Updating `res = max(res, len)` ensures `res` $\geq$ this run's length, and `res` never decreases. Thus `res` is the maximum over all runs in $S[1..i]$.

### Why No Special Post-Loop Handling Is Needed

The code compares `S[i]` with `S[i+1]` (look-ahead) rather than `S[i-1]` (look-behind). When detecting `S[i] != S[i+1]` or `i == n`, we know the current run ends at position $i$ and update immediately. Therefore, the final run is also handled within the loop, requiring no additional processing.

### Proof of Optimality

**Lower bound:** Every character must be read at least once to determine whether it continues or ends a run. Skipping any character means we cannot know if the run extends past that position. Hence the lower bound is $\Omega(n)$.

**Upper bound:** The algorithm traverses the string exactly once, each step $O(1)$, totaling $O(n)$.

Therefore the algorithm is optimal: $\Theta(n)$.

### Example

S = "ATTCGGGA":

| i | S[i] | S[i+1] | len | Action | res |
|---|------|--------|-----|--------|-----|
| 1 | A | T | 1 | Different $\to$ update | 1 |
| 2 | T | T | 1 | Same $\to$ continue | 1 |
| 3 | T | C | 2 | Different $\to$ update | 2 |
| 4 | C | G | 1 | Different $\to$ update | 2 |
| 5 | G | G | 1 | Same $\to$ continue | 2 |
| 6 | G | G | 2 | Same $\to$ continue | 2 |
| 7 | G | A | 3 | Different $\to$ update | 3 |
| 8 | A | (end) | 1 | Last $\to$ update | 3 |

Result: 3 (the run "GGG")

## Complexity

- **Time:** $O(n)$
- **Memory:** $O(n)$ for the string array (can be reduced to $O(1)$ by reading characters one at a time)

## Code (C++)

[Solution Code](../code/Repetitions.cpp)
