# Tower of Hanoi - Solution

**ID:** 2165 | **URL:** https://cses.fi/problemset/task/2165

## Approach

### Problem Restatement

Move $n$ disks ($1 \le n \le 16$) from peg 1 to peg 3, moving one disk at a time, never placing a larger disk on a smaller one. Minimize the total number of moves.

### Core Idea

Label the pegs **A** (source), **B** (auxiliary), **C** (target). To move a stack of $n$ disks from A to C, we must free the largest disk (disk $n$) by moving the top $n-1$ disks out of the way:

1. Recursively move the top $n-1$ disks from A to B (using C as temporary storage).
2. Move disk $n$ directly from A to C.
3. Recursively move the $n-1$ disks from B to C (using A as temporary storage).

**Correctness.** After step 1, only disk $n$ remains on A (free to move) and peg C is empty. Step 2 places disk $n$ on the empty peg C — no rule is violated. Step 3 places $n-1$ smaller disks on top of disk $n$ on peg C — since all are smaller, the ordering rule holds, and this is exactly the same problem for $n-1$ disks.

**Minimality.** Let $T(n)$ be the minimum moves. Any solution must: (i) move the top $n-1$ disks off disk $n$ (at least $T(n-1)$ moves), (ii) move disk $n$ to C (at least 1 move), (iii) move the $n-1$ disks back on top (at least $T(n-1)$ moves). So $T(n) \ge 2T(n-1) + 1$ with $T(1) \ge 1$. Our strategy achieves exactly $T(n) = 2T(n-1) + 1$ with $T(1) = 1$, so it is optimal.

**Solving the recurrence:** $T(n) + 1 = 2(T(n-1) + 1)$ gives $S(n) = T(n) + 1 = 2 \cdot S(n-1)$ with $S(1) = 2$. This is a geometric progression: $S(n) = 2^n$, hence $T(n) = 2^n - 1$.

### Algorithm

Call `Move(n, 1, 3, 2)` where `Move(k, src, dst, aux)`:
1. If $k = 0$, return.
2. Recursively call `Move(k-1, src, aux, dst)`.
3. Print `src dst`.
4. Recursively call `Move(k-1, aux, dst, src)`.

Total moves: $2^n - 1$.

### Example

**Problem example ($n = 2$):** $2^2 - 1 = 3$ moves.

| Step | Move |
|---|---|
| 1 | 1 → 2 |
| 2 | 1 → 3 |
| 3 | 2 → 3 |

**Illustrative example ($n = 3$):** $2^3 - 1 = 7$ moves. Disks numbered 1 (smallest) to 3 (largest), pegs A, B, C.

| Step | Disk | Move | State |
|---|---|---|---|
| 1 | 1 | A → C | |
| 2 | 2 | A → B | |
| 3 | 1 | C → B | Disks 1,2 on B; disk 3 free |
| 4 | 3 | A → C | Disk 3 reaches target |
| 5 | 1 | B → A | |
| 6 | 2 | B → C | |
| 7 | 1 | A → C | Tower reassembled on C |

## Complexity

- **Time:** $O(2^n)$ — exactly $2^n - 1$ moves are output
- **Space:** $O(n)$ — maximum recursion depth

## Code (C++)

[Solution Code](../code/Tower%20of%20Hanoi.cpp)
