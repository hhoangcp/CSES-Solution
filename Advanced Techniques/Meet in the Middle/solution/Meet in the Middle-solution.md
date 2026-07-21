# Meet in the Middle - Solution

**ID:** 1628 | **URL:** https://cses.fi/problemset/task/1628

## Approach

### Problem Restatement

Given an array of $n$ numbers, how many ways can you choose a subset of numbers with sum equal to $x$?

### Core Idea

With $n \le 40$, brute force over all $2^{40} \approx 10^{12}$ subsets is infeasible. **Meet in the Middle** splits the array into two halves of at most 20 elements each, reducing the search space to $2 \times 2^{20} \approx 2 \times 10^6$.

For each half, enumerate all subset sums into arrays $D_1$ and $D_2$. Every subset $S$ of the full array decomposes uniquely into $S_1 = S \cap \text{first half}$ and $S_2 = S \cap \text{second half}$, with $\text{sum}(S) = \text{sum}(S_1) + \text{sum}(S_2)$. So counting subsets with sum $x$ reduces to counting pairs $(v_1, v_2)$ with $v_1 \in D_1$, $v_2 \in D_2$, and $v_1 + v_2 = x$. Each such pair corresponds to exactly one subset, and every subset with sum $x$ is counted exactly once.

Sort both $D_1$ and $D_2$. Since $D_1$ is sorted ascending, $x - v$ decreases as $v$ increases, so a two-pointer sweep over $D_2$ (moving only leftward) counts the occurrences of each target value in $O(|D_1| + |D_2|)$.

### Algorithm

1. Split the array at $mid = \lfloor n/2 \rfloor$.
2. Enumerate all subset sums for each half (prune sums exceeding $x$).
3. Sort $D_1$ and $D_2$.
4. Sweep $D_1$ ascending; use two pointers on $D_2$ to count elements equal to $x - v$ for each $v \in D_1$.
5. Output the total count.

### Example

$n = 4$, $x = 5$, numbers: $[1, 2, 3, 2]$.

First half $[1, 2]$: $D_1 = [0, 1, 2, 3]$. Second half $[3, 2]$: $D_2 = [0, 2, 3, 5]$.

| $v \in D_1$ | Need $x - v$ | Count in $D_2$ | Subsets |
|-------------|-------------|-----------------|---------|
| 0 | 5 | 1 | $\emptyset + \{3,2'\}$ |
| 1 | 4 | 0 | — |
| 2 | 3 | 1 | $\{2\} + \{3\}$ |
| 3 | 2 | 1 | $\{1,2\} + \{2'\}$ |

Total: 3.

## Complexity

- **Time:** $O(2^{n/2} \cdot n/2 + 2^{n/2} \log 2^{n/2})$ — enumeration + sorting.
- **Memory:** $O(2^{n/2})$

## Code (C++)

[Solution Code](../code/Meet%20in%20the%20Middle.cpp)
