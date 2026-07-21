# Robot Path - Solution

**ID:** 1742 | **URL:** https://cses.fi/problemset/task/1742

## Approach

### Problem Restatement

A robot starts at $(0,0)$ and executes $n$ horizontal/vertical move commands. It stops immediately upon returning to a previously visited point. Compute the total distance traveled.

### Core idea

Each command becomes an axis-aligned line segment. Self-intersection only occurs between a horizontal and a vertical segment (or consecutive reverse commands). We use a segment tree storing `set<long long>` at each node to detect the first intersection in two passes.

**Reverse commands:** If two consecutive commands are opposite (e.g., U then D), the robot immediately returns to its previous position — output the distance up to that point and stop.

**Two-pass intersection detection:** In Pass 1, insert horizontal segments into the segment tree (built on compressed $x$-coordinates) and query for each vertical segment. In Pass 2, insert vertical segments (tree on compressed $y$) and query for each horizontal segment. Each pass detects one direction of intersection.

**Segment tree with sets:** Each node stores a `set` of values. To insert a horizontal segment at height $y$ spanning $[x_1, x_2]$: add $y$ to the `set` at each node fully covered by $[x_1, x_2]$. To query a vertical segment at $x$ spanning $[y_1, y_2]$: traverse root-to-leaf at position $x$, and at each node use `upper_bound` / `lower_bound` to find the nearest $y$-value within $[y_1, y_2]$. `Query_min` finds the smallest $y > y_1$ (intersection from below); `Query_max` finds the largest $y < y_1$ (intersection from above). The nearest intersection to the starting endpoint is the one that matters — it determines how far the robot travels before stopping.

**Finding the first collision command:** Process commands in order. In each pass, when a query finds an intersection, record the command index and distance, and stop processing further. The minimum command index across both passes gives the first collision. All commands before it contribute their full length; the collision command contributes only the distance to the intersection point.

**Coordinate compression:** Coordinates can reach $10^{11}$ ($10^5$ commands × $10^6$ per command), so both axes are compressed to indices in $[0, 2n]$.

### Algorithm

1. Simulate the path, recording each segment. Check for reverse commands.
2. Compress $x$ and $y$ coordinates.
3. **Pass 1:** For each command in order:
   - Horizontal: insert its $y$-value into the segment tree over $[x_1, x_2]$.
   - Vertical: query for the nearest horizontal crossing. If found, record the collision.
4. Clear the segment tree. **Pass 2:** For each command in order:
   - Vertical: insert its $x$-value into the segment tree over $[y_1, y_2]$.
   - Horizontal: query for the nearest vertical crossing. If found, record the collision.
5. Sum distances: full lengths for commands before the first collision, partial length for the collision command.

### Example

5 commands: U2, R3, D1, L5, U2.

| # | Command | Segment | Distance |
|---|---------|----------|----------|
| 1 | U 2 | $(0,0)\to(0,2)$ | 2 |
| 2 | R 3 | $(0,2)\to(3,2)$ | 3 |
| 3 | D 1 | $(3,2)\to(3,1)$ | 1 |
| 4 | L 5 | $(3,1)\to(-2,1)$ | 3 (stops at $(0,1)$) |

Command 4 (L5) is horizontal at $y=1$, spanning $x \in [-2, 3]$. It crosses command 1 (U2), which is vertical at $x=0$, spanning $y \in [0, 2]$. The intersection $(0,1)$ is 3 units from the start of L5.

Total: $2 + 3 + 1 + 3 = 9$.

## Complexity

- **Time:** $O(n \log^2 n)$
- **Space:** $O(n \log n)$

## Code (C++)

[Solution Code](../code/Robot%20Path.cpp)
