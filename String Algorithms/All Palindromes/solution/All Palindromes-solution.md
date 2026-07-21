# All Palindromes - Solution

**ID:** 3138 | **URL:** https://cses.fi/problemset/task/3138

## Problem Statement

Given a string $s$ of length $n$, for each position $i$ ($1 \le i \le n$), find the length of the longest palindrome ending at position $i$.

## Approach

### Step 1: String transformation with a sentinel

Insert a sentinel character `$` between every pair of adjacent characters and at both ends, producing string $t$ of length $2n+1$. For example, $s = \text{"abba"}$ becomes $t = \text{"\$a\$b\$b\$a\$"}$.

**Property:** Every palindrome in $t$ has odd length. A palindrome centered at $c$ with radius $r$ in $t$ corresponds to a palindrome of length $r$ in $s$.

### Step 2: Manacher's algorithm

Compute the array $\text{manacher}[i]$ = radius of the longest palindrome centered at $i$ in $t$, i.e. $t[i - \text{manacher}[i] .. i + \text{manacher}[i]]$ is a palindrome.

The algorithm maintains the rightmost-known palindrome window $[l, r]$ (center $l$, right boundary $r = l + \text{manacher}[l]$) to exploit mirror symmetry:

1. If $i \le r$, initialize $\text{manacher}[i] = \min(r - i, \text{manacher}[2l - i])$ (mirror around $l$); otherwise initialize to $0$.
2. Extend by comparing $t[i - \text{manacher}[i] - 1]$ and $t[i + \text{manacher}[i] + 1]$.
3. If $i + \text{manacher}[i] > r$, update $l = i$, $r = i + \text{manacher}[i]$.

### Step 3: Finding the longest palindrome ending at each position

Consider an odd position $i$ in $t$ (corresponding to a real character in $s$). Every palindrome ending exactly at $i$ has a center $c \le i$, uses radius $i - c$ to reach $i$, and has length $i - c + 1$ in $s$. For it to be valid, the center $c$ must have a large enough radius: $c + \text{manacher}[c] \ge i$ (the right boundary of the palindrome at $c$ covers $i$).

Since the length $i - c + 1$ increases as $c$ decreases, the **smallest center** (farthest to the left of $i$) still satisfying $c + \text{manacher}[c] \ge i$ yields the longest palindrome ending at $i$.

Optimize with a deque storing centers in increasing order, scanning $i$ from left to right:

- Repeatedly remove centers from the front whose right boundary no longer covers $i$: $c + \text{manacher}[c] < i$.
- Push $i$ to the back as a new candidate center.
- If $i$ is odd, the answer for the corresponding position in $s$ is $i - (\text{deque front}) + 1$.

**Why does the front give the optimal result?** Centers are stored in increasing order. When a center is removed (because $c + \text{manacher}[c] < i$), it cannot cover any later position $i' > i$ either, so removal is safe and never needs to be undone. After removal, the front of the deque is the smallest center still covering $i$; since the length $i - c + 1$ is maximized when $c$ is minimized, the front is exactly the center yielding the longest palindrome ending at $i$.

### Example

Using the example from the problem statement: $s = \text{"ababbababaa"}$ ($n = 11$). The transformed string is $t = \text{"\$a\$b\$a\$b\$b\$a\$b\$a\$b\$a\$a\$"}$ ($|t| = 23$).

The $\text{manacher}$ table (indices $i$ starting from $0$):

| $i$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| $t[i]$ | \$ | a | \$ | b | \$ | a | \$ | b | \$ | b | \$ | a | \$ | b | \$ | a | \$ | b | \$ | a | \$ | a | \$ |
| $\text{manacher}$ | 0 | 1 | 0 | 3 | 0 | 3 | 0 | 1 | 8 | 1 | 0 | 3 | 0 | 5 | 0 | 5 | 0 | 3 | 0 | 1 | 2 | 1 | 0 |

Odd positions $i = 1, 3, 5, \dots, 21$ correspond to $s[1..11]$. The deque scan yields:

| $i$ | 1 | 3 | 5 | 7 | 9 | 11 | 13 | 15 | 17 | 19 | 21 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| deque front | 1 | 3 | 3 | 5 | 8 | 8 | 8 | 8 | 13 | 15 | 20 |
| answer | 1 | 1 | 3 | 3 | 2 | 4 | 6 | 8 | 5 | 5 | 2 |

Some notable steps:

- $i = 5$: front is $3$, $\text{manacher}[3] = 3$ so $3 + 3 = 6 \ge 5$. Answer $5 - 3 + 1 = 3$ (palindrome $\text{"aba"}$).
- $i = 9$: centers $1, 3, 5, 7$ are removed as they no longer cover $9$; the new front is $8$ with $\text{manacher}[8] = 8$. Answer $9 - 8 + 1 = 2$ (palindrome $\text{"bb"}$).
- $i = 15$: front is still $8$ since $8 + 8 = 16 \ge 15$. Answer $15 - 8 + 1 = 8$ (palindrome $\text{"ababbaba"}$).
- $i = 17$: center $8$ is removed ($8 + 8 = 16 < 17$); the new front is $13$ with $\text{manacher}[13] = 5$. Answer $17 - 13 + 1 = 5$ (palindrome $\text{"babab"}$).

Result: `1 1 3 3 2 4 6 8 5 5 2`.

## Complexity

- **Time:** $O(n)$ $\textemdash$ Manacher is linear; each position is pushed to and popped from the deque at most once.
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/All%20Palindromes.cpp)
