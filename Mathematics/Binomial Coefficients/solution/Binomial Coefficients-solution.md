# Binomial Coefficients - Solution

**ID:** 1079 | **URL:** https://cses.fi/problemset/task/1079

## Approach

### Problem Restatement

Given $n$ queries, each computing $\binom{a}{b} \mod (10^9 + 7)$ with $0 \le b \le a \le 10^6$.

### Core Idea

By definition, $\binom{a}{b} = \frac{a!}{b! \cdot (a-b)!}$. Since factorials overflow and division doesn't work directly in modular arithmetic, we replace division by multiplication with modular inverse:

$$\binom{a}{b} \equiv a! \cdot (b!)^{-1} \cdot ((a-b)!)^{-1} \pmod{p}$$

where $p = 10^9 + 7$ is prime. Precompute two arrays up to $M = \max a$:

1. **Factorials:** $fact[i] = i! \mod p$
2. **Inverse factorials:** $inv\_f[i] = (i!)^{-1} \mod p$

**Modular inverse per element.** For prime $p$ and $1 \le i < p$, write $p = q \cdot i + r$ with $q = \lfloor p/i \rfloor$ and $r = p \bmod i$. Then:

$$q \cdot i + r \equiv 0 \pmod{p} \implies i^{-1} \equiv -q \cdot r^{-1} \pmod{p}$$

Since $r < i$, $inv[r]$ is already computed, giving the $O(1)$ recurrence:

$$inv[i] = p - \lfloor p/i \rfloor \cdot inv[p \bmod i] \bmod p$$

**Inverse factorials.** From $inv\_f[0] = 1$:

$$inv\_f[i] = inv\_f[i-1] \cdot inv[i] \bmod p$$

since $(i!)^{-1} = i^{-1} \cdot ((i-1)!)^{-1} = inv[i] \cdot inv\_f[i-1]$.

### Algorithm

1. Precompute $fact[i]$ for $i = 0, 1, \ldots, M$ where $M = \max a$.
2. Precompute $inv[i]$ and $inv\_f[i]$ for $i = 0, 1, \ldots, M$.
3. For each query $(a, b)$: output $fact[a] \cdot inv\_f[b] \cdot inv\_f[a-b] \bmod p$.

### Example

**Test 1:** $\binom{5}{3} = \frac{5!}{3! \cdot 2!} = \frac{120}{6 \cdot 2} = 10$. Output: `10`.

**Test 2:** $\binom{8}{1} = \frac{8!}{1! \cdot 7!} = 8$. Output: `8`.

**Test 3:** $\binom{9}{5} = \frac{9!}{5! \cdot 4!} = \frac{362880}{120 \cdot 24} = 126$. Output: `126`.

## Complexity

- **Time:** $O(M)$ precomputation + $O(1)$ per query, where $M = \max a$
- **Memory:** $O(M)$
