# Polynomial Queries - Solution

**ID:** 1736 | **URL:** https://cses.fi/problemset/task/1736

## Approach

### Problem Restatement

Maintain an array of $n$ values. Process $q$ queries:
1. Increase position $i$ in range $[a, b]$ by $(i - a + 1)$.
2. Calculate the sum of values in range $[a, b]$.

### Core idea

Standard lazy propagation only handles constant range additions. Here the increase is linear in $i$: $\Delta_i = (i - a + 1) = i - (a - 1)$. Decompose into a constant part $-(a-1)$ and a linear part $+i$. Store two lazy parameters per node:

- **`Lazy_1`**: accumulates the constant coefficient. Contributes $\text{Lazy\_1} \times (r - l + 1)$ to the sum of segment $[l, r]$.
- **`Lazy_2`**: accumulates the linear coefficient. Contributes $\text{Lazy\_2} \times \sum_{i=l}^{r} i$ to the sum, where $\sum_{i=l}^{r} i = \frac{r(r+1)}{2} - \frac{(l-1)l}{2}$ is computable in $O(1)$.

This is correct because each position $i$ in a segment should receive $\text{Lazy\_2} \cdot i + \text{Lazy\_1}$, so the sum over $[l', r']$ is:

$$\sum_{i=l'}^{r'} (\text{Lazy\_2} \cdot i + \text{Lazy\_1}) = \text{Lazy\_2} \cdot \sum_{i=l'}^{r'} i + \text{Lazy\_1} \cdot (r' - l' + 1)$$

When splitting $[l, r]$ into $[l, mid]$ and $[mid+1, r]$, the same $(\text{Lazy\_1}, \text{Lazy\_2})$ pair is passed to both children — only the index range changes, preserving correctness:

$$\sum_{i=l}^{r} (\text{Lazy\_2} \cdot i + \text{Lazy\_1}) = \sum_{i=l}^{mid} (\text{Lazy\_2} \cdot i + \text{Lazy\_1}) + \sum_{i=mid+1}^{r} (\text{Lazy\_2} \cdot i + \text{Lazy\_1})$$

### Algorithm

1. **Build** a segment tree where each node stores `sum`, `Lazy_1`, `Lazy_2`.
2. **Update** $[a, b]$ with `val`: At fully covered node $[l, r]$:
   - `Lazy_1 -= val × (a - 1)`, `Lazy_2 += val`.
   - `sum += val × (cal(r) - cal(l-1)) - val × (a-1) × (r-l+1)`.
3. **Push lazy** to children $[l, mid]$ and $[mid+1, r]$:
   - Add parent's `Lazy_1` and `Lazy_2` to each child's lazy values.
   - Update each child's `sum` using the formula above with the child's index range.
   - Reset parent's lazy values to 0.
4. **Query** $[a, b]$: Standard range sum query with lazy propagation.

### Example

Input:
```
5 3
4 2 3 1 7
2 1 5
1 1 5
2 1 5
```

Array: $[4, 2, 3, 1, 7]$. Root sum $= 17$.

- Query $[1, 5]$: return 17.
- Update $[1, 5]$ with val $= 1$: `Lazy_1 -= 0`, `Lazy_2 += 1`, `sum += cal(5) - cal(0) = 15`. New root sum $= 32$. Array becomes $[5, 4, 6, 5, 12]$.
- Query $[1, 5]$: return 32.

Output:
```
17
32
```

## Complexity

- **Time:** $O((n + q) \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Polynomial%20Queries.cpp)
