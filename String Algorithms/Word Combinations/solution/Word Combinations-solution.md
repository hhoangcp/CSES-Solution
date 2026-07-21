# Word Combinations - Solution

**ID:** 1731 | **URL:** https://cses.fi/problemset/task/1731

## Problem Statement

Given a string $s$ of length $n$ and a dictionary of $k$ words, count the number of ways to form $s$ by concatenating dictionary words (each word may be used multiple times), modulo $10^9+7$.

## Approach

### Step 1: Trie

Store the dictionary in a Trie: each node has 26 children (for 'a'–'z') and a flag marking the end of a word. Insert all $k$ words into the Trie; cost $O(\sum |w_i|)$.

### Step 2: Right-to-left dynamic programming

Let $dp[i]$ = the number of ways to form the suffix $s[i..n{-}1]$ (0-indexed) using dictionary words. Base case $dp[n] = 1$ (the empty suffix has exactly one way: use no words).

Process $i$ from $n{-}1$ down to $0$. At each $i$, walk the Trie from the root following the characters $s[i], s[i{+}1], \ldots$:

- If the current node has no child for $s[j]$, stop (no word matches further).
- If the child exists, descend; if the new node marks a word end, then $s[i..j]$ is a dictionary word, so add:
$$dp[i] = \bigl(dp[i] + dp[j+1]\bigr) \bmod (10^9+7)$$

In short: $dp[i] = \sum_{j: s[i..j] \in \text{dict}} dp[j+1]$. The answer is $dp[0]$.

**Correctness (induction):** $dp[n]=1$ is correct. Assume $dp[j+1]$ is correct for all $j > i$. Any way to form $s[i..n{-}1]$ must start with a dictionary word $s[i..j]$, then form $s[j{+}1..n{-}1]$ in $dp[j+1]$ ways; summing over all words matching at $i$ gives the correct $dp[i]$. No double-counting, since different decompositions have different first words (or the same first word but different remaining parts), so they appear in different terms.

### Example

Using the example from the problem statement: $s = \text{"ababc"}$ ($n = 5$), dictionary $\{$`ab`, `abab`, `c`, `cb`$\}$.

Trie (the `(end …)` flag marks a word end):

```
root
├ a → b (end "ab") → a → b (end "abab")
└ c (end "c") → b (end "cb")
```

DP table (right to left):

| $i$ | $s[i..]$ | matching words (→ $dp[j{+}1]$) | $dp[i]$ |
|---|---|---|---|
| 5 | (empty) | — (base) | 1 |
| 4 | `c` | `c` → $dp[5]=1$ | 1 |
| 3 | `bc` | none (no word starts with `b`) | 0 |
| 2 | `abc` | `ab` → $dp[4]=1$ | 1 |
| 1 | `babc` | none | 0 |
| 0 | `ababc` | `ab` → $dp[2]=1$; `abab` → $dp[4]=1$ | 2 |

Answer $dp[0] = 2$, corresponding to the two ways: `ab + ab + c` and `abab + c`.

Result:
```
2
```

## Complexity

- **Time:** $O(n^2 + \sum |w_i|)$ $\textemdash$ building the Trie costs $O(\sum |w_i|)$; the DP has two nested loops, $O(n^2)$ in the worst case. The Trie prunes non-matching branches early, so it is much faster in practice than iterating over each word.
- **Memory:** $O(n + \sum |w_i|)$ $\textemdash$ the $dp$ array of size $n$ and the Trie nodes.

## Code (C++)

[Solution Code](../code/Word%20Combinations.cpp)
