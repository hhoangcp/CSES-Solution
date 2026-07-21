# Salary Queries - Solution

**ID:** 1144 | **URL:** https://cses.fi/problemset/task/1144

## Approach

### Problem Restatement

A company has $n$ employees, each with salary $p_i$. Process $q$ queries:
1. `! k x`: change employee $k$'s salary to $x$.
2. `? a b`: count employees with salary in range $[a, b]$.

### Core idea

Use a **Fenwick tree (BIT)** with **coordinate compression**. Since salaries reach $10^9$, we can't use them directly as array indices. Instead, collect all values that will ever appear — initial salaries, update values, and query boundaries $a, b$ — sort them, and map each to its rank. This compression is order-preserving: $v_1 \le v_2 \iff f(v_1) \le f(v_2)$, so a range query $[a, b]$ in original coordinates maps exactly to $[f(a), f(b)]$ in compressed coordinates.

The BIT maintains a frequency count at each compressed position. Range count $[a, b]$ is computed as `query(f(b)) - query(f(a)-1)`. For updates, we remove the old salary (`update(f(p_k), -1)`) and add the new one (`update(f(x), +1)`).

### Algorithm

1. **Coordinate compression:** Collect all salary values (initial, updates, query boundaries). Sort, deduplicate, map each to its rank.
2. **Initialize BIT:** For each employee, `update(f(p_i), +1)`.
3. **Update** `! k x`: `update(f(p_k), -1)`, `update(f(x), +1)`, set $p_k = x$.
4. **Query** `? a b`: Return `query(f(b)) - query(f(a) - 1)`.

### Example

Input:
```
5 3
3 7 2 2 5
? 2 3
! 3 6
? 2 3
```

Salaries: $[3, 7, 2, 2, 5]$.

- Query `? 2 3`: employees with salary $\in [2, 3]$ are positions 1, 3, 4. Count $= 3$.
- Update `! 3 6`: employee 3's salary changes from 2 to 6. Salaries become $[3, 7, 6, 2, 5]$.
- Query `? 2 3`: employees with salary $\in [2, 3]$ are positions 1, 4. Count $= 2$.

Output:
```
3
2
```

## Complexity

- **Time:** $O((n + q) \log(n + q))$
- **Space:** $O(n + q)$

## Code (C++)

[Solution Code](../code/Salary%20Queries.cpp)
