# Movie Festival - Solution

**ID:** 1629 | **URL:** https://cses.fi/problemset/task/1629

## Approach

Sort all $n$ movies by end time in increasing order. Let the sorted array be $P[1], P[2], \ldots, P[n]$ with $P[1].v \le P[2].v \le \cdots \le P[n].v$.

Define $f[i]$ = maximum number of movies that can be watched from $\{P[1], \ldots, P[i]\}$, with $f[0] = 0$.

For movie $i$, we have two choices:

1. **Don't watch movie $i$:** $f[i] = f[i-1]$.
2. **Watch movie $i$:** find the largest index $\text{pos}$ such that $P[\text{pos}].v \le P[i].u$, then $f[i] = f[\text{pos}] + 1$. Since the array is sorted by end time, $\text{pos}$ is found via binary search in $O(\log n)$.

Transition: $f[i] = \max(f[i-1], f[\text{pos}] + 1)$, where $\text{pos} = 0$ if no movie ends before movie $i$ starts.

**Correctness:** By induction. If the optimal solution for $\{P[1], \ldots, P[i]\}$ does not select movie $i$, it is a subset of $\{P[1], \ldots, P[i-1]\}$, giving $f[i-1]$. If it selects movie $i$, all other selected movies must end before $P[i].u$; since movies are sorted by end time, these have indices $\le \text{pos}$, giving $f[\text{pos}] + 1$. The maximum of both cases is optimal.

The answer is $f[n]$.

**Note:** This problem can also be solved greedily by always selecting the movie that ends earliest. The DP approach is more general and extends to weighted variants.

### Example

Consider $n = 3$, movies: $(3, 5)$, $(4, 9)$, $(5, 8)$. After sorting by end time: $P[1] = (3, 5)$, $P[2] = (5, 8)$, $P[3] = (4, 9)$.

| $i$ | $P[i]$ | $\text{pos}$ (largest with $P[\text{pos}].v \le P[i].u$) | $f[i] = \max(f[i-1], f[\text{pos}]+1)$ | $f[i]$ |
|---|---|---|---|---|
| 0 | — | — | Init | 0 |
| 1 | $(3, 5)$ | No prior movie → $0$ | $\max(0, 0+1)$ | 1 |
| 2 | $(5, 8)$ | $P[1].v = 5 \le 5$ → $1$ | $\max(1, 1+1)$ | 2 |
| 3 | $(4, 9)$ | $P[1].v = 5 > 4$ → $0$ | $\max(2, 0+1)$ | 2 |

Answer: $f[3] = 2$ — watch $(3, 5)$ and $(5, 8)$.

## Complexity

- **Time:** $O(n \log n)$ — sorting $O(n \log n)$, each of $n$ iterations does binary search $O(\log n)$.
- **Memory:** $O(n)$ — movie array and DP array.

## Code (C++)

[Solution Code](../code/Movie%20Festival.cpp)
