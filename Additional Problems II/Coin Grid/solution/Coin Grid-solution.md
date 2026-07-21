# Coin Grid - Solution

**ID:** 1709 | **URL:** https://cses.fi/problemset/task/1709

## Problem Statement

Given an $n \times n$ grid with coins in some cells, remove all coins using the fewest operations, where each operation removes all coins in one row or column. Output the minimum number of operations and the sequence.

## Approach

### Modeling: Minimum Vertex Cover on a Bipartite Graph

Build a bipartite graph $G = (L \cup R, E)$: left vertices $L$ represent the $n$ rows, right vertices $R$ represent the $n$ columns, a coin at $(i,j)$ creates an edge between row $i$ and column $j$. Selecting a row or column corresponds to selecting a vertex that "covers" all incident edges. The problem reduces to finding a **Minimum Vertex Cover** on a bipartite graph.

### König's Theorem: MVC = Maximum Matching

By **König's theorem**, in a bipartite graph, the minimum vertex cover has size equal to the maximum matching.

Given maximum matching $M$, construct the MVC as follows: let $U \subseteq L$ be the unmatched left vertices, $Z$ the set of all vertices reachable from $U$ via alternating paths. Define $C = (L \setminus Z) \cup (R \cap Z)$.

**Why $C$ is an MVC:**

- **$|C| = |M|$:** Every alternating path from $U$ to a right vertex $r \in R \cap Z$ ends with a matching edge (otherwise we'd have an augmenting path, contradicting maximality of $M$). Counting: $|L \setminus Z| + |R \cap Z| = |M|$.
- **$C$ covers all edges:** Consider edge $(l, r)$. If $l \notin Z$ then $l \in C$. If $l \in Z$ and the edge is in $M$ then $r \in Z \Rightarrow r \in C$. If $l \in Z$ and the edge is not in $M$, the alternating path to $l$ plus this edge extends to $r$, so $r \in Z \Rightarrow r \in C$.
- **Minimality:** Matching edges share no vertices, so each needs at least one endpoint in any cover, meaning every vertex cover has size $\geq |M|$. Since $|C| = |M|$, $C$ is minimum.

## Algorithm

1. Build bipartite flow network: source $\to$ rows (cap 1), rows $\to$ columns (cap 1 for each coin), columns $\to$ sink (cap 1).
2. Compute maximum matching using Dinic.
3. Find unmatched rows, DFS on alternating-path graph (undirected, reverse matching edges) to find $Z$.
4. Output: rows not in $Z$ (type 1) and columns in $Z$ (type 2).

## Example

$3 \times 3$ grid: coins at $(1,3), (2,1), (2,3)$.

- Maximum matching: $\{(2,1), (1,3)\}$, size 2.
- Minimum vertex cover: row 2, column 3.
- Result:
```
2
1 2
2 3
```

## Implementation Notes

- Use Dinic for maximum matching.
- After matching, build an undirected graph `V2` for alternating-path traversal: for each matched row, reverse the matching edge in `V2`.
- Unmatched rows are the starting points for the alternating-path DFS.

## Complexity

- **Time:** $O(n^{5/2})$ — Dinic on bipartite graph
- **Memory:** $O(n^2)$

## Code (C++)

[Solution Code](../code/Coin%20Grid.cpp)
