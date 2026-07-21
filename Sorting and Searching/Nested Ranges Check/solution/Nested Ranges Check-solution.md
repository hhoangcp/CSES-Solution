# Nested Ranges Check - Solution

**ID:** 2168 | **URL:** https://cses.fi/problemset/task/2168

## Approach

Sort the $n$ ranges by right endpoint $r$ increasing; if $r$ is equal, by left endpoint $l$ decreasing. After sorting, when processing range $i$, all previously processed ranges have $r_j \leq r_i$. For equal $r$, the narrower range (larger $l$) comes first, so the wider range is processed after and can detect containment.

Coordinate-compress the $l$ values (since $x_i \leq 10^9$) and use a Fenwick tree (BIT) for both queries.

### Check if a range contains another (forward traversal)

Traverse ranges in sorted order. Maintain a BIT counting $l$ values of processed ranges.

For range $i$ (0-indexed in sorted order):
1. Ranges with $l_j \geq l_i$ among processed ones: $i - \text{query}(l_i - 1)$. (Total processed is $i$; $\text{query}(l_i - 1)$ counts those with $l_j < l_i$.)
2. If positive, there exists range $j$ with $l_j \geq l_i$ and $r_j \leq r_i$ (by sorting), so range $i$ contains range $j$.
3. Add $l_i$ to the BIT.

**Correctness:** Range $j$ is contained by $i$ iff $l_i \leq l_j$ and $r_i \geq r_j$. All processed ranges satisfy $r_j \leq r_i$ by sorting. The count $i - \text{query}(l_i - 1)$ exactly counts those with $l_j \geq l_i$.

### Check if a range is contained by another (reverse traversal)

Traverse in reverse sorted order. Maintain a new BIT.

For range $i$ (in reverse order):
1. Processed ranges have $r_j \geq r_i$ (they come after $i$ in sorted order).
2. Count of ranges with $l_j \leq l_i$: $\text{query}(l_i)$.
3. If positive, there exists range $j$ with $l_j \leq l_i$ and $r_j \geq r_i$, so range $j$ contains range $i$.
4. Add $l_i$ to the BIT.

**Correctness:** Range $j$ contains $i$ iff $l_j \leq l_i$ and $r_j \geq r_i$. In reverse traversal, all processed ranges satisfy $r_j \geq r_i$. The BIT query $\text{query}(l_i)$ counts those with $l_j \leq l_i$.

### Example

Consider $n = 4$, ranges: $[1, 6], [2, 4], [4, 8], [3, 6]$.

Sorted by $r$ increasing, $l$ decreasing: $[2,4], [3,6], [1,6], [4,8]$.

Compressed $l$: $\{1,2,3,4\} \to \{1,2,3,4\}$.

**Contains another (forward):**

| $i$ | Range | $l_i$ | $\text{query}(l_i-1)$ | $i - \text{query}$ | Contains? |
|-----|-------|-------|------------------------|---------------------|-----------|
| 0 | $[2,4]$ | 2 | 0 | 0 | 0 |
| 1 | $[3,6]$ | 3 | 1 | 0 | 0 |
| 2 | $[1,6]$ | 1 | 0 | 2 | 1 |
| 3 | $[4,8]$ | 4 | 3 | 0 | 0 |

**Contained by another (reverse):**

| $i$ | Range | $l_i$ | $\text{query}(l_i)$ | Contained? |
|-----|-------|-------|----------------------|------------|
| 3 | $[4,8]$ | 4 | 0 | 0 |
| 2 | $[1,6]$ | 1 | 0 | 0 |
| 1 | $[3,6]$ | 3 | 1 | 1 |
| 0 | $[2,4]$ | 2 | 1 | 1 |

Result (original order): `1 0 0 0` and `0 1 0 1`.

## Complexity

- **Time:** $O(n \log n)$ — sorting $O(n \log n)$, each BIT operation $O(\log n)$.
- **Memory:** $O(n)$ — range array and BIT.

## Code (C++)

[Solution Code](../code/Nested%20Ranges%20Check.cpp)
