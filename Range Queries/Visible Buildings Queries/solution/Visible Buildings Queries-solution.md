# Visible Buildings Queries - Solution

**ID:** 3304 | **URL:** https://cses.fi/problemset/task/3304

## Approach

### Problem Restatement

Given $n$ buildings with heights $h_1, \ldots, h_n$, process $q$ queries: if only buildings in range $[a, b]$ existed, how many would be visible from the left? A building is visible if it is strictly taller than all buildings to its left.

### Core idea

Building $i$ is visible in range $[a, b]$ iff $h_i > \max_{j \in [a, i-1]} h_j$. The visible buildings form a strictly increasing sequence of heights starting from position $a$.

Process queries offline, sorted by left boundary $l$ in **decreasing** order. Scan position $i$ from $n$ down to $1$, maintaining a **monotonic stack** $S$ of positions with strictly decreasing heights from bottom to top:

1. Pop all positions $j$ from the top with $h_j \le h_i$ (building $j$ is hidden by $i$ since $i < j$ and $h_i \ge h_j$).
2. Push $i$ onto the stack.

**Invariant:** After processing position $i$, the stack contains exactly the visible buildings from the left of $i$ within $[i, n]$.

*Proof by induction:* At $i = n$, pushing $n$ into an empty stack is correct. Assume the invariant holds after processing $i+1$. When processing $i$: every popped position $j$ has $h_j \le h_i$, so $j$ is hidden by building $i$ and cannot be visible from the left of $i$. Position $i$ itself is always visible (it is the first building). The remaining positions have heights $> h_i$ and were visible from $i+1$ by hypothesis; they remain visible from $i$ since $i$ cannot block them, and no building between $i$ and them is tall enough to do so — if such a building existed, it would not have been popped by $i$ (being taller than $h_i$) and would still be in the stack between $i$ and them, contradicting stack adjacency.

To answer query $[l, r]$ when $i = l$: the stack contains visible buildings in $[l, n]$. Since positions in the stack decrease from bottom to top, use binary search to find the first position $\le r$; all elements from there to the top have positions $\le r$ and lie within $[l, r]$. The answer is the count of such elements.

### Algorithm

1. Read all queries and group them by left boundary $l$.
2. Scan $i$ from $n$ down to $1$:
   - Pop all positions $j$ from the stack with $h_j \le h_i$.
   - Push $i$ onto the stack.
   - For each query $[l, r]$ with $l = i$: binary search the stack for the first position $\le r$; answer = stack size minus that index.
3. Output answers in original query order.

### Example

Input:
```
5 3
4 1 2 2 3
1 5
2 5
3 4
```

Heights: $[4, 1, 2, 2, 3]$.

Scan from $i = 5$ down to $1$:

- $i = 5$ ($h = 3$): Push 5. $S = [5]$.
- $i = 4$ ($h = 2$): $h[5] = 3 > 2$, no pop. Push 4. $S = [5, 4]$.
- $i = 3$ ($h = 2$): $h[4] = 2 \le 2$, pop 4. $h[5] = 3 > 2$, stop. Push 3. $S = [5, 3]$.
- $i = 2$ ($h = 1$): $h[3] = 2 > 1$, no pop. Push 2. $S = [5, 3, 2]$.
- $i = 1$ ($h = 4$): Pop 2, 3, 5 ($h \le 4$). Push 1. $S = [1]$.

Queries (processed when scan reaches $l$):

- **$[3, 4]$** at $i = 3$: $S = [5, 3]$. First position $\le 4$ is 3 at index 1. Answer $= 2 - 1 = 1$. Correct: heights $[2, 2]$, only position 3 visible.
- **$[2, 5]$** at $i = 2$: $S = [5, 3, 2]$. First position $\le 5$ is 5 at index 0. Answer $= 3 - 0 = 3$. Correct: heights $[1, 2, 2, 3]$, positions 2, 3, 5 visible.
- **$[1, 5]$** at $i = 1$: $S = [1]$. First position $\le 5$ is 1 at index 0. Answer $= 1 - 0 = 1$. Correct: height 4 blocks all others.

Output:
```
1
3
1
```

## Complexity

- **Time:** $O((n + q) \log n)$ — each position enters and exits the stack at most once ($O(n)$ total), each query requires $O(\log n)$ binary search.
- **Space:** $O(n + q)$

## Code (C++)

[Solution Code](../code/Visible%20Buildings%20Queries.cpp)
