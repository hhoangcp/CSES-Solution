# Nearest Smaller Values - Solution

**ID:** 1645 | **URL:** https://cses.fi/problemset/task/1645

## Approach

Consider position $i$ and two earlier positions $j < k < i$. If $x_j \geq x_k$, then $x_j$ can never be the answer for any position to the right of $k$: if $x_k < x_i$, then $x_k$ is closer and smaller; if $x_k \geq x_i$, then both are too large. This means the set of viable candidates always has **strictly increasing** values from left to right — a monotonic stack is the natural data structure.

Process the array from left to right, maintaining a stack of indices with strictly increasing values from bottom to top. For each position $i$:

1. **Pop:** While the stack is non-empty and $x_{S.\text{top}()} \geq x_i$, pop.
2. **Query:** If the stack is empty, output $0$; otherwise output $S.\text{top}()$.
3. **Push:** Push $i$ onto the stack.

**Correctness:** After the pop step, all elements with value $\geq x_i$ have been removed from the top. The remaining top (if any) has value $< x_i$ and is the nearest such position — any position between it and $i$ either was already popped (value $\geq$ something $\geq x_i$) or has value $\geq x_i$. If the stack is empty, no position to the left has a smaller value.

### Example

Consider $n = 8$, array $x = [2, 5, 1, 4, 8, 3, 2, 5]$ (1-indexed).

| $i$ | $x_i$ | Stack action | Answer | Stack after push |
|-----|-------|-------------|--------|-------------------|
| 1 | $2$ | Empty → no pop | $0$ | $\{1\}$ |
| 2 | $5$ | Top $x_1=2 < 5$ → no pop | $1$ | $\{1, 2\}$ |
| 3 | $1$ | Pop 2 ($x_2=5 \geq 1$), pop 1 ($x_1=2 \geq 1$) | $0$ | $\{3\}$ |
| 4 | $4$ | Top $x_3=1 < 4$ → no pop | $3$ | $\{3, 4\}$ |
| 5 | $8$ | Top $x_4=4 < 8$ → no pop | $4$ | $\{3, 4, 5\}$ |
| 6 | $3$ | Pop 5 ($x_5=8 \geq 3$), pop 4 ($x_4=4 \geq 3$) | $3$ | $\{3, 6\}$ |
| 7 | $2$ | Pop 6 ($x_6=3 \geq 2$) | $3$ | $\{3, 7\}$ |
| 8 | $5$ | Top $x_7=2 < 5$ → no pop | $7$ | $\{3, 7, 8\}$ |

Output: `0 1 0 3 4 3 3 7`

## Complexity

- **Time:** $O(n)$ — each element is pushed and popped at most once.
- **Memory:** $O(n)$ — stack holds at most $n$ elements.

## Code (C++)

[Solution Code](../code/Nearest%20Smaller%20Values.cpp)
