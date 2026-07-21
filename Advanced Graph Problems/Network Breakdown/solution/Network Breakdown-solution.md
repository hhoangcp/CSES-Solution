# Network Breakdown - Solution

**ID:** 1677 | **URL:** https://cses.fi/problemset/task/1677

## Approach

### Problem Restatement

Given a network of $n$ computers and $m$ connections, $k$ connections break down one by one. After each breakdown, report the number of connected components.

### Core idea

Removing edges from DSU is hard, but adding edges is easy. Reverse the process: start with the state after all breakdowns (only surviving edges), then add back broken edges in reverse order ($e_k, e_{k-1}, \ldots, e_1$). Invariant: after adding back $\{e_k, \ldots, e_{i+1}\}$, the current edge set is exactly $E \setminus \{e_1, \ldots, e_i\}$, matching the state after breakdown $i$. Since the number of components depends only on the edge set (not insertion order), the component count recorded before adding $e_i$ is the answer for breakdown $i$.

### Algorithm

1. Read all $m$ edges into set `Start`. Read $k$ breakdown edges, remove from `Start`, store in `Q`.
2. Initialize DSU with $n$ components. Union all edges in `Start`.
3. Process breakdowns from $k$ down to $1$:
   - Record `ans[i] = comps` (current component count).
   - Union breakdown edge $i$. If endpoints in different components, `comps--`.
4. Output `ans[1], ans[2], ..., ans[k]`.

### Example

Network: 1-2, 1-3, 2-3, 3-4, 4-5. Breakdowns: (3,4), (2,3), (4,5).

After removing breakdowns: Start = {1-2, 1-3, 2-3}. comps = 3.

Add back in reverse: ans[3]=3, add 4-5 → comps=2. ans[2]=2. ans[1]=2.

Output: `2 2 3`

## Complexity

- **Time:** $O((n + m) \cdot \alpha(n))$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Network%20Breakdown.cpp)
