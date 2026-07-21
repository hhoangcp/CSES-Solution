# Grid Paths II - Solution

**ID:** 1078 | **URL:** https://cses.fi/problemset/task/1078

## Approach

### Problem Restatement

Count the number of paths from $(1,1)$ to $(n,n)$ on an $n \times n$ grid, moving only right or down, that avoid $m$ trap cells. Result modulo $10^9 + 7$.

### Path counting without traps

The number of paths from $(r_1, c_1)$ to $(r_2, c_2)$ (where $r_2 \ge r_1$, $c_2 \ge c_1$) without traps is $\binom{(r_2 - r_1) + (c_2 - c_1)}{r_2 - r_1}$: choose which of the total steps are down steps.

### Inclusion-exclusion DP on traps

Since $m \le 1000$ (much smaller than $n$), we apply DP on the trap list rather than on the full grid.

**Sort traps** by row then column. This ensures that if trap $j$ can lie on a path to trap $i$ (i.e., $r_j \le r_i$ and $c_j \le c_i$), then $j < i$ in the sorted order.

Define $P[i]$ = number of paths from $(1,1)$ to trap $i$ where trap $i$ is the **first** trap encountered. By processing traps in sorted order:

$$P[i] = \binom{r_i + c_i - 2}{r_i - 1} - \sum_{\substack{j < i \\ r_j \le r_i, c_j \le c_i}} P[j] \cdot \binom{(r_i - r_j) + (c_i - c_j)}{r_i - r_j}$$

The first term counts all paths to trap $i$. The sum subtracts paths that already passed through an earlier trap $j$ — for each such $j$, $P[j]$ paths reach $j$ as the first trap, then continue freely to $i$. The condition $r_j \le r_i$, $c_j \le c_i$ ensures $j$ is reachable from $i$'s direction.

**Final result:** Subtract all paths whose first trap is $i$, then continue to $(n,n)$:

$$\text{ans} = \binom{2n-2}{n-1} - \sum_{i=1}^{m} P[i] \cdot \binom{(n - r_i) + (n - c_i)}{n - r_i}$$

Each violating path is subtracted exactly once — attributed to its first trap — so no double counting occurs.

### Example

**Problem example:** $n = 3$, $m = 1$, trap at $(2, 2)$.

$P[1] = \binom{2}{1} = 2$ (paths to trap: R,D and D,R).

$\text{ans} = \binom{4}{2} - 2 \cdot \binom{2}{1} = 6 - 4 = \mathbf{2}$. ✓

The 2 valid paths: RRDD and DDRR (the 4 invalid paths all pass through $(2,2)$).

**Multi-trap example:** $n = 3$, traps at $(2,1)$ and $(2,2)$.

- $P[1] = \binom{1}{1} = 1$ (only path: D to $(2,1)$).
- $P[2] = \binom{2}{1} - P[1] \cdot \binom{1}{0} = 2 - 1 = 1$ (paths to $(2,2)$ minus those through $(2,1)$).

$\text{ans} = 6 - 1 \cdot \binom{3}{1} - 1 \cdot \binom{2}{1} = 6 - 3 - 2 = \mathbf{1}$. ✓ (Only RRDD is valid.)

## Complexity

- **Time:** $O(n + m^2)$ — $O(n)$ for factorial preprocessing, $O(m^2)$ for the DP over trap pairs.
- **Space:** $O(n + m)$ — for factorials and trap data.

## Code (C++)

[Solution Code](../code/Grid%20Paths%20II.cpp)
