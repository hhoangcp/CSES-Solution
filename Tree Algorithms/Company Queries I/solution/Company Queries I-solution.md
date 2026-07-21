# Company Queries I - Solution

**ID:** 1687 | **URL:** https://cses.fi/problemset/task/1687

## Approach

### Problem Restatement

A company has $n$ employees forming a tree hierarchy, with employee $1$ as the general director (root). Every other employee has exactly one direct boss. Process $q$ queries, each $(x, k)$ asking for the boss $k$ levels higher (i.e. the $k$-th ancestor) of employee $x$. If none exists (the jump passes the general director), print $-1$.

**Constraints:** $1 \le n, q \le 2 \cdot 10^5$, $1 \le k \le n$.

### Core idea

If each query walks one step at a time up to the direct boss, the cost is $O(k) = O(n)$, totaling $O(q \cdot n)$ — too slow. **Binary lifting** precomputes jumps whose lengths are powers of $2$ ($1, 2, 4, 8, \dots$), answering each query in $O(\log n)$.

Let $par[u][i]$ be the $2^i$-th ancestor of employee $u$. The transition is:

$$par[u][i] = par[par[u][i-1]][i-1]$$

— a $2^i$-step jump is a $2^{i-1}$-step jump to an intermediate boss, followed by another $2^{i-1}$-step jump. The table is filled during a DFS from the root. Since $n \le 2 \cdot 10^5$, the tree height is at most $n$, so $\lceil \log_2 n \rceil = 18$ levels suffice; set $LOG = 18$.

**Correctness (induction on $i$):** For $i = 0$, $par[u][0]$ is the direct parent, exactly the $2^0 = 1$-st ancestor. For $i > 0$, the $2^i$-th ancestor of $u$ is the $2^{i-1}$-th ancestor of the $2^{i-1}$-th ancestor of $u$, so by the inductive hypothesis the correct value is $par[par[u][i-1]][i-1]$. When answering a query, the binary representation gives $k = \sum_{i \in S} 2^i$ (unique); jumping $2^i$ steps for each set bit $i$ (from high bit to low) moves exactly $k$ steps in total, landing on the $k$-th ancestor. If at any step $u$ reaches $0$, the root has been passed and the answer is $-1$.

### Algorithm

1. Read $n, q$; build the tree's adjacency list from the $n-1$ direct bosses. Set $par[1][0] = 0$ (the root has no parent).
2. DFS from the root $1$:
   - For each $i$ from $1$ to $18$: $par[u][i] = par[par[u][i-1]][i-1]$.
   - For each child $v$ of $u$ (excluding the parent): set $par[v][0] = u$, then DFS($v$).
3. For each query $(x, k)$:
   - Set $\text{ans} = x$. Iterate $i$ from $18$ down to $0$: if bit $i$ of $k$ is set ($k \wedge (1 \ll i) \ne 0$), set $\text{ans} = par[\text{ans}][i]$.
   - If $\text{ans} = 0$, print $-1$; otherwise print $\text{ans}$.

### Example

The problem statement gives $n = 5$, $q = 3$, with bosses $e_2 = 1,\ e_3 = 1,\ e_4 = 3,\ e_5 = 3$. Tree: node $1$ is the root; children of $1$ are $\{2, 3\}$; children of $3$ are $\{4, 5\}$.

Table $par[\cdot][0]$ (direct parent): $par[1][0]=0,\ par[2][0]=1,\ par[3][0]=1,\ par[4][0]=3,\ par[5][0]=3$.

Table $par[\cdot][1]$ (2nd ancestor): $par[1][1]=0,\ par[2][1]=0,\ par[3][1]=0,\ par[4][1]=1,\ par[5][1]=1$.

- Query $(4, 1)$: $k = 1 = 2^0$. Jump $2^0$ from $4$: $\text{ans} = par[4][0] = 3$. Print $3$.
- Query $(4, 2)$: $k = 2 = 2^1$. Jump $2^1$ from $4$: $\text{ans} = par[4][1] = 1$. Print $1$.
- Query $(4, 3)$: $k = 3 = 2^0 + 2^1$. Jump $2^1$ from $4$: $\text{ans} = par[4][1] = 1$; then jump $2^0$ from $1$: $\text{ans} = par[1][0] = 0$. Print $-1$.

Output: `3`, `1`, `-1` — matching the problem's example.

## Complexity

- **Time:** $O((n + q) \log n)$ — preprocessing $O(n \log n)$, each query $O(\log n)$.
- **Memory:** $O(n \log n)$ — the $par$ table of size $n \times (LOG + 1)$.

## Code (C++)

[Solution Code](../code/Company%20Queries%20I.cpp)
