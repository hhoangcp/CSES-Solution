# Distinct Values Queries - Solution

**ID:** 1734 | **URL:** https://cses.fi/problemset/task/1734

## Approach

### Problem Restatement

Given an array of $n$ integers, process $q$ queries: how many distinct values are in range $[a, b]$?

### Core idea

A value at position $i$ is the "first occurrence in range $[l, r]$" iff no equal value appears at a position $\ge l$ and $< i$. The number of distinct values in $[l, r]$ equals the number of such first occurrences.

Define $\text{Next}[i]$ = nearest position to the right of $i$ with the same value as $a[i]$ (0 if none). We process queries offline, sorted by left boundary $l$. Maintain a BIT where position $j$ stores 1 if $j$ is the "representative" for its value (the leftmost occurrence $\ge l$), and 0 otherwise. Then `query(r)` on the BIT returns exactly the count of distinct values in $[l, r]$.

When the left boundary moves from $l$ to $l+1$, position $l$ leaves all future ranges. We deactivate $l$ (add $-1$). If $\text{Next}[l] > 0$, position $\text{Next}[l]$ becomes the new representative for $a[l]$ (since no equal value exists in $[l+1, \text{Next}[l]-1]$), so we activate it (add $1$). If $\text{Next}[l] = 0$, the value $a[l]$ no longer appears, and no new representative is needed. This preserves the invariant that the BIT correctly reflects the set of representatives for the current left boundary.

### Algorithm

1. **Coordinate compression:** Compress array values from $[1, 10^9]$ to $[1, n]$.
2. **Compute Next[]:** Iterate right to left, tracking the nearest right position of each value.
3. **Initialize BIT:** For the first occurrence of each value (scanning left to right), add 1 at that position.
4. **Process queries:** Group queries by $l$, sorted in increasing order. Iterate $i$ from 1 to $n$: answer all queries with $l = i$ using `query(r)`, then deactivate $i$ (add $-1$) and activate $\text{Next}[i]$ if nonzero (add $1$).

### Example

Input:
```
5 3
3 2 3 1 2
1 3
2 4
1 5
```

Array: $[3, 2, 3, 1, 2]$, Next: $[3, 5, 0, 0, 0]$.

- **$l = 1$:** BIT = $[1, 1, 0, 1, 0]$ (positions 1, 2, 4 active as first occurrences of 3, 2, 1).
  - Query $[1, 3]$: `query(3) = 2`. Correct: $\{3, 2\}$.
  - Query $[1, 5]$: `query(5) = 3`. Correct: $\{3, 2, 1\}$.
  - Deactivate 1, activate $\text{Next}[1] = 3$. BIT = $[0, 1, 1, 1, 0]$.
- **$l = 2$:**
  - Query $[2, 4]$: `query(4) = 3`. Correct: $\{2, 3, 1\}$.
  - Deactivate 2, activate $\text{Next}[2] = 5$. BIT = $[0, 0, 1, 1, 1]$.

Output:
```
2
3
3
```

## Complexity

- **Time:** $O((n + q) \log n)$
- **Space:** $O(n + q)$

## Code (C++)

[Solution Code](../code/Distinct%20Values%20Queries.cpp)
