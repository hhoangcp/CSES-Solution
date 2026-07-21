# Increasing Array II - Solution

**ID:** 2132 | **URL:** https://cses.fi/problemset/task/2132

## Problem Statement

Given an array of $n$ integers, transform it into a non-decreasing array by increasing or decreasing values. Each unit of change costs 1. Find the minimum total cost.

## Approach

### DP on convex functions: $f_i(x) = |a_i - x| + \min_{z \le x} f_{i-1}(z)$

Find a non-decreasing sequence $y_1 \le y_2 \le \cdots \le y_n$ minimizing $\sum |a_i - y_i|$. Let $f_i(x)$ be the minimum cost for the first $i$ elements with $y_i = x$. The recurrence is:

$$f_i(x) = |a_i - x| + \min_{z \le x} f_{i-1}(z)$$

$f_i(x)$ is a **convex piecewise-linear function**: $f_1(x) = |a_1 - x|$ is convex, prefix-min $\min_{z \le x}$ preserves convexity, and adding $|a_i - x|$ (convex) preserves it. Thus the function is fully characterized by its **breakpoints** (positions where the slope changes).

### Slope Trick: Store breakpoints in a Max-Heap

A convex piecewise-linear function is fully determined by its breakpoints. Since $\min_{z \le x}$ "flattens" all positive-slope segments, we only need to store breakpoints in the non-positive slope region using a **Max-Heap**:

- **$|a_i - x|$ adds a breakpoint at $a_i$**: slope decreases by 1 to the left of $a_i$, increases by 1 to the right.
- **$\min_{z \le x}$ clips positive-slope segments**: if heap top $t > a_i$, the segment $[a_i, t]$ has unnecessary positive slope. Lowering to $a_i$ saves $t - a_i$. Pop $t$, push $a_i$ back (maintaining the new convex structure).

## Algorithm

1. Initialize max-heap `Q` and `ans = 0`.
2. For each element $a_i$:
   - Push $a_i$ into the heap.
   - If `Q.top() > a_i`: `ans += Q.top() - a_i`, pop top, push $a_i$ back.
3. Output `ans`.

## Example

Array: $[3, 8, 5]$.

- **Add 3:** Heap `{3}`, `ans = 0`. (V-shaped function, minimum at 3).
- **Add 8:** Heap `{8, 3}`, `ans = 0`. (8 is right of the minimum, minimum extends from 3 to 8).
- **Add 5:**
  - Push 5: Heap `{8, 5, 3}`.
  - $5 < $ `Q.top()` $= 8$: `ans += 8 - 5 = 3`.
  - Pop 8, push 5: Heap `{5, 5, 3}`.

Result: 3.

### Problem Statement Example

Array: $[3, 8, 5, 6, 5]$.

- **Add 3:** Heap `{3}`, `ans = 0`.
- **Add 8:** Heap `{8, 3}`, `ans = 0`.
- **Add 5:**
  - Push 5: Heap `{8, 5, 3}`.
  - $5 < $ `Q.top()` $= 8$: `ans += 8 - 5 = 3`.
  - Pop 8, push 5: Heap `{5, 5, 3}`.
- **Add 6:**
  - Push 6: Heap `{6, 5, 5, 3}`.
  - $6 \not< $ `Q.top()` $= 6$: no change. `ans = 3`.
- **Add 5:**
  - Push 5: Heap `{6, 5, 5, 5, 3}`.
  - $5 < $ `Q.top()` $= 6$: `ans += 6 - 5 = 1`. `ans = 4`.
  - Pop 6, push 5: Heap `{5, 5, 5, 5, 3}`.

Result: 4.

## Complexity

- **Time:** $O(n \log n)$ — at most 2 heap operations per element
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Increasing%20Array%20II.cpp)
