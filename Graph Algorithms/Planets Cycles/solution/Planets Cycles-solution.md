# Planets Cycles - Solution

**ID:** 1751 | **URL:** https://cses.fi/problemset/task/1751

## Approach

### Problem Restatement

Given a functional graph (each vertex has exactly one outgoing edge) on $n$ vertices, compute for each vertex the number of distinct vertices visited when starting from it and following edges until a previously visited vertex is reached.

### Core idea

Each connected component of a functional graph consists of exactly one cycle with directed trees (tails) feeding into it. For a vertex on a cycle of length $c$, the answer is $c$. For a vertex on a tail $d$ steps from the cycle, the answer is $d + c$ — the ship travels $d$ steps along the tail then visits all $c$ cycle vertices.

The algorithm processes one component at a time via DFS. Each vertex is pushed onto a queue $Q$ before checking visitation, so the queue captures the full DFS path including the repeated vertex at cycle closure. After DFS, the queue is drained: tail vertices get decreasing `len` values (subtracting 1 per step closer to the cycle), while cycle vertices all share the same `len` equal to the cycle length. The transition from tail to cycle is detected when `Q.front() == Q.back()` — the first cycle vertex has been reached.

### Algorithm

1. For each unvisited vertex $u$, start DFS following the single outgoing edge. Push each vertex onto $Q$ before checking visitation. Count `steps`.
2. If DFS reaches a visited vertex $v$ with known `len[v]`: add `len[v]` to `steps` and return (path enters a known component).
3. After DFS, process $Q$ with `sub = 1`. For each dequeued vertex $u$:
   - If `Q.front() == Q.back()`: set `sub = 0` (cycle entry detected).
   - Set `len[u] = steps`, then `steps -= sub`.
4. Output `len[1..n]`.

### Example

Input:
```
5
2 4 3 1 4
```

Functional graph: $1 \to 2 \to 4 \to 1$ (cycle of length 3), $3 \to 3$ (self-loop, length 1), $5 \to 4$ (tail of length 1 into cycle).

- DFS from 1: visits $1 \to 2 \to 4 \to 1$. $Q = [1,2,4,1]$, steps = 3. Front == back at start → all cycle: len[1] = len[2] = len[4] = 3.
- DFS from 3: visits $3 \to 3$. $Q = [3,3]$, steps = 1. Self-loop: len[3] = 1.
- DFS from 5: visits $5$, then 4 (already visited, len[4] = 3). steps = 1 + 3 = 4. $Q = [5,4]$. Dequeue 5 (tail, sub = 1): len[5] = 4. Dequeue 4 (front == back, sub = 0): len[4] = 3.

Output:
```
3 3 1 3 4
```

## Complexity

- **Time:** $O(n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Planets%20Cycles.cpp)
