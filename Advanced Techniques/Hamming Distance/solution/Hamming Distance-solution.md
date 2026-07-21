# Hamming Distance - Solution

**ID:** 2136 | **URL:** https://cses.fi/problemset/task/2136

## Approach

### Problem Restatement

The Hamming distance between two strings $a$ and $b$ of equal length is the number of positions where they differ. Given $n$ bit strings of length $k$, find the minimum Hamming distance between any two strings.

### Core Idea

Since $k \le 30$, each bit string fits in a 32-bit integer. Encode each string as an integer where bit $j$ is set if position $j$ is '1'. The Hamming distance between two strings then equals $\text{popcount}(a_i \oplus a_j)$: XOR produces 1-bits at exactly the positions where the two strings differ, and popcount counts those positions.

With $n \le 2 \times 10^4$, there are $\binom{n}{2} \approx 2 \times 10^8$ pairs. Each XOR + popcount takes ~1 CPU cycle with hardware support, so the brute-force approach runs in ~0.2 seconds — fast enough.

### Algorithm

1. Encode each bit string as a 32-bit integer.
2. For all pairs $(i, j)$, $i < j$: compute $\operatorname{popcount}(a[i] \oplus a[j])$ and track the minimum.
3. Output the minimum.

### Example

5 strings of length 6: `110111`, `001000`, `100001`, `101000`, `101110`.

- `101000` vs `001000`: differ only at position 0 → Hamming distance = 1.
- `110111` vs `001000`: differ at all 6 positions → distance = 6.
- `100001` vs `101000`: differ at positions 2 and 5 → distance = 2.

Minimum = 1.

## Complexity

- **Time:** $O(n^2)$ — with hardware popcount, the constant is very small.
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Hamming%20Distance.cpp)
