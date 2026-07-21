# Grid Coloring II - Solution

**ID:** 3312 | **URL:** https://cses.fi/problemset/task/3312

## Problem Statement

Given an $n \times m$ grid where each cell contains a character `A`, `B`, or `C`, change each cell to `A`, `B`, or `C` (different from the current character) such that no two adjacent cells (4 directions) have the same character.

## Approach

### Each cell has exactly 2 choices → Binary variable

Each cell must change to a different character. From 3 characters, removing the current one leaves exactly 2 choices: **option 0** and **option 1**. Assign a binary variable $x_{i,j}$: option 0 ($x = \text{false}$) or option 1 ($x = \text{true}$). Every variable assignment corresponds 1-1 with a coloring.

### Adjacent constraint → 2-SAT clause

For each adjacent pair $(u, v)$, check 4 option combinations. If option $i$ of $u$ and option $k$ of $v$ give the same character, the combination is forbidden by the clause: $\neg(u = i \land v = k)$, i.e., $(u \neq i) \lor (v \neq k)$. This is an OR clause on two negated variables — proper 2-SAT form.

In the implication graph, add two edges: $u_i \to v_{\neg k}$ (if $u$ chooses $i$ then $v$ must not choose $k$) and $v_k \to u_{\neg i}$ (the converse).

### Solve via Tarjan's SCC

1. Find all SCCs using Tarjan's algorithm.
2. If variable $x$ and $\neg x$ are in the same SCC $\to$ implications $x \Rightarrow \neg x \Rightarrow x$ create a logical contradiction $\to$ unsatisfiable.
3. Otherwise, assign by topological order: higher-numbered SCCs (processed first) determine values. Since $x$ and $\neg x$ are in different SCCs, and no edge leads from SCC($\neg x$) to SCC($x$) when SCC($x$) > SCC($\neg x$), the assignment is consistent.

## Example

Grid:
```
AAAA
CCBB
ABCA
```

Cell $(1,1)$ is `A` (options: `B`, `C`), cell $(1,2)$ is also `A` (options: `B`, `C`). If both choose `B` $\to$ forbidden $\to$ add clause: if $(1,1)$ chooses `B` then $(1,2)$ must choose `C`, and vice versa.

Result after solving 2-SAT:
```
BCBC
ABCA
CABC
```

## Complexity

- **Time:** $O(nm)$ — $nm$ variables, $O(nm)$ clauses, Tarjan is linear
- **Memory:** $O(nm)$

## Code (C++)

[Solution Code](../code/Grid%20Coloring%20II.cpp)
