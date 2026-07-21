# Movie Festival II - Solution

**ID:** 1632 | **URL:** https://cses.fi/problemset/task/1632

## Approach

Sort all movies by end time in increasing order. This greedy ordering ensures that picking a movie ending earlier never blocks more future options than picking one ending later.

Maintain a `multiset` of size $k$, where each element represents the end time of the last movie assigned to a member. Initialize all $k$ entries to $0$ (everyone is available from the start).

For each movie $(a_i, b_i)$ in sorted order:

1. Use `upper_bound(a_i)` on the multiset to find the first end time $> a_i$, then take the element just before — this is the member who finishes latest but is still available ($\leq a_i$).
2. If such a member exists: erase their old end time, insert $b_i$, increment the answer.
3. If not (all members are busy at time $a_i$): skip this movie.

**Why assign to the member who finishes latest?** Suppose member $X$ is free from time $3$ and member $Y$ from time $5$. For a movie starting at $6$, assigning to $Y$ keeps $X$ available for any future movie starting in $[3, 5]$, whereas assigning to $X$ would waste $X$'s flexibility. Choosing the latest-available member preserves the most scheduling flexibility for future movies.

**Correctness:** By an exchange argument. If an optimal solution assigns the current movie to an earlier-available member $X$ instead of a later-available member $Y$, swapping the assignment to $Y$ keeps $X$'s earlier end time available, which is at least as good for all future assignments. Thus, always assigning to the latest-available member is never worse than any other choice.

### Example

Consider $n = 5$, $k = 2$, movies: $(1, 5)$, $(8, 10)$, $(3, 6)$, $(2, 5)$, $(6, 9)$.

After sorting by end time: $(1, 5)$, $(2, 5)$, $(3, 6)$, $(6, 9)$, $(8, 10)$.

Initial multiset: $\{0, 0\}$.

| Movie | $a_i$ | $b_i$ | `upper_bound(a_i)` result | Action | Multiset after |
|-------|-------|-------|---------------------------|--------|----------------|
| $(1,5)$ | $1$ | $5$ | Found $0$ (latest $\leq 1$) | Assign | $\{0, 5\}$ |
| $(2,5)$ | $2$ | $5$ | Found $0$ (latest $\leq 2$) | Assign | $\{5, 5\}$ |
| $(3,6)$ | $3$ | $6$ | `it == begin()` (no $\leq 3$) | Skip | $\{5, 5\}$ |
| $(6,9)$ | $6$ | $9$ | Found $5$ (latest $\leq 6$) | Assign | $\{5, 9\}$ |
| $(8,10)$ | $8$ | $10$ | Found $5$ (latest $\leq 8$) | Assign | $\{9, 10\}$ |

Answer: 4 movies watched.

## Complexity

- **Time:** $O(n \log n + n \log k)$ — sorting $O(n \log n)$, each movie: find/erase/insert in multiset of size $k$ costs $O(\log k)$.
- **Memory:** $O(n + k)$

## Code (C++)

[Solution Code](../code/Movie%20Festival%20II.cpp)
