# Parcel Delivery - Solution

**ID:** 2121 | **URL:** https://cses.fi/problemset/task/2121

## Approach

### Problem Restatement

Given $n$ cities and $m$ directed routes, each with capacity $r$ (max parcels) and cost $c$ per parcel, send exactly $k$ parcels from city 1 to city $n$ at minimum total cost (or report $-1$ if impossible).

### Core Idea

This is a **min-cost flow** problem: send $k$ units of flow from node 1 to node $n$, where each edge has capacity $r$ and cost $c$ per unit.

**Network construction:** Each route $(a, b, r, c)$ becomes a forward edge (capacity $r$, cost $c$) and a reverse edge (capacity 0, cost $-c$). Add a super source $S \to$ city 1 and city $n \to$ super sink $T$, both with capacity $k$ and cost 0.

**Successive Shortest Augmenting Path (SSAP):** Repeatedly find the cheapest augmenting path from $S$ to $T$ and push flow along it. A flow is optimal iff no negative-cost augmenting path exists in the residual network — if one did, augmenting along it would reduce total cost, contradicting optimality.

**Potentials for Dijkstra:** Residual edges can have negative cost (from reverse edges). Use potentials `del[u]` (shortest distance from $S$ to $u$) to define reduced cost $w'(i) = c_i + del[u] - del[v] \geq 0$, which is non-negative and preserves shortest paths (since $\sum_{i \in P} w'(i) = \sum_{i \in P} c_i + del[S] - del[T]$, a constant offset). This enables Dijkstra instead of Bellman-Ford.

### Algorithm

1. Build the flow network with super source $S$ and super sink $T$.
2. Repeat:
   - Run Dijkstra with reduced costs to find the cheapest augmenting path.
   - If no path exists: if total flow $< k$, output $-1$; otherwise output total cost.
   - Augment maximum possible flow along the path (up to remaining $k$).
   - Update potentials: $del[u] \mathrel{+}= dist[u]$ for all reachable $u$.
3. Output total cost when flow reaches $k$.

### Example

$n=4$, $m=5$, $k=3$. Routes: $(1,2,5,100), (1,3,10,50), (1,4,7,500), (2,4,8,350), (3,4,2,100)$.

| Round | Path | Cost/unit | Augment | Subtotal |
|-------|------|-----------|---------|----------|
| 1     | $1 \to 3 \to 4$ | $50+100=150$ | 2 (capped by edge $3\to4$) | $2 \times 150 = 300$ |
| 2     | $1 \to 2 \to 4$ | $100+350=450$ | 1 | $1 \times 450 = 450$ |

Total: $300 + 450 = \mathbf{750}$.

## Complexity

- **Time:** $O(k \cdot m \log n)$
- **Memory:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Parcel%20Delivery.cpp)
