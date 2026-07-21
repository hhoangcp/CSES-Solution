# Missing Number - Solution

**ID:** 1083 | **URL:** https://cses.fi/problemset/task/1083

## Approach

### Problem Restatement

Given $n - 1$ distinct integers from the set $\{1, 2, \ldots, n\}$ ($2 \le n \le 2 \times 10^5$), find the only missing number.

### Core Idea

Three standard approaches, all $O(n)$ time:

**1. Marking array (used in code):** Mark each present number in a boolean array of size $n+1$. With $n-1$ distinct numbers from $\{1, \ldots, n\}$, exactly one position remains unmarked — the answer. Space: $O(n)$.

**2. XOR:** Compute $(1 \oplus 2 \oplus \cdots \oplus n) \oplus (a_1 \oplus a_2 \oplus \cdots \oplus a_{n-1})$. Each present number $x$ appears in both sets and cancels ($x \oplus x = 0$); the missing number $m$ appears only in the first set and survives. The prefix XOR $1 \oplus \cdots \oplus n$ can be computed in $O(1)$ using the pattern: $n \bmod 4 = 0 \to n$, $1 \to 1$, $2 \to n+1$, $3 \to 0$. Space: $O(1)$, no overflow risk.

**3. Sum subtraction:** $\text{missing} = \frac{n(n+1)}{2} - \sum a_i$. Since the input contains all of $\{1, \ldots, n\}$ except $m$, the sum of input equals $\frac{n(n+1)}{2} - m$. Space: $O(1)$, but requires 64-bit integers since $\frac{n(n+1)}{2}$ can reach $\approx 2 \times 10^{10}$.

### Algorithm

For the marking array method (as in the code):
1. Create array `mark[1..n]` initialized to 0.
2. For each input number $x$, increment `mark[x]`.
3. Find and output the index $i$ where `mark[i] == 0`.

### Example

$n = 5$, input: `2 3 1 5`. Missing number is **4**.
- Marking: positions 1, 2, 3, 5 are marked; position 4 is unmarked.
- XOR: $(1 \oplus 2 \oplus 3 \oplus 4 \oplus 5) \oplus (2 \oplus 3 \oplus 1 \oplus 5) = 4$.
- Sum: $15 - 11 = 4$.

## Complexity

- **Time:** $O(n)$
- **Space:** $O(n)$ (marking); $O(1)$ (XOR or sum)

## Code (C++)

[Solution Code](../code/Missing%20Number.cpp)
