# Planets Queries I - Solution

**ID:** 1750 | **URL:** https://cses.fi/problemset/task/1750

## Approach

### Problem Restatement

Given a functional graph (each vertex has exactly one outgoing edge) on $n$ vertices, process $q$ queries of the form: starting from vertex $x$, which vertex is reached after $k$ steps?

### Core idea

Since $k$ can be up to $10^9$, step-by-step simulation is infeasible. **Binary lifting** precomputes a table $\text{up}[u][i]$ = the vertex reached from $u$ after $2^i$ steps. The recurrence $\text{up}[u][i] = \text{up}[\text{up}[u][i-1]][i-1]$ is correct because jumping $2^i$ steps equals two consecutive jumps of $2^{i-1}$ steps, and the forward path in a functional graph is unique — the order of jumps doesn't affect the result. Since $k < 2^{30}$, only 30 levels are needed.

Each query decomposes $k$ into its binary representation and applies the corresponding jumps: for each set bit $i$ of $k$, update $x \leftarrow \text{up}[x][i]$. The total steps equal $k$ by binary decomposition.

### Algorithm

1. Read input. Set $\text{up}[u][0] = t_u$ for all $u$.
2. For $i = 1$ to $30$: $\text{up}[u][i] = \text{up}[\text{up}[u][i-1]][i-1]$ for all $u$.
3. For each query $(x, k)$: for each bit $i$ from 30 down to 0, if bit $i$ of $k$ is set, $x \leftarrow \text{up}[x][i]$. Output $x$.

### Example

Input:
```
4 3
2 1 1 4
1 2
3 4
4 1
```

Teleporters: $1 \to 2$, $2 \to 1$, $3 \to 1$, $4 \to 4$.

| $u$ | up[u][0] | up[u][1] | up[u][2] |
|-----|----------|----------|----------|
| 1   | 2        | 1        | 1        |
| 2   | 1        | 2        | 2        |
| 3   | 1        | 2        | 2        |
| 4   | 4        | 4        | 4        |

- Query $(1, 2)$: $k = 10_2$, bit 1 set. $x = \text{up}[1][1] = 1$. **Output: 1**.
- Query $(3, 4)$: $k = 100_2$, bit 2 set. $x = \text{up}[3][2] = 2$. **Output: 2**.
- Query $(4, 1)$: $k = 1_2$, bit 0 set. $x = \text{up}[4][0] = 4$. **Output: 4**.

## Complexity

- **Time:** $O((n + q) \log K)$ where $K = 10^9$
- **Space:** $O(n \log K)$

## Code (C++)

[Solution Code](../code/Planets%20Queries%20I.cpp)
