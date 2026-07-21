# Functional Graph Distribution - Solution

**ID:** 2415 | **URL:** https://cses.fi/problemset/task/2415

## Approach

### Problem Restatement

For each $k = 1 \ldots n$, count the number of functional graphs on $n$ vertices with exactly $k$ connected components. A functional graph is a directed graph where each vertex has exactly one outgoing edge.

### Structure of functional graphs

In a functional graph, following outgoing edges from any vertex always reaches a cycle (since the graph is finite and each vertex has out-degree 1). Each connected component contains exactly one cycle, so the number of components equals the number of cycles. The problem reduces to counting functional graphs with exactly $k$ cycles.

### Main formula

$$\text{ans}(k) = \sum_{i=1}^{n} \binom{n-1}{i-1} \cdot n^{n-i} \cdot c(i, k)$$

where $c(i, k)$ is the **unsigned Stirling number of the first kind** (the number of permutations of $i$ elements with exactly $k$ cycles).

The summation is over $i$, the number of vertices that lie on cycles. Fix vertex 1 as always being on a cycle (to avoid overcounting), then choose $i - 1$ other cycle vertices from $n - 1$: $\binom{n-1}{i-1}$. These $i$ vertices form $k$ cycles: $c(i, k)$ ways. The remaining $n - i$ vertices each independently choose a destination from all $n$ vertices (pointing into the cycle-attached tree structure): $n^{n-i}$.

### Unsigned Stirling numbers of the first kind

$$c(i, j) = (i-1) \cdot c(i-1, j) + c(i-1, j-1)$$

When adding element $i$ to a permutation of $\{1, \ldots, i{-}1\}$: insert $i$ after any existing element into a cycle (does not change the cycle count, $(i{-}1)$ ways), or create a new cycle containing only $i$ (increases the cycle count by 1, 1 way).

### Example

**Problem example:** $n = 3$.

Stirling numbers: $c(1,1){=}1$; $c(2,1){=}1, c(2,2){=}1$; $c(3,1){=}2, c(3,2){=}3, c(3,3){=}1$.

| $k$ | $i{=}1$ | $i{=}2$ | $i{=}3$ | **ans** |
|-----|---------|---------|---------|---------|
| 1 | $\binom{2}{0} \cdot 9 \cdot 1 = 9$ | $\binom{2}{1} \cdot 3 \cdot 1 = 6$ | $\binom{2}{2} \cdot 1 \cdot 2 = 2$ | **17** |
| 2 | $\binom{2}{0} \cdot 9 \cdot 0 = 0$ | $\binom{2}{1} \cdot 3 \cdot 1 = 6$ | $\binom{2}{2} \cdot 1 \cdot 3 = 3$ | **9** |
| 3 | 0 | 0 | $\binom{2}{2} \cdot 1 \cdot 1 = 1$ | **1** |

Output: 17, 9, 1. ✓

## Complexity

- **Time:** $O(n^2)$ — for precomputing Stirling numbers and computing all answers.
- **Space:** $O(n^2)$ — for the Stirling number table.

## Code (C++)

[Solution Code](../code/Functional%20Graph%20Distribution.cpp)
