# Same Sum Subsets - Solution

**ID:** 3425 | **URL:** https://cses.fi/problemset/task/3425

## Problem Statement

Given a set of $n$ positive integers, select two disjoint subsets with equal sums.

## Approach

### Step 1: Solution existence

The constraint $\sum_{i=1}^{n} x_i \leq 2^n - 2$ guarantees a solution exists. There are $2^n - 1$ non-empty subsets, each with sum in $\{1, 2, \ldots, S\}$ where $S = \sum x_i \leq 2^n - 2$, so at most $2^n - 2$ distinct sum values. Since $2^n - 1 > 2^n - 2$, by the **pigeonhole principle**, at least two different subsets share the same sum.

### Step 2: Meet-in-the-middle

With $n \leq 40$, $2^{40}$ is too large to enumerate. Split the array:

- First half: $m = \lfloor n/2 \rfloor \leq 20$ elements.
- Second half: $n - m \leq 20$ elements.

For each half, enumerate all $2^m$ (or $2^{n-m}$) subset sums using **merge-based enumeration** (similar to merge sort): when adding element $i$, merge the sorted "without $i$" and "with $i$ + $a_i$" lists. Total time $O(2^{n/2} \cdot n/2)$.

### Step 3: Find two subsets with the same sum

With sorted arrays $D_1$ and $D_2$, use **binary search** to find a sum $s$ with at least 2 ways to form it from $D_1 + D_2$:

- Function `countLess(s)`: count pairs $(i, j)$ with $D_1[i] + D_2[j] < s$, using two pointers on $D_1$ (decreasing) and $D_2$ (increasing).
- Predicate $P(s)$: $\text{countLess}(s) \leq s$.
- Binary search for the largest $s$ satisfying $P(s)$.

**Correctness of binary search on a non-monotone predicate:** Let $g(s) = \text{countLess}(s) - s$. Since $g(s+1) - g(s) = \text{freq}(s) - 1$ (where $\text{freq}(s)$ is the number of pairs summing to $s$), $g$ is not monotone --- $P(s)$ is **not** a monotone predicate. However, binary search is still correct thanks to two invariants:

1. $P(\texttt{lo})$ is true. Initially $\text{countLess}(0) = 0 \leq 0$. $\texttt{lo}$ only increases when $P(\texttt{mid})$ is true, so the invariant holds.
2. $P(\texttt{hi} + 1)$ is false. Initially $\text{countLess}(2^n - 1) = 2^n > 2^n - 1$. $\texttt{hi}$ only decreases when $P(\texttt{mid})$ is false, setting $\texttt{hi} = \texttt{mid} - 1$, so $P(\texttt{hi} + 1) = P(\texttt{mid})$ is false, and the invariant holds.

At convergence $\texttt{lo} = \texttt{hi} = s^*$, we have $P(s^*)$ true and $P(s^* + 1)$ false, i.e.:

$$\text{countLess}(s^*) \leq s^* \quad \text{and} \quad \text{countLess}(s^* + 1) > s^* + 1$$

Hence $\text{freq}(s^*) = \text{countLess}(s^* + 1) - \text{countLess}(s^*) > 1$, guaranteeing at least 2 pairs with sum $s^*$.

Once $s^*$ is found, scan to find two distinct subset masks $mask_1$ and $mask_2$ both yielding sum $s^*$.

### Step 4: Remove common elements

$mask_1$ and $mask_2$ may share elements. Let $C = mask_1 \cap mask_2$. We have $\text{sum}(mask_1) = \text{sum}(mask_1 \setminus C) + \text{sum}(C) = s$ and $\text{sum}(mask_2) = \text{sum}(mask_2 \setminus C) + \text{sum}(C) = s$, so $\text{sum}(mask_1 \setminus C) = \text{sum}(mask_2 \setminus C)$. Moreover $(mask_1 \setminus C) \cap (mask_2 \setminus C) = \emptyset$. Thus $mask_1' = mask_1 \oplus C$ and $mask_2' = mask_2 \oplus C$ are two disjoint subsets with equal sums.

### Example

$n = 6$, elements: $[1, 2, 3, 5, 7, 8]$.

Result: subset $\{2, 3\}$ and subset $\{5\}$, both with sum 5.

## Complexity

- **Time:** $O(2^{n/2} \cdot n)$
- **Memory:** $O(2^{n/2})$

## Code (C++)

[Solution Code](../code/Same%20Sum%20Subsets.cpp)
