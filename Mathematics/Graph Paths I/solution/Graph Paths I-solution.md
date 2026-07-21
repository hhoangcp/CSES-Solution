# Graph Paths I - Solution

**ID:** 1723 | **URL:** https://cses.fi/problemset/task/1723

## Approach

### Problem Restatement

Given a directed graph with $n$ vertices and $m$ edges, count the number of paths from vertex 1 to vertex $n$ with exactly $k$ edges, modulo $10^9+7$.

### Core Idea

Let $A$ be the adjacency matrix, where $A[i][j]$ = number of edges from $i$ to $j$. Then $(A^k)[i][j]$ counts the number of paths with exactly $k$ edges from $i$ to $j$.

*Proof (induction on $k$).* Base: $A^1[i][j]$ counts 1-edge paths (by definition). Step: assume $(A^{k-1})[i][\ell]$ counts $(k{-}1)$-edge paths from $i$ to $\ell$. Then:

$$(A^k)[i][j] = \sum_{\ell=1}^{n} (A^{k-1})[i][\ell] \cdot A[\ell][j]$$

Each $k$-edge path from $i$ to $j$ decomposes uniquely into a $(k{-}1)$-edge path from $i$ to an intermediate vertex $\ell$, followed by one edge from $\ell$ to $j$. Summing over all $\ell$ counts every such path exactly once.

**Binary matrix exponentiation.** Since $k$ can be up to $10^9$, compute $A^k$ via divide-and-conquer:

$$A^k = \begin{cases} I & k = 0 \\ (A^{k/2})^2 & k \text{ even} \\ A \cdot (A^{(k-1)/2})^2 & k \text{ odd} \end{cases}$$

Each $n \times n$ matrix multiplication costs $O(n^3)$, and binary exponentiation requires $O(\log k)$ multiplications.

### Algorithm

1. Build the adjacency matrix $A$ from the input edges.
2. Compute $A^k$ using binary matrix exponentiation, taking modulo $10^9+7$ after each multiplication.
3. Output $(A^k)[1][n]$.

### Example

$n = 3$, $m = 4$, $k = 8$, edges: $1{\to}2$, $2{\to}3$, $3{\to}1$, $3{\to}2$.

$$A = \begin{pmatrix} 0 & 1 & 0 \\ 0 & 0 & 1 \\ 1 & 1 & 0 \end{pmatrix}, \quad A^8 = \begin{pmatrix} 3 & 4 & 2 \\ 2 & 3 & 4 \\ 4 & 6 & 3 \end{pmatrix}$$

$(A^8)[1][3] = 2$. The two paths: $1{\to}2{\to}3{\to}1{\to}2{\to}3{\to}1{\to}2{\to}3$ and $1{\to}2{\to}3{\to}2{\to}3{\to}2{\to}3{\to}2{\to}3$.

## Complexity

- **Time:** $O(n^3 \log k)$
- **Memory:** $O(n^2)$
