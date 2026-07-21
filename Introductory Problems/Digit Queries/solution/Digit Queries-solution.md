# Digit Queries - Solution

**ID:** 2431 | **URL:** https://cses.fi/problemset/task/2431

## Approach

### Problem Restatement

The infinite string $S = \text{"123456789101112131415..."}$ is formed by concatenating all positive integers. Given $q$ queries ($1 \le q \le 1000$), each with position $k$ ($1 \le k \le 10^{18}$), find the $k$-th digit in $S$.

### Core Idea

Since $k$ can be up to $10^{18}$, we cannot construct $S$. Instead, we exploit its structure: $S$ consists of consecutive groups of numbers with the same digit count.

| Group | Numbers | Count | Total Digits |
|-------|---------|-------|--------------|
| 1-digit | 1--9 | 9 | 9 |
| 2-digit | 10--99 | 90 | 180 |
| $d$-digit | $10^{d-1}$--$10^d-1$ | $9 \times 10^{d-1}$ | $9 \times 10^{d-1} \times d$ |

The count formula comes from: $d$-digit numbers range from $10^{d-1}$ to $10^d-1$, giving $9 \times 10^{d-1}$ numbers, each contributing $d$ digits.

**Three-step approach:**

1. **Find the digit group:** Subtract group sizes from $k$ until $k$ falls within the current group of $d$-digit numbers. This works because after removing all digits from shorter groups, the remaining $k$ is a 1-indexed position within the $d$-digit group.

2. **Find the specific number:** The first $d$-digit number is $10^{d-1}$. Each number occupies $d$ positions, so the target number is $\text{num} = 10^{d-1} + \lfloor(k-1)/d\rfloor$. The $(k-1)$ offset and integer division correctly map $k$ to the number containing that position.

3. **Extract the digit:** The digit index within the number is $\text{pos} = (k-1) \bmod d$ (0-indexed from left). Extract by dividing by $10^{d-1-\text{pos}}$ and taking modulo 10.

### Algorithm

1. Precompute powers of 10 up to $10^{18}$.
2. For each query $k$:
   - Subtract $9 \times 10^{d-1} \times d$ from $k$ while $k$ exceeds it, incrementing $d$.
   - Compute $\text{num} = 10^{d-1} + (k-1)/d$.
   - Compute $\text{pos} = (k-1) \bmod d$.
   - Extract the digit at position $\text{pos}$ from $\text{num}$.
3. Output the digit.

### Example

From the sample:
- $k = 7$: In 1-digit group. $\text{num} = 1 + 6/1 = 7$, $\text{pos} = 0$. Digit = **7**.
- $k = 19$: Subtract 9 → $k = 10$ in 2-digit group. $\text{num} = 10 + 9/2 = 14$, $\text{pos} = 1$. Digit at position 1 of "14" = **4**.
- $k = 12$: Subtract 9 → $k = 3$ in 2-digit group. $\text{num} = 10 + 2/2 = 11$, $\text{pos} = 0$. Digit at position 0 of "11" = **1**.

## Complexity

- **Time:** $O(\log k)$ per query — the group loop runs at most 18 times
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Digit%20Queries.cpp)
