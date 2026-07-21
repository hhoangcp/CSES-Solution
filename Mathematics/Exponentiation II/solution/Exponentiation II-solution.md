# Exponentiation II - Solution

**ID:** 1712 | **URL:** https://cses.fi/problemset/task/1712

## Approach

### Problem Restatement

Compute $a^{b^c} \bmod (10^9+7)$ for $n$ queries ($1 \le n \le 10^5$, $0 \le a, b, c \le 10^9$), with the convention $0^0 = 1$.

### Core Idea

The exponent $b^c$ can reach $10^{9 \cdot 10^9}$ — impossible to compute directly. By **Fermat's Little Theorem**, since $p = 10^9+7$ is prime and $a^{p-1} \equiv 1 \pmod{p}$ when $\gcd(a, p) = 1$, we can reduce the exponent modulo $p-1$:

$$a^{b^c} \equiv a^{b^c \bmod (p-1)} \pmod{p} \quad \text{(when } \gcd(a, p) = 1\text{)}$$

*Proof.* Write $b^c = q(p-1) + r$ with $r = b^c \bmod (p-1)$. Then $a^{b^c} = (a^{p-1})^q \cdot a^r \equiv a^r \pmod{p}$.

### Edge Cases

The formula $a^{b^c} \equiv a^{b^c \bmod (p-1)} \pmod{p}$ **fails** when $p \mid a$ and $b^c \bmod (p-1) = 0$ but $b^c > 0$, because it would compute $a^0 = 1$ instead of the correct $0$. Since $a \le 10^9 < p$, the only case with $p \mid a$ is $a = 0$.

**Case analysis for $a = 0$:**

| $b$ | $c$ | $b^c$ | $a^{b^c} = 0^{b^c}$ | Explanation |
|:---:|:---:|:------:|:--------------------:|:------------|
| $0$ | $0$ | $1$ | $0^1 = 0$ | $0^0 = 1$ by convention, so $0^{0^0} = 0^1$ |
| $0$ | $>0$ | $0$ | $0^0 = 1$ | Convention $0^0 = 1$ |
| $>0$ | $0$ | $1$ | $0^1 = 0$ | |
| $>0$ | $>0$ | $>0$ | $0^+ = 0$ | |

The only case yielding $1$ is $a = 0, b = 0, c > 0$. In all other cases with $a = 0$, the answer is $0$.

**Fix for $a > 0$:** When $e = b^c \bmod (p-1) = 0$, either $b^c = 0$ (if $b = 0, c > 0$) or $b^c$ is a positive multiple of $p-1$. In both cases, $a^{b^c} \equiv 1 \pmod{p}$ (since $a^0 = 1$ and $a^{k(p-1)} = (a^{p-1})^k \equiv 1$ by FLT). We replace $e = 0$ with $e = p-1$: since $a^{p-1} \equiv 1 \equiv a^0 \pmod{p}$, the answer is the same.

### Algorithm

1. For each query $(a, b, c)$:
   - If $a = 0$: output $1$ if $b = 0$ and $c > 0$, otherwise $0$.
   - If $a > 0$: compute $e = b^c \bmod (10^9{+}6)$ via binary exponentiation. If $e = 0$, set $e = 10^9{+}6$. Compute $a^e \bmod (10^9{+}7)$ via binary exponentiation.

### Example

**Test 1:** $3^{7^1} = 3^7 = 2187$. $7^1 \bmod (10^9{+}6) = 7$, $3^7 \bmod (10^9{+}7) = 2187$.

**Test 2:** $15^{2^2} = 15^4 = 50625$. $2^2 \bmod (10^9{+}6) = 4$, $15^4 \bmod (10^9{+}7) = 50625$.

**Test 3:** $3^{4^5}$. $4^5 = 1024$, $1024 \bmod (10^9{+}6) = 1024$, $3^{1024} \bmod (10^9{+}7) = 763327764$.

## Complexity

- **Time:** $O(\log c + \log b)$ per query — two binary exponentiations
- **Memory:** $O(1)$
