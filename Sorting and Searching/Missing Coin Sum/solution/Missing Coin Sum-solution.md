# Missing Coin Sum - Solution

**ID:** 2183 | **URL:** https://cses.fi/problemset/task/2183

## Approach

Sort the coins in increasing order, then maintain a variable $cur$ with the following invariant: **after processing coins $a_1, \ldots, a_{i-1}$, we can form every sum from $0$ to $cur$**. Initially $cur = 0$.

When considering coin $a_i$ (sorted):

- **If $a_i > cur + 1$:** We cannot form sum $cur + 1$. Any subset using only $a_1, \ldots, a_{i-1}$ has sum $\leq cur$, and any subset using at least one coin from $a_i, a_{i+1}, \ldots$ has sum $\geq a_i > cur + 1$ (since the array is sorted). Thus $cur + 1$ is the smallest unattainable sum, and the algorithm stops.

- **If $a_i \leq cur + 1$:** We can form every sum from $0$ to $cur + a_i$:
  - Sums in $[0, cur]$: formable by the invariant.
  - Sums in $[a_i, cur + a_i]$: take any sum $t \in [0, cur]$ and add $a_i$ to get $t + a_i \in [a_i, cur + a_i]$.
  - Since $a_i \leq cur + 1$, the ranges $[0, cur]$ and $[a_i, cur + a_i]$ are contiguous (no gap). Update $cur \leftarrow cur + a_i$.

If we process all coins without stopping, the answer is $cur + 1$.

### Example

Consider $n = 5$, coins $[2, 9, 1, 2, 7]$. After sorting: $[1, 2, 2, 7, 9]$.

| Step ($i$) | $a_i$ | Condition ($a_i \leq cur + 1$) | New $cur$ | Formable range |
|---|---|---|---|---|
| Init | — | — | $0$ | $[0, 0]$ |
| 1 | $1$ | $1 \leq 1$ ✓ | $0 + 1 = 1$ | $[0, 1]$ |
| 2 | $2$ | $2 \leq 2$ ✓ | $1 + 2 = 3$ | $[0, 3]$ |
| 3 | $2$ | $2 \leq 4$ ✓ | $3 + 2 = 5$ | $[0, 5]$ |
| 4 | $7$ | $7 \leq 6$ ✗ | — | Gap at $6$ |

Answer: $cur + 1 = 5 + 1 = 6$.

Verification: from $\{1, 2, 2\}$ we can form sums $0, 1, 2, 3, 4, 5$ but not $6$.

## Complexity

- **Time:** $O(n \log n)$ — sorting dominates; the traversal is $O(n)$.
- **Memory:** $O(n)$ — storing the array.

## Code (C++)

[Solution Code](../code/Missing%20Coin%20Sum.cpp)
