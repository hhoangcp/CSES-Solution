# Flight Routes Check - Solution

**ID:** 1682 | **URL:** https://cses.fi/problemset/task/1682

## Approach

### Problem Restatement

Given a directed graph with $n$ vertices and $m$ edges, check whether every city can reach every other city. If yes, print "YES". If no, print "NO" and a pair $(a, b)$ such that $a$ cannot reach $b$.

### Core Idea

Every vertex can reach every other vertex if and only if the graph has exactly **one Strongly Connected Component (SCC)**. Use Tarjan's algorithm to find all SCCs, then check:

- **Case 1 (not weakly connected):** If the first DFS from vertex $u_0$ doesn't cover all vertices, there exists an unvisited vertex $v$. Then $u_0$ cannot reach $v$ (otherwise DFS would have visited it). Output $(u_0, v)$.

- **Case 2 (weakly connected but not strongly):** If DFS covers all vertices but there exists an inter-SCC edge $u \to v$ with $\text{lab}[u] \neq \text{lab}[v]$, then there is no path from $v$ to $u$ (if there were, $u$ and $v$ would be in the same SCC). Output $(v, u)$.

If neither case occurs, the graph has exactly 1 SCC and the answer is "YES".

### Algorithm

1. Run Tarjan's DFS: compute `num[u]` (discovery order) and `low[u]` (smallest `num` reachable via tree edges and at most one back edge). When `low[u] >= num[u]`, pop all vertices from the stack down to $u$ as one SCC, assigning labels `lab[v]`.
2. During DFS, if starting a new DFS tree (i.e., the first DFS didn't cover all vertices), output the source of the first tree and the unvisited vertex as the counterexample pair.
3. After DFS, if all vertices were visited, scan all edges: if `lab[u] != lab[v]` for edge $u \to v$, output $(v, u)$.
4. If no inter-SCC edge exists, output "YES".

### Example

Input:
```
4 5
1 2
2 3
3 1
1 4
3 4
```

Tarjan finds: SCC 1 = $\{1, 2, 3\}$ (cycle $1 \to 2 \to 3 \to 1$), SCC 2 = $\{4\}$.

DFS from vertex 1 covers all vertices (edge $1 \to 4$ reaches vertex 4). Check inter-SCC edges: edge $3 \to 4$ has $\text{lab}[3] \neq \text{lab}[4]$. No reverse path exists from 4 to 3 (city 4 has no outgoing edges).

Output:
```
NO
4 3
```

Note: the problem accepts any valid pair; $(4, 1)$ or $(4, 2)$ are also correct since city 4 cannot reach any city in SCC 1.

## Complexity

- **Time:** $O(n + m)$ — Tarjan DFS and inter-SCC edge scan each process every vertex and edge once.
- **Space:** $O(n + m)$ — adjacency list and auxiliary arrays.

## Code (C++)

[Solution Code](../code/Flight%20Routes%20Check.cpp)
