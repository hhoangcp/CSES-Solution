# Flight Routes - Solution

**ID:** 1196 | **URL:** https://cses.fi/problemset/task/1196

## Approach

### Problem Restatement

Given a directed weighted graph with non-negative edge weights, find the $k$ shortest paths from vertex 1 to vertex $n$. A path may visit the same city multiple times. Two paths are considered different if they use different sets of edges.

### Core Idea

Extend Dijkstra by storing the **$k$ shortest distances** at each vertex instead of just one. Each vertex $v$ maintains a max-heap `Best[v]` of at most $k$ values. When processing an edge $u \to v$ with candidate distance `tmp = dist + c`:
- If `Best[v]` has fewer than $k$ elements: insert `tmp`.
- If `tmp < Best[v].top()` (the largest in the heap): replace it with `tmp`.

This is correct because: with non-negative edge weights, candidates are generated in non-decreasing order (same greedy property as Dijkstra). Every value in `Best[v]` corresponds to an actual path (built by induction: extending a path to $u$ with edge $u \to v$). No valid path is missed: if a path of length $d_P$ to $n$ were excluded, then `Best[n]` already had $k$ values $\leq d_P$, meaning $k$ shorter paths were already found.

The stale-entry check (`dist > Best[u].top()` → skip) ensures only current best-$k$ candidates are processed, preventing infinite work.

### Algorithm

1. Initialize `Best[1] = {0}`, push `(0, 1)` into a global min-priority queue PQ.
2. While PQ is not empty:
   - Extract `(dist, u)` with smallest `dist`.
   - If `dist > Best[u].top()`: skip (stale entry).
   - For each edge $u \to v$ with weight $c$:
     - Compute `tmp = dist + c`.
     - If `|Best[v]| < k`: add `tmp` to `Best[v]`, push `(tmp, v)` into PQ.
     - Else if `tmp < Best[v].top()`: remove `Best[v].top()`, add `tmp`, push `(tmp, v)` into PQ.
3. Output the $k$ values in `Best[n]` in increasing order.

### Example

Input:
```
4 6 3
1 2 1
1 3 3
2 3 2
2 4 6
3 2 8
3 4 1
```

Key steps:
- Pop `(0, 1)`: `Best[2] = {1}`, `Best[3] = {3}`. Push `(1,2)`, `(3,3)`.
- Pop `(1, 2)`: `tmp=3` for edge $2\to3$, `Best[3]={3,3}`. `tmp=7` for edge $2\to4$, `Best[4]={7}`. Push `(3,3)`, `(7,4)`.
- Pop `(3, 3)`: `tmp=4` for edge $3\to4$, `Best[4]={7,4}`. Push `(4,4)`.
- Pop `(3, 3)`: `tmp=4` for edge $3\to4$, `Best[4]={7,4,4}`. Push `(4,4)`.
- Subsequent pops from 4 find no outgoing edges. Entries from vertex 2 with `dist=11` are too large.

`Best[4]` sorted: `4, 4, 7` (paths: $1\to3\to4$, $1\to2\to3\to4$, $1\to2\to4$).

Output: `4 4 7`

## Complexity

- **Time:** $O(k \cdot m \log(k \cdot m))$ — each edge can generate up to $k$ PQ entries.
- **Space:** $O(k \cdot n)$ — $k$ distances per vertex.

## Code (C++)

[Solution Code](../code/Flight%20Routes.cpp)
