# Divisor Analysis - Solution

**ID:** 2182 | **URL:** https://cses.fi/problemset/task/2182

## Approach

### Problem Restatement

Given $n = x_1^{k_1} \cdot x_2^{k_2} \cdots x_m^{k_m}$ in prime factorization form, compute: (1) number of divisors, (2) sum of divisors, (3) product of divisors, all modulo $10^9+7$.

### Core Idea

**Number of divisors.** Each divisor has the form $x_1^{e_1} \cdots x_m^{e_m}$ with $0 \le e_i \le k_i$, giving $k_i + 1$ independent choices per factor:

$$d(n) = \prod_{i=1}^{m}(k_i + 1) \pmod{10^9+7}$$

**Sum of divisors.** By multiplicativity, the divisor sum factors over prime powers. For $x_i^{k_i}$, the sum is a geometric series:

$$\sigma(n) = \prod_{i=1}^{m} \frac{x_i^{k_i+1} - 1}{x_i - 1} \pmod{10^9+7}$$

Division by $x_i - 1$ uses modular inverse ($x_i \ge 2$ is prime, so $x_i - 1 \ge 1$).

**Product of divisors.** Let $D = d(n)$. Divisors come in pairs $(d, n/d)$ with product $n$, so the product of all divisors is $n^{D/2}$. More precisely: if $D$ is even, there are $D/2$ pairs each with product $n$; if $D$ is odd, the middle divisor is $\sqrt{n}$ and the product is $n^{(D-1)/2} \cdot \sqrt{n} = n^{D/2}$.

**Computing $n^{D/2} \bmod p$.** Rather than computing $n^{D/2}$ directly (where $D/2$ may not be an integer), compute the exponent contribution of each $x_i$ separately. The total exponent of $x_i$ across all $D$ divisors is:

$$e_i = \frac{k_i(k_i+1)}{2} \cdot \frac{D}{k_i+1} = \frac{k_i \cdot D}{2}$$

*Proof.* There are $D/(k_i+1)$ divisors with exponent $j$ of $x_i$, for each $j = 0, \ldots, k_i$. Sum: $\frac{D}{k_i+1} \cdot \sum_{j=0}^{k_i} j = \frac{D}{k_i+1} \cdot \frac{k_i(k_i+1)}{2} = \frac{k_i \cdot D}{2}$.

To compute $\frac{D}{k_i+1} = \prod_{j \ne i}(k_j+1)$ modulo $\phi(p) = 10^9+6$, use prefix/suffix products of $(k_j+1)$. Then the product of divisors is:

$$\prod_{i=1}^{m} x_i^{e_i} \pmod{p}$$

where $e_i = \frac{k_i(k_i+1)}{2} \cdot \prod_{j \ne i}(k_j+1) \bmod \phi(p)$.

### Algorithm

1. Compute $D = \prod (k_i+1) \bmod p$.
2. Compute prefix/suffix products of $(k_i+1)$ modulo $\phi(p)$.
3. For each $i$: compute $e_i = \frac{k_i(k_i+1)}{2} \cdot \text{Pre}[i{-}1] \cdot \text{Suf}[i{+}1] \bmod \phi(p)$, then multiply $x_i^{e_i} \bmod p$.
4. Compute sum using geometric series formula with modular inverses.

### Example

$n = 12 = 2^2 \cdot 3^1$:

- Number: $(2+1)(1+1) = 6$
- Sum: $\frac{2^3-1}{2-1} \cdot \frac{3^2-1}{3-1} = 7 \cdot 4 = 28$
- Product: $e_1 = \frac{2 \cdot 3}{2} \cdot 2 = 6$, $e_2 = \frac{1 \cdot 2}{2} \cdot 3 = 3$ → $2^6 \cdot 3^3 = 64 \cdot 27 = 1728$

## Complexity

- **Time:** $O(m \log k_{\max})$ — modular exponentiation per factor
- **Memory:** $O(m)$ — prefix/suffix arrays
