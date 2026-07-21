# Bus Companies - Solution

**ID:** 3158 | **URL:** https://cses.fi/problemset/task/3158

## Approach

### Problem Restatement

There are $n$ cities and $m$ bus companies. Company $i$ has ticket cost $c_i$ and operates in $k_i$ cities. Buying a ticket from company $i$ allows travel between any two of its cities. Find the cheapest cost to travel from city 1 to every other city.

### Core idea

Instead of creating edges between every pair of cities in the same company (up to $O(n^2)$ edges), use an **intermediate node** technique: build a graph with $n + m$ nodes — $n$ city nodes and $m$ company nodes. Buying a ticket from company $i$ corresponds to the path $u \to (n+i)$ (paying $c_i$) then $(n+i) \to v$ (cost 0), matching the original problem's cost exactly. Conversely, every path in the augmented graph alternates between city and company nodes (bipartite structure), so each visit to company node $n+i$ costs exactly $c_i$, corresponding to buying and using that ticket. Since Dijkstra finds shortest paths in the augmented graph, the results correspond to optimal routes in the original problem.

### Algorithm

1. Create a graph with $n + m$ nodes. For each company $i$ with cost $c_i$ operating in cities $a_1, \ldots, a_k$:
   - Add edge $a_j \to (n+i)$ with weight $c_i$ (paying for the ticket).
   - Add edge $(n+i) \to a_j$ with weight 0 (using the ticket to reach a city).
2. Run Dijkstra's algorithm from node 1.
3. Output `dist[1], dist[2], ..., dist[n]`.

### Example

$n=5$, $m=3$, costs $[4,3,2]$.

- Company 3 (cost 2) serves $\{2,3,4,5\}$: edges $2 \to 8, 3 \to 8, 4 \to 8, 5 \to 8$ (weight 2) and $8 \to 2, 8 \to 3, 8 \to 4, 8 \to 5$ (weight 0).
- From city 3 to city 2: $3 \xrightarrow{2} 8 \xrightarrow{0} 2$, total cost 2.

Dijkstra from node 1: `0 5 4 4 3`.

## Complexity

- **Time:** $O((n + m + \sum k_i) \log(n + m))$
- **Space:** $O(n + m + \sum k_i)$

## Code (C++)

[Solution Code](../code/Bus%20Companies.cpp)
