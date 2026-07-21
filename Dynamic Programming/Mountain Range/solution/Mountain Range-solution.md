# Mountain Range - Solution

**ID:** 3314 | **URL:** https://cses.fi/problemset/task/3314

## Approach

### Problem Restatement

There are $n$ mountains in a row with heights $h_i$. You can glide from mountain $a$ to mountain $b$ if $h_a > h_b$ and all mountains between $a$ and $b$ are shorter than $h_a$. Find the maximum number of mountains visitable on a single journey.

### Core Idea

From mountain $i$, we can glide directly to any mountain $j$ in the interval $(L[i], R[i])$ with $h_j < h_i$, where $L[i]$ is the nearest index to the left with $h_{L[i]} > h_i$ and $R[i]$ is the nearest index to the right with $h_{R[i]} > h_i$. Mountain $i$ is the tallest in $[L[i]+1, R[i]-1]$, so it dominates all mountains in that range.

**Why $(L[i], R[i])$ is the exact reachable zone:** If $b < L[a]$, then $h_{L[a]} > h_a$ and $L[a]$ lies between $a$ and $b$, so $a$ is not taller than all mountains in between. Conversely, for $b \in (L[a], R[a])$ with $h_b < h_a$, every mountain between $a$ and $b$ lies in $(L[a], R[a])$ and has height $< h_a$, so gliding is possible.

**DP on decreasing height:** Let $dp[i]$ be the maximum number of mountains visitable on a journey ending at $i$. Process mountains from tallest to shortest using a segment tree. When processing $p$: query $dp[p]$ from the segment tree (values propagated by taller mountains that can reach $p$), then propagate $dp[p] + 1$ to ranges $[L[p]+1, p-1]$ and $[p+1, R[p]-1]$. The answer is $\max(dp) + 1$.

**Correctness:** By induction on height. The tallest mountain has $dp = 0$. When processing $p$, all taller mountains have already propagated their values. The segment tree value at $p$ is the maximum of all $dp[q] + 1$ where $q$ is taller and can glide to $p$, which is exactly the best journey prefix ending at $p$.

Compute $L[i]$ and $R[i]$ with monotonic stacks in $O(n)$: maintain a strictly decreasing stack; $L[i]$ (or $R[i]$) is the stack top after popping all heights $< h_i$.

### Algorithm

1. Compute $L[i]$ and $R[i]$ using monotonic stacks.
2. Sort mountain indices by decreasing height.
3. For each mountain $p$ in sorted order:
   - $dp[p] = \text{query}(p)$ on segment tree
   - $\text{update}(L[p]+1, p-1, dp[p]+1)$ and $\text{update}(p+1, R[p]-1, dp[p]+1)$
4. Output $\max(dp) + 1$.

### Example

$h = [20, 15, 17, 35, 25, 40, 12, 19, 13, 12]$

$L = [0, 1, 1, 0, 4, 0, 6, 6, 8, 9]$, $R = [4, 3, 4, 6, 6, 11, 8, 11, 11, 11]$ (boundaries 0, 11)

Processing in decreasing height order:

| Step | $p$ | $h_p$ | $dp[p]$ | Propagate $dp[p]+1$ to |
|------|-----|-------|---------|------------------------|
| 1 | 6 | 40 | 0 | $[1,5]$ and $[7,10]$ |
| 2 | 4 | 35 | 1 | $[1,3]$ and $[5,5]$ |
| 3 | 5 | 25 | 2 | — (ranges empty) |
| 4 | 1 | 20 | 2 | $[2,3]$ |
| 5 | 8 | 19 | 1 | $[7,7]$ and $[9,10]$ |
| 6 | 3 | 17 | 3 | $[2,2]$ |
| 7 | 2 | 15 | 4 | — |
| 8 | 9 | 13 | 2 | $[10,10]$ |
| 9 | 7 | 12 | 2 | — |
| 10 | 10 | 12 | 3 | — |

$\max(dp) = 4$, answer $= 4 + 1 = \mathbf{5}$.

One optimal path: mountain 6 → 4 → 1 → 3 → 2 (heights 40 → 35 → 20 → 17 → 15).

## Complexity

- **Time:** $O(n \log n)$ — sorting + $n$ segment tree operations each $O(\log n)$
- **Space:** $O(n)$ — for arrays, segment tree, and stack

## Code (C++)

[Solution Code](../code/Mountain%20Range.cpp)
