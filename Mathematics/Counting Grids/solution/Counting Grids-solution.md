# Counting Grids - Solution

**ID:** 2210 | **URL:** https://cses.fi/problemset/task/2210

## Approach

### Problem Restatement

Count distinct $n \times n$ grids ($1 \le n \le 10^9$), each cell black or white, up to rotation. Two grids are the same if one can be rotated to obtain the other. Output modulo $10^9+7$.

### Core Idea

Apply **Burnside's Lemma** with the rotation group $C_4 = \{0°, 90°, 180°, 270°\}$:

$$\text{answer} = \frac{1}{4} \sum_{g \in C_4} |X^g|$$

where $|X^g|$ is the number of grids invariant under rotation $g$. Each rotation partitions cells into **orbits**; cells in the same orbit must share a color for invariance, so $|X^g| = 2^{\text{number of orbits}}$.

**Rotation $0°$:** Every cell is its own orbit. $|X^{0°}| = 2^{n^2}$.

**Rotation $90°$ and $270°$:** Cell $(r,c)$ maps to $(c, n{+}1{-}r)$, forming orbits of size 4 (except the center cell when $n$ is odd, which is a fixed orbit of size 1). Number of orbits $= \lceil n^2/4 \rceil$. Since $90°$ and $270°$ have the same orbit structure: $|X^{90°}| = |X^{270°}| = 2^{\lceil n^2/4 \rceil}$.

**Rotation $180°$:** Cell $(r,c)$ maps to $(n{+}1{-}r, n{+}1{-}c)$, forming orbits of size 2 (except the center cell when $n$ is odd). Number of orbits $= \lceil n^2/2 \rceil$. $|X^{180°}| = 2^{\lceil n^2/2 \rceil}$.

**Final formula:**

$$\text{answer} = \frac{2^{n^2} + 2 \cdot 2^{\lceil n^2/4 \rceil} + 2^{\lceil n^2/2 \rceil}}{4} \pmod{10^9+7}$$

**Modular arithmetic.** Since $n \le 10^9$, exponents reach $10^{18}$. Reduce exponents modulo $\phi(10^9{+}7) = 10^9{+}6$ before computing $2^E \bmod (10^9{+}7)$ (Fermat's little theorem). Division by 4 uses the modular inverse $4^{-1} \equiv 250000002 \pmod{10^9+7}$.

### Algorithm

1. Compute $e_1 = n^2 \bmod (10^9{+}6)$, $e_2 = \lceil n^2/4 \rceil \bmod (10^9{+}6)$, $e_3 = \lceil n^2/2 \rceil \bmod (10^9{+}6)$.
2. Compute $v_1 = 2^{e_1}$, $v_2 = 2^{e_2}$, $v_3 = 2^{e_3}$, all modulo $10^9{+}7$.
3. Output $(v_1 + 2 \cdot v_2 + v_3) \cdot 250000002 \bmod (10^9{+}7)$.

### Example

$n = 4$:
- $|X^{0°}| = 2^{16} = 65536$
- $|X^{90°}| = |X^{270°}| = 2^{4} = 16$
- $|X^{180°}| = 2^{8} = 256$
- Answer $= (65536 + 32 + 256)/4 = 65824/4 = 16456$

## Complexity

- **Time:** $O(\log n)$ — modular exponentiation
- **Memory:** $O(1)$
