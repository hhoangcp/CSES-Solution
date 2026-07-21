# Collecting Numbers Distribution - Solution

**ID:** 3157 | **URL:** https://cses.fi/problemset/task/3157

## Approach

### Problem Restatement

For each $k = 1, 2, \ldots, n$, count the number of permutations of $\{1, \ldots, n\}$ requiring exactly $k$ rounds to collect all numbers in increasing order (scanning left-to-right each round, collecting consecutive numbers). Output modulo $10^9 + 7$.

### Rounds and descents

Let $\text{pos}[x]$ denote the position of value $x$ in the permutation. A new round is forced at value $x+1$ precisely when $\text{pos}[x+1] < \text{pos}[x]$ — the next number appears to the left, so we've already passed it. Call this a **descent** (of the position function). The total number of rounds is:

$$\text{rounds} = 1 + (\text{number of } x \in \{1, \ldots, n-1\} \text{ where } \text{pos}[x+1] < \text{pos}[x])$$

Equivalently, this is 1 plus the number of descents in the inverse permutation $p^{-1}$. Since the map $p \mapsto p^{-1}$ is a bijection on $S_n$, the number of permutations with $j$ descents in their inverse equals the number with $j$ descents in $p$ itself — both are counted by the **Eulerian number** $A(n, j)$.

Thus the answer for $k$ rounds is $A(n, k-1)$.

### Eulerian numbers and the recurrence

$A(n, j)$ counts permutations of $\{1, \ldots, n\}$ with exactly $j$ descents. It satisfies:

$$A(n, j) = (j+1) \cdot A(n-1, j) + (n-j) \cdot A(n-1, j-1)$$

**Proof by inserting element $n$:** Take a permutation of $\{1, \ldots, n-1\}$ and insert $n$ at some position. Since $n$ is the largest element, inserting $n$ at an interior position always creates one new ascent (left neighbor $< n$) and one new descent ($n >$ right neighbor), while replacing the original relationship at that gap.

- **Preserving $j$ descents** (from a permutation with $j$ descents): Insert $n$ right after an existing descent, or at the end. Inserting after a descent replaces the descent pair $a > b$ with $a < n > b$ (one ascent + one descent, net 0 change). Inserting at the end adds only an ascent. Total: $j + 1$ positions.

- **Adding one descent** (from a permutation with $j-1$ descents): Insert $n$ after an ascent, or at the beginning. Inserting after an ascent replaces the ascent pair $a < b$ with $a < n > b$ (net +1 descent). Inserting at the beginning adds only a descent. Total: $(n-1-(j-1)) + 1 = n - j$ positions.

### Examples

**Problem example:** $n = 3$.

| $k$ | Descents | Permutations | $A(3, k-1)$ |
|-----|----------|-------------|-------------|
| 1 | 0 | $[1,2,3]$ | $A(3,0) = 1$ |
| 2 | 1 | $[1,3,2],\ [2,1,3],\ [2,3,1],\ [3,1,2]$ | $A(3,1) = 4$ |
| 3 | 2 | $[3,2,1]$ | $A(3,2) = 1$ |

**Verifying the recurrence** for $A(3,1)$: $(1+1) \cdot A(2,1) + (3-1) \cdot A(2,0) = 2 \cdot 1 + 2 \cdot 1 = 4$. ✓

Total: $1 + 4 + 1 = 6 = 3!$. ✓

## Complexity

- **Time:** $O(n^2)$ — building the $n \times n$ DP table.
- **Space:** $O(n^2)$ — for the DP table (reducible to $O(n)$ using two rows).

## Code (C++)

[Solution Code](../code/Collecting%20Numbers%20Distribution.cpp)
