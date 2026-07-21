# Planets Queries II - Solution

**ID:** 1160 | **URL:** https://cses.fi/problemset/task/1160

## Approach

### Problem Restatement

Given a functional graph on $n$ vertices, process $q$ queries: find the minimum number of steps to go from vertex $a$ to vertex $b$, or $-1$ if unreachable.

### Core idea

In a functional graph, from any vertex $a$, the unique forward path goes through a tail into a cycle. So $b$ is reachable from $a$ only if $b$ lies on this path — either on the tail from $a$ to the cycle, or within the cycle.

Define $\text{len}[u]$ so that it decreases by exactly 1 along each edge: $\text{len}[u] = \text{len}[t_u] + 1$. This is computed via DFS: when DFS reaches an already-visited vertex (cycle closure), it returns the base value, and back-propagation ensures $\text{len}$ decreases by 1 per step along the edge direction. Consequently, when $b$ is downstream of $a$ (i.e., reachable by following edges), the distance is simply $\text{len}[a] - \text{len}[b]$.

To answer a query $(a, b)$:
- **Case 1:** $b$ is on the tail from $a$ to the cycle. Check via binary lifting: if $\text{Lifting}(a, \text{len}[a] - \text{len}[b]) = b$, the answer is $\text{len}[a] - \text{len}[b]$.
- **Case 2:** $b$ is in the cycle. Let $x = \text{Lifting}(a, \text{len}[a])$ be $a$'s cycle entry. If $\text{Lifting}(x, \text{len}[x] - \text{len}[b]) = b$, the answer is $\text{len}[a] + \text{len}[x] - \text{len}[b]$.
- **Otherwise:** $b$ is unreachable from $a$ (in a different component or not downstream).

### Algorithm

1. Build binary lifting table $\text{up}[u][i]$ from the input.
2. DFS to compute $\text{len}[u]$ for all vertices.
3. For each query $(a, b)$:
   - If $\text{Lifting}(a, \text{len}[a] - \text{len}[b]) = b$: output $\text{len}[a] - \text{len}[b]$.
   - Else if $\text{Lifting}(\text{Lifting}(a, \text{len}[a]), \text{len}[\text{Lifting}(a, \text{len}[a])] - \text{len}[b]) = b$: output $\text{len}[a] + \text{len}[\text{Lifting}(a, \text{len}[a])] - \text{len}[b]$.
   - Else: output $-1$.

### Example

Input:
```
5 3
2 3 2 3 2
1 2
1 3
1 4
```

Graph: cycle $2 \to 3 \to 2$ (length 2). Tails: $1 \to 2$, $4 \to 3$, $5 \to 2$.

$\text{len} = [3, 2, 1, 2, 3]$ (len[3] = 1 on cycle, len[2] = 2 on cycle, tails add their distance).

- Query $(1, 2)$: Case 1 — $\text{Lifting}(1, 3-2) = \text{Lifting}(1, 1) = 2 = b$. Answer: $3 - 2 = 1$.
- Query $(1, 3)$: Case 1 — $\text{Lifting}(1, 3-1) = \text{Lifting}(1, 2) = 3 = b$. Answer: $3 - 1 = 2$.
- Query $(1, 4)$: Case 1 — $\text{Lifting}(1, 3-2) = 2 \ne 4$. Case 2 — $x = \text{Lifting}(1, 3) = 2$, $\text{Lifting}(2, 2-2) = 2 \ne 4$. Answer: $-1$.

Output:
```
1
2
-1
```

## Complexity

- **Time:** $O((n + q) \log n)$
- **Space:** $O(n \log n)$

## Code (C++)

[Solution Code](../code/Planets%20Queries%20II.cpp)
