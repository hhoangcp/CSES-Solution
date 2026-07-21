# Third Permutation - Solution

**ID:** 3422 | **URL:** https://cses.fi/problemset/task/3422

## Approach

### Problem Restatement

Given two permutations $a$ and $b$ of size $n$ with $a_i \ne b_i$ for all $i$, find a third permutation $c$ such that $c_i \ne a_i$ and $c_i \ne b_i$ for all $i$.

### Core idea

For $n = 2$, impossible — $a_i$ and $b_i$ are two distinct values occupying all of $\{1, 2\}$ at each position. For $n \ge 3$, a solution always exists using a cyclic shift.

Define the **shift** at position $i$ as $s_i = (b_i - a_i) \bmod n$ (0-indexed). Since $a_i \ne b_i$, $s_i \in \{1, \ldots, n-1\}$. If we set $c_i = (a_i + t) \bmod n + 1$ for some constant $t \in \{1, \ldots, n-1\}$, then $c$ is a permutation, $c_i \ne a_i$ (since $t \ne 0$), and $c_i \ne b_i$ as long as $t \ne s_i$ for all $i$. So if some shift $t$ has $\text{freq}[t] = 0$, we are done.

When does a zero-frequency shift exist? Since $\sum_i s_i = \sum_i b_i - \sum_i a_i \equiv 0 \pmod{n}$: for **odd** $n$, a zero-frequency shift always exists (otherwise $\sum_{k=1}^{n-1} k + r \equiv 0 \pmod{n}$ for the repeated shift $r$, forcing $r \equiv 0$, impossible). For **even** $n$, all shifts can appear, but then the repeated shift must be $r = n/2$.

When all shifts appear ($n$ even, shift $n/2$ appears exactly twice at positions $p_1, p_2$): set base $c_i = (a_i + n/2) \bmod n + 1$, which conflicts with $b$ only at $p_1, p_2$. **Case A**: if $a_{p_2} \not\equiv a_{p_1} + n/2 \pmod{n}$, swap $c_{p_1}$ and $c_{p_2}$ — this resolves both conflicts without creating new ones. **Case B**: if $a_{p_2} \equiv a_{p_1} + n/2 \pmod{n}$, the direct swap would make $c_{p_1} = a_{p_1} + 1$. Instead, pick two other positions $p_3, p_4$ and swap $c_{p_1} \leftrightarrow c_{p_3}$, $c_{p_2} \leftrightarrow c_{p_4}$ — since $b$ is a permutation, values at $p_3, p_4$ differ from those at $p_1, p_2$, satisfying all constraints.

### Algorithm

1. If $n \le 2$: output `IMPOSSIBLE`.
2. Compute shifts $s_i = (b_i - a_i) \bmod n$ and their frequencies.
3. If some $t \in \{1, \ldots, n-1\}$ has $\text{freq}[t] = 0$: output $c_i = (a_i + t) \bmod n + 1$.
4. Otherwise (all shifts appear, $n$ even, shift $n/2$ appears twice at $p_1, p_2$):
   - Set base $c_i = (a_i + n/2) \bmod n + 1$.
   - **Case A** ($a_{p_2} \not\equiv a_{p_1} + n/2 \pmod{n}$): swap $c_{p_1}$ and $c_{p_2}$.
   - **Case B**: pick $p_3, p_4$ different from $p_1, p_2$, swap $c_{p_1} \leftrightarrow c_{p_3}$ and $c_{p_2} \leftrightarrow c_{p_4}$.
5. Output $c$.

### Example

$n = 5$, $a = [1, 3, 2, 5, 4]$, $b = [4, 1, 3, 2, 5]$ (problem example, valid output: `3 2 5 4 1`):

1. 0-indexed: $a = [0, 2, 1, 4, 3]$, $b = [3, 0, 2, 1, 4]$. Shifts: $[3, 3, 1, 2, 1]$.
2. Frequencies: $1 \to 2$, $2 \to 1$, $3 \to 2$. Shift $4$ has frequency 0.
3. Use $t = 4$: $c_i = (a_i + 4) \bmod 5 + 1 = [5, 2, 1, 4, 3]$.

Check: $5 \notin \{1,4\}$, $2 \notin \{3,1\}$, $1 \notin \{2,3\}$, $4 \notin \{5,2\}$, $3 \notin \{4,5\}$. ✓

## Complexity

- **Time:** $O(n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Third%20Permutation.cpp)
