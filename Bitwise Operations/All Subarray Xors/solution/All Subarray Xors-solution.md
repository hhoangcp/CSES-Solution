# All Subarray Xors - Solution

**ID:** 3233 | **URL:** https://cses.fi/problemset/task/3233

## Approach

### Problem Restatement

Given an array of $n$ integers, find all distinct values that are the XOR of some subarray, and print them in increasing order.

### Core idea

The XOR of subarray $[l, r]$ equals $\text{pre}[r] \oplus \text{pre}[l-1]$, where $\text{pre}[i]$ is the prefix XOR. Thus the problem reduces to finding all values $\text{pre}[i] \oplus \text{pre}[j]$ with $j < i$. This is XOR convolution of the prefix frequency array with itself, computable in $O(MAX \cdot H)$ via the Fast Walsh-Hadamard Transform (FWHT).

### Algorithm

1. **Prefix XOR:** Compute $\text{pre}[0] = 0$, $\text{pre}[i] = x_1 \oplus \cdots \oplus x_i$. Build frequency array $f[v]$ = count of prefix values equal to $v$.
2. **XOR convolution via FWHT:**
   - Apply forward FWHT: transform $f$ into $\hat{f}$.
   - Square each element: $\hat{f}[i] = \hat{f}[i]^2$.
   - Apply inverse FWHT: recover $\text{numX}[v] = \sum_{a \oplus b = v} f[a] \cdot f[b]$.

   The forward transform at each step with length $len$: $\hat{f}[i] = f[i] + f[i + len]$, $\hat{f}[i + len] = f[i] - f[i + len]$. Inverse transform is similar, then divide by $2^H$. This works because the Walsh-Hadamard transform diagonalizes XOR convolution: $\widehat{f * g}[i] = \hat{f}[i] \cdot \hat{g}[i]$, so squaring in the transform domain computes XOR self-convolution.

3. **Adjust result:** $\text{numX}[v]$ counts ordered pairs $(i, j)$ including self-pairs. Adjust:
   - Subtract $n + 1$ from $\text{numX}[0]$ to remove self-pairs ($\text{pre}[i] \oplus \text{pre}[i] = 0$).
   - Divide all $\text{numX}[v]$ by 2 to convert ordered pairs to unordered pairs ($j < i$).
   - Every $v > 0$ with $\text{numX}[v] > 0$ is a valid subarray XOR.

### Example

Input: $n = 4$, array $[5, 1, 5, 9]$.

Prefix XOR: $[0, 5, 4, 1, 8]$. Frequency: $f[0]{=}f[1]{=}f[4]{=}f[5]{=}f[8]{=}1$.

All pairs $(j < i)$ and their XOR:
- $(0,1)$: $5 \oplus 0 = 5$
- $(0,2)$: $4 \oplus 0 = 4$
- $(0,3)$: $1 \oplus 0 = 1$
- $(0,4)$: $8 \oplus 0 = 8$
- $(1,2)$: $4 \oplus 5 = 1$
- $(1,3)$: $1 \oplus 5 = 4$
- $(1,4)$: $8 \oplus 5 = 13$
- $(2,3)$: $1 \oplus 4 = 5$
- $(2,4)$: $8 \oplus 4 = 12$
- $(3,4)$: $8 \oplus 1 = 9$

Distinct non-zero values: $\{1, 4, 5, 8, 9, 12, 13\}$ → **7 values**.

## Complexity

- **Time:** $O(n + 2^{20} \cdot 20)$ — FWHT dominates
- **Space:** $O(2^{20})$

## Code (C++)

[Solution Code](../code/All%20Subarray%20Xors.cpp)
