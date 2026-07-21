# Bracket Sequences I - Solution

**ID:** 2064 | **URL:** https://cses.fi/problemset/task/2064

## Approach

### Problem Restatement

Count the number of valid bracket sequences of length $n$ ($1 \le n \le 10^6$), modulo $10^9+7$. A bracket sequence is valid if at every prefix the number of opening brackets $\geq$ the number of closing brackets, and total counts are equal.

### Core Idea

If $n$ is odd, the answer is $0$. If $n = 2k$, the answer is the $k$-th **Catalan number**:

$$C_k = \frac{1}{k+1}\binom{2k}{k} = \frac{(2k)!}{k! \cdot (k+1)!}$$

**Proof (André's Reflection Principle).** The total number of sequences with $k$ opening and $k$ closing brackets is $\binom{2k}{k}$. To count the invalid ones, for each invalid sequence let $p$ be the first position where closing brackets exceed opening brackets. At position $p$, there are $m$ opening and $m+1$ closing brackets. Flip all brackets from position $p$ onward (opening $\leftrightarrow$ closing). The new sequence has $k-1$ opening and $k+1$ closing brackets. This is a bijection between invalid sequences and all sequences with $k-1$ opening and $k+1$ closing brackets, so the number of invalid sequences is $\binom{2k}{k-1}$.

$$C_k = \binom{2k}{k} - \binom{2k}{k-1} = \frac{(2k)!}{k! \cdot k!} \cdot \left(1 - \frac{k}{k+1}\right) = \frac{1}{k+1}\binom{2k}{k}$$

**Modular computation.** With $p = 10^9+7$ prime, precompute factorials $fact[i] = i! \bmod p$ and inverse factorials $inv\_f[i] = (i!)^{-1} \bmod p$ up to $n$. Then:

$$C_k = fact[n] \cdot inv\_f[k] \cdot inv\_f[k+1] \bmod p$$

### Algorithm

1. If $n$ is odd, output $0$.
2. Otherwise, let $k = n/2$. Output $fact[n] \cdot inv\_f[k] \cdot inv\_f[k+1] \bmod p$.

### Example

$n = 6$ ($k = 3$): $C_3 = \frac{1}{4}\binom{6}{3} = \frac{20}{4} = 5$. The 5 valid sequences: `((()))`, `(()())`, `(())()`, `()(())`, `()()()`.

## Complexity

- **Time:** $O(n)$ — precompute factorials and inverse factorials
- **Memory:** $O(n)$
