# Christmas Party - Solution

**ID:** 1717 | **URL:** https://cses.fi/problemset/task/1717

## Approach

### Problem Restatement

There are $n$ children at a Christmas party, each bringing a gift. Count the number of ways to redistribute gifts so that no child receives their own gift, modulo $10^9+7$.

### Core Idea

This is the **derangement** problem: count permutations $\sigma$ of $\{1, 2, \ldots, n\}$ with $\sigma(i) \neq i$ for all $i$. Denote this count as $D_n$.

**Recurrence.** Consider element 1, which must go to one of $n-1$ positions, say position $k$. Then element $k$ has two possibilities:

- **Case A:** Element $k$ goes to position 1. Elements 1 and $k$ form a swap pair, and the remaining $n-2$ elements need a derangement: $D_{n-2}$ ways.
- **Case B:** Element $k$ does not go to position 1. The remaining $n-1$ elements need a derangement (where element $k$ is "forbidden" from position 1 instead of its own): $D_{n-1}$ ways.

Since there are $n-1$ choices for $k$ and the two cases partition all derangements:

$$D_n = (n-1)(D_{n-1} + D_{n-2})$$

Base cases: $D_0 = 1$ (empty permutation), $D_1 = 0$.

**Closed form (inclusion-exclusion):** $D_n = n! \sum_{i=0}^{n} \frac{(-1)^i}{i!}$. The recurrence is simpler for $O(n)$ computation.

### Algorithm

1. Initialize $D_0 = 1$, $D_1 = 0$.
2. For $i = 2$ to $n$: $D_i = (i-1)(D_{i-1} + D_{i-2}) \bmod (10^9+7)$.
3. Output $D_n$.

### Example

$n = 4$: $D_0 = 1$, $D_1 = 0$, $D_2 = 1 \cdot (0+1) = 1$, $D_3 = 2 \cdot (1+0) = 2$, $D_4 = 3 \cdot (2+1) = 9$.

## Complexity

- **Time:** $O(n)$
- **Memory:** $O(1)$ — only two previous values needed
