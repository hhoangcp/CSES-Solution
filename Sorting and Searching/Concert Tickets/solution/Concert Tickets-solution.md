# Concert Tickets - Solution

**ID:** 1091 | **URL:** https://cses.fi/problemset/task/1091

## Approach

### Problem Restatement

There are $n$ concert tickets with prices $h_i$, and $m$ customers arriving in order. Customer $j$ will pay at most $t_j$ and buys the most expensive ticket not exceeding their budget. Each ticket is sold at most once. If no suitable ticket exists, output $-1$.

### Core Idea

For each customer with budget $b$, we need to find the ticket with the largest price $\le b$ — a predecessor search problem. This greedy choice is globally optimal because selling the most expensive suitable ticket to the current customer preserves cheaper tickets for later customers: any future customer with budget $b' \ge v^*$ can also buy a cheaper ticket $v' < v^*$, but a customer with $v' \le b' < v^*$ cannot buy $v^*$. Thus, selling $v^*$ now never reduces the total number of tickets sold.

We use a `multiset` (balanced BST) for efficient predecessor search. `upper_bound(b)` returns an iterator to the first element $> b$; decrementing (`--it`) gives the largest element $\le b$. If `upper_bound` returns `begin()`, no element $\le b$ exists.

### Algorithm

1. Insert all $n$ ticket prices into a `multiset`.
2. For each customer with budget $b$:
   - Call `it = S.upper_bound(b)`.
   - If `it == S.begin()`: no suitable ticket, output $-1$.
   - Otherwise: `--it`, output `*it`, remove via `S.erase(it)`.

### Example

$n = 5$, $m = 3$. Tickets: $[5, 3, 7, 8, 5]$, Customers: $[4, 8, 3]$.

$S = \{3, 5, 5, 7, 8\}$.

| Customer | $b$ | `upper_bound(b)` | `--it` | Result | $S$ after |
|----------|-----|-------------------|--------|--------|-----------|
| 1 | 4 | → 5 | → 3 | **3** | $\{5, 5, 7, 8\}$ |
| 2 | 8 | → end() | → 8 | **8** | $\{5, 5, 7\}$ |
| 3 | 3 | → 5 = begin() | — | **-1** | $\{5, 5, 7\}$ |

## Complexity

- **Time:** $O((n + m) \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Concert%20Tickets.cpp)
