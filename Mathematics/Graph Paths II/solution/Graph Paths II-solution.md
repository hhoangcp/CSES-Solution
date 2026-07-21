# Graph Paths II - Solution

**ID:** 1724 | **URL:** https://cses.fi/problemset/task/1724

## Approach

### Problem Restatement

Given a directed weighted graph with $n$ vertices and $m$ edges, find the shortest path from vertex $1$ to vertex $n$ using **exactly** $k$ edges. If no such path exists, output $-1$.

### Core idea

Use **min-plus matrix multiplication** (also called distance product) instead of standard matrix multiplication:

$$C[i][j] = \min_{\ell=1}^{n}(A[i][\ell] + B[\ell][j])$$

$C[i][j]$ represents the shortest path combining two consecutive segments: from $i$ to intermediate vertex $\ell$ (via $A$), then from $\ell$ to $j$ (via $B$).

**Key property:** With min-plus multiplication, $(A^k)[i][j]$ gives the shortest path using exactly $k$ edges from $i$ to $j$.

**Proof by induction:** Base case $k=1$: $A[i][j]$ is the minimum edge weight from $i$ to $j$ (or $\infty$ if no edge exists). Inductive step: assume $A^{k-1}[i][\ell]$ gives the shortest $(k-1)$-edge path from $i$ to $\ell$. Then $A^k[i][j] = \min_\ell(A^{k-1}[i][\ell] + A[\ell][j])$. Every $k$-edge path from $i$ to $j$ must pass through some intermediate vertex $\ell$ at the last step: a $(k-1)$-edge path from $i$ to $\ell$ plus one edge from $\ell$ to $j$. Taking the minimum over all $\ell$ yields the shortest $k$-edge path.

Min-plus multiplication is associative: $(A \cdot B) \cdot C = A \cdot (B \cdot C)$, since both give $\min_{\ell_1, \ell_2}(A[i][\ell_1] + B[\ell_1][\ell_2] + C[\ell_2][j])$. Therefore, binary exponentiation applies, computing $A^k$ in $O(n^3 \log k)$.

### Algorithm

1. Initialize matrix $A$ where $A[i][j]$ = minimum edge weight from $i$ to $j$ (take minimum for parallel edges), or $\infty$ if no edge exists. Note: $A[i][i]$ is not 0 — a 0-edge path is invalid since $k \geq 1$.
2. Compute $A^k$ using binary exponentiation with min-plus multiplication.
3. Output $(A^k)[1][n]$ if it is not $\infty$, otherwise $-1$.

### Example

$n = 3$, $m = 4$, $k = 8$. Edges: $1 \to 2$ (weight 5), $2 \to 3$ (weight 4), $3 \to 1$ (weight 1), $3 \to 2$ (weight 2).

$$A = \begin{pmatrix} \infty & 5 & \infty \\ \infty & \infty & 4 \\ 1 & 2 & \infty \end{pmatrix}$$

After computing $A^8$ via binary exponentiation, $(A^8)[1][3] = 27$. The optimal path is $1 \to 2 \to 3 \to 2 \to 3 \to 2 \to 3 \to 2 \to 3$ with total cost $5 + 4 + 2 + 4 + 2 + 4 + 2 + 4 = 27$. Note that going $3 \to 2$ directly (cost 2) is cheaper than going $3 \to 1 \to 2$ (cost $1 + 5 = 6$), so the optimal path avoids returning to vertex 1.

## Complexity

- **Time:** $O(n^3 \log k)$
- **Space:** $O(n^2)$

## Code (C++)

[Solution Code](../code/Graph%20Paths%20II.cpp)
