# Counting LCM Arrays - Solution

**ID:** 3169 | **URL:** https://cses.fi/problemset/task/3169

## Problem Statement

Count the number of arrays $a_1, a_2, \ldots, a_n$ of positive integers such that the Least Common Multiple (LCM) of every two consecutive elements always equals $k$, i.e., $\operatorname{lcm}(a_i, a_{i+1}) = k$ for all $1 \leq i < n$. Return the result modulo $10^9 + 7$.

## Approach

### 1. Analyze the LCM condition

For $\operatorname{lcm}(a_i, a_{i+1}) = k$ to hold, every element $a_i$ must be a divisor of $k$.

Consider the prime factorization of $k$:
$$k = p_1^{e_1} p_2^{e_2} \cdots p_r^{e_r}$$

For each prime factor $p_j$, let $f_{i,j}$ denote the exponent of $p_j$ in $a_i$. The LCM condition is equivalent to:
$$\max(f_{i,j}, f_{i+1,j}) = e_j$$

That is, among two consecutive elements, **at least one** must have the exponent of $p_j$ exactly equal to $e_j$.

### 2. Independence across prime factors

Due to the properties of LCM, the condition for each prime factor $p_j$ is completely independent of the others. The total number of valid arrays is the **product** of the counts satisfying the condition for each prime factor $p_j$.

### 3. Dynamic programming and matrix exponentiation

For a prime factor $p$ with exponent $e$ in $k$, we need to count the number of ways to choose a sequence of exponents $f_1, f_2, \dots, f_n$ such that $0 \le f_i \le e$ and $\max(f_i, f_{i+1}) = e$.

Define:
- $f_i$: Number of ways to fill the sequence up to position $i$ with $f_i = e$ (exactly 1 way to choose the exponent value).
- $g_i$: Number of ways to fill the sequence up to position $i$ with $f_i < e$ ($e$ ways to choose the exponent from $0, 1, \dots, e-1$).

**Recurrence:**
- $f_i = f_{i-1} + g_{i-1}$ (If $f_i = e$, the previous element can be any value in $[0, e]$).
- $g_i = f_{i-1} \cdot e$ (If $f_i < e$, the previous element $f_{i-1}$ must equal $e$ to satisfy $\max(f_{i-1}, f_i) = e$).

**Matrix representation:**
$$\begin{pmatrix} f_i \\ g_i \end{pmatrix} = \begin{pmatrix} 1 & 1 \\ e & 0 \end{pmatrix} \begin{pmatrix} f_{i-1} \\ g_{i-1} \end{pmatrix}$$

With base case at $n=1$: $f_1 = 1$ and $g_1 = e$. We use **matrix exponentiation** to compute the state at $n$ in $O(\log n)$.

## Example

For $n=3, k=4 = 2^2$ ($e=2$):

- Matrix $M = \begin{pmatrix} 1 & 1 \\ 2 & 0 \end{pmatrix}$.
- $M^{3-1} = M^2 = \begin{pmatrix} 3 & 1 \\ 2 & 2 \end{pmatrix}$.
- $\begin{pmatrix} f_3 \\ g_3 \end{pmatrix} = \begin{pmatrix} 3 & 1 \\ 2 & 2 \end{pmatrix} \begin{pmatrix} 1 \\ 2 \end{pmatrix} = \begin{pmatrix} 5 \\ 6 \end{pmatrix}$.
- Total ways: $5 + 6 = 11$ (Matches the sample).

## Complexity

- **Time:** $O(\sqrt{k} + r \cdot \log n)$, where $r$ is the number of distinct prime factors of $k$ (at most about 9-10 for $k \le 10^9$).
- **Memory:** $O(1)$ (excluding the output array storage).

## Code (C++)

[Solution Code](../code/Counting%20LCM%20Arrays.cpp)
