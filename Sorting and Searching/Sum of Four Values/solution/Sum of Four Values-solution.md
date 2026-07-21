# Sum of Four Values - Solution

**ID:** 1642 | **URL:** https://cses.fi/problemset/task/1642

## Problem Statement

Given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and a target value $x$, find four distinct indices $i, j, k, l$ such that $a_i + a_j + a_k + a_l = x$. If several solutions exist, output any; if none exists, output `IMPOSSIBLE`.

## Approach

### 1. Core idea: split the 4-sum into 2 + 2

Instead of scanning every quadruple in $O(n^4)$, reduce the problem to finding two disjoint pairs whose sums add up to $x$. If $S_{\text{first}} = a_p + a_q$ and $S_{\text{second}} = a_i + a_j$, we need:

$$S_{\text{first}} + S_{\text{second}} = x \iff S_{\text{first}} = x - S_{\text{second}}$$

We keep a map storing the sums of already-processed pairs, together with the two indices that produced each sum.

### 2. "Check before, insert after" to keep indices distinct

To guarantee four fully distinct indices without complicated checks, we separate two operations as we sweep with a milestone index $i$:

1. Initialize the map with the first pair: $M[a_1 + a_2] = (1, 2)$.
2. For each milestone $i$ from $3$ to $n - 1$:
   - **Check first:** for each $j$ from $i + 1$ to $n$, compute $X = x - a_i - a_j$. If $X$ is already in the map as a pair $(p, q)$, we have found a valid quadruple. Since every pair in the map was inserted in earlier steps, we are guaranteed $p < q < i < j$, so the four indices are distinct; print the result and stop.
   - **Insert after:** before moving to the next $i$, insert all pairs $(a_k + a_i)$ for $k$ from $1$ to $i - 1$ into the map.

Separating the two operations ensures the pairs being checked always have an index $\ge i$ (specifically $j > i$), while every pair in the map has both indices $< i$; hence the four indices are guaranteed to be distinct.

## Example

Consider $n = 5$, $x = 10$, array $a = [1, 2, 3, 4, 5]$.

- **Initialize:** $M = \{a_1 + a_2 : (1, 2)\} = \{3 : (1, 2)\}$.
- **Milestone $i = 3$ ($a_3 = 3$):**
  - **Check $j = 4$ ($a_4 = 4$):** $X = 10 - a_3 - a_4 = 10 - 3 - 4 = 3$. The value $3$ is in the map, matching pair $(1, 2)$.
- **Result:** found quadruple $(1, 2, 3, 4)$ with sum $1 + 2 + 3 + 4 = 10$.

## Complexity

- **Time:** $O(n^2 \log n)$ with `std::map`, or $O(n^2)$ with `std::unordered_map`. Two nested loops scan the index pairs; each state does a lookup or insert costing $O(\log n)$ or $O(1)$.
- **Memory:** $O(n^2)$ to store up to $\binom{n}{2}$ distinct pairs.
