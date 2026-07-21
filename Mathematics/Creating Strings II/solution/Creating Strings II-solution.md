# Creating Strings II - Solution

**ID:** 1715 | **URL:** https://cses.fi/problemset/task/1715

## Approach

### Problem Restatement

Given a string of length $n$ ($1 \le n \le 10^6$) with characters `a`–`z`, count the number of distinct permutations. Output modulo $10^9+7$.

### Core Idea

Let $c_1, c_2, \ldots, c_{26}$ be the frequencies of each character ($\sum c_i = n$). If all characters were distinct, there would be $n!$ permutations. With repeated characters, permuting within each group of $c_i$ identical characters yields $c_i!$ identical arrangements, so the answer is the **multinomial coefficient**:

$$\frac{n!}{c_1! \cdot c_2! \cdot \ldots \cdot c_{26}!}$$

*Proof.* Sequential position selection: choose $c_1$ positions for character 1 in $\binom{n}{c_1}$ ways, then $c_2$ positions from the remaining $n - c_1$ in $\binom{n-c_1}{c_2}$ ways, and so on. The product telescopes to $\frac{n!}{c_1! \cdot c_2! \cdot \ldots \cdot c_{26}!}$.

**Modular computation.** With $p = 10^9+7$ prime, replace division by multiplication with modular inverse:

$$\frac{n!}{\prod c_i!} \equiv n! \cdot \prod (c_i!)^{-1} \pmod{p}$$

Precompute $fact[i] = i! \bmod p$ and $inv\_f[i] = (i!)^{-1} \bmod p$ up to $n$, using the linear inverse recurrence. Then:

$$\text{answer} = fact[n] \cdot \prod_{i: c_i > 0} inv\_f[c_i] \bmod p$$

### Algorithm

1. Read string, count character frequencies.
2. Precompute $fact$ and $inv\_f$ up to $n$.
3. Compute $fact[n] \cdot \prod inv\_f[c_i] \bmod p$.

### Example

String `aabac`: $n = 5$, frequencies $c_a = 3, c_b = 1, c_c = 1$.

$$\text{answer} = \frac{5!}{3! \cdot 1! \cdot 1!} = \frac{120}{6} = 20$$

## Complexity

- **Time:** $O(n)$ — counting frequencies + precomputing factorials
- **Memory:** $O(n)$ — factorial and inverse factorial arrays
