# Maximum Xor Subarray - Solution

**ID:** 1655 | **URL:** https://cses.fi/problemset/task/1655

## Approach

### Problem Restatement

Given an array of $n$ integers, find the maximum XOR sum of a subarray (contiguous segment).

### Core idea

The XOR of subarray $[l, r]$ equals $\text{pre}[r] \oplus \text{pre}[l-1]$, where $\text{pre}[i]$ is the prefix XOR. So we need $\max_{0 \le j < i \le n} (\text{pre}[i] \oplus \text{pre}[j])$. For each $i$, find the $j < i$ maximizing $\text{pre}[i] \oplus \text{pre}[j]$ using a **binary trie** with greedy bit selection.

### Algorithm

1. **Prefix XOR:** Compute $\text{pre}[0] = 0$, $\text{pre}[i] = x_1 \oplus \cdots \oplus x_i$. Insert $\text{pre}[0]$ into the trie.
2. **Process each position:** For $i = 1$ to $n$:
   - Query the trie for the stored value maximizing $\text{pre}[i] \oplus v$. At each bit level $i$ (from 30 down to 0), prefer the branch with the opposite bit of $\text{pre}[i]$ (to make the result bit 1). If the preferred branch doesn't exist, take the other. This greedy choice is optimal because $2^i > 2^0 + 2^1 + \cdots + 2^{i-1}$ — losing bit $i$ cannot be compensated by any combination of lower bits.
   - Update the answer with the query result.
   - Insert $\text{pre}[i]$ into the trie.

### Example

Input: $n = 4$, array $[5, 1, 5, 9]$.

Prefix XOR: $\text{pre}[0]{=}0, \text{pre}[1]{=}5, \text{pre}[2]{=}4, \text{pre}[3]{=}1, \text{pre}[4]{=}8$.

| $i$ | $\text{pre}[i]$ | Trie contains | Best XOR | Value |
|---|---|---|---|---|
| 1 | 5 | $\{0\}$ | $5 \oplus 0$ | 5 |
| 2 | 4 | $\{0, 5\}$ | $4 \oplus 0$ | 4 |
| 3 | 1 | $\{0, 5, 4\}$ | $1 \oplus 4$ | 5 |
| 4 | 8 | $\{0, 5, 4, 1\}$ | $8 \oplus 5$ | **13** |

Result: **13**.

## Complexity

- **Time:** $O(n \cdot 31)$ — each element inserts and queries in $O(31)$
- **Space:** $O(n \cdot 31)$ — at most $n$ prefix values, each requiring 31 trie nodes

## Code (C++)

[Solution Code](../code/Maximum%20Xor%20Subarray.cpp)
