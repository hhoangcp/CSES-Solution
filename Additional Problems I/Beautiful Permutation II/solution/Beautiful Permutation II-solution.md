# Beautiful Permutation II - Solution

**ID:** 3175 | **URL:** https://cses.fi/problemset/task/3175

## Problem Statement

A permutation of the integers $1,2,\ldots,n$ is called *beautiful* if no two adjacent elements differ by $1$. Find the lexicographically smallest beautiful permutation. If no such permutation exists, print "NO SOLUTION".

## Approach

### 1. Analyze existence and proof

- **$n = 1$:** The permutation $[1]$ trivially satisfies the condition since there are no adjacent pairs.

- **$n = 2, 3$:** For $n = 2$, the set of permutations is $\{[1,2], [2,1]\}$, both containing adjacent consecutive numbers. For $n = 3$, every Hamiltonian path on the graph of numbers $1 \dots 3$ (with edges connecting two numbers whose difference is not $1$) cannot cover all 3 vertices (the only such edge is $1-3$). Therefore, no solution exists.

- **$n \geq 4$:** A solution always exists. Proof: Consider the "Odd - Even" split structure — place all odd numbers in increasing order first, then all even numbers in increasing order (e.g., $n = 5 \to [1, 3, 5, 2, 4]$). The gap between two consecutive odd numbers or two consecutive even numbers is always $2$. At the boundary between the last odd number and the first even number ($2$), the difference is $|(2\lceil n/2 \rceil - 1) - 2|$. For $n \geq 4$, this value is always $\geq 2$, ensuring the permutation is beautiful.

### 2. Algorithm for lexicographically smallest permutation

To find the lexicographically smallest result, we apply **Backtracking** with the following rules:

- **Priority order:** At each position $i$ in the permutation (from left to right), we always try the smallest unused number $x$ in the set $\{1, 2, \dots, n\}$.
- **Local constraint:** The number $x$ can only be chosen if $|x - \text{previous element}| \neq 1$.
- **Proof of optimality:** Since the search space is explored in increasing order of values at each position, the first valid configuration that the algorithm reaches is guaranteed to be the lexicographically smallest. Specifically: at the first position, the algorithm tries the smallest value first; if a beautiful permutation starting with this value exists, it will be found, and this permutation is smaller than any starting with a larger value. Otherwise, the algorithm tries the next larger value. The same logic applies recursively at each subsequent position.
- **Pruning:** As soon as a branch cannot select any number satisfying the adjacency constraint, we backtrack immediately. Due to the nature of beautiful permutations, invalid branches are typically eliminated early, making the algorithm efficient in practice.

### Example

$n = 5$: Smallest beautiful permutation is $[1, 3, 5, 2, 4]$.

- $|1 - 3| = 2 \neq 1$ $\checkmark$
- $|3 - 5| = 2 \neq 1$ $\checkmark$
- $|5 - 2| = 3 \neq 1$ $\checkmark$
- $|2 - 4| = 2 \neq 1$ $\checkmark$

$n = 3$: No solution, output "NO SOLUTION".

## Complexity

- **Time:** $O(n!)$ in theory, but very fast in practice thanks to strong pruning constraints from the beautiful permutation property.
- **Memory:** $O(n)$ for storing the used-number state array and the recursion stack.

## Code (C++)

[Solution Code](../code/Beautiful%20Permutation%20II.cpp)
