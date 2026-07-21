# Hotel Queries - Solution

**ID:** 1143 | **URL:** https://cses.fi/problemset/task/1143

## Approach

### Problem Restatement

There are $n$ hotels, each with $h_i$ available rooms. Process $m$ groups sequentially: assign each group needing $r_j$ rooms to the **leftmost hotel** with $h_i \ge r_j$, then reduce that hotel's rooms by $r_j$. If no hotel suffices, output 0.

### Core idea

For each group needing $x$ rooms, we must find the smallest index $p$ with $h_p \ge x$, then update $h_p \leftarrow h_p - x$. A **max segment tree** supports both tasks in $O(\log n)$.

To find the leftmost hotel with $\ge x$ rooms, we traverse the segment tree top-down. At each internal node, if the left child's maximum $\ge x$, the answer lies in the left half (prioritizing leftmost). Otherwise, if the right child's maximum $\ge x$, the answer lies in the right half. If both are $< x$, no hotel suffices and we return 0. This search is correct because the leftmost valid position $p^*$ must be in the left half whenever that half contains any valid position, and must be in the right half only when the left half has none. Each step reduces the search range by half, so the traversal takes $O(\log n)$.

After finding position $p$, update $h_p$ via a standard point update on the segment tree.

### Algorithm

1. **Build** a max segment tree from the hotel array.
2. **For each group** needing $x$ rooms:
   - Search the tree top-down: at each node, prefer left child if its max $\ge x$; otherwise go right if its max $\ge x$; otherwise return 0.
   - If a position $p$ is found, output $p$ and update $h_p \leftarrow h_p - x$.
   - Otherwise, output 0.

### Example

Input:
```
8 5
3 2 4 1 5 5 2 6
4 4 7 1 1
```

Hotels: $[3, 2, 4, 1, 5, 5, 2, 6]$.

- Group needs 4: walk down — left half $[1,4]$ max$=4 \ge 4$ → left; $[1,2]$ max$=3 < 4$ → right $[3,4]$; $[3,3]$ max$=4 \ge 4$ → left; leaf: hotel 3. Update: $h_3 = 0$. Array: $[3, 2, 0, 1, 5, 5, 2, 6]$.
- Group needs 4: $[1,4]$ max$=3 < 4$ → right $[5,8]$ max$=6 \ge 4$ → eventually hotel 5. Update: $h_5 = 1$. Array: $[3, 2, 0, 1, 1, 5, 2, 6]$.
- Group needs 7: root max$=6 < 7$ → 0.
- Group needs 1: hotel 1 ($h_1=3$). Update: $h_1 = 2$.
- Group needs 1: hotel 1 ($h_1=2$). Update: $h_1 = 1$.

Output: `3 5 0 1 1`

## Complexity

- **Time:** $O((n + m) \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Hotel%20Queries.cpp)
