# Tree Distances I - Solution

**ID:** 1132 | **URL:** https://cses.fi/problemset/task/1132

## Approach

### Problem Restatement

Given a tree with $n$ nodes, compute for each node the maximum distance from it to any other node.

**Constraints:** $1 \le n \le 2 \cdot 10^5$.

### Core idea

This is a rerooting DP solved in two DFS passes. The maximum distance from $u$ goes in two directions: **down** into $u$'s subtrees, or **up** through the parent then possibly down another branch or further up.

**First DFS (downward distances):** Pick node $1$ as a temporary root. For each $u$, compute $dp[u]$ = the maximum distance from $u$ to a node in the subtree of $u$:

$$dp[u] = \max_{v \in \text{children}(u)} (dp[v] + 1) \quad (\text{leaf: } dp[u] = 0)$$

**Second DFS (rerooting):** When visiting $u$, first set $ans[u] = dp[u]$ (the answer for $u$ once $u$ is the "root" of the visited part). To reroot from $u$ to child $v$, temporarily remove $v$'s contribution from $dp[u]$ to get $dp'[u]$, then set $dp[v] = \max(dp[v],\ dp'[u] + 1)$ to fold the "up through $u$" direction into $v$, and recurse `Rotate(v)`. On return, restore $dp[u], dp[v]$.

To compute $dp'[u]$ in $O(1)$ when removing child $i$ (the list $V[u]$ includes the parent too, since the parent appears there with its already-rerooted $dp$ reflecting the upward direction), build a prefix-max array over $u$'s neighbors:

$$Left[i] = \max_{j \le i}(dp[V[u][j]] + 1)$$

and iterate children right-to-left maintaining $Right$ = max of $dp[w]+1$ for children to the right of $i$. Then:

$$dp'[u] = \max(Left[i-1],\ Right)$$

**Correctness (induction on the rerooting DFS):** At root $1$, $dp[1]$ is correct since every node lies in the subtree of $1$. Assume that when `Rotate(u)` is called, $dp[u]$ already equals the maximum distance from $u$ to any node (including the upward direction, because the parent's reroot step updated $dp[u] \mathrel{+}= dp'[\text{parent}]+1$). When rerooting to child $v$, $dp'[u]$ takes the max over all downward directions from $u$ except through $v$ — and the "up through $u$'s parent" direction is still present (it lives in $dp[\text{parent}]+1$, counted in $Left/Right$). Hence $dp[v] = \max(dp[v], dp'[u]+1)$ correctly folds the upward direction into $v$, and `ans[v] = dp[v]` records the correct answer for $v$ before going deeper.

### Algorithm

1. Read $n$; build the adjacency list from the $n-1$ edges.
2. `DFS(u)` (using `lab` to avoid walking back to the parent): $dp[u] = 0$; for each child $v$ (`lab[u] != v`): set $lab[v] = u$, call `DFS(v)`, then $dp[u] = \max(dp[u], dp[v] + 1)$.
3. `Rotate(u)`:
   - $ans[u] = dp[u]$.
   - Build $Left[i] = \max(Left[i-1],\ dp[V[u][i]] + 1)$ over $V[u]$.
   - $Right = 0$. Iterate $i$ from $|V[u]|-1$ down to $0$, with $v = V[u][i]$:
     - If $lab[u] \ne v$: save $tmp_u = dp[u], tmp_v = dp[v]$; set $dp[u] = \max(Left[i-1], Right)$ (or $Right$ if $i=0$); $dp[v] = \max(dp[v], dp[u]+1)$; call `Rotate(v)`; restore $dp[u] = tmp_u, dp[v] = tmp_v$.
     - $Right = \max(Right, dp[v] + 1)$.
4. Call `DFS(1)`, then `Rotate(1)`; print $ans[1..n]$.

### Example

The problem statement gives $n = 5$, edges `1-2, 1-3, 3-4, 3-5`. Tree: $1 \to \{2, 3\}$; $3 \to \{4, 5\}$.

**First DFS (root $1$)** — downward distances $dp$:

| $u$ | $1$ | $2$ | $3$ | $4$ | $5$ |
|---|---|---|---|---|---|
| $dp[u]$ | $2$ | $0$ | $1$ | $0$ | $0$ |

**Second DFS (rerooting)** — recording $ans[u] = dp[u]$ on entry to each $u$:

| Step | At | Temporary $dp'$ | Update | $ans$ |
|---|---|---|---|---|
| enter $1$ | — | — | $ans[1] = dp[1] = 2$ | $ans[1]=2$ |
| $1 \to 3$ | remove child $3$ from $dp[1]$: $dp'[1] = dp[2]+1 = 1$ | $dp'[1]=1$ | $dp[3] = \max(1,\ 1+1) = 2$ | $ans[3]=2$ |
| $3 \to 5$ | remove child $5$ from $dp[3]$: $dp'[3] = \max(dp[1]+1,\ dp[4]+1) = \max(2, 1) = 2$ | $dp'[3]=2$ | $dp[5] = \max(0,\ 2+1) = 3$ | $ans[5]=3$ |
| $3 \to 4$ | remove child $4$ from $dp[3]$: $dp'[3] = \max(dp[1]+1,\ dp[5]+1) = \max(2, 1) = 2$ | $dp'[3]=2$ | $dp[4] = \max(0,\ 2+1) = 3$ | $ans[4]=3$ |
| $1 \to 2$ | remove child $2$ from $dp[1]$: $dp'[1] = dp[3]+1 = 2$ | $dp'[1]=2$ | $dp[2] = \max(0,\ 2+1) = 3$ | $ans[2]=3$ |

(Note: at node $3$, $V[3]=[1,4,5]$ includes the parent $1$; by then $dp[1]$ has been rerooted to $1$, so $dp[1]+1 = 2$ represents $3$'s "up through parent" direction.)

Result for nodes $1..5$: `2 3 2 3 3` — matching the problem's example.

## Complexity

- **Time:** $O(n)$ — two DFS passes; at each $u$, building $Left/Right$ and iterating children costs proportional to $|V[u]|$, summing to $O(n)$.
- **Memory:** $O(n)$ — adjacency list, the $dp$, $ans$, $lab$ arrays, and the temporary $Left$ array inside `Rotate`.

## Code (C++)

[Solution Code](../code/Tree%20Distances%20I.cpp)
