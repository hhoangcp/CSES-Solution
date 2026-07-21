# Prüfer Code - Solution

**ID:** 1134 | **URL:** https://cses.fi/problemset/task/1134

## Approach

### Problem Restatement

Given a Prüfer code of length $n-2$ for a labeled tree on $n$ nodes, reconstruct and output the edges of the tree.

### Core idea

Reverse the Prüfer construction: a node's degree equals 1 + (number of appearances in the code). At each step, the smallest-degree-1 node is the next leaf to connect to the current code element. After connecting, decrementing that element's degree may create a new leaf. If it's smaller than the current pointer, use it immediately; otherwise advance the pointer to find the next smallest leaf. This exactly reverses the original encoding (by bijectivity of Prüfer codes), so the reconstruction is correct and unique. The pointer `cur` only moves forward, giving $O(n)$ total work instead of needing a priority queue.

### Algorithm

1. Compute `deg[i]` = (count of $i$ in code) + 1 for each node.
2. Set `cur` = smallest node with `deg == 1`, `leaf = cur`.
3. For each code element $x$:
   - Output edge `leaf -- x`.
   - Decrement `deg[x]`. If `deg[x] == 1` and `x < cur`, set `leaf = x`.
   - Otherwise, increment `cur` until `deg[cur] == 1`, set `leaf = cur`.
4. Output final edge `leaf -- n`.

### Example

$n=5$, code: 2 2 4. deg: [1,3,1,2,1].

- leaf=1: output 1-2, deg[2]=2. cur→3, leaf=3.
- leaf=3: output 3-2, deg[2]=1, 2<3 → leaf=2.
- leaf=2: output 2-4, deg[4]=1. cur→4, leaf=4.
- Final: 4-5.

Output: 1-2, 3-2, 2-4, 4-5.

## Complexity

- **Time:** $O(n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Pr%C3%BCfer%20Code.cpp)
