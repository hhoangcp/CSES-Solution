# Nearest Shops - Solution

**ID:** 3303 | **URL:** https://cses.fi/problemset/task/3303

## Approach

### Problem Restatement

Given $n$ cities, $m$ bidirectional roads, and $k$ cities with anime shops, for each city find the minimum distance to a **different** city that has an anime shop. If a city has a shop itself, it must find the nearest *other* shop city. If no such city exists, output $-1$.

### Core idea

Run a multi-source BFS from all shop cities, storing `dist[v]` (distance to nearest shop) and `src[v]` (which shop). Cities with the same `src` form an influence zone.

- **Non-shop city:** `ans = dist[v]` (the nearest shop is in a different city).
- **Shop city $s$:** the shortest path to another shop must cross a boundary edge $(u,v)$ where `src[u] != src[v]`. Any path from $s$ to another shop must pass through an edge where the source changes, and the shortest such path goes from $s$ to $u$ (distance `dist[u]`), crosses the edge (+1), from $v$ to its shop (distance `dist[v]`), totaling `dist[u] + dist[v] + 1`. Take the minimum over all boundary edges.

### Algorithm

1. Multi-source BFS from all shop cities. Store `dist[v]` and `src[v]`.
2. Initialize `ans[i] = dist[i]` for non-shop cities, `ans[i] = INF` for shop cities.
3. For each edge $(u, v)$ where `src[u] != src[v]`:
   - $d = \text{dist}[u] + \text{dist}[v] + 1$
   - Update `ans[src[u]] = min(ans[src[u]], d)` and `ans[src[v]] = min(ans[src[v]], d)`.
4. For each city $i$: if `ans[i] == INF`, output $-1$; otherwise output `ans[i]`.

### Example

$n=9, m=6, k=4$, shops: {2,4,5,7}.

Shops 2 and 4 are adjacent: edge (2,4) gives $d = 0+0+1=1$. `ans[2]=1, ans[4]=1`. Shops 5 and 7 are isolated: `ans[5]=-1, ans[7]=-1`.

Output: `1 1 1 1 -1 1 -1 2 -1`

## Complexity

- **Time:** $O(n + m)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Nearest%20Shops.cpp)
