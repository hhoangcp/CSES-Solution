# New Roads Queries - Solution

**ID:** 2101 | **URL:** https://cses.fi/problemset/task/2101

## Approach

### Problem Restatement

$n$ cities initially with no roads. Each day a new road is built (total $m$ roads). For $q$ queries "after how many days can you first travel from $a$ to $b$?", answer each (or $-1$ if never connected).

### Core Idea

For a query $(a, b)$, the answer is the smallest day $d$ such that after adding the first $d$ roads, $a$ and $b$ are connected. Connectivity is **monotone**: if $a$ and $b$ are connected after day $d$, they remain connected for all later days. This monotonicity enables binary search on the answer.

**Parallel Binary Search (PBS):** Instead of running binary search separately for each query ($O(q \cdot m \log m)$), process all queries simultaneously. In each iteration, every active query computes its midpoint $mid$ and is placed into a bucket indexed by $mid$. Then a single sweep adds edges 1 to $m$ into a DSU; after adding edge $i$, all queries in bucket $i$ are checked against the DSU. This reduces the total work to $O((m + q) \log m)$ DSU operations.

### Algorithm

1. Initialize each query with $L=1$, $R=m$, `ans=-1` (or 0 if $a=b$).
2. Repeat until no active queries remain:
   - For each active query, compute $mid = (L+R)/2$, place into bucket $mid$.
   - Reset DSU to $n$ isolated vertices.
   - Sweep edges $i = 1 \dots m$: union the edge, then check each query in bucket $i$:
     - If $a$ and $b$ are connected: set `ans = i`, $R = i - 1$.
     - Otherwise: $L = i + 1$.
3. Output answers.

### Example

$n=5$, $m=4$, roads: $(1,2), (2,3), (1,3), (2,5)$. Queries: $(1,3), (3,4), (3,5)$.

**Iteration 1:** all queries $[1,4]$, $mid=2$, bucket[2] = $\{(1,3), (3,4), (3,5)\}$.

| After edge | DSU components | Check bucket |
|------------|----------------|--------------|
| 1: (1,2)   | {1,2} {3} {4} {5} | — |
| 2: (2,3)   | {1,2,3} {4} {5} | (1,3): connected → ans=2, R=1; (3,4): no → L=3; (3,5): no → L=3 |

**Iteration 2:** (3,4) and (3,5) both $[3,4]$, $mid=3$, bucket[3] = $\{(3,4), (3,5)\}$.

Sweep to edge 3: DSU = {1,2,3} {4} {5}. (3,4): not connected → L=4. (3,5): not connected → L=4.

**Iteration 3:** both $[4,4]$, $mid=4$, bucket[4] = $\{(3,4), (3,5)\}$.

Sweep to edge 4: (2,5) added. DSU = {1,2,3,5} {4}. (3,4): not connected → ans=-1. (3,5): connected → ans=4.

Results: **(1,3)→2, (3,4)→−1, (3,5)→4**.

## Complexity

- **Time:** $O((m + q) \log m \cdot \alpha(n))$
- **Memory:** $O(n + m + q)$

## Code (C++)

[Solution Code](../code/New%20Roads%20Queries.cpp)
