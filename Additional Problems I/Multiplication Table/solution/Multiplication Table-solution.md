# Multiplication Table - Solution

**ID:** 2422 | **URL:** https://cses.fi/problemset/task/2422

## Problem Statement

Given an $n \times n$ multiplication table (where $n$ is odd), find the median element when all $n^2$ elements of the table are sorted in increasing order.

## Approach

### 1. Problem analysis

- The $n \times n$ multiplication table has $n^2$ elements in total. Since $n$ is odd, $n^2$ is also odd.
- The middle element is at position $p = \frac{n^2 + 1}{2}$ in the sorted sequence.
- With $n$ up to $10^6$, we cannot create an array of $n^2$ ($10^{12}$) elements as it would exceed memory limits. Therefore, we use **Binary Search on Value**.

### 2. Binary search on the result value

We need to find the smallest value $x$ such that at least $p$ elements in the multiplication table have value $\le x$.

- Search range: $l = 1$, $r = n^2$.
- Counting function: To count how many elements in the table are $\le x$, iterate through each row $i$ from $1$ to $n$.
  - In row $i$, the values are: $i \times 1, i \times 2, \dots, i \times n$.
  - The number of elements $\le x$ in row $i$ is $\min(n, \lfloor x/i \rfloor)$.
  - Total elements $\le x$ in the entire table: $Leq = \sum_{i=1}^{n} \min(n, \lfloor x/i \rfloor)$.

### 3. Implementation procedure

1. Compute the target position $p = (n^2 + 1) / 2$.
2. Perform binary search with $mid = (l + r) / 2$.
3. Compute the total count $Leq \le mid$ by iterating through $n$ rows.
4. If $Leq \ge p$, the median may be $mid$ or smaller ($ans = mid, r = mid - 1$).
5. If $Leq < p$, the median must be greater than $mid$ ($l = mid + 1$).

## Example walkthrough

For $n = 3$, multiplication table:
$$
\begin{matrix}
1 & 2 & 3 \\
2 & 4 & 6 \\
3 & 6 & 9 \\
\end{matrix}
$$

- Median position $p = (3^2 + 1) / 2 = 5$.
- Try $mid = 3$:
  - Row 1: $\min(3, 3/1) = 3$ (values 1, 2, 3).
  - Row 2: $\min(3, 3/2) = 1$ (value 2).
  - Row 3: $\min(3, 3/3) = 1$ (value 3).
  - Total $Leq = 3 + 1 + 1 = 5$.
- Since $Leq = 5$ equals the target position, the smallest satisfying result is **3**.

## Complexity

- **Time:** $O(n \log(n^2))$ — The binary search loop runs $\log(n^2)$ times, each time iterating through $n$ rows to count.
- **Memory:** $O(1)$ — Only a few integer variables are used, independent of array size.

## Code (C++)

[Solution Code](../code/Multiplication%20Table.cpp)
