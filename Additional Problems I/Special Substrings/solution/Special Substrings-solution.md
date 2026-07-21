# Special Substrings - Solution

**ID:** 2186 | **URL:** https://cses.fi/problemset/task/2186

## Problem Statement

A substring is called *special* if every character that appears in it appears the same number of times. Count all special substrings.

## Approach

### Difference vector

Let $cnt[i][c]$ be the count of character $c$ in prefix $s[1 \ldots i]$. A substring $s[l \ldots r]$ is special iff $cnt[r][c] - cnt[l-1][c]$ is the same for all $c$. This is equivalent to: the vector of consecutive differences at position $r$ equals that at position $l-1$.

Define the difference vector at position $i$ with $k$ distinct characters (indexed $0, 1, \ldots, k-1$):

$$cur[j] = cnt[i][j+1] - cnt[i][j], \quad j = 0, 1, \ldots, k-2$$

If two positions have the same $cur$, then all $cnt$ values differ by the same constant between them, meaning every character in the substring appears equally. So we just count pairs of positions with equal vectors.

### Algorithm

1. Pre-scan the string to identify all distinct characters and assign indices.
2. Initialize `map<vector<int>, int>` with the empty-prefix vector.
3. For each position $i$: update $cnt$, recompute $cur$, add `map[cur]` to the answer, then increment `map[cur]`.

### Example

$s = \text{abccabab}$, distinct characters: a(0), b(1), c(2). Vector has 2 elements: $[cnt[1]-cnt[0], cnt[2]-cnt[1]]$.

| Pos | Char | $cnt$ | $cur$ | map count | Substrings |
|-----|------|-------|-------|-----------|------------|
| 0 | - | [0,0,0] | [0,0] | - | - |
| 1 | a | [1,0,0] | [-1,0] | 0 | - |
| 2 | b | [1,1,0] | [0,-1] | 0 | - |
| 3 | c | [1,1,1] | [0,0] | 1 | `abc` |
| 4 | c | [1,1,2] | [0,1] | 0 | - |
| 5 | a | [2,1,2] | [-1,1] | 0 | - |
| 6 | b | [2,2,2] | [0,0] | 2 | `abccab`, `cab` |
| 7 | a | [3,2,2] | [-1,0] | 1 | `bccaba` |
| 8 | b | [3,3,2] | [0,-1] | 1 | `ccabab` |

Total: $1 + 2 + 1 + 1 = \mathbf{5}$.

## Complexity

- **Time:** $O(n \cdot |\Sigma| \log n)$ — each map operation takes $O(|\Sigma| \log n)$ (vector comparison $O(|\Sigma|)$, map $O(\log n)$)
- **Memory:** $O(n \cdot |\Sigma|)$

## Code (C++)

[Solution Code](../code/Special%20Substrings.cpp)
