# Knuth Division - Solution

**ID:** 2088 | **URL:** https://cses.fi/problemset/task/2088

## Approach

### Problem Restatement

Given an array of $n$ numbers, split it into $n$ subarrays each containing one element. At each step, choose any subarray and split it into two. The cost of a step is the sum of values in the chosen subarray. What is the minimum total cost?

### Core Idea

Define $dp[i][j]$ = minimum cost to split subarray $[i, j]$ into single elements:

$$dp[i][j] = \min_{i \le k < j} \left( dp[i][k] + dp[k+1][j] + S(i, j) \right)$$

where $S(i, j) = \text{prefix}[j] - \text{prefix}[i-1]$. The cost $S(i, j)$ accounts for the current split; the recursive terms handle further splits of the two halves. Naive DP is $O(n^3)$ — too slow for $n = 5000$.

**Knuth optimization** reduces this to $O(n^2)$ by exploiting the monotonicity of the optimal split point: $opt[i][j-1] \le opt[i][j] \le opt[i+1][j]$. This holds when the cost function $w(i,j) = S(i,j)$ satisfies:
1. **Quadrangle inequality:** $w(a,c) + w(b,d) \le w(a,d) + w(b,c)$ for $a \le b \le c \le d$. Both sides equal $(prefix[c] - prefix[a-1]) + (prefix[d] - prefix[b-1])$, so QI holds with equality.
2. **Monotonicity:** $w(b,c) \le w(a,d)$ for $a \le b \le c \le d$. True since all $a_i > 0$.

Because $S$ satisfies QI, $dp$ also satisfies QI (by induction on segment length), which implies the monotonicity of $opt$. With this, the total number of candidates checked across all DP states is $O(n^2)$.

### Algorithm

1. Compute prefix sums.
2. Initialize $dp[i][i] = 0$, $opt[i][i] = i$.
3. Fill DP by increasing segment length. For each $[i, j]$: search $k$ only in $[opt[i][j-1], \min(opt[i+1][j], j-1)]$.
4. Output $dp[1][n]$.

### Example

Array: $[2, 7, 3, 2, 5]$. Prefix: $[0, 2, 9, 12, 14, 19]$.

Optimal split of $[1, 5]$:

| Step | Subarray | Split at $k$ | Cost $S(i,j)$ | Result |
|------|----------|-------------|----------------|--------|
| 1 | $[1,5]$ | 2 | $19$ | $[1,2] + [3,5]$ |
| 2 | $[1,2]$ | 1 | $9$ | $[1] + [2]$ |
| 3 | $[3,5]$ | 4 | $10$ | $[3,4] + [5]$ |
| 4 | $[3,4]$ | 3 | $5$ | $[3] + [4]$ |

Total: $19 + 9 + 10 + 5 = 43$.

## Complexity

- **Time:** $O(n^2)$ — Knuth optimization reduces from $O(n^3)$.
- **Memory:** $O(n^2)$ — DP and `opt` tables.

## Code (C++)

[Solution Code](../code/Knuth%20Division.cpp)
