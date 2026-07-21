# SOS Bit Problem - Solution

**ID:** 1654 | **URL:** https://cses.fi/problemset/task/1654

## Approach

### Problem Restatement

Given a list of $n$ integers, for each element $x$ compute:
1. The number of $y$ such that $x \mid y = x$ (i.e., $y$ is a submask of $x$)
2. The number of $y$ such that $x \wedge y = x$ (i.e., $y$ is a superset of $x$)
3. The number of $y$ such that $x \wedge y \ne 0$

### Core idea

All three queries reduce to counting elements in submask or superset relationships. **SOS DP** (Sum Over Subsets) computes these counts for all masks simultaneously in $O(h \cdot 2^h)$ instead of the naive $O(3^h)$ per query:
- Query 1: count submasks of $x$ → $dp_1[x]$
- Query 2: count supersets of $x$ → $dp_0[x]$
- Query 3: count by complement → $n - dp_1[\overline{x} \wedge (2^h - 1)]$

### Algorithm

**Submask SOS DP ($dp_1$):** Initialize $dp_1[mask] = f[mask]$ (frequency). For each bit $i$ from 0 to $h-1$, if bit $i$ is set in $mask$: $dp_1[mask] \mathrel{+}= dp_1[mask \oplus 2^i]$. This accumulates counts from submasks that differ only in bit $i$ being 0. After processing all bits, $dp_1[mask]$ counts all elements that are submasks of $mask$.

**Superset SOS DP ($dp_0$):** Initialize $dp_0[mask] = f[mask]$. For each bit $i$, if bit $i$ is **not** set in $mask$: $dp_0[mask] \mathrel{+}= dp_0[mask \mid 2^i]$. This accumulates counts from supersets that have bit $i$ additionally set. After processing, $dp_0[mask]$ counts all elements that are supersets of $mask$.

**Why SOS DP works:** By induction on bit $i$. After processing bit $i$, $dp_1[mask]$ correctly counts submasks considering only bits $0$ through $i$. When bit $i$ is set in $mask$, adding $dp_1[mask \oplus 2^i]$ incorporates submasks with bit $i = 0$; submasks with bit $i = 1$ were already accounted for. The superset direction is symmetric.

**Query 3 via complement:** $x \wedge y \ne 0$ iff $y$ shares at least one bit with $x$. Its complement is $x \wedge y = 0$, meaning $y$ only uses bits that $x$ doesn't — i.e., $y$ is a submask of $\overline{x}$ (bitwise NOT of $x$, masked to $h$ bits). The count is $dp_1[\overline{x} \wedge (2^h - 1)]$, so the answer is $n$ minus this value.

### Example

Input: $n = 5$, list $[3, 7, 2, 9, 2]$. $h = 4$, $2^h - 1 = 15$.

Frequencies: $f[2]=2, f[3]=1, f[7]=1, f[9]=1$ (all others 0).

**For $x = 3$ (0011):**
1. Submasks of 3: $\{0, 1, 2, 3\}$. Count = $f[0]+f[1]+f[2]+f[3] = 0+0+2+1 = \mathbf{3}$.
2. Supersets of 3 (elements with bits 0 and 1 set): $\{3, 7\}$. Count = $f[3]+f[7] = 1+1 = \mathbf{2}$.
3. $\overline{3} \wedge 15 = 12$ (1100). Submasks of 12: $\{0, 4, 8, 12\}$. Count = 0. Answer = $5 - 0 = \mathbf{5}$.

**For $x = 9$ (1001):**
1. Submasks of 9: $\{0, 1, 8, 9\}$. Count = $f[9] = \mathbf{1}$.
2. Supersets of 9 (elements with bits 0 and 3 set): $\{9\}$. Count = $\mathbf{1}$.
3. $\overline{9} \wedge 15 = 6$ (0110). Submasks of 6: $\{0, 2, 4, 6\}$. Count = $f[2] = 2$. Answer = $5 - 2 = \mathbf{3}$.

Full output: `3 2 5`, `4 1 5`, `2 4 4`, `1 1 3`, `2 4 4`.

## Complexity

- **Time:** $O(n + h \cdot 2^h)$
- **Space:** $O(2^h)$

## Code (C++)

[Solution Code](../code/SOS%20Bit%20Problem.cpp)
