# Apples and Bananas - Solution

**ID:** 2111 | **URL:** https://cses.fi/problemset/task/2111

## Approach

### Problem Restatement

Given $n$ apples and $m$ bananas, each with integer weight in $[1, k]$. For each total weight $w \in [2, 2k]$, count the number of ways to choose one apple and one banana such that their total weight equals $w$. Two fruits of the same type with the same weight are considered distinct.

### Core Idea

Let $A[i]$ be the number of apples with weight $i$, $B[j]$ be the number of bananas with weight $j$. The answer for weight $w$ is:

$$\text{ans}[w] = \sum_{\substack{i+j=w \\ 1 \le i,j \le k}} A[i] \cdot B[j]$$

This is exactly the **discrete convolution** of arrays $A$ and $B$, which corresponds to polynomial multiplication. If we construct $P(x) = \sum_{i} A[i] x^i$ and $Q(x) = \sum_{j} B[j] x^j$, then the coefficient of $x^w$ in $P \cdot Q$ equals $\sum_{i+j=w} A[i] B[j]$.

Naive convolution takes $O(k^2)$, too slow. **FFT** computes polynomial multiplication in $O(n \log n)$ where $n$ is the smallest power of 2 $\ge 2k+1$. The correctness follows from the **convolution theorem**: if $R(x) = P(x) \cdot Q(x)$, then at each root of unity $\omega^k$: $R(\omega^k) = P(\omega^k) \cdot Q(\omega^k)$. Thus the point-value representation of $R$ is obtained by element-wise multiplication. Inverse FFT then recovers the coefficients. Since $A[i]=0$ for $i>k$ and $B[j]=0$ for $j>k$, the maximum nonzero coefficient index is $2k$, so choosing $h \ge 2k+1$ avoids aliasing.

### Algorithm

1. Build arrays $A$ and $B$ of size $h$ (smallest power of 2 $\ge 2k+1$), where $A[i]$ counts apples of weight $i$, $B[j]$ counts bananas of weight $j$.
2. Apply forward FFT to $A$ and $B$, converting from coefficient representation to point-value representation.
3. Multiply the two point-value representations element-wise: $C[i] = A[i] \cdot B[i]$.
4. Apply inverse FFT to $C$ to obtain the coefficient-form result.
5. For $w$ from 2 to $2k$, output $\text{round}(C[w].a)$.

### Example

$k=5$, apples: $[5, 2, 5]$, bananas: $[4, 3, 2, 3]$.

Frequency arrays (index 0–5):

| $i$ | 0 | 1 | 2 | 3 | 4 | 5 |
|-----|---|---|---|---|---|---|
| $A[i]$ | 0 | 0 | 1 | 0 | 0 | 2 |
| $B[i]$ | 0 | 0 | 1 | 2 | 1 | 0 |

Convolution results ($w$ from 2 to $2k{=}10$):

- $w=4$: $A[2] \cdot B[2] = 1 \cdot 1 = 1$
- $w=5$: $A[2] \cdot B[3] = 1 \cdot 2 = 2$
- $w=6$: $A[2] \cdot B[4] = 1 \cdot 1 = 1$
- $w=7$: $A[5] \cdot B[2] = 2 \cdot 1 = 2$
- $w=8$: $A[5] \cdot B[3] = 2 \cdot 2 = 4$
- $w=9$: $A[5] \cdot B[4] = 2 \cdot 1 = 2$

(All other $w$ yield 0.)

Output: `0 0 1 2 1 2 4 2 0`

## Complexity

- **Time:** $O(k \log k)$
- **Memory:** $O(k)$

## Code (C++)

[Solution Code](../code/Apples%20and%20Bananas.cpp)
