# Factory Machines - Solution

**ID:** 1620 | **URL:** https://cses.fi/problemset/task/1620

## Approach

### Problem Restatement

There are $n$ machines, machine $i$ takes $a_i$ seconds to produce one product. All machines operate simultaneously and continuously. Find the minimum time to produce at least $t$ products.

### Core Idea

Let $f(T) = \sum_{i=1}^{n} \lfloor T / a_i \rfloor$ be the total products after $T$ seconds. Since each term $\lfloor T/a_i \rfloor$ is non-decreasing in $T$, so is $f(T)$. The set of feasible times $\{T : f(T) \ge t\}$ has the form $[T^*, +\infty)$ — enabling binary search on the answer to find the minimum $T^*$. Use 64-bit integers for $T$ and the running sum (which can exceed $10^{18}$), with early termination when the sum reaches $t$ to avoid overflow.

### Algorithm

1. Set $L = 0$, $R = 10^{18}$.
2. Binary search on $T$ in $[L, R]$:
   - For each $mid$, compute $f(mid) = \sum \lfloor mid / a_i \rfloor$ (early-terminate when $\ge t$).
   - If $f(mid) \ge t$: record answer, search lower half.
   - Otherwise: search upper half.

### Example

$n = 3$, $t = 7$, $a = [3, 2, 5]$.

| $T$ | $\lfloor T/3 \rfloor$ | $\lfloor T/2 \rfloor$ | $\lfloor T/5 \rfloor$ | Total | $\ge 7$? |
|-----|-----------------------|-----------------------|-----------------------|-------|----------|
| 7 | 2 | 3 | 1 | 6 | No |
| 8 | 2 | 4 | 1 | 7 | Yes |

Answer: **8**.

## Complexity

- **Time:** $O(n \log(10^{18})) = O(n \cdot 60)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Factory%20Machines.cpp)
