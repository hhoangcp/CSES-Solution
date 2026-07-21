# Josephus Queries - Solution

**ID:** 2164 | **URL:** https://cses.fi/problemset/task/2164

## Approach

### Problem Restatement

$n$ people stand in a circle numbered $1, 2, \ldots, n$. Each round, every second person from the starting point is eliminated. Repeat until nobody remains. Process $q$ queries: given $n$ and $k$, who is the $k$-th person eliminated?

### Core idea

In one pass around the circle of $n$, all even-positioned people ($2, 4, 6, \ldots$) are eliminated. This removes $\lceil n/2 \rceil$ people and leaves $\lfloor n/2 \rfloor$ survivors, forming a smaller subproblem. Let $f(n, k)$ be the $k$-th person eliminated in a circle of $n$.

**Case $k \le \lceil n/2 \rceil$:** The $k$-th eliminated is in the first pass. The answer is $2k$ if $2k \le n$, or $(2k) \bmod n$ if $2k > n$ (this only happens when $n$ is odd and $k = \lceil n/2 \rceil$, giving person 1).

**Case $k > \lceil n/2 \rceil$:** The $k$-th eliminated overall is the $(k - \lceil n/2 \rceil)$-th eliminated among the $\lfloor n/2 \rfloor$ survivors. Recursively compute $p = f(\lfloor n/2 \rfloor, k - \lceil n/2 \rceil)$, then map position $p$ back to the original numbering.

**Reverse mapping:** After the first pass eliminates all even positions, the survivors in order are:
- $n$ even: $1, 3, 5, \ldots, n-1$. The $p$-th survivor has original number $2p - 1$.
- $n$ odd: $3, 5, 7, \ldots, n$. The $p$-th survivor has original number $2p + 1$. (Since $n$ is odd, the last person in the first pass is person 1, so the next round starts from person 3.)

### Algorithm

For each query $(n, k)$:
1. Base case: if $n = 1$, return $1$.
2. If $k \le \lceil n/2 \rceil$: return $2k$ if $2k \le n$, else $(2k) \bmod n$.
3. Otherwise: compute $p = f(\lfloor n/2 \rfloor, k - \lceil n/2 \rceil)$ recursively. Return $2p - 1$ if $n$ is even, $2p + 1$ if $n$ is odd.

### Example

For $n = 7$, the full elimination order is $2, 4, 6, 1, 5, 3, 7$.

- $f(7, 1)$: $k = 1 \le 4$, $2 \cdot 1 = 2 \le 7$ → answer **2**.
- $f(7, 3)$: $k = 3 \le 4$, $2 \cdot 3 = 6 \le 7$ → answer **6**.
- $f(7, 5)$: $k = 5 > 4$. $k' = 1$, $p = f(3, 1) = 2$. $n = 7$ odd → $2 \cdot 2 + 1 =$ **5**.
- $f(2, 2)$: $k = 2 \le 1$? No, $k = 2 > 1$. $k' = 1$, $p = f(1, 1) = 1$. $n = 2$ even → $2 \cdot 1 - 1 =$ **1**.

## Complexity

- **Time:** $O(\log n)$ per query ($n$ halves each recursion level)
- **Space:** $O(\log n)$ (recursion depth), or $O(1)$ if iteratively implemented

## Code (C++)

[Solution Code](../code/Josephus%20Queries.cpp)
