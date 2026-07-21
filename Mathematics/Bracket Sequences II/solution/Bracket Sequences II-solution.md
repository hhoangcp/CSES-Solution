# Bracket Sequences II - Solution

**ID:** 2187 | **URL:** https://cses.fi/problemset/task/2187

## Approach

### Problem Restatement

Given length $n$ and a prefix of `(` and `)`, count the number of ways to complete a valid bracket sequence of exact length $n$ starting with that prefix, modulo $10^9+7$.

### Core Idea

**Step 1: Analyze the prefix.** Let the prefix have length $L$. Compute the **balance** $k$ (opening minus closing) by scanning the prefix. If at any point $k < 0$, the prefix is invalid and the answer is $0$. If $n$ is odd, the answer is $0$.

**Step 2: Reduce to a counting subproblem.** After the prefix, there are $m = n - L$ positions to fill with balance $k$. We need $a$ additional opening and $b$ additional closing brackets where:

$$a = \frac{m - k}{2}, \quad b = \frac{m + k}{2}$$

If $m - k$ is odd or $a < 0$ or $b < 0$, the answer is $0$.

**Step 3: Generalized Ballot formula.** The problem reduces to counting lattice paths from $(0, k)$ to $(m, 0)$ using steps $+1$ (opening) and $-1$ (closing), never touching $y < 0$. By André's reflection principle:

$$f(m, k) = \binom{m}{a} - \binom{m}{a-1} = \frac{k+1}{m+1}\binom{m+1}{a}$$

*Proof.* Unrestricted paths from $(0, k)$ to $(m, 0)$: $\binom{m}{a}$. For each invalid path (touching $y = -1$), find the first such point and reflect the remainder (swap up $\leftrightarrow$ down). The reflected path goes to $(m, -2)$ with $a-1$ up-steps, giving $\binom{m}{a-1}$ such paths. The reflection is a bijection, so $f(m,k) = \binom{m}{a} - \binom{m}{a-1}$.

**Step 4: Recurrence computation.** Rather than the direct Ballot formula, compute via recurrence. Let $C[i]$ be the answer when $i$ additional opening brackets are needed, with current balance $k$:

$$C[i] = C[i-1] \cdot \frac{(2i+k-1)(2i+k)}{i \cdot (i+k+1)}$$

derived from the ratio of consecutive Ballot values. Base case: $C[0] = 1$.

### Algorithm

1. Scan prefix: compute balance $k$. If $k < 0$ at any point, output $0$.
2. If $n$ is odd, output $0$.
3. Compute $m = n - L$, $a = (m-k)/2$. If infeasible, output $0$.
4. Compute modular inverses up to $a + k + 1$.
5. Compute $C[0], C[1], \ldots, C[a]$ using the recurrence. Output $C[a]$.

### Example

$n = 6$, prefix `(()`. $L = 3$, $k = 1$. $m = 3$, $a = 1$.

$C[1] = C[0] \cdot \frac{(2+1-1)(2+1)}{1 \cdot (1+1+1)} = \frac{2 \cdot 3}{3} = 2$.

The 2 valid completions: `(())()` and `(()())`.

## Complexity

- **Time:** $O(n)$ — prefix scan + recurrence computation
- **Memory:** $O(n)$ — inverse and recurrence arrays
