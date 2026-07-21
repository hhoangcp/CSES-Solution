# Subarray Divisibility - Solution

**ID:** 1662 | **URL:** https://cses.fi/problemset/task/1662

## Approach

### Problem Restatement

Given an array of $n$ integers, count the number of contiguous subarrays whose element sum is divisible by $n$.

### Core idea

Let $\text{prefix}[0] = 0$ and $\text{prefix}[i] = \sum_{j=1}^{i} a_j$. The sum of subarray $[l, r]$ is
$$S(l, r) = \text{prefix}[r] - \text{prefix}[l-1].$$
This is divisible by $n$ exactly when the two prefix sums share the same remainder modulo $n$:
$$\text{prefix}[r] \equiv \text{prefix}[l-1] \pmod{n},$$
because $S(l,r) \bmod n = (\text{prefix}[r] - \text{prefix}[l-1]) \bmod n$ is $0$ iff the two remainders coincide. Hence the problem reduces to counting pairs of prefix indices $(j, i)$ with $j < i$ that have equal remainders modulo $n$ — equivalently $\sum_{r} \binom{c_r}{2}$, where $c_r$ is the number of prefixes leaving remainder $r$. Counting these pairs in a single left-to-right pass gives the answer.

### Algorithm

Maintain a frequency table of the remainders seen so far.
1. Initialize $\text{freq}[0] = 1$ for the empty prefix $\text{prefix}[0] = 0$, so that subarrays starting at index $1$ are counted.
2. For each $i = 1, \ldots, n$:
   - Update the running prefix and reduce it to a canonical remainder in $\{0, \ldots, n-1\}$:
     $$r = ((\text{prefix} + a_i) \bmod n + n) \bmod n.$$
     The double modulo fixes C++'s `%`, which may be negative for a negative operand.
   - Add $\text{freq}[r]$ to the answer — every earlier prefix with the same remainder yields one valid subarray ending at $i$.
   - Increment $\text{freq}[r]$.

### Example

The problem's sample is $n = 5$, $a = [3, 1, 2, 7, 4]$.

| $i$ | $a_i$ | prefix | rem (mod 5) | $\text{freq}[r]$ before | added |
|-----|-------|--------|-------------|-------------------------|-------|
| 0 | — | 0 | 0 | (init $\text{freq}[0]=1$) | — |
| 1 | 3 | 3 | 3 | 0 | 0 |
| 2 | 1 | 4 | 4 | 0 | 0 |
| 3 | 2 | 6 | 1 | 0 | 0 |
| 4 | 7 | 13 | 3 | 1 | $+1$ |
| 5 | 4 | 17 | 2 | 0 | 0 |

Total: $1$. The single valid subarray is $[2,4]$: $1 + 2 + 7 = 10$, divisible by $5$. $\checkmark$

## Complexity

- **Time:** $O(n \log n)$ with `std::map`, or $O(n)$ with a direct array of size $n$ (remainders always lie in $\{0, \ldots, n-1\}$).
- **Memory:** $O(n)$ for the frequency table.
