# Cyclic Array - Solution

**ID:** 1191 | **URL:** https://cses.fi/problemset/task/1191

## Problem Statement

Given a cyclic array of $n$ elements, split it into the minimum number of subarrays such that the sum of elements in each subarray does not exceed $k$.

## Approach

### 1. Handle cyclicity by doubling the array

Since the array is cyclic, the split point can be anywhere. A common technique is to double the array to $2n$ elements, converting the cyclic problem into a linear one.

- Create a new array: $a[1], a[2], \dots, a[n], a[1], a[2], \dots, a[n]$.
- Compute the prefix sum array $sum[i]$ to allow $O(1)$ range sum queries.

### 2. Compute the farthest jump (Greedy)

For each starting position $i$, we want to know the farthest endpoint of a subarray starting at $i$ such that the sum still $\leq k$.

- Let $next[i]$ be the position immediately after the last element of the subarray starting at $i$.
- $next[i]$ is found via binary search (`upper_bound`) on the prefix sum array such that $sum[next[i]-1] - sum[i-1] \leq k$.

### 3. Optimize with Binary Lifting

If we jump greedily step by step from $i \to next[i] \to next[next[i]]$, the complexity is $O(n^2)$ in the worst case. To optimize, we use a binary lifting table:

- `jump[i][j]`: The position reached after making $2^j$ subarray jumps starting from $i$.
- Formula: $jump[i][j] = jump[jump[i][j-1]][j-1]$.

### 4. Find the optimal solution

For each starting position $i \in [1, n]$, compute the minimum number of subarrays needed to cover a span of $n$ elements (i.e., reach position $\geq i + n$).

- Use the `jump` table to descend from the highest bit down to find the minimum number of jumps.
- The final answer is the smallest value found across all starting positions $i$.

### Proof of correctness

- **Greedy optimality:** In this segment-splitting problem, always choosing the longest possible segment at each step (greedy) never worsens the result compared to choosing a shorter segment, because a farther endpoint opens up more options for subsequent segments (Exchange Argument).
- **Binary lifting:** This is simply a way to accelerate the greedy jumping process from $O(n)$ to $O(\log n)$ per starting position.

## Complexity

- **Time:** $O(n \log n)$ — includes building the binary lifting table and performing $n$ queries each taking $O(\log n)$.
- **Memory:** $O(n \log n)$ to store the `jump` table.

## Example

$n=5$, $k=10$, $a = [3, 5, 2, 4, 1]$.

### Step 1: Double the array and compute prefix sums

Doubled array: $[3, 5, 2, 4, 1, 3, 5, 2, 4, 1]$

Prefix sums: $[3, 8, 10, 14, 15, 18, 23, 25, 29, 30]$.

### Step 2: Compute next[i] (farthest start of next segment)

Find the first position where $sum[j] > sum[i-1] + k$:

| $i$ | $sum[i-1]+k$ | $next[i]$ | Subarray  | Sum |
|-----|--------------|-----------|------------|-----|
| 1   | 10           | 4         | $[3,5,2]$  | 10  |
| 2   | 13           | 4         | $[5,2]$    | 7   |
| 3   | 18           | 7         | $[2,4,1,3]$| 10  |
| 4   | 20           | 7         | $[4,1,3]$  | 8   |
| 5   | 24           | 8         | $[1,3,5]$  | 9   |

### Step 3: Binary Lifting

Try starting position $i=1$:
- Jump 1: $1 \to next[1]=4$, segment $[3,5,2]$.
- Jump 2: $4 \to next[4]=7$, segment $[4,1,3]$. Reached $7 \ge 1+5=6$.

Only **2 subarrays** needed. Trying other starting positions also yields a minimum of 2.

**Result: 2.**

### Problem Statement Example

$n=8$, $k=5$, $a = [2, 2, 2, 1, 3, 1, 2, 1]$.

#### Step 1: Double the array and compute prefix sums

Doubled array: $[2, 2, 2, 1, 3, 1, 2, 1, 2, 2, 2, 1, 3, 1, 2, 1]$

Prefix sums: $[2, 4, 6, 7, 10, 11, 13, 14, 16, 18, 20, 21, 24, 25, 27, 28]$.

#### Step 2: Compute next[i]

| $i$ | $sum[i-1]+k$ | $next[i]$ | Subarray  | Sum |
|-----|--------------|-----------|------------|-----|
| 1   | 5            | 3         | $[2,2]$    | 4   |
| 2   | 7            | 5         | $[2,2,1]$  | 5   |
| 3   | 9            | 5         | $[2,1]$    | 3   |
| 4   | 11           | 7         | $[1,3,1]$  | 5   |
| 5   | 12           | 7         | $[3,1]$    | 4   |
| 6   | 15           | 9         | $[1,2,1]$  | 4   |
| 7   | 16           | 10        | $[2,1,2]$  | 5   |
| 8   | 18           | 11        | $[1,2,2]$  | 5   |

#### Step 3: Binary Lifting

Try starting position $i=2$:
- Jump 1: $2 \to next[2]=5$, segment $[2,2,1]$.
- Jump 2: $5 \to next[5]=7$, segment $[3,1]$.
- Jump 3: $7 \to next[7]=10$, segment $[2,1,2]$. Reached $10 \ge 2+8=10$.

Only **3 subarrays** needed. Trying other starting positions also yields a minimum of 3.

**Result: 3.**

## Code (C++)

[Solution Code](../code/Cyclic%20Array.cpp)
