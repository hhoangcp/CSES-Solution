# Nested Ranges Count - Solution

**ID:** 2169 | **URL:** https://cses.fi/problemset/task/2169

## Approach

Sort the $n$ ranges by right endpoint $r$ increasing; if $r$ is equal, by left endpoint $l$ decreasing. This fixes one boundary: in forward traversal, all processed ranges have $r_j \leq r_i$; in reverse, all processed ranges have $r_j \geq r_i$. Sorting $l$ decreasing for equal $r$ ensures the narrower range is processed first in forward traversal, so the wider range can correctly count it.

Coordinate-compress the $l$ values (since $x_i \leq 10^9$) and use a Fenwick tree (BIT) for both queries.

### Count ranges contained by this one (forward traversal)

Traverse ranges in sorted order. Maintain a BIT counting $l$ values of processed ranges.

For range $i$ (0-indexed in sorted order):
1. Ranges with $l_j \geq l_i$ among processed ones: $i - \text{query}(l_i - 1)$. (Total processed is $i$; $\text{query}(l_i - 1)$ counts those with $l_j < l_i$.)
2. This equals the number of ranges contained by $i$: all processed ranges satisfy $r_j \leq r_i$ by sorting, and $l_j \geq l_i$ by the query condition.
3. Store the full count.
4. Add $l_i$ to the BIT.

### Count ranges containing this one (reverse traversal)

Traverse in reverse sorted order. Maintain a new BIT.

For range $i$ (in reverse order):
1. Processed ranges have $r_j \geq r_i$ (they come after $i$ in sorted order).
2. Count of ranges with $l_j \leq l_i$: $\text{query}(l_i)$.
3. This equals the number of ranges containing $i$: all processed ranges satisfy $r_j \geq r_i$, and $l_j \leq l_i$ by the query.
4. Store the full count.
5. Add $l_i$ to the BIT.

**No double counting:** Each range only considers relationships with previously processed ranges in each traversal, never with itself.

### Example

Consider $n = 4$, ranges: $[1, 6], [2, 4], [4, 8], [3, 6]$.

Sorted by $r$ increasing, $l$ decreasing: $[2,4], [3,6], [1,6], [4,8]$.

Compressed $l$: $\{1,2,3,4\} \to \{1,2,3,4\}$.

**Count contained (forward):**

| $i$ | Range | $l_i$ | $\text{query}(l_i-1)$ | $i - \text{query}$ | Contained count |
|-----|-------|-------|------------------------|---------------------|-----------------|
| 0 | $[2,4]$ | 2 | 0 | 0 | 0 |
| 1 | $[3,6]$ | 3 | 1 | 0 | 0 |
| 2 | $[1,6]$ | 1 | 0 | 2 | 2 |
| 3 | $[4,8]$ | 4 | 3 | 0 | 0 |

**Count containing self (reverse):**

| $i$ | Range | $l_i$ | $\text{query}(l_i)$ | Containing count |
|-----|-------|-------|----------------------|------------------|
| 3 | $[4,8]$ | 4 | 0 | 0 |
| 2 | $[1,6]$ | 1 | 0 | 0 |
| 1 | $[3,6]$ | 3 | 1 | 1 |
| 0 | $[2,4]$ | 2 | 1 | 1 |

Result (original order): `2 0 0 0` and `0 1 0 1`.

## Complexity

- **Time:** $O(n \log n)$ — sorting $O(n \log n)$, each BIT operation $O(\log n)$.
- **Memory:** $O(n)$ — range array and BIT.

## Code (C++)

[Solution Code](../code/Nested%20Ranges%20Count.cpp)
