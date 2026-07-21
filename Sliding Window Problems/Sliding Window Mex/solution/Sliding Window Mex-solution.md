# Sliding Window Mex - Solution

**ID:** 3219 | **URL:** https://cses.fi/problemset/task/3219

## Approach

### Problem Restatement

Given an array of $n$ integers, for each sliding window of $k$ consecutive elements, find the mex — the smallest non-negative integer not present in the window.

### Core Idea

A window of $k$ elements has mex at most $k$, so only values in $[0, k]$ matter. Maintain a sorted set of values in $[0, k]$ currently absent from the window; the mex is always the smallest element of this set. Update the set incrementally as the window slides.

### Algorithm

**Step 1: Upper bound on mex.** A set of $k$ elements has mex at most $k$ (achieved only when $\{0, 1, \ldots, k-1\}$ are all present). Any value $> k$ can be ignored.

**Step 2: Data structures.** Maintain:
- `cnt[v]`: occurrence count of value $v$ in the current window (for $v \le k$ only).
- `set<int> S`: all values in $[0, k]$ currently absent from the window, initialized to $\{0, 1, \ldots, k\}$.

**Step 3: Slide the window.** For each position $i$:
1. If $a[i] \le k$: increment `cnt[a[i]]`. If this is the first occurrence (count was 0), erase $a[i]$ from $S$.
2. If $i > k$ and $a[i-k] \le k$: decrement `cnt[a[i-k]]`. If count reaches 0, re-insert $a[i-k]$ into $S$.
3. When $i \ge k$: mex is `*S.begin()`.

$S$ always equals $[0, k] \setminus \{v \in [0, k] : \text{cnt}[v] > 0\}$, so its smallest element is exactly the mex.

### Example

With $n=8$, $k=3$, array $[1, 2, 1, 0, 5, 1, 1, 0]$:

- $i=1$: add 1, erase from $S$. $S = \{0, 2, 3\}$
- $i=2$: add 2, erase from $S$. $S = \{0, 3\}$
- $i=3$: add 1 (already absent from $S$). $S = \{0, 3\}$. Mex = **0**
- $i=4$: add 0, erase. Remove $a[1]=1$ (cnt 2→1). $S = \{3\}$. Mex = **3**
- $i=5$: add 5 (>3, skip). Remove $a[2]=2$ (cnt 1→0, re-insert). $S = \{2, 3\}$. Mex = **2**
- $i=6$: add 1 (cnt 1→2). Remove $a[3]=1$ (cnt 2→1). $S = \{2, 3\}$. Mex = **2**
- $i=7$: add 1 (cnt 2→3). Remove $a[4]=0$ (cnt 1→0, re-insert). $S = \{0, 2, 3\}$. Mex = **0**
- $i=8$: add 0, erase. Remove $a[5]=5$ (>3, skip). $S = \{2, 3\}$. Mex = **2**

Output: `0 3 2 2 0 2`

## Complexity

- **Time:** $O(n \log k)$
- **Space:** $O(k)$

## Code (C++)

[Solution Code](../code/Sliding%20Window%20Mex.cpp)
