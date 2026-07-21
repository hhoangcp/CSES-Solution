# Corner Subgrid Check - Solution

**ID:** 3360 | **URL:** https://cses.fi/problemset/task/3360

## Approach

### Problem Restatement

Given an $n \times n$ grid of letters (first $k$ uppercase letters). For each letter, determine whether there exists a subgrid of size at least $2 \times 2$ where all four corners have that letter.

### Core Idea

A subgrid is determined by two rows $(r_1, r_2)$ and two columns $(c_1, c_2)$. The four corners at $(r_1, c_1)$, $(r_1, c_2)$, $(r_2, c_1)$, $(r_2, c_2)$ must all have the same letter $c$. This means letter $c$ must appear at both columns $c_1$ and $c_2$ in both row $r_1$ and row $r_2$ — equivalently, the same column pair $(c_1, c_2)$ appears in at least two different rows for letter $c$.

The converse also holds: if a valid subgrid exists with all four corners equal to $c$, then some column pair appears in two rows with letter $c$. So checking whether any column pair repeats across rows is both necessary and sufficient. If a repeated pair $(u, v)$ is found at rows $r_1 \neq r_2$, then $u \neq v$ (distinct columns) and $r_1 \neq r_2$ (distinct rows), guaranteeing the subgrid is at least $2 \times 2$.

To detect repeating column pairs efficiently, we use a `last[u][v]` array of bytes, where `last[u][v]` stores the index of the last letter that marked the column pair $(u, v)$ (initialized to 26, a value outside $0 \ldots k-1$). Letters are processed one at a time in increasing order of $c$. When processing row $r$ for letter $c$ and forming pair $(u, v)$: if `last[u][v] == c`, this pair was already seen in a previous row during this same letter-$c$ pass → YES; otherwise, set `last[u][v] = c`. Because earlier letters only ever wrote values strictly less than $c$, the equality check `== c` can only be true if letter $c$ itself marked the pair earlier in the current pass, so all $k$ letters safely share the same array without interference.

### Algorithm

1. Precompute: for each letter $c$ and each row $r$, collect the list of columns where letter $c$ appears.
2. For each letter $c$ from 0 to $k-1$:
   - For each row $r$ from 0 to $n-1$:
     - For each column pair $(u, v)$ from the column list of letter $c$ in row $r$:
       - If `last[u][v] == c` → YES for letter $c$, move to next letter.
       - Otherwise, set `last[u][v] = c`.
   - If no repeating pair found → NO.

### Example

Grid (0-indexed):
```
Row 0: A A A A
Row 1: C B B C
Row 2: C B B E
Row 3: A A A A
```

- **A:** Row 0 has A at columns $\{0,1,2,3\}$, row 3 has A at columns $\{0,1,2,3\}$. Column pair $(0,1)$ appears in both rows → **YES**.
- **B:** Row 1 has B at columns $\{1,2\}$, row 2 has B at columns $\{1,2\}$. Column pair $(1,2)$ appears in both rows → **YES**.
- **C:** Row 1 has C at columns $\{0,3\}$, pair $(0,3)$ is marked. Row 2 has C only at column $\{0\}$, no pairs. No second row with pair $(0,3)$ → **NO**.
- **D:** Never appears → **NO**.
- **E:** Only appears at (row 2, column 3), single occurrence, no pairs possible → **NO**.

Output: `YES YES NO NO NO`

## Complexity

- **Time:** $O(k \cdot n \cdot m^2)$ where $m$ is the maximum number of occurrences of any single letter in a row. Early exit on YES keeps the practical running time efficient.
- **Memory:** $O(n^2)$ — the `last` array (bytes, $\approx 9$MB) plus the per-letter/per-row column lists storing $\approx n^2$ ints in total.

## Code (C++)

[Solution Code](../code/Corner%20Subgrid%20Check.cpp)
