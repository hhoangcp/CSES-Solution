# Eulerian Subgraphs - Solution

**ID:** 2078 | **URL:** https://cses.fi/problemset/task/2078

## Approach

### Problem Restatement

Given an undirected graph with $n$ vertices and $m$ edges, consider subgraphs containing all vertices and a subset of edges. A subgraph is *Eulerian* if every vertex has even degree. Count the number of Eulerian subgraphs modulo $10^9 + 7$.

### Core Idea

Build a **spanning forest** using DSU. When processing edges, an edge connecting two different DSU components is a **tree edge** (part of the forest); an edge connecting vertices already in the same component is a **cycle edge**. The spanning forest has $n - c$ tree edges (where $c$ is the number of connected components), so the number of cycle edges is $m - (n - c) = m - n + c$.

Each cycle edge, when added to the spanning forest, creates exactly one **fundamental cycle**. These fundamental cycles form a **basis for the cycle space over $\mathbb{F}_2$**: they are linearly independent and span all Eulerian subgraphs. The bijection holds because the incidence matrix of the graph over $\mathbb{F}_2$ has rank $n - c$ (each component contributes $n_i - 1$), so the kernel (cycle space) has dimension $m - n + c$. Each subset of the $m - n + c$ fundamental cycles corresponds to exactly one Eulerian subgraph (XOR of selected cycles), and vice versa.

Thus the answer is $2^{m - n + c} \pmod{10^9 + 7}$.

### Algorithm

1. Initialize DSU with $n$ elements and `res = 1`.
2. For each edge $(u, v)$: if `Union(u, v)` fails (already connected), multiply `res` by 2 modulo $10^9 + 7$.
3. Output `res`.

### Example

$n = 4$, $m = 3$, edges: (1,2), (1,3), (2,3).

- Edge (1,2): different components → tree edge.
- Edge (1,3): different components → tree edge.
- Edge (2,3): same component (2→1→3) → cycle edge. `res *= 2 = 2`.

$c = 2$ (component $\{1,2,3\}$ and isolated vertex $\{4\}$). Answer: $2^{3-4+2} = 2^1 = 2$.

The two Eulerian subgraphs: the empty graph (all degrees 0) and the full triangle (all degrees 2).

## Complexity

- **Time:** $O(m \cdot \alpha(n))$ — each edge one DSU operation.
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Eulerian%20Subgraphs.cpp)
