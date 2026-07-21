# Elevator Rides - Solution

**ID:** 1653 | **URL:** https://cses.fi/problemset/task/1653

## Approach

### Problem Restatement

Given $n$ people with weights $w_i$ and an elevator with capacity $x$, find the minimum number of rides to transport everyone. Each person takes exactly one ride.

### Core idea

Since $n \le 20$, use **bitmask DP**. Represent a subset of people as bitmask $S$. For each subset, store a pair $(r, w)$ compared lexicographically: $r$ = minimum number of rides, $w$ = minimum weight in the last ride (for the same $r$).

Storing $w$ is essential: without it, we cannot determine whether the last ride has room for the next person. With $w$, we know the remaining capacity is $x - w$.

For each person $j \in S$, let $(R, W) = dp[S \setminus \{j\}]$:

- **Last ride has room** ($W + w_j \le x$): add person $j$ to the last ride. New state: $(R, W + w_j)$.
- **Last ride full** ($W + w_j > x$): start a new ride. New state: $(R + 1, \min(W, w_j))$.

$$dp[S] = \min_{j \in S} \begin{cases} (R, W + w_j) & \text{if } W + w_j \le x \\ (R + 1, \min(W, w_j)) & \text{if } W + w_j > x \end{cases}$$

**Why $\min(W, w_j)$:** When starting a new ride, we can reorder the rides — the "last ride" in our representation doesn't have to be the one containing person $j$. We keep the lighter ride as last to maximize remaining capacity. Since rides are unordered in reality, both arrangements are valid, and keeping the smaller weight is always at least as good.

Base case: $dp[0] = (1, 0)$ — one empty ride with weight 0, ready to accept people. Answer: $dp[2^n - 1].r$.

### Algorithm

1. Initialize $dp[0] = (1, 0)$.
2. For $S = 1$ to $2^n - 1$:
   - Set $dp[S] = (\infty, 0)$.
   - For each $j$ where bit $j$ of $S$ is set:
     - $(R, W) = dp[S \setminus \{j\}]$.
     - If $W + w_j \le x$: candidate $= (R, W + w_j)$.
     - Else: candidate $= (R + 1, \min(W, w_j))$.
     - $dp[S] = \min(dp[S], \text{candidate})$ (lexicographic).
3. Output $dp[2^n - 1].r$.

### Example

Input: $n = 4$, $x = 10$, $w = [4, 8, 6, 1]$.

| $S$ | Set | $dp[S]$ | Key transition |
|:---:|:---|:---:|:---|
| 0000 | $\emptyset$ | (1, 0) | Base |
| 0001 | $\{0\}$ | (1, 4) | $0{+}4 \le 10$ |
| 0010 | $\{1\}$ | (1, 8) | $0{+}8 \le 10$ |
| 0011 | $\{0,1\}$ | (2, 4) | Both $4{+}8{>}10 \to$ new ride, $\min(4,8){=}4$ |
| 0100 | $\{2\}$ | (1, 6) | $0{+}6 \le 10$ |
| 0101 | $\{0,2\}$ | (1, 10) | $6{+}4 \le 10$ |
| 0111 | $\{0,1,2\}$ | (2, 8) | From $\{0,2\}$: $10{+}8{>}10 \to (2, \min(10,8))$ |
| 1111 | $\{0,1,2,3\}$ | (2, 9) | From $\{0,2,3\}$: $1{+}8 \le 10 \to (2, 9)$ |

Result: 2 rides — e.g., $\{4, 6\}$ and $\{8, 1\}$.

## Complexity

- **Time:** $O(2^n \cdot n)$
- **Space:** $O(2^n)$

## Code (C++)

[Solution Code](../code/Elevator%20Rides.cpp)
