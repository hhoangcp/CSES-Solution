# MST Edge Set Check - Solution

**ID:** 3408 | **URL:** https://cses.fi/problemset/task/3408

## Approach

### Problem Restatement

Given a connected undirected weighted graph and $q$ edge sets, determine for each set whether all edges in the set can simultaneously be included in some MST.

### Core idea

A set of edges $S$ can be in some MST iff for every weight $w$, the edges of weight $w$ in $S$ do not form a cycle when added to a DSU containing only edges of weight $< w$. If $S$ is in some MST $T$, then every edge in $T$ was added by Kruskal without creating a cycle, so edges of weight $w$ in $S$ don't either. Conversely, if there's no conflict, we can extend $S$ to an MST by Kruskal: since edges in $S$ don't conflict with each other or with lighter edges, an MST containing $S$ exists.

### Algorithm

1. Group graph edges by weight: `edgeW[w]`. For each query, group edges by weight: `layers[w]`.
2. Process weights in increasing order. For each $w$:
   - **Check queries:** Save checkpoint $t = S.size()$. For each query layer at $w$, try to union its edges. If any union fails, mark NO. Rollback to checkpoint.
   - **Permanently add:** Union all graph edges of weight $w$.
3. Output YES/NO for each query.

### Rollback DSU

Use union by size (no path compression, since it's hard to roll back). Each `Union` saves $(u, v, cnt_v)$ to a stack. `Rollback(t)` undoes all operations from position $t$ onward.

### Example

Query with edge weight 4 connecting nodes 1 and 2: after adding edges of weight $< 4$, nodes 1 and 2 are already connected. Union fails → NO.

Query with edge weight 2 connecting nodes 3 and 4: with only edges of weight $< 2$ in the DSU, nodes 3 and 4 are in different components. Union succeeds → YES.

## Complexity

- **Time:** $O(m \log m + (m + \sum k) \log n)$ — DSU without path compression, so each `Find` costs $O(\log n)$
- **Space:** $O(n + m + q)$

## Code (C++)

[Solution Code](../code/MST%20Edge%20Set%20Check.cpp)
