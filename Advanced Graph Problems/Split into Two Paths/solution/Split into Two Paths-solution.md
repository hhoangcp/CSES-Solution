# Split into Two Paths - Solution

**ID:** 3358 | **URL:** https://cses.fi/problemset/task/3358

## Code (C++)

### Problem Restatement

Given a DAG with $n$ nodes and $m$ edges, determine if the nodes can be partitioned into at most two directed paths (each node appears in exactly one path, consecutive nodes in each path must have an edge).

### Method 1: Minimum Path Cover via Matching

**Core idea:** The minimum path cover in a DAG has size $n - |M|$, where $M$ is a maximum matching on the bipartite graph constructed by splitting each node $u$ into $u_L$ (left side) and $u_R$ (right side), and adding edge $u_L \to v_R$ for each original edge $u \to v$. We need cover size $\le 2$ (one path can be empty), so $|M| \ge n - 2$.

**Algorithm:**
1. Build bipartite graph: left side = $\{u_L : u \in V\}$, right side = $\{v_R : v \in V\}$. For each original edge $u \to v$, add bipartite edge $u_L \to v_R$.
2. Find maximum matching using Hopcroft-Karp. If $|M| < n - 2$ (cover size $> 2$), output NO.
3. Extract paths from matching: each node $u$ with no matched edge entering $u_R$ is a path start; follow matched edges $u_L \to v_R$ to trace each path.
4. Output YES and the at most two paths (if only 1 path, output size 0 for the second).

### Method 2: DP on Topological Order

**Core idea:** Every directed path in a DAG visits nodes as an increasing subsequence of the topological order. If two paths partition all $n$ nodes, there exists a split position $s$ such that path 1 covers positions in $[1, s]$ and path 2 covers positions in $[s, n]$ (with possible interleaving resolved by DP). A contiguous segment of the topological sequence is a valid path iff every consecutive pair has an edge — tracked by marking "gaps" and prefix sums.

**Algorithm:**
1. **Topological sort** using Kahn's algorithm. If cycle exists, output NO.
2. **Mark gaps:** For each position $i = 2 \ldots n$, mark position $i$ as a gap if no edge from the $(i-1)$-th to the $i$-th node in topological order. Compute prefix sums of gaps.
3. **Path check:** A segment $[l, r]$ is a valid path iff it contains no gaps (prefix sum check in $O(1)$).
4. **DP:** Let $f[j]$ = the left boundary of the current second-path segment ending at position $j$ (or $-1$ if unreachable).
   - Initialize: for $h = 2 \ldots n$, if segment $[1, h)$ is a valid path, set $f[h] = 1$.
   - For each position $i$ where $f[i] \ne -1$:
     - If segment $[i, n]$ is a valid path, found solution — reconstruct the two paths.
     - Otherwise, for each outgoing edge from the $(i-1)$-th topo node to node $v$ at position $j > i$: if segment $[i, j)$ is a valid path, set $f[j] = i$.
5. If no valid split found, output NO.

**Reconstruction:** Trace $f[\cdot]$ backwards from the split point, alternating which path each segment belongs to, then collect nodes into two paths.

### Examples

**YES example (Matching):** $n=4$, edges: $1 \to 2$, $1 \to 3$, $2 \to 4$, $3 \to 4$.

Bipartite graph: $1_L \to 2_R$, $1_L \to 3_R$, $2_L \to 4_R$, $3_L \to 4_R$. Maximum matching: $\{1_L \to 2_R, 2_L \to 4_R\}$, $|M|=2 \ge 4-2$. Partition: Path 1: $1 \to 2 \to 4$, Path 2: $3$.

**NO example (Matching):** $n=4$, edges: $1 \to 4$, $2 \to 4$, $3 \to 4$.

Bipartite graph: $1_L \to 4_R$, $2_L \to 4_R$, $3_L \to 4_R$. Maximum matching is only $|M|=1 < 4-2=2$. Need at least 3 paths → NO.

**YES example (DP on Topo):** $n=5$, edges: $1 \to 2$, $1 \to 4$, $3 \to 4$, $4 \to 5$.

Topological order: $3, 1, 2, 4, 5$. Gaps: position 2 (no edge $3 \to 1$), position 4 (no edge $2 \to 4$). Prefix: $\text{pref}=[0,0,1,1,2,2]$.

DP:
- Initialize: $f[2]=1$ (segment $[1,1]$ valid). Segment $[1,2]$ has gap → stop.
- $i=2$: Segment $[2,5]$ invalid. From $\text{topo}[1]=3$, edge $3\to 4$ at position 4. Segment $[2,3]$ valid ($\text{pref}[3]-\text{pref}[2]=0$) → $f[4]=2$.
- $i=4$: Segment $[4,5]$ valid ($\text{pref}[5]-\text{pref}[4]=0$) → solution found!

Reconstruction (alternating paths):
- $[4,5]$: path 1 → $\text{topo}[4..5]=4,5$
- $[2,4)$: path 2 → $\text{topo}[2..3]=1,2$
- $[1,2)$: path 1 → $\text{topo}[1]=3$

Result: Path 1: $3\to 4\to 5$, Path 2: $1\to 2$. ✓

**NO example (DP on Topo):** $n=4$, edges: $1 \to 4$, $2 \to 4$, $3 \to 4$.

Topological order: $1, 2, 3, 4$. Gaps: positions 2, 3. Prefix: $\text{pref}=[0,0,1,2,2]$.

DP:
- Initialize: $f[2]=1$ (segment $[1,1]$ valid). Segment $[1,2]$ has gap → stop.
- $i=2$: Segment $[2,4]$ invalid. From $\text{topo}[1]=1$, edge $1\to 4$ at position 4. Segment $[2,3]$ invalid → no update.
- No more reachable positions → NO.

### Comparison

| | Matching / Flow | DP on Topo |
|---|---|---|
| **Time** | $O(m\sqrt{n})$ | $O(n + m)$ |
| **Space** | $O(n + m)$ | $O(n + m)$ |
| **Strength** | Generalizes to $k$ paths | Simpler, faster for $k=2$ |
| **Code** | [C++ (Matching)](../code/Split%20into%20Two%20Paths%20-%20Matching.cpp) | [C++ (DP Topo)](../code/Split%20into%20Two%20Paths%20-%20DP%20Topo.cpp) |

## Complexity

- **Method 1:** $O(m\sqrt{n})$ time, $O(n + m)$ space
- **Method 2:** $O(n + m)$ time, $O(n + m)$ space
