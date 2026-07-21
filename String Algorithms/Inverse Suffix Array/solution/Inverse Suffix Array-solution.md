# Inverse Suffix Array - Solution

**ID:** 3225 | **URL:** https://cses.fi/problemset/task/3225

## Problem Statement

Given the suffix array $sa$ (1-indexed) of a string $s$ of length $n$, reconstruct $s$ using the fewest distinct characters (only 'a'–'z'). If no string corresponds to $sa$, output $-1$.

## Approach

### Step 1: Inverse permutation and the differ condition

Set $p[sa[i]] = i$, i.e. $p[j]$ is the lexicographic rank of the suffix starting at $j$. By convention $p[n+1] = 0$ (the empty suffix, always smallest).

Comparing two adjacent suffixes in $sa$, namely $sa[i]$ and $sa[i+1]$:

- If their first characters are equal ($s[sa[i]] = s[sa[i+1]]$), their order is decided by the remainder, i.e. the suffixes at $sa[i]+1$ and $sa[i+1]+1$. Since $sa[i]$ comes first, we must have $p[sa[i]+1] \le p[sa[i+1]+1]$.
- If $p[sa[i]+1] > p[sa[i+1]+1]$, the remainder of $sa[i]+1$ comes **after** $sa[i+1]+1$; for $sa[i]$ to still come first, the first characters **must differ** ($s[sa[i]] \neq s[sa[i+1]]$), otherwise dropping the identical first character would reverse the order, contradicting $sa$.

So the necessary and sufficient condition for $s[sa[i]] \neq s[sa[i+1]]$ is:

$$p[sa[i]+1] > p[sa[i+1]+1]$$

### Step 2: Counting and greedy assignment

Let $C$ be the number of positions $i$ ($1 \le i < n$) satisfying the condition above. In $sa$ order, the sequence $s[sa[1]], s[sa[2]], \ldots, s[sa[n]]$ must be non-decreasing (an earlier suffix is smaller than a later one), and each violation forces a strict increase. Along this sequence, $C$ strict increases force at least $C + 1$ distinct characters. If $C + 1 > 26$ (i.e. $C \ge 26$), this exceeds the alphabet 'a'–'z', so output $-1$.

The greedy algorithm assigns characters in $sa$ order, increasing exactly at the violations, thus using exactly $C + 1$ characters $\textemdash$ optimal:

- Assign $s[sa[1]] = \text{'a'}$.
- Iterate $i$ from $1$ to $n-1$:
  - If $p[sa[i]+1] > p[sa[i+1]+1]$: increase the character level, $s[sa[i+1]] = s[sa[i]] + 1$.
  - Otherwise: $s[sa[i+1]] = s[sa[i]]$ (keep the same).

**Consistency:** When there is no violation, keeping the first characters equal is valid because the suffix order is then entirely decided by the remainder, and $p[sa[i]+1] \le p[sa[i+1]+1]$ ensures the remainder is correctly ordered; when there is a violation, $s[sa[i]] < s[sa[i+1]]$ directly gives $sa[i] < sa[i+1]$. Hence the produced string has exactly the suffix array $sa$.

### Example

Using the example from the problem statement: $n = 7$, $sa = [4, 1, 3, 5, 6, 7, 2]$.

Inverse permutation $p$ (with $p[8] = 0$ for the empty suffix):

| $j$ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|---|
| $p[j]$ | 2 | 7 | 3 | 1 | 4 | 5 | 6 | 0 |

Checking the condition $p[sa[i]+1] > p[sa[i+1]+1]$:

| $i$ | $sa[i]$ | $sa[i+1]$ | $p[sa[i]+1]$ | $p[sa[i+1]+1]$ | violation? |
|---|---|---|---|---|---|
| 1 | 4 | 1 | $p[5]=4$ | $p[2]=7$ | no |
| 2 | 1 | 3 | $p[2]=7$ | $p[4]=1$ | yes |
| 3 | 3 | 5 | $p[4]=1$ | $p[6]=5$ | no |
| 4 | 5 | 6 | $p[6]=5$ | $p[7]=6$ | no |
| 5 | 6 | 7 | $p[7]=6$ | $p[8]=0$ | yes |
| 6 | 7 | 2 | $p[8]=0$ | $p[3]=3$ | no |

$C = 2$ (at $i = 2$ and $i = 5$), needing $C + 1 = 3$ distinct characters $\le 26$: valid.

Greedy assignment in $sa$ order:

| step | assign | character |
|---|---|---|
| init | $s[sa[1]] = s[4]$ | a |
| $i=1$ | $s[sa[2]] = s[1]$ | a (no increase) |
| $i=2$ | $s[sa[3]] = s[3]$ | b (increase) |
| $i=3$ | $s[sa[4]] = s[5]$ | b |
| $i=4$ | $s[sa[5]] = s[6]$ | b |
| $i=5$ | $s[sa[6]] = s[7]$ | c (increase) |
| $i=6$ | $s[sa[7]] = s[2]$ | c |

Result: $s = \text{"acbabbc"}$ (using only 3 characters `a, b, c`).

Check: the suffixes of `acbabbc` sort to $sa = [4, 1, 3, 5, 6, 7, 2]$, matching the input. The problem sample prints `aybabtu` (the original string, 5 characters), but the statement accepts **any** string with the correct suffix array; the algorithm minimizes the number of distinct characters, so it outputs `acbabbc`, which is also a valid answer.

Result:
```
acbabbc
```

## Complexity

- **Time:** $O(n)$ $\textemdash$ building the inverse array $p$, counting violations, and the greedy assignment are all linear passes.
- **Memory:** $O(n)$ $\textemdash$ storing the suffix array, the inverse array $p$, and the result string.

## Code (C++)

[Solution Code](../code/Inverse%20Suffix%20Array.cpp)
