# Gray Code - Solution

**ID:** 2205 | **URL:** https://cses.fi/problemset/task/2205

## Approach

### Problem Restatement

Generate all $2^n$ bit strings of length $n$ ($1 \le n \le 16$) such that any two consecutive strings differ in exactly one bit (a Gray code sequence).

### Core Idea

Two methods can construct a Gray code sequence:

**Method 1: Reflection (used in code).** Build $G(n)$ from $G(n-1)$: prepend "0" to each string in $G(n-1)$ for the first half, then prepend "1" to each string in reversed $G(n-1)$ for the second half. Formula: $G(n) = 0 \cdot G(n-1) + 1 \cdot \overline{G(n-1)}$.

*Correctness:* Within each half, consecutive strings differ in exactly 1 bit because their suffixes come from consecutive elements of $G(n-1)$ (or its reverse), which differ in 1 bit by the inductive hypothesis. At the boundary, the last string of the first half ($0 \cdot a_{last}$) and the first string of the second half ($1 \cdot a_{last}$) share identical suffixes and differ only in the leading bit.

**Method 2: Direct formula.** The $i$-th Gray code (0-indexed) is $g(i) = i \oplus (i \gg 1)$. When $i \to i+1$, the only bit that changes in the Gray code corresponds to the lowest set bit of $i+1$ — all other changes in $i$ and $i \gg 1$ cancel out under XOR. Thus consecutive codes differ in exactly 1 bit.

### Algorithm

1. Start with $G = \{"0", "1"\}$.
2. For each step from 2 to $n$: duplicate $G$ in reverse order with prefix "1" and append; prepend "0" to each element of the original half.
3. Output all strings in $G$.

### Example

$n = 2$: $G(1) = \{"0", "1"\}$. First half: $\{"00", "01"\}$. Second half: $\{"11", "10"\}$. Result: 00, 01, 11, 10.

## Complexity

- **Time:** $O(2^n \cdot n)$
- **Space:** $O(2^n \cdot n)$

## Code (C++)

[Solution Code](../code/Gray%20Code.cpp)
