# De Bruijn Sequence - Solution

**ID:** 1692 | **URL:** https://cses.fi/problemset/task/1692

## Approach

### Problem Restatement

Given integer $n$ ($1 \le n \le 15$), construct a minimum-length binary string that contains every binary string of length $n$ exactly once as a consecutive substring.

### Core Idea

Model the problem as finding an **Euler circuit** on the **De Bruijn graph** $B(n-1, 2)$:

- **Vertices:** Each binary string of length $n-1$ ($2^{n-1}$ vertices).
- **Edges:** From vertex $b_1 b_2 \ldots b_{n-1}$, there is an edge labeled 0 to $b_2 \ldots b_{n-1} 0$, and an edge labeled 1 to $b_2 \ldots b_{n-1} 1$. Each edge corresponds to a unique binary string of length $n$: the edge from $b_1 \ldots b_{n-1}$ to $b_2 \ldots b_{n-1} b_n$ represents string $b_1 b_2 \ldots b_{n-1} b_n$. Total: $2^n$ edges.

An Euler circuit traverses every edge exactly once, so it visits all $2^n$ length-$n$ strings exactly once. This circuit always exists because every vertex has in-degree = out-degree = 2, and the graph is weakly connected — satisfying Euler's theorem for directed graphs.

The result is optimal: a linear string must have length at least $2^n + n - 1$ to contain $2^n$ distinct length-$n$ substrings, and the algorithm achieves exactly this bound.

### Algorithm

1. Start DFS from vertex $00\ldots0$ (string of $n-1$ zeros).
2. At each vertex, try appending bit 0 then bit 1. If the resulting length-$n$ string hasn't been seen, mark it seen and recursively explore the new suffix vertex (drop first character, append the new bit).
3. Record each chosen bit in **postorder** (after the recursive call returns). This follows Hierholzer's algorithm: edges are recorded after all branches are fully explored, producing the Euler circuit in reverse.
4. Concatenate all $2^n$ bits from the `edges` array, then append the starting string of $n-1$ zeros to form the linear output of length $2^n + n - 1$.

### Example

Input:
```
2
```

Vertices (length 1): `0`, `1`. Edges: `0→0` (label 0, string "00"), `0→1` (label 1, string "01"), `1→0` (label 0, string "10"), `1→1` (label 1, string "11").

DFS from `0`:
- Try bit 0 → "00" (new): recurse on suffix `0`. No new edges from `0`. Record bit **0**.
- Try bit 1 → "01" (new): recurse on suffix `1`.
  - Try bit 0 → "10" (new): recurse on suffix `0`. No new edges. Record bit **0**.
  - Try bit 1 → "11" (new): recurse on suffix `1`. No new edges. Record bit **1**.
  - Record bit **1** (for edge "01").
- Record bit **0** (for edge "00").

Postorder edges: `0, 0, 1, 1`. String: `0011` + `0` = `00110`.

Output:
```
00110
```

Check: substrings of length 2 are `00`, `01`, `11`, `10` — all 4 binary strings. ✓

## Complexity

- **Time:** $O(n^2 \cdot 2^n)$ — each edge visited once; `set<string>` operations cost $O(n \log 2^n) = O(n^2)$ per edge.
- **Space:** $O(2^n)$ — `set` of seen strings and `edges` array.

## Code (C++)

[Solution Code](../code/De%20Bruijn%20Sequence.cpp)
