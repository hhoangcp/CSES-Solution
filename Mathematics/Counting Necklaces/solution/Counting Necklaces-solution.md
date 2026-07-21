# Counting Necklaces - Solution

**ID:** 2209 | **URL:** https://cses.fi/problemset/task/2209

## Approach

### Problem Restatement

Count distinct necklaces of $n$ beads ($1 \le n \le 10^6$), each colored with one of $m$ colors ($1 \le m \le 10^6$), up to rotation. Output modulo $10^9+7$.

### Core Idea

Apply **Burnside's Lemma** with the rotation group $\mathbb{Z}_n = \{r_0, r_1, \ldots, r_{n-1}\}$:

$$\text{answer} = \frac{1}{n} \sum_{i=0}^{n-1} |X^{r_i}|$$

where $|X^{r_i}|$ is the number of colorings invariant under rotation by $i$ positions.

**Counting invariant colorings.** Rotation $r_i$ maps position $j$ to $j + i \pmod{n}$, dividing the $n$ positions into cycles. Each cycle has length $n / \gcd(n, i)$, so the number of cycles is $\gcd(n, i)$. All positions in the same cycle must share a color for invariance, giving:

$$|X^{r_i}| = m^{\gcd(n, i)}$$

*Proof of cycle count.* The cycle of position $j$ has length equal to the smallest $t$ with $t \cdot i \equiv 0 \pmod{n}$, i.e., $t = n/\gcd(n,i)$. Since all cycles have equal length, the number of cycles is $n/(n/\gcd(n,i)) = \gcd(n,i)$.

**Final formula:**

$$\text{answer} = \frac{1}{n} \sum_{i=0}^{n-1} m^{\gcd(n, i)}$$

**Optimization with Euler's totient.** Group terms by $d = \gcd(n, i)$. For $d \mid n$, the count of $i \in [0, n{-}1]$ with $\gcd(n, i) = d$ is $\varphi(n/d)$, giving:

$$\text{answer} = \frac{1}{n} \sum_{d \mid n} \varphi(n/d) \cdot m^d$$

With $n \le 10^6$, direct iteration in $O(n \log n)$ suffices.

Division by $n$ uses modular inverse: $n^{-1} \equiv n^{p-2} \pmod{10^9+7}$.

### Algorithm

1. For $i = 0$ to $n-1$: accumulate $m^{\gcd(n,i)} \bmod (10^9{+}7)$.
2. Multiply the sum by $n^{-1} \bmod (10^9{+}7)$.

### Example

$n = 4$, $m = 3$:

| $i$ | $\gcd(4, i)$ | $m^{\gcd(4,i)}$ |
|:---:|:---:|:---:|
| 0 | 4 | $3^4 = 81$ |
| 1 | 1 | $3^1 = 3$ |
| 2 | 2 | $3^2 = 9$ |
| 3 | 1 | $3^1 = 3$ |

Answer $= (81 + 3 + 9 + 3)/4 = 96/4 = 24$.

## Complexity

- **Time:** $O(n \log n)$ — $n$ iterations, each computing $\gcd$ and modular exponentiation
- **Memory:** $O(1)$
