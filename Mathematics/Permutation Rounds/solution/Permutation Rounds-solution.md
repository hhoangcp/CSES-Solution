# Permutation Rounds - Solution

**ID:** 3398 | **URL:** https://cses.fi/problemset/task/3398

## Approach

### Problem Restatement

Given a sorted array $[1, 2, \ldots, n]$ and a permutation $p_1, p_2, \ldots, p_n$. Each round, the element at position $i$ moves to position $p_i$. Find the minimum number of rounds for the array to return to its initial state, modulo $10^9+7$.

### Core idea

Any permutation decomposes uniquely into **disjoint cycles**. An element in a cycle of length $L$ returns to its starting position after exactly a multiple of $L$ rounds. For the entire array to return to its initial state, every element must return simultaneously, so the number of rounds must be a common multiple of all cycle lengths. The minimum is:

$$\text{Result} = \text{lcm}(L_1, L_2, \ldots, L_t)$$

**Proof:** Necessity — after $k$ rounds, an element in a cycle of length $L_i$ returns iff $L_i \mid k$. For all elements to return, $k$ must be a common multiple. Minimality gives LCM. Sufficiency — LCM is divisible by every $L_i$, so all elements return after LCM rounds.

Since the answer can be very large, compute LCM modulo $10^9+7$ via **prime factorization**. For each cycle length $L_i$, factorize it and track the maximum exponent for each prime across all lengths. Then:

$$\text{LCM} = \prod_p p^{\max_i(e_p(L_i))} \pmod{10^9+7}$$

This avoids the need for modular division (which would be problematic since LCM may exceed $10^9+7$ before reduction).

### Algorithm

1. Build a linear sieve to get the smallest prime factor of each number up to $n$.
2. Traverse the permutation to find all cycle lengths.
3. For each cycle length, factorize it using the sieve and update the maximum exponent for each prime.
4. Compute the answer as $\prod_p p^{\max\_e[p]} \pmod{10^9+7}$.

### Example

$p = [5, 3, 2, 6, 4, 1, 8, 7]$, $n = 8$.

Cycles: $1 \to 5 \to 4 \to 6 \to 1$ (length 4), $2 \to 3 \to 2$ (length 2), $7 \to 8 \to 7$ (length 2).

Factorizations: $4 = 2^2$, $2 = 2^1$, $2 = 2^1$. Max exponent of 2 is 2.

$\text{LCM} = 2^2 = 4$ $\checkmark$.

After 4 rounds, the array returns to $[1, 2, 3, 4, 5, 6, 7, 8]$.

## Complexity

- **Time:** $O(n)$ for cycle finding + $O(n \log \log n)$ for sieve + $O(\sum \log L_i)$ for factorization
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Permutation%20Rounds.cpp)
