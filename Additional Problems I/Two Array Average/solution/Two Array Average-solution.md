# Two Array Average - Solution

**ID:** 3361 | **URL:** https://cses.fi/problemset/task/3361

## Problem Statement

Given two arrays of $n$ integers, choose a non-empty prefix from each array such that the average of all selected numbers is maximized.

## Approach

### Binary search on the result

The average when choosing prefix $i$ from $A$ and prefix $j$ from $B$ is:

$$\frac{\text{prefA}[i] + \text{prefB}[j]}{i + j}$$

Check whether the maximum average $\geq x$:

$$\frac{\text{prefA}[i] + \text{prefB}[j]}{i + j} \geq x \iff (\text{prefA}[i] - xi) + (\text{prefB}[j] - xj) \geq 0$$

For fixed $x$, the two terms are independent. So the check reduces to:

$$\max_i(\text{prefA}[i] - xi) + \max_j(\text{prefB}[j] - xj) \geq 0$$

The check function is monotone (if average $\geq x$ is achievable, so is $\geq x'$ for any $x' < x$), so binary search is valid. Run 80 iterations for $10^{-6}$ precision, tracking the best $(i, j)$.

### Example

$n = 4$, $A = [1, 5, 5, 2]$, $B = [3, 1, 3, 1]$.

$\text{prefA} = [1, 6, 11, 13]$, $\text{prefB} = [3, 4, 7, 8]$.

Best: prefix 3 from $A$ and prefix 1 from $B$: $\frac{11 + 3}{3 + 1} = 3.5$.

Result: `3 1`.

## Complexity

- **Time:** $O(n \cdot \text{iterations})$ — with 80 iterations
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Two%20Array%20Average.cpp)
