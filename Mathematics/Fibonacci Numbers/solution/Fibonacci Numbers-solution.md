# Fibonacci Numbers - Solution

**ID:** 1722 | **URL:** https://cses.fi/problemset/task/1722

## Approach

### Problem Restatement

Compute $F_n \bmod (10^9+7)$ where $F_0 = 0$, $F_1 = 1$, $F_n = F_{n-1} + F_{n-2}$, and $0 \le n \le 10^{18}$.

### Core Idea

With $n$ up to $10^{18}$, $O(n)$ iteration is infeasible. Use **matrix exponentiation** in $O(\log n)$.

Define $\mathbf{v}_n = \begin{pmatrix} F_{n+1} \\ F_n \end{pmatrix}$. Then:

$$\mathbf{v}_n = \begin{pmatrix} F_n + F_{n-1} \\ F_n \end{pmatrix} = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} \begin{pmatrix} F_n \\ F_{n-1} \end{pmatrix} = A \cdot \mathbf{v}_{n-1}$$

where $A = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}$. Unrolling: $\mathbf{v}_n = A^n \cdot \mathbf{v}_0 = A^n \begin{pmatrix} 1 \\ 0 \end{pmatrix}$. So $F_n$ is the element at position $(1,0)$ of $A^n$.

*Correctness (induction).* $A^n = \begin{pmatrix} F_{n+1} & F_n \\ F_n & F_{n-1} \end{pmatrix}$. Base: $A^1 = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} = \begin{pmatrix} F_2 & F_1 \\ F_1 & F_0 \end{pmatrix}$. Step: $A^{n+1} = A \cdot A^n = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} \begin{pmatrix} F_{n+1} & F_n \\ F_n & F_{n-1} \end{pmatrix} = \begin{pmatrix} F_{n+2} & F_{n+1} \\ F_{n+1} & F_n \end{pmatrix}$.

**Binary matrix exponentiation.** Compute $A^n$ via divide-and-conquer:

$$A^n = \begin{cases} I & n = 0 \\ (A^{n/2})^2 & n \text{ even} \\ (A^{(n-1)/2})^2 \cdot A & n \text{ odd} \end{cases}$$

Each $2 \times 2$ matrix multiplication is $O(1)$. Total: $O(\log n)$.

### Algorithm

1. Initialize $R = I$ (identity), $B = A$.
2. While $n > 0$: if $n$ is odd, $R \gets R \cdot B$; $B \gets B \cdot B$; $n \gets n/2$.
3. Output $R[1][0] \bmod (10^9+7)$.

### Example

$n = 10$: $A^{10} = \begin{pmatrix} 89 & 55 \\ 55 & 34 \end{pmatrix}$, so $F_{10} = 55$.

## Complexity

- **Time:** $O(\log n)$ — each step is a $2 \times 2$ matrix multiplication
- **Memory:** $O(1)$
