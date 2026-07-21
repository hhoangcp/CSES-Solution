# Traffic Lights - Solution

**ID:** 1163 | **URL:** https://cses.fi/problemset/task/1163

## Problem Statement

There is a street of length $x$ meters, initially with no traffic lights. Add $n$ traffic lights one by one at positions $p_1, p_2, \ldots, p_n$. After each addition, print the length of the longest contiguous segment without a traffic light.

## Approach

### 1. Model the problem

The street of length $x$ starts as a single segment $[0, x]$. Each time a light is added at position $p$, it splits the segment containing $p$ into two smaller segments. We must maintain simultaneously:

- the positions of the lights placed so far (to quickly identify the segment being split),
- the list of lengths of all current segments (to query the longest one instantly).

### 2. Optimal data structures

Use two balanced search trees together:

- **Position set $S$:** the light positions, including the two boundaries $0$ and $x$, automatically kept sorted increasingly so neighbors can be found by binary search (`lower_bound`/`upper_bound`).
- **Length multiset $T$:** the lengths of all segments, kept in decreasing order so the front element is always the longest.

### 3. Procedure for adding a light at position $p$

1. **Find the split segment:** binary-search $S$ for the two lights surrounding $p$: $l$ (the largest value still $< p$, the predecessor) and $r$ (the smallest value $> p$, the successor).
2. **Update segments:** the old segment $[l, r]$ of length $r - l$ is removed; it is replaced by two new segments $[l, p]$ and $[p, r]$ of lengths $p - l$ and $r - p$. Apply these changes to $T$.
3. **Update positions:** insert $p$ into $S$.
4. **Read the result:** the longest segment is the front element of $T$.

## Example

Consider $x = 8$, $n = 3$, light positions $[3, 6, 2]$.

- **Initialize:** $S = \{0, 8\}$, $T = \{8\}$.
- **Add light at $3$:** neighbors $l = 0$, $r = 8$. Remove $8$ from $T$, insert $3 - 0 = 3$ and $8 - 3 = 5$. $S = \{0, 3, 8\}$, $T = \{5, 3\}$. Longest $= 5$.
- **Add light at $6$:** neighbors $l = 3$, $r = 8$. Remove $5$ from $T$, insert $6 - 3 = 3$ and $8 - 6 = 2$. $S = \{0, 3, 6, 8\}$, $T = \{3, 3, 2\}$. Longest $= 3$.
- **Add light at $2$:** neighbors $l = 0$, $r = 3$. Remove $3$ from $T$, insert $2 - 0 = 2$ and $3 - 2 = 1$. $S = \{0, 2, 3, 6, 8\}$, $T = \{3, 2, 2, 1\}$. Longest $= 3$.

Result after each step: `5 3 3`.

## Complexity

- **Time:** $O(n \log n)$ — for each added light, the boundary search and the length removal/insertion on a balanced tree each cost $O(\log n)$; over $n$ queries the total is $O(n \log n)$.
- **Memory:** $O(n)$ to store at most $n + 2$ positions in $S$ and $n + 1$ segment lengths in $T$.
