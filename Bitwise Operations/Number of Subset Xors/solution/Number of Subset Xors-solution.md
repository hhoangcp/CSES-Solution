# Number of Subset Xors - Solution

**ID:** 3211 | **URL:** https://cses.fi/problemset/task/3211

## Approach

### Problem Restatement

Given an array of $n$ integers, find the number of distinct subset XOR values (including XOR of the empty set which is 0).

### Core idea

The set of all subset XORs forms a vector subspace over GF(2). A maximal set of linearly independent vectors — an **XOR basis** — spans this space. If the basis has size $sz$, the number of distinct XOR values is $2^{sz}$. This is because each of the $sz$ basis vectors can be independently included or excluded, and by linear independence, each of the $2^{sz}$ choices yields a distinct value: if two different subsets of basis vectors gave the same XOR, their symmetric difference would be a non-trivial combination equal to 0, contradicting independence.

### Algorithm

Maintain `basis[30]` where `basis[i]` stores a vector with bit $i$ as its highest set bit (or 0 if empty). For each input element `mask`:

1. Iterate bits $i$ from 0 to 29.
2. If bit $i$ is set in `mask`:
   - If `basis[i]` ≠ 0: XOR `mask` with `basis[i]` to eliminate bit $i$, continue.
   - If `basis[i]` = 0: set `basis[i] = mask`, increment `sz`, stop.
3. If `mask` becomes 0, the element is linearly dependent.

The low-to-high bit order ensures that when we set `basis[i] = mask`, all bits $j < i$ have already been eliminated, so bit $i$ is the unique highest bit of `basis[i]`. This guarantees linear independence: in any non-trivial XOR combination $\bigoplus_{j \in S} \text{basis}[j] = 0$, the largest index $i \in S$ would contribute bit $i$ unmatched by any other vector — a contradiction.

Result: $2^{sz}$.

### Example

Input: $n = 3$, array $[3, 6, 5]$ (binary: 011, 110, 101).

| Element | Processing | Result |
|---|---|---|
| 3 (011) | bit 0 set, `basis[0]` empty → `basis[0]=3`, $sz=1$ | Added |
| 6 (110) | bit 0 off; bit 1 set, `basis[1]` empty → `basis[1]=6`, $sz=2$ | Added |
| 5 (101) | bit 0 set, `basis[0]=3` → $5 \oplus 3 = 6$; bit 1 set, `basis[1]=6` → $6 \oplus 6 = 0$ | Dependent |

Basis: $\{3, 6\}$, $sz = 2$. Answer: $2^2 = 4$.

Distinct values: $\{0,\ 3,\ 6,\ 3 \oplus 6 = 5\}$.

## Complexity

- **Time:** $O(n \cdot 30)$
- **Space:** $O(30)$

## Code (C++)

[Solution Code](../code/Number%20of%20Subset%20Xors.cpp)
