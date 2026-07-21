# Money Sums - Solution

**ID:** 1745 | **URL:** https://cses.fi/problemset/task/1745

## Approach

### Problem Restatement

Given $n$ coins with values $x_1, \ldots, x_n$ ($1 \le n \le 100$, $1 \le x_i \le 1000$), find all distinct sums that can be formed by choosing any subset of the coins. Output the count and list the sums in increasing order.

### Core Idea

This is the classic **subset sum** problem. Let $dp[s]$ indicate whether sum $s$ is achievable. Initially only $dp[0]$ is true (empty subset). For each coin of value $x$, update $dp[s] = dp[s] \lor dp[s-x]$ iterating $s$ from $S_{\max}$ down to $x$ (reverse order prevents using the same coin twice). The maximum achievable sum is $S_{\max} = \sum x_i \le 100 \times 1000 = 10^5$.

**Bitset optimization:** Represent the entire $dp$ array as a `bitset<100001>`. The update for coin $x$ becomes a single operation:

$$\text{bs} \leftarrow \text{bs} \lor (\text{bs} \ll x)$$

The left shift $\text{bs} \ll x$ maps each achievable sum $s$ to $s+x$ (adding coin $x$ to existing subsets). The OR combines sums without $x$ and with $x$. Bitset exploits 64-bit parallelism, giving roughly 64× speedup over a sequential boolean array.

**Correctness (invariant):** After processing $k$ coins, bit $s$ is set iff there exists a subset of $\{x_1, \ldots, x_k\}$ with sum $s$. Proof by induction: base case has only bit 0 (empty subset). Inductive step: $\text{bs} \ll x_{k+1}$ creates sums that include $x_{k+1}$; the OR merges these with sums that don't — so every subset of $\{x_1, \ldots, x_{k+1}\}$ is accounted for exactly once.

### Algorithm

1. Initialize `bitset<100001> bs` with only bit 0 set.
2. For each coin $x$: `bs |= (bs << x)`.
3. Output `bs.count() - 1` (excluding sum 0), then all set bits from 1 onward.

### Example

Coins $\{4, 2, 5, 2\}$:

| Step | Coin $x$ | `bs << x` adds | Reachable sums (after OR) |
|------|----------|-----------------|---------------------------|
| Init | — | — | $\{0\}$ |
| 1 | 4 | $\{4\}$ | $\{0, 4\}$ |
| 2 | 2 | $\{2, 6\}$ | $\{0, 2, 4, 6\}$ |
| 3 | 5 | $\{5, 7, 9, 11\}$ | $\{0, 2, 4, 5, 6, 7, 9, 11\}$ |
| 4 | 2 | $\{2, 4, 6, 7, 8, 9, 11, 13\}$ | $\{0, 2, 4, 5, 6, 7, 8, 9, 11, 13\}$ |

Result: 9 sums: $2, 4, 5, 6, 7, 8, 9, 11, 13$.

## Complexity

- **Time:** $O(n \cdot S / 64)$ where $S \le 10^5$ is the maximum sum — each shift and OR takes $O(S/64)$
- **Space:** $O(S)$ for the bitset

## Code (C++)

[Solution Code](../code/Money%20Sums.cpp)
