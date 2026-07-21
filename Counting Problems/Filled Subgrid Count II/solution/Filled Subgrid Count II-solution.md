# Filled Subgrid Count II - Solution

**ID:** 3414 | **URL:** https://cses.fi/problemset/task/3414

## Approach

### Problem Restatement

Given an $n \times n$ grid of uppercase letters, count for each of the first $k$ letters the number of rectangular subgrids where every cell contains the same letter.

### Histogram + monotonic stack

Process each row $i$ as the base of a histogram. For each column $j$, maintain $h[j]$ = number of consecutive cells with the same letter as $a[i][j]$ extending upward:

$$h[j] = \begin{cases} h[j] + 1 & \text{if } a[i][j] = a[i-1][j] \\ 1 & \text{otherwise} \end{cases}$$

Now count homogeneous rectangles with bottom edge at row $i$. Scan columns left to right within each maximal horizontal run of the same letter — when $a[i][j] \ne a[i][j{-}1]$, no homogeneous rectangle can span both columns, so reset the stack and running sum.

Maintain a stack of (height, width) pairs in strictly increasing height order. For each column $j$:

1. Pop elements with height $\ge h[j]$, accumulating their width. Subtract their contribution $h_k \cdot w_k$ from the running sum.
2. Push $(h[j], \text{accumulated width} + 1)$, adding $h[j] \cdot w$ to the sum.

The running sum after processing column $j$ equals the total number of homogeneous rectangles with bottom at row $i$ ending at column $j$. This works because the stack partitions the histogram into blocks of distinct heights, and each block of height $h_k$ and width $w_k$ contributes exactly $h_k \cdot w_k$ rectangles ending at column $j$ — one for each choice of top row (from $h_k$ options) and left column (from $w_k$ options).

### Example

**Problem example:** $n = 5$, $k = 3$, grid:
```
A B B B C
B B B B C
B C A A A
A A A A A
A A A A A
```

Histogram heights $h$ and per-row contributions:

| Row | $h$ values | A | B | C |
|-----|-----------|---|----|---|
| 1 | 1 1 1 1 1 | 1 | 6 | 1 |
| 2 | 1 2 2 2 2 | 0 | 16 | 2 |
| 3 | 2 1 1 1 1 | 6 | 2 | 1 |
| 4 | 1 1 2 2 2 | 21 | 0 | 0 |
| 5 | 2 2 3 3 3 | 36 | 0 | 0 |

Row 5 trace (all A): stack evolution at columns 1–5:

- $j{=}1$: $h{=}2$. Stack: $(2,1)$, sum $= 2$.
- $j{=}2$: $h{=}2$. Pop $(2,1)$, push $(2,2)$. Sum $= 4$.
- $j{=}3$: $h{=}3$. Push $(3,1)$. Sum $= 4 + 3 = 7$.
- $j{=}4$: $h{=}3$. Pop $(3,1)$, push $(3,2)$. Sum $= 4 + 6 = 10$.
- $j{=}5$: $h{=}3$. Pop $(3,2)$, push $(3,3)$. Sum $= 4 + 9 = 13$.

Row 5 total for A: $2 + 4 + 7 + 10 + 13 = 36$.

**Totals:** A $= 1{+}0{+}6{+}21{+}36 = \mathbf{64}$, B $= 6{+}16{+}2{+}0{+}0 = \mathbf{24}$, C $= 1{+}2{+}1{+}0{+}0 = \mathbf{4}$. ✓

## Complexity

- **Time:** $O(n^2)$ — each cell is pushed and popped from the stack at most once per row.
- **Space:** $O(n)$ — for the histogram array and monotonic stack.

## Code (C++)

[Solution Code](../code/Filled%20Subgrid%20Count%20II.cpp)
