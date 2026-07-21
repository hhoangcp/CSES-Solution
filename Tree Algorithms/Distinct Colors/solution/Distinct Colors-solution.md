# Distinct Colors - Solution

**ID:** 1139 | **URL:** https://cses.fi/problemset/task/1139

## Approach

### Problem Restatement

Given a rooted tree with $n$ nodes (root is node $1$). Each node $u$ has a color $c_u$. For each node $u$, compute the number of distinct colors in the subtree rooted at $u$.

**Constraints:** $1 \le n \le 2 \cdot 10^5$, $1 \le c_i \le 10^9$.

### Core idea

**Flatten the tree with an Euler tour:** DFS from the root, assign $Start[u]$ as the entry time and set $color[Start[u]] = c_u$. After the subtree of $u$ is fully traversed, the current time is $End[u]$. The subtree of $u$ then corresponds to the contiguous segment $[Start[u], End[u]]$ in the Euler array $color[1..n]$. The task reduces to: for each segment $[Start[u], End[u]]$, count the number of distinct values.

**Offline distinct-value counting with a BIT:** Coordinate-compress colors to $[1, n]$ (since $c_i \le 10^9$ but there are at most $n$ distinct colors). Scan the Euler array left to right, keeping on the BIT a value of $1$ at the **last (rightmost) occurrence** of each color so far, and $0$ at older positions. For each $i$:

- Let $pre[i]$ be the previous occurrence of $color[i]$ (read from $link[color[i]]$). If $pre[i] > 0$, clear the old mark with $\text{Update}(pre[i], -1)$ and set the new one with $\text{Update}(i, +1)$; if $pre[i] = 0$, just $\text{Update}(i, +1)$. Then set $link[color[i]] = i$.
- When $i = End[u]$ (the whole subtree of $u$ has been scanned), the number of distinct colors in the subtree is the number of $1$ marks inside $[Start[u], End[u]]$:

$$ans[u] = \text{Query}(End[u]) - \text{Query}(Start[u] - 1)$$

**Correctness:** By induction on $i$, after processing position $i$ the BIT carries $1$ exactly at the last occurrence of each color in $[1, i]$, since each time a color reappears we drop the old mark and place a new one at $i$. Since the subtree of $u$ occupies $[Start[u], End[u]]$ and every position in it is $\le End[u]$, every color present in the subtree has exactly one "last" position inside the segment (the last occurrence of that color at or before $End[u]$, which must be $\ge Start[u]$ because the color appears in the subtree). The number of $1$ marks in the segment therefore equals the number of distinct colors in the subtree.

### Algorithm

1. Read $n$, the color array $c[1..n]$, and the $n-1$ edges; build the adjacency list.
2. Coordinate-compress: sort and unique the colors, then map each $c[i]$ to its index in $[1, n]$ via `lower_bound`.
3. DFS from the root $1$ (use `lab[v] = u` to skip the parent): $Start[u] = ++Time$, $color[Time] = c[u]$; after visiting all children, push the pair $\{Start[u], u\}$ into the list $L[Time]$ (so $Time$ here equals $End[u]$).
4. Initialization loop $i = 1..n$: $pre[i] = link[color[i]]$; if $pre[i] = 0$, $\text{Update}(i, +1)$; set $link[color[i]] = i$.
5. Main loop $i = 1..n$:
   - If $pre[i] > 0$: $\text{Update}(pre[i], -1)$ then $\text{Update}(i, +1)$.
   - For each pair $\{Start[u], u\} \in L[i]$: $ans[u] = \text{Query}(i) - \text{Query}(Start[u] - 1)$.
6. Print $ans[1..n]$.

### Example

The problem statement gives $n = 5$, colors $c = [2,\ 3,\ 2,\ 2,\ 1]$ (for nodes $1..5$), and edges `1-2, 1-3, 3-4, 3-5`. The root is $1$.

Tree: children of $1$ are $\{2, 3\}$; children of $3$ are $\{4, 5\}$.

Coordinate compression: sorted unique $= [1, 2, 3]$, mapping gives $c = [2,\ 3,\ 2,\ 2,\ 1]$.

Euler tour (with adjacency order `V[1]=[2,3]`, `V[3]=[1,4,5]`):

| $u$ | $Start[u]$ | $End[u]$ | $color[Start[u]]$ |
|---|---|---|---|
| $1$ | $1$ | $5$ | $2$ |
| $2$ | $2$ | $2$ | $3$ |
| $3$ | $3$ | $5$ | $2$ |
| $4$ | $4$ | $4$ | $2$ |
| $5$ | $5$ | $5$ | $1$ |

Euler array: $color[1..5] = [2,\ 3,\ 2,\ 2,\ 1]$. Previous-occurrence links: $pre = [,\ 0,\ 0,\ 1,\ 3,\ 0]$ (color $2$ appears at positions $1, 3, 4$).

BIT initialization (mark first occurrence of each color): positions $1$ (color $2$), $2$ (color $3$), $5$ (color $1$). $BIT = [1, 1, 0, 0, 1]$.

Main scan:

| $i$ | Action | BIT after | Queries at $End = i$ |
|---|---|---|---|
| $1$ | $pre[1]=0$, unchanged | $[1,1,0,0,1]$ | — |
| $2$ | $pre[2]=0$, unchanged | $[1,1,0,0,1]$ | $End[2]=2$: $ans[2]=Q(2)-Q(1)=2-1=\mathbf{1}$ |
| $3$ | $pre[3]=1$: $Up(1,-1),Up(3,+1)$ | $[0,1,1,0,1]$ | — |
| $4$ | $pre[4]=3$: $Up(3,-1),Up(4,+1)$ | $[0,1,0,1,1]$ | $End[4]=4$: $ans[4]=Q(4)-Q(3)=2-1=\mathbf{1}$ |
| $5$ | $pre[5]=0$, unchanged | $[0,1,0,1,1]$ | $End[5]=5$: $ans[5]=Q(5)-Q(4)=3-2=\mathbf{1}$; $End[3]=5$: $ans[3]=Q(5)-Q(2)=3-1=\mathbf{2}$; $End[1]=5$: $ans[1]=Q(5)-Q(0)=\mathbf{3}$ |

Result: `3 1 2 1 1` — matching the problem's example.

## Complexity

- **Time:** $O(n \log n)$ — coordinate compression $O(n \log n)$; DFS and each BIT operation $O(\log n)$.
- **Memory:** $O(n)$ — adjacency list, Euler/`Start`/`pre`/`link` arrays, list $L$, and the BIT.

## Code (C++)

[Solution Code](../code/Distinct%20Colors.cpp)
