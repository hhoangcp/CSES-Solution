# Playlist - Solution

**ID:** 1141 | **URL:** https://cses.fi/problemset/task/1141

## Approach

Maintain a sliding window $[l, i]$ where all songs have distinct IDs. Traverse each position $i$ (right pointer) and adjust $l$ (left pointer) to ensure distinctness. Use a frequency map (`std::map` since IDs can be up to $10^9$) to count occurrences of each ID in the current window.

For each position $i$ from $1$ to $n$:

1. Increment $\text{cnt}[a[i]]$ by 1.
2. If $\text{cnt}[a[i]] > 1$, shrink from the left: decrement $\text{cnt}[a[l]]$ and increment $l$ until $\text{cnt}[a[i]] = 1$.
3. Update $\text{res} = \max(\text{res}, i - l + 1)$.

**Correctness:** After shrinking, $\text{cnt}[a[i]] = 1$, and no other song is duplicated (only $a[i]$ was duplicated, and shrinking only decrements counts). The window $[l, i]$ is the longest distinct window ending at $i$: any window $[l', i]$ with $l' < l$ would contain two copies of $a[i]$, contradicting distinctness. Since every distinct subarray $[a, b]$ satisfies $a \geq l_b$, its length is at most $b - l_b + 1$, so taking the max over all $i$ gives the global answer.

### Example

Consider $n = 8$, songs $a = [1, 2, 1, 3, 2, 7, 4, 2]$ (1-indexed).

| $i$ | $a[i]$ | Window $[l, i]$ | $l$ | Size | $\text{res}$ |
|-----|--------|-----------------|-----|------|---------------|
| 1 | $1$ | $[1,1]$ | 1 | 1 | 1 |
| 2 | $2$ | $[1,2]$ | 1 | 2 | 2 |
| 3 | $1$ | $[2,3]$ (duplicate 1, shrink past $a[1]$) | 2 | 2 | 2 |
| 4 | $3$ | $[2,4]$ | 2 | 3 | 3 |
| 5 | $2$ | $[3,5]$ (duplicate 2, shrink past $a[2]$) | 3 | 3 | 3 |
| 6 | $7$ | $[3,6]$ | 3 | 4 | 4 |
| 7 | $4$ | $[3,7]$ | 3 | 5 | 5 |
| 8 | $2$ | $[6,8]$ (duplicate 2, shrink past $a[5]$) | 6 | 3 | 5 |

Answer: $5$ (subarray $[1, 3, 2, 7, 4]$ from positions 3 to 7).

## Complexity

- **Time:** $O(n \log n)$ with `map` (each access $O(\log n)$). Both pointers advance monotonically, so total shrinking steps $\leq n$. Can be $O(n)$ with coordinate compression + array.
- **Memory:** $O(n)$ — frequency map stores at most $n$ entries.

## Code (C++)

[Solution Code](../code/Playlist.cpp)
