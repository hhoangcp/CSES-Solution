# Water Containers Queries - Solution

**ID:** 3214 | **URL:** https://cses.fi/problemset/task/3214

## Problem Statement

For multiple queries, determine whether it is possible to measure $x$ units of water in container $A$ using two containers of capacities $a$ and $b$.

## Approach

### Bezout's Lemma

Amount $x$ in container $A$ is achievable iff $0 \leq x \leq a$ and $\gcd(a, b) \mid x$.

**Necessary:** Every operation (FILL, EMPTY, MOVE) changes $u_a$ by a multiple of $\gcd(a, b)$ (since $a$ and $b$ are multiples of $d = \gcd(a, b)$, and by induction $u_a, u_b$ remain multiples of $d$). So any achievable $u_a$ must be a multiple of $d$.

**Sufficient:** The repeated FILL A → MOVE A→B → EMPTY B pattern simulates the Euclidean algorithm, producing every multiple of $d$ in container $A$.

### Algorithm

For each query $(a, b, x)$:
- If $x > a$: `NO`.
- Else if $x \mod \gcd(a, b) = 0$: `YES`.
- Else: `NO`.

### Example

| $a$ | $b$ | $x$ | $\gcd(a,b)$ | $x \leq a$? | $x \mod g = 0$? | Result |
|-----|-----|-----|-------------|-------------|-----------------|--------|
| 5 | 3 | 4 | 1 | ✓ | ✓ | YES |
| 1 | 1 | 2 | 1 | ✗ | — | NO |
| 2 | 2 | 1 | 2 | ✓ | ✗ | NO |
| 123 | 456 | 42 | 3 | ✓ | ✓ | YES |

## Complexity

- **Time:** $O(\log(\min(a, b)))$ per query for GCD
- **Memory:** $O(1)$

## Code (C++)

[Solution Code](../code/Water%20Containers%20Queries.cpp)
