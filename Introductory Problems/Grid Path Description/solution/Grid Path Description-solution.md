# Grid Path Description - Solution

**ID:** 1625 | **URL:** https://cses.fi/problemset/task/1625

## Approach

### Problem Restatement

Count the number of paths on a $7 \times 7$ grid from $(1,1)$ to $(1,7)$ matching a given 48-character pattern of 'U', 'D', 'L', 'R', and '?' (any direction). The path must visit every cell exactly once (a Hamiltonian path, 48 steps).

### Core Idea

A naive backtracking over $4^{48} \approx 7.2 \times 10^{28}$ possibilities is infeasible. The key optimization is **partition rule pruning**, which detects when the current path splits the unvisited region into two disconnected components — making a Hamiltonian completion impossible.

**Partition rule:** At the current cell $(x, y)$, prune immediately if either condition holds:
1. **Vertical barrier:** The cells above and below are blocked (boundary or visited), but the cells to the left and right are both open.
2. **Horizontal barrier:** The cells to the left and right are blocked, but the cells above and below are both open.

*Correctness:* Suppose the cell above is blocked and both left/right are open. Moving left (or right) turns the current cell into a wall, isolating the open region on the opposite side — the only connection between the two sides passes through the current cell (now visited). That isolated region can never be reached without revisiting a cell, violating the simple path constraint. Thus no valid completion exists, and pruning is safe.

Additional pruning: reaching $(1,7)$ before step 49 is invalid (remaining cells unreachable), and if the Manhattan distance to $(1,7)$ exceeds remaining steps, the destination cannot be reached in time.

With the partition rule, most branches are cut very early — in a $7 \times 7$ grid, "partition" situations arise frequently, reducing the branching factor from 4 to 1 in many cases. The all-'?' pattern has exactly 88,418 valid paths and runs under 1 second.

### Algorithm

```
Try(step, x, y):
    if (x, y) == (1, 7): count += (step == 49); return
    if partition rule conditions met: return
    mark (x, y) as visited
    if pattern[step] == '?': try all 4 valid directions
    else: try only the specified direction
    unmark (x, y)
```

### Example

Input: `??????R??????U??????????????????????????LD????D?` → Output: 201.

## Complexity

- **Time:** runs under 1 second with partition pruning
- **Space:** $O(1)$ — fixed $7 \times 7$ grid and recursion depth capped at 48

## Code (C++)

[Solution Code](../code/Grid%20Path%20Description.cpp)
