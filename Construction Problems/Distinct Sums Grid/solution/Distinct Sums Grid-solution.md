# Distinct Sums Grid - Solution

**ID:** 3424 | **URL:** https://cses.fi/problemset/task/3424

## Approach

### Problem Restatement

Construct an $n \times n$ grid where (1) each integer $1 \dots n$ appears exactly $n$ times, and (2) all $2n$ row and column sums are distinct.

### Impossible cases

For $n \le 3$, no valid grid exists:

- **$n = 1$:** Only 1 row sum and 1 column sum, both equal 1 — cannot be distinct.
- **$n = 2$:** The total of all elements is $n \cdot n = 4$. We need $r_1 + r_2 = c_1 + c_2 = 4$ with $r_1, r_2, c_1, c_2$ all distinct, which is impossible.
- **$n = 3$:** Similarly, no arrangement satisfies both conditions.

### Construction for $n \ge 4$

**Base grid:** Fill the $(n-1) \times (n-1)$ top-left subgrid with $a[i][j] = i$ (each row is constant), set the last column $a[i][n] = n$ for all $i$, and set the last row $a[n][j] = j$. After this, each number $1 \dots n$ appears exactly $n$ times (the subgrid contributes $n-1$ copies of each $i < n$, the last column adds one copy of $n$, and the last row adds one copy of each $1 \dots n$).

Row sums $i(n-1)+n$ for $i < n$ form an arithmetic sequence with common difference $n-1 \ge 3$, so they are already distinct. Row $n$ sum is $\frac{n(n+1)}{2}$, which differs from all other row sums for $n \ge 4$. However, some column sums may coincide, requiring adjustment.

**Swaps to fix column conflicts:**

- **$n$ odd:** Swap $a[n][2]$ with $a[\lfloor n/2 \rfloor][n]$. This shifts the sum of column 2 and row $\lfloor n/2 \rfloor$, breaking any equality. Since we only exchange existing values, the counting invariant is preserved.
- **$n$ even:** Swap $a[n][n-1]$ with $a[n/2-1][n]$, then swap $a[n][n/2-1]$ with $a[n/2][n/2-1]$. Two swaps adjust enough sums to ensure all $2n$ values are distinct.

### Example

$n = 5$:

Base grid:
```
1 1 1 1 5
2 2 2 2 5
3 3 3 3 5
4 4 4 4 5
1 2 3 4 5
```

$n$ is odd, so swap $a[5][2]$ (value 2) with $a[2][5]$ (value 5):

```
1 1 1 1 5
2 2 2 2 2
3 3 3 3 5
4 4 4 4 5
1 5 3 4 5
```

Row sums: $\{9, 10, 17, 21, 18\}$, column sums: $\{11, 15, 13, 14, 22\}$ — all 10 values distinct, and each number $1 \dots 5$ appears exactly 5 times.

## Complexity

- **Time:** $O(n^2)$
- **Space:** $O(n^2)$

## Code (C++)

[Solution Code](../code/Distinct%20Sums%20Grid.cpp)
