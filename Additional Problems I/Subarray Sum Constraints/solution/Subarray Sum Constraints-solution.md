# Subarray Sum Constraints - Solution

**ID:** 3294 | **URL:** https://cses.fi/problemset/task/3294

## Problem Statement

Construct an array $x_1, x_2, \ldots, x_n$ satisfying $m$ constraints of the form: $x_l + x_{l+1} + \ldots + x_r = s$, or determine that no such array exists.

## Approach

### Prefix sum transformation

Define prefix sums $p_0 = 0, p_i = x_1 + \ldots + x_i$. The constraint $x_l + \ldots + x_r = s$ becomes:

$$p_r - p_{l-1} = s$$

The problem reduces to: assign values to $p_0, p_1, \ldots, p_n$ satisfying all difference constraints, or detect contradiction.

### Weighted DSU

Model each $p_i$ as a node. Each constraint $p_r - p_{l-1} = s$ creates an edge between nodes $l-1$ and $r$ with weight $s$. Use DSU with `diff[x]` storing $p_x - p_{\text{root}(x)}$:

- **`find(x)`**: path compression + accumulate `diff` so that `diff[x] = p_x - p_root`.
- **`unite(u, v, w)`** (enforce $p_v - p_u = w$):
  - If same root: check consistency — $diff[v] - diff[u]$ must equal $w$, else contradiction.
  - If different roots: attach root $rv$ under root $ru$, setting `diff[rv] = diff[u] - diff[v] + w` so that $p_v - p_u = w$ is preserved.

After `unite`, for any node $x$ in the merged component, calling `find(x)` gives the correct $p_x - p_{\text{root}}$ by accumulating diffs along the path.

### Recover the array

1. For each $i \in [0, n]$, call `find(i)` and read `diff[i]` (= $p_i - p_{\text{root}}$).
2. Compute $x_i = p_i - p_{i-1}$.

Since each DSU component's root has `diff = 0` (so $p_{\text{root}} = 0$ relative to itself), unconstrained nodes default to $p = 0$.

### Example

$n = 5, m = 3$: $(1,3,3), (3,5,3), (4,4,-1)$.

Constraints: $p_3 - p_0 = 3$, $p_5 - p_2 = 3$, $p_4 - p_3 = -1$.

| Constraint | `unite` call | DSU change |
|------------|-------------|------------|
| $p_3 - p_0 = 3$ | `unite(0, 3, 3)` | node 3 → root 0, `diff[3] = 3` |
| $p_5 - p_2 = 3$ | `unite(2, 5, 3)` | node 5 → root 2, `diff[5] = 3` |
| $p_4 - p_3 = -1$ | `unite(3, 4, -1)` | node 4 → root 0, `diff[4] = 2` |

After recovery: $p = [0, 0, 0, 3, 2, 3]$, so $x = [0, 0, 3, -1, 1]$.

Check: $0+0+3=3$ ✓, $3+(-1)+1=3$ ✓, $-1=-1$ ✓.

## Complexity

- **Time:** $O((n + m) \cdot \alpha(n))$
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Subarray%20Sum%20Constraints.cpp)
