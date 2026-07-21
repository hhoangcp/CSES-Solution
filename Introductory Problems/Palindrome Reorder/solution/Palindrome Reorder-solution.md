# Palindrome Reorder - Solution

**ID:** 1755 | **URL:** https://cses.fi/problemset/task/1755

## Approach

### Problem Restatement

Given a string of length $n$ ($1 \le n \le 10^6$) consisting of uppercase letters A–Z, reorder its characters to form a palindrome. If impossible, print "NO SOLUTION".

### Core Idea

A palindrome reads the same forward and backward, so every character not at the center must appear in a symmetric pair. This means:
- If $n$ is even: every character frequency must be even.
- If $n$ is odd: exactly one character can have an odd frequency (placed at the center); all others must be even.

If the number of odd-frequency characters exceeds 0 (even $n$) or 1 (odd $n$), no palindrome exists.

**Construction:** Use two pointers `L = 1` and `R = n`. For each character with frequency $\geq 2$, place one copy at `L` and one at `R`, then move the pointers inward. Repeat until the character's count drops below 2. If one character remains (odd frequency, $n$ odd), place it at the center position $\lfloor(n+1)/2\rfloor$.

**Correctness:** Each pair is placed at positions $L$ and $R$ where $L + R = n + 1$, so position $i$ always matches position $n+1-i$. The center character (if any) is trivially symmetric. Every character is placed exactly its frequency count times, so the result uses all $n$ characters.

### Algorithm

1. Count the frequency of each character.
2. Check validity: count characters with odd frequency. If invalid, output "NO SOLUTION".
3. Build the palindrome with two pointers, placing characters in pairs from both ends.
4. If $n$ is odd, place the remaining odd-frequency character at the center.

### Example

Input: `AAAACACBA` ($n = 9$). Frequencies: A=6, C=2, B=1. One odd frequency (B), $n$ odd → valid.

| Step | Character | L | R | String State |
|------|-----------|---|---|--------------|
| 1 | A (pair 1) | 1 | 9 | `A _ _ _ _ _ _ _ A` |
| 2 | A (pair 2) | 2 | 8 | `A A _ _ _ _ _ A A` |
| 3 | A (pair 3) | 3 | 7 | `A A A _ _ _ A A A` |
| 4 | C (pair 1) | 4 | 6 | `A A A C _ C A A A` |
| 5 | B (center) | 5 | 5 | `A A A C B C A A A` |

Output: `AAACBCAAA` (a valid palindrome).

## Complexity

- **Time:** $O(n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Palindrome%20Reorder.cpp)
