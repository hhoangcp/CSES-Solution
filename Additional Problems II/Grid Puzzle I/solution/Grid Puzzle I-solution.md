# Grid Puzzle I - Solution

**ID:** 2432 | **URL:** https://cses.fi/problemset/task/2432

## Problem Statement

Given an $n \times n$ grid, select exactly $a_i$ cells from each row $i$ and exactly $b_j$ cells from each column $j$. Output any valid selection, or $-1$ if impossible.

## Approach

### Modeling: Integer flow on a bipartite network

The problem is to select cells satisfying both row degree constraints ($a_i$) and column degree constraints ($b_j$). Build a flow network:

- **Source $S$** $\to$ **row $i$**: capacity $a_i$ (row $i$ selects exactly $a_i$ cells).
- **Row $i$** $\to$ **column $j$**: capacity 1 (each cell selected at most once). Each unit of flow here = selecting cell $(i,j)$.
- **Column $j$** $\to$ **sink $T$**: capacity $b_j$ (column $j$ selects exactly $b_j$ cells).

### A valid selection exists iff max flow = $\sum a_i$

A valid selection sends 1 unit through each selected cell, total flow = $\sum a_i$, saturating all source $\to$ row and column $\to$ sink edges. Conversely, if max flow = $\sum a_i$, all source $\to$ row and column $\to$ sink edges are saturated. Since row $\to$ column edges have integer capacity (1), by the integer flow theorem, flow on each such edge is 0 or 1 — corresponding to "not selected" or "selected", satisfying all degree constraints exactly.

## Algorithm

1. If $\sum a_i \neq \sum b_j$, output $-1$.
2. Compute max flow using Dinic.
3. If flow $< \sum a_i$, output $-1$.
4. Otherwise, for each row $\to$ column edge with flow = 1, mark cell `X`.

## Example

$n = 5$, $a = [0, 1, 3, 2, 0]$, $b = [1, 2, 2, 0, 1]$. $\sum = 6$.

Max flow = 6 = $\sum a_i$. Cells with flow = 1 are marked `X`, each row has exactly $a_i$ cells, each column has exactly $b_j$ cells.

## Complexity

- **Time:** $O(n^{5/2})$ — Dinic on unit-capacity bipartite graph
- **Memory:** $O(n^2)$

## Code (C++)

[Solution Code](../code/Grid%20Puzzle%20I.cpp)
