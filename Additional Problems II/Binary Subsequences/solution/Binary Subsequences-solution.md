# Binary Subsequences - Solution

**ID:** 2430 | **URL:** https://cses.fi/problemset/task/2430

## Problem Statement

Find a shortest bit string that contains exactly $n$ distinct non-empty subsequences.

## Approach

### Subsequence counting

Let $a$ = number of distinct subsequences ending in `0`, $b$ = ending in `1`. Total non-empty subsequences $= a + b$.

Appending a character:
- **`0`:** every existing subsequence can be extended with `0`, plus the single `0`. New state: $(a, b) \to (a + b + 1, b)$.
- **`1`:** similarly, $(a, b) \to (a, a + b + 1)$.

### Reverse Euclidean process

To recover the string from target $n = a + b$, reverse the process from state $(a, b)$:

- If $a \geq b$: emit `0`, set $a \leftarrow a - (b + 1)$.
- If $a < b$: emit `1`, set $b \leftarrow b - (a + 1)$.

Each step reduces $a + b$ by at least half (like the Euclidean algorithm), so it runs in $O(\log n)$ steps. The process is valid iff it reaches $(0, 0)$ (every split corresponds to exactly one reverse process, and every binary string with $n$ subsequences corresponds to exactly one split).

### Try all splits

We don't know which $a + b = n$ gives the shortest string, so try every $a$ from $0$ to $\lfloor n/2 \rfloor$ (symmetry: swapping $a \leftrightarrow b$ swaps `0` $\leftrightarrow$ `1`). For each, simulate the reverse process; keep the shortest valid string.

### Example

$n = 6$, trying $a = 2, b = 4$:

1. $(2, 4)$: $a < b$, emit `1`, $b = 4 - 3 = 1$ → $(2, 1)$
2. $(2, 1)$: $a \geq b$, emit `0`, $a = 2 - 2 = 0$ → $(0, 1)$
3. $(0, 1)$: $a < b$, emit `1`, $b = 1 - 1 = 0$ → $(0, 0)$ ✓

String (reversed): `101`. Length 3.

Other splits: $a = 0, b = 6$ gives `111111` (length 6); $a = 1, b = 5$ yields $a = -1$ (invalid).

Result: `101`.

## Complexity

- **Time:** $O(n \log n)$ — $O(n)$ splits, each $O(\log n)$ steps
- **Memory:** $O(\log n)$ — storing the result string

## Code (C++)

[Solution Code](../code/Binary%20Subsequences.cpp)
