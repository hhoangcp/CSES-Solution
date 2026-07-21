# Range Updates and Sums - Solution

**ID:** 1735 | **URL:** https://cses.fi/problemset/task/1735

## Approach

### Problem Restatement

Given an array of $n$ integers, process $q$ queries of three types:
1. Increase each value in range $[a, b]$ by $x$.
2. Set each value in range $[a, b]$ to $x$.
3. Calculate the sum of values in range $[a, b]$.

### Core idea

Use a segment tree with **two lazy parameters**: `increase` (pending increment) and `Set`/`Set_All` (pending assignment). The key challenge is that assignment overwrites all previous increments, while increments accumulate.

Any sequence of operations on an element $v$ can be represented as a linear function $f(v) = c \cdot v + d$:
- Identity (no pending operation): $f(v) = 1 \cdot v + 0$ (`Set_All = false`, `increase = 0`).
- After increment by $x$: $g(v) = f(v) + x = c \cdot v + (d + x)$. So `increase += x`.
- After assignment to $x$: $h(v) = 0 \cdot v + x$. The slope collapses to 0, so `increase = 0`, `Set = x`, `Set_All = true`.

This algebraic view directly explains the lazy propagation rules:

**Push down** from parent to child:
- If parent has `Set_All = true`: the assignment overrides everything on the child. Set `child.Set = parent.Set`, `child.increase = parent.increase`, `child.Set_All = true`, and `child.sum = (parent.Set + parent.increase) * length`.
- If parent has `Set_All = false` (only increment): `child.increase += parent.increase`, `child.sum += parent.increase * length`. If the child already has `Set_All = true`, the increment just adds to `child.increase` (since $c \cdot v + (d + x)$).

**Apply increment** to a fully-covered node: `increase += x`, `sum += x * length`.

**Apply assignment** to a fully-covered node: `Set = x`, `Set_All = true`, `increase = 0`, `sum = x * length`.

### Algorithm

1. **Build** a segment tree, each node storing `sum`, `increase`, `Set`, `Set_All`.
2. **Range increment** $[a, b]$ by $x$: at fully covered nodes, `increase += x`, `sum += x * length`. At partial overlaps, push down and recurse.
3. **Range assign** $[a, b]$ to $x$: at fully covered nodes, `Set = x`, `Set_All = true`, `increase = 0`, `sum = x * length`. At partial overlaps, push down and recurse.
4. **Range sum** $[a, b]$: standard query with lazy propagation.

### Example

Input:
```
6 5
2 3 1 1 5 3
3 3 5
1 2 4 2
3 3 5
2 2 4 5
3 3 5
```

Array: $[2, 3, 1, 1, 5, 3]$.

- Sum $[3, 5]$: $1 + 1 + 5 = 7$.
- Increment $[2, 4]$ by 2: array becomes $[2, 5, 3, 3, 5, 3]$.
- Sum $[3, 5]$: $3 + 3 + 5 = 11$.
- Set $[2, 4]$ to 5: array becomes $[2, 5, 5, 5, 5, 3]$.
- Sum $[3, 5]$: $5 + 5 + 5 = 15$.

Output:
```
7
11
15
```

## Complexity

- **Time:** $O((n + q) \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Range%20Updates%20and%20Sums.cpp)
