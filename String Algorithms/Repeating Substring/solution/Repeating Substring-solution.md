# Repeating Substring - Solution

**ID:** 2106 | **URL:** https://cses.fi/problemset/task/2106

## Problem Statement

Given a string $s$ of length $n$ consisting of characters 'a'–'z', a repeating substring is a substring that occurs at two or more different positions. Print the longest repeating substring; if several share the maximum length, print any of them; if no substring repeats, print $-1$.

## Approach

### Step 1: Suffix array, LCP, and repeating substrings

The suffix array $sa$ sorts every suffix of $s$ lexicographically; $lcp[i] = \text{LCP}(sa[i-1], sa[i])$ is the longest common prefix length of two adjacent suffixes.

**Core property:** If a substring $w$ occurs at $k \ge 2$ positions, the $k$ corresponding suffixes all share $w$ as a prefix, and in $sa$ they form a contiguous block (sharing a prefix keeps them adjacent when sorted); the LCP of every adjacent pair in that block is $\ge |w|$.

**Theorem:** $\max_i lcp[i]$ equals the length of the longest repeating substring.

**Proof:**
- ($\ge$) Let $w$ be the longest repeating substring (length $|w|$); its two occurrences give two suffixes sharing $w$ as a prefix, so $\max lcp \ge |w|$.
- ($\le$) If $lcp[i] = L = \max lcp$, then suffixes $sa[i-1]$ and $sa[i]$ share a prefix of length $L$; that substring (length $L$) occurs at both $sa[i-1]$ and $sa[i]$, so a repeating substring of length $L$ exists, i.e. the longest repeating substring $\ge L$.
- Combining both directions: $\max lcp$ equals the longest repeating substring length.

So the adjacent pair $(sa[i-1], sa[i])$ attaining $\max lcp$ shares exactly the longest repeating substring as its prefix.

### Step 2: Algorithm and extracting the result

1. Build $sa$ with SA-IS and compute $lcp$ with Kasai, both in $O(n)$.
2. While computing $lcp$, maintain $\text{res} = \max lcp$ and $\text{pos}$ = the position (in the original string) of the suffix attaining $\text{res}$ (updated when a larger value is found).
3. If $\text{res} \le 0$, no substring repeats $\to$ output $-1$.
4. Otherwise, output $s[\text{pos}..\text{pos}+\text{res}-1]$: this is the longest common prefix of the suffix at $\text{pos}$ with the suffix just before it in $sa$, so it occurs in both places $\textemdash$ a valid repeating substring of length $\text{res}$. The statement accepts any longest repeating substring, so the recorded position $\text{pos}$ always yields a correct answer.

### Example

Using the example from the problem statement: $s = \text{"cabababc"}$ ($n = 8$).

| $i$ | $sa[i]$ | suffix | $lcp[i]$ |
|---|---|---|---|
| 0 | 1 | abababc | — |
| 1 | 3 | ababc | 4 |
| 2 | 5 | abc | 2 |
| 3 | 2 | bababc | 0 |
| 4 | 4 | babc | 3 |
| 5 | 6 | bc | 1 |
| 6 | 7 | c | 0 |
| 7 | 0 | cabababc | 1 |

$\max lcp = 4$ at $i = 1$: suffixes $sa[0] = 1$ ($\text{"abababc"}$) and $sa[1] = 3$ ($\text{"ababc"}$) share the prefix $\text{"abab"}$ (length 4). So $\text{"abab"}$ is the longest repeating substring, occurring at positions 1 and 3 ($s[1..4]$ and $s[3..6]$). The algorithm records $\text{pos} = 3$ (the suffix at position 3 whose LCP with its predecessor is 4) and outputs $s[3..6] = \text{"abab"}$.

Result:
```
abab
```

## Complexity

- **Time:** $O(n)$ $\textemdash$ building $sa$ with SA-IS and computing $lcp$ with Kasai are both linear.
- **Memory:** $O(n)$ $\textemdash$ storing the suffix array, the Rank array, the LCP array, and auxiliary arrays.

## Code (C++)

[Solution Code](../code/Repeating%20Substring.cpp)
