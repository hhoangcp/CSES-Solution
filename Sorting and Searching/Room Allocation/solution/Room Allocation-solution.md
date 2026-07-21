# Room Allocation - Solution

**ID:** 1164 | **URL:** https://cses.fi/problemset/task/1164

## Approach

For each customer $i$, create two events: an **arrival** at day $a_i$ with type $+1$ (needs a room), and a **departure** at day $b_i$ with type $-1$ (frees a room). This gives $2n$ events total.

Sort all events by time increasing. For ties at the same day, process arrival ($+1$) before departure ($-1$) (sort by `type` decreasing). This ensures a room freed on day $t$ is **not** immediately reassigned to a customer arriving on day $t$, since the problem requires the departure day to be **strictly earlier** than the arrival day for room reuse.

Maintain a stack of available room numbers, initialized with $1, 2, \ldots, n$ (pushed in reverse so room 1 is on top — smallest room prioritized for reuse). Process events in sorted order:

- **Arrival ($+1$):** Pop the room on top of the stack, assign it to this customer. Update $\text{res} = \max(\text{res}, \text{room})$.
- **Departure ($-1$):** Push this customer's room back onto the stack.

**Correctness:** Let $d(t)$ be the number of customers present on day $t$. The minimum rooms needed is $\max_t d(t)$ since at the busiest time each customer needs a separate room. The algorithm uses exactly this many: at each time $t$, the number of rooms in use equals $d(t)$ (arrivals add, departures remove, and processing arrivals before departures at the same day correctly enforces the strict-inequality constraint). Each room is assigned to at most one customer at a time (a room is only pushed back upon departure), so two customers share a room iff their intervals don't overlap.

### Example

Consider $n = 3$ customers: $(1, 2)$, $(2, 4)$, $(4, 4)$.

Events after sorting (arrival before departure at same day): $(1, +1, 0)$, $(2, +1, 1)$, $(2, -1, 0)$, $(4, +1, 2)$, $(4, -1, 1)$, $(4, -1, 2)$.

Initial stack: $[1, 2, 3]$ (room 1 on top).

| Event | Action | Stack after | Rooms in use |
|-------|--------|-------------|--------------|
| $(1, +1, 0)$ | Assign room 1 to customer 0 | $[2, 3]$ | 1 |
| $(2, +1, 1)$ | Assign room 2 to customer 1 | $[3]$ | 2 |
| $(2, -1, 0)$ | Return room 1 | $[1, 3]$ | 1 |
| $(4, +1, 2)$ | Assign room 1 to customer 2 | $[3]$ | 2 |
| $(4, -1, 1)$ | Return room 2 | $[2, 3]$ | 1 |
| $(4, -1, 2)$ | Return room 1 | $[1, 2, 3]$ | 0 |

Answer: 2 rooms, assignment `1 2 1`.

Note: customer 1 arrives on day 2 when customer 0 departs — since arrival is processed first, customer 1 gets room 2 (not room 1), correctly reflecting that day 2 is not strictly earlier than day 2. Customer 2 arrives on day 4 when customer 1 departs — similarly gets room 1 (freed since day 2), not room 2.

## Complexity

- **Time:** $O(n \log n)$ — sorting $2n$ events; each stack operation is $O(1)$.
- **Memory:** $O(n)$ — events array, stack, and assignment array.

## Code (C++)

[Solution Code](../code/Room%20Allocation.cpp)
