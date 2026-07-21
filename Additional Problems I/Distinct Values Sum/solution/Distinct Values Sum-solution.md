# Distinct Values Sum - Solution

**ID:** 3150 | **URL:** https://cses.fi/problemset/task/3150

## Problem Statement

Given an array $x_1, x_2, \dots, x_n$. Let $d(a,b)$ be the number of distinct values in the subarray from index $a$ to $b$. Compute the sum of all $d(a,b)$ for every pair $1 \le a \le b \le n$.

## Approach

### 1. Change perspective: Count by value

Instead of examining each subarray and counting distinct values, we consider each distinct value $v$ and count how many subarrays contain this value.

- If value $v$ appears at least once in subarray $[a, b]$, it contributes $1$ to $d(a, b)$.
- The desired sum: $S = \sum_{v \in \text{distinct values}} (\text{number of subarrays containing at least one } v)$.

### 2. Complementary counting

To count the number of subarrays containing at least one $v$, we take the total number of subarrays minus the number of subarrays **not containing** $v$.

- Total number of subarrays of an array of length $n$: $\frac{n(n+1)}{2}$.
- A subarray **does not contain** $v$ if it lies entirely within a "gap" between consecutive occurrences of $v$.

### 3. Implementation steps

1. Store the positions of each value $v$ in a list (using `std::map<int, std::vector<int>>`).
2. For each value $v$, identify the gaps:
   - First gap: from the start of the array to the first occurrence of $v$.
   - Middle gaps: between two consecutive positions $p_i$ and $p_{i+1}$ of $v$.
   - Last gap: from the last occurrence of $v$ to the end of the array.
3. If a gap has length $g$, the number of subarrays entirely within it is $\frac{g(g+1)}{2}$.
4. Accumulate the result for all distinct values.

## Example walkthrough

Array: `1 2 3 1 1`, $n=5$. Total subarrays: $\frac{5 \times 6}{2} = 15$.

- **Value 1:** Positions $\{1, 4, 5\}$.
  - Gaps: before $1$ (length $0$), between $1$ and $4$ (length $2$, elements $\{2, 3\}$), between $4$ and $5$ (length $0$), after $5$ (length $0$).
  - Subarrays not containing $1$: $\frac{2 \times 3}{2} = 3$.
  - Subarrays containing $1$: $15 - 3 = 12$.
- **Value 2:** Positions $\{2\}$.
  - Gaps: before $2$ (length $1$), after $2$ (length $3$).
  - Subarrays not containing $2$: $\frac{1 \times 2}{2} + \frac{3 \times 4}{2} = 1 + 6 = 7$.
  - Subarrays containing $2$: $15 - 7 = 8$.
- **Value 3:** Positions $\{3\}$.
  - Gaps: before $3$ (length $2$), after $3$ (length $2$).
  - Subarrays not containing $3$: $\frac{2 \times 3}{2} + \frac{2 \times 3}{2} = 3 + 3 = 6$.
  - Subarrays containing $3$: $15 - 6 = 9$.

**Total:** $12 + 8 + 9 = 29$.

## Complexity

- **Time:** $O(n \log n)$ — time spent classifying element positions using `map` or sorting.
- **Memory:** $O(n)$ — storing position lists for each element.

## Code (C++)

[Solution Code](../code/Distinct%20Values%20Sum.cpp)
