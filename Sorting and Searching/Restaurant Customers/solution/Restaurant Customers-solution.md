# Restaurant Customers - Solution

**ID:** 1619 | **URL:** https://cses.fi/problemset/task/1619

## Approach

Convert each customer's interval $[a_i, b_i]$ into two events: an **arrival** at time $a_i$ with value $+1$, and a **departure** at time $b_i$ with value $-1$. This gives $2n$ events total.

Sort all $2n$ events by time increasing. For ties at the same time, process arrival ($+1$) before departure ($-1$) — sorting by `val` decreasing ensures this. This convention accounts for the case where a customer departing at $t$ and another arriving at $t$ are both present at $t$.

Traverse the sorted events, maintaining `cnt` (current number of customers): `cnt += val`, then `res = max(res, cnt)`.

**Correctness:** The customer count only changes at event times and is constant between consecutive events. At each event time, `cnt` reflects the exact number of customers present (arrivals add, departures remove). Processing arrivals before departures at the same time ensures the count is captured correctly at the peak. Therefore, the maximum value of `cnt` over the sweep equals the maximum number of simultaneously present customers.

### Example

Consider $n = 3$, customers: $(5, 8)$, $(2, 4)$, $(3, 9)$.

Events: $(2,+1)$, $(3,+1)$, $(4,-1)$, $(5,+1)$, $(8,-1)$, $(9,-1)$.

| Step | Time | `val` | `cnt` | `res` |
|------|------|-------|-------|-------|
| Init | — | — | 0 | 0 |
| 1 | $2$ | $+1$ | 1 | 1 |
| 2 | $3$ | $+1$ | 2 | 2 |
| 3 | $4$ | $-1$ | 1 | 2 |
| 4 | $5$ | $+1$ | 2 | 2 |
| 5 | $8$ | $-1$ | 1 | 2 |
| 6 | $9$ | $-1$ | 0 | 2 |

Answer: 2 (peak at time $t = 3$).

## Complexity

- **Time:** $O(n \log n)$ — sorting $2n$ events; the sweep is $O(n)$.
- **Memory:** $O(n)$ — array of $2n$ events.

## Code (C++)

[Solution Code](../code/Restaurant%20Customers.cpp)
