# Road Construction - Solution

**ID:** 1676 | **URL:** https://cses.fi/problemset/task/1676

## Approach

### Problem Restatement

There are $n$ cities with no roads initially. Roads are added one at a time. After each addition, report the number of connected components and the size of the largest component.

### Core idea

Use **Disjoint Set Union (DSU)** with two optimizations: path compression in `Find` and union by size in `Union`. Maintain a global `components` counter (starts at $n$, decreases by 1 on each successful merge) and `cur_max` (updated to $\max(\text{cur\_max}, \text{sz}[ru])$ after each merge).

The invariant holds because `components` correctly tracks the number of sets (only successful merges reduce it), and `cur_max` correctly tracks the maximum set size (it only increases when a merge produces a larger set than any existing one). Union by size ensures each merge attaches the smaller tree under the larger one, so tree depth stays $O(\log n)$; combined with path compression, each operation runs in $O(\alpha(n))$ — effectively constant.

### Algorithm

1. Initialize: $\text{par}[u] = u$, $\text{sz}[u] = 1$ for all $u$. Set `components = n`, `cur_max = 1`.
2. For each road $(u, v)$:
   - Find $ru = \text{Find}(u)$, $rv = \text{Find}(v)$.
   - If $ru = rv$: no change.
   - If $ru \neq rv$: attach smaller set under larger, update $\text{sz}$, `components--`, `cur_max = max(cur_max, sz[ru])`.
   - Output `components` and `cur_max`.

### Example

Input:
```
5 3
1 2
1 3
4 5
```

| Road   | Merge? | components | cur_max |
|--------|--------|------------|---------|
| Initial| —      | 5          | 1       |
| (1, 2) | Yes    | 4          | 2       |
| (1, 3) | Yes    | 3          | 3       |
| (4, 5) | Yes    | 2          | 3       |

Output:
```
4 2
3 3
2 3
```

## Complexity

- **Time:** $O(m \cdot \alpha(n))$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Road%20Construction.cpp)
