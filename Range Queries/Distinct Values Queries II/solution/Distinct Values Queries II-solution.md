# Distinct Values Queries II - Solution

**ID:** 3356 | **URL:** https://cses.fi/problemset/task/3356

## Approach

### Problem Restatement

Given an array of $n$ integers, process $q$ queries:
1. Update the value at position $k$ to $u$.
2. Check whether all values in range $[a, b]$ are distinct.

### Core idea

All values in $[a, b]$ are distinct iff no two positions in $[a, b]$ share the same value. Equivalently, for every position $i \in [a, b]$, the next occurrence of $a[i]$ to the right must lie outside $[a, b]$.

Define $\text{init}[i]$ = nearest position to the right of $i$ with the same value (or $n+1$ if none). Then:

$$\text{All values in } [a, b] \text{ are distinct} \iff \min_{i \in [a,b]} \text{init}[i] > b$$

We maintain $\text{init}$ using a segment tree storing range minimums. Query type 2 computes `m = query(a, b)`; if $m > b$ the answer is YES, otherwise NO.

**Update correctness:** When changing $a[p]$ from old value to new value, positions with the same value form sorted linked lists. Removing $p$ from the old value's list links its predecessor $l$ directly to its successor $r$ (setting `init[l] = r`). Inserting $p$ into the new value's list sets `init[l] = p` (if predecessor $l$ exists) and `init[p] = r`. These are the only positions whose `init` values change, and the segment tree is updated accordingly. No other position is affected: `init[r]` is unchanged because $r$'s nearest right occurrence doesn't depend on what's to its left, and positions outside these linked lists are unaffected.

### Algorithm

1. **Coordinate compression:** Compress all values (including future updates) to $[1, m]$.
2. **Build init[] and segment tree:** Iterate right to left; for each $i$, set `init[i]` to the nearest right position with the same value (or $n+1$), then insert $i$ into the value's set. Build the segment tree on `init`.
3. **Process queries:**
   - Type 2: Compute `m = query(a, b)`. Output YES if $m > b$, else NO.
   - Type 1 (update position $p$ to new value):
     - Remove $p$ from old value's set. If predecessor $l$ exists, set `init[l] = successor` (or $n+1$). Update segment tree at $l$.
     - Insert $p$ into new value's set. If predecessor $l$ exists, set `init[l] = p`. Set `init[p] = successor` (or $n+1$). Update segment tree at $l$ and $p$.

### Example

Input:
```
5 4
3 2 7 2 8
2 3 5
2 2 5
1 2 9
2 2 5
```

Array: $[3, 2, 7, 2, 8]$, init: $[6, 4, 6, 6, 6]$ (position 2 has init$=4$ since $a[4]=2=a[2]$; others have init$=n{+}1=6$).

- Query $[3,5]$: $\min(\text{init}[3..5]) = 6 > 5$. **YES** ($\{7, 2, 8\}$ all distinct).
- Query $[2,5]$: $\min(\text{init}[2..5]) = 4 \le 5$. **NO** ($a[2]=a[4]=2$).
- Update position 2 to 9: remove 2 from value-2 set (no predecessor; successor$=4$; nothing to update). Insert 2 into value-9 set (no predecessor, no successor). `init[2]` becomes $n{+}1=6$. init: $[6, 6, 6, 6, 6]$.
- Query $[2,5]$: $\min(\text{init}[2..5]) = 6 > 5$. **YES** ($\{9, 7, 2, 8\}$ all distinct).

Output:
```
YES
NO
YES
```

## Complexity

- **Time:** $O((n + q) \log n)$
- **Space:** $O(n + q)$

## Code (C++)

[Solution Code](../code/Distinct%20Values%20Queries%20II.cpp)
