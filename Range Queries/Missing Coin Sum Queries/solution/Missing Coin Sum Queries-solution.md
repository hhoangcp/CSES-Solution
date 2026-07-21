# Missing Coin Sum Queries - Solution

**ID:** 2184 | **URL:** https://cses.fi/problemset/task/2184

## Approach

### Problem Restatement

Given $n$ coins with positive integer values, process $q$ queries: for coins in positions $[a, b]$, what is the smallest sum that cannot be produced?

### Core idea

The classic greedy algorithm for sorted coins $c_1 \le c_2 \le \cdots \le c_k$: maintain $s$ = smallest unrepresentable sum (initially 1). If $c_i \le s$, update $s \leftarrow s + c_i$; otherwise $s$ is the answer. This works because after representing all sums in $[0, s{-}1]$, adding a coin $c_i \le s$ extends the representable range to $[0, s + c_i - 1]$ (the new range $[c_i, s + c_i - 1]$ overlaps or connects with $[0, s-1]$ since $c_i \le s$). If $c_i > s$, there's a gap at $s$.

For range queries, we can't sort each subarray independently. Instead, sort the **entire array** by value and use a BIT on original positions. Insert elements in increasing value order. After inserting the $i$-th smallest element, the BIT stores the sum of the $i$ smallest elements at their original positions. For a query $[a, b]$, compute `ans = BIT.query(b) - BIT.query(a-1) + 1` — the sum of all inserted elements in the range plus 1. Find the largest position $p$ in the sorted array with value $\le$ ans. If $p \le i$ (all relevant elements already inserted), ans is final. Otherwise, schedule re-evaluation at step $p$.

Each query is re-evaluated at most $O(\log \Sigma x_i)$ times because $s$ at least doubles each time (if sum of elements $\le s$ is $\ge s$, then the new $s$ is at least $2s$). Total re-evaluations across all queries is bounded by $O((n + q) \log \Sigma x_i)$.

### Algorithm

1. **Sort** array by value: `sorted[i]` = value of $i$-th smallest element, `pos[i]` = its original position.
2. **Schedule** all queries at step 0.
3. **Sweep** $i$ from 0 to $n$: insert `sorted[i]` at position `pos[i]` into the BIT (if $i > 0$). For each query scheduled at step $i$:
   - Compute `ans = BIT.sum(a, b) + 1`.
   - Find $p$ = largest index where `sorted[p]` $\le$ ans (binary search).
   - If $p > i$: re-schedule query at step $p$.
   - Otherwise: `ans` is the final answer.

### Example

Input:
```
5 3
2 9 1 2 7
2 4
4 4
1 5
```

Coins: $[2, 9, 1, 2, 7]$. Sorted: values $[1, 2, 2, 7, 9]$, positions $[3, 1, 4, 5, 2]$.

- Query $[2,4]$ (coins $[9, 1, 2]$: sorted $[1, 2, 9]$):
  - After step 1 (insert 1 at pos 3): sum$[2,4] = 1$, ans$=2$. Not stable (elements $\le 2$ at steps $\le 3$).
  - After step 3 (inserted 1, 2, 2): sum$[2,4] = 3$, ans$=4$. All elements $\le 4$ already inserted. Answer = **4**.
- Query $[4,4]$ (coins $[2]$):
  - After step 1: sum$[4,4] = 0$, ans$=1$. Stable (no element $\le 1$ in range). Answer = **1**.
- Query $[1,5]$ (coins $[2, 9, 1, 2, 7]$):
  - After step 3: sum$[1,5] = 5$, ans$=6$. Stable (7 > 6). Answer = **6**.

Output:
```
4
1
6
```

## Complexity

- **Time:** $O((n + q) \log n \cdot \log(\sum x_i))$
- **Space:** $O(n + q)$

## Code (C++)

[Solution Code](../code/Missing%20Coin%20Sum%20Queries.cpp)
