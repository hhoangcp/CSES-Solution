# Finding Periods - Solution

**ID:** 1733 | **URL:** https://cses.fi/problemset/task/1733

## Problem Statement

Given a string $s$ of length $n$ consisting of characters 'a'–'z', a period of length $k$ is a prefix $s[1..k]$ such that $s$ is a prefix of the infinite string $s[1..k]^{\infty}$ (the last repetition may be partial). Print all period lengths in increasing order.

## Approach

### Step 1: Z-function and the period condition

For a string $s$ (1-indexed), $Z[i]$ is the length of the longest substring starting at $i$ that matches the prefix of $s$; by convention $Z[1] = 0$.

Consider a length $k$ ($1 \le k < n$). For $k$ to be a period, the remainder of the string from $k+1$, i.e. the suffix $s[k+1..n]$, must fully match the prefix of the same length $n-k$ (since each position $i \ge k+1$ must equal $s[i-k]$). The necessary and sufficient condition is:

$$Z[k+1] = n - k \quad \Longleftrightarrow \quad (k+1) + Z[k+1] - 1 = n$$

**Proof of equivalence:**
- ($\Rightarrow$) If $k$ is a period then $s[i] = s[i-k]$ for all $i \ge k+1$, so $s[k+1..n] = s[1..n-k]$, i.e. $Z[k+1] \ge n-k$; this segment is only $n-k$ long, so $Z[k+1] = n-k$.
- ($\Leftarrow$) If $Z[k+1] = n-k$ then $s[i] = s[i-k]$ for all $i \in [k+1, n]$. Applying this relation repeatedly brings any index $i$ down to $r = ((i-1) \bmod k) + 1 \in [1, k]$, giving $s[i] = s[r]$, which is exactly the definition of a period.

Setting $i = k+1$, the condition becomes $i + Z[i] - 1 = n$ and the period length is $k = i - 1$.

### Step 2: Algorithm

1. Compute the $Z$ array for $s$ in $O(n)$ (two-pointer method).
2. Scan $i$ from $2$ to $n$ in increasing order; each position with $i + Z[i] - 1 = n$ gives a period of length $i - 1$. Since $i$ increases, the lengths $i - 1$ come out in increasing order automatically $\textemdash$ no sorting or stack needed.
3. The length $n$ is always a period (the string repeated once), so print $n$ last.

### Example

Using the example from the problem statement: $s = \text{"abcabca"}$ ($n = 7$).

| $i$ | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|
| $s[i]$ | a | b | c | a | b | c | a |
| $Z[i]$ | 0 | 0 | 0 | 4 | 0 | 0 | 1 |

Checking the condition $i + Z[i] - 1 = n = 7$:

| $i$ | $Z[i]$ | $i + Z[i] - 1$ | period? |
|---|---|---|---|
| 4 | 4 | 7 | yes, length $i - 1 = 3$: $\text{"abc"}$ |
| 7 | 1 | 7 | yes, length $i - 1 = 6$: $\text{"abcabc"}$ |

(All other $i$ have $Z[i] = 0$, so $i + Z[i] - 1 < n$.) Adding $n = 7$, which is always a period.

Indeed, $\text{"abcabca"}$ is a prefix of $\text{"abc"}^{\infty}$ (repeat $\text{"abc"}$ then append $\text{"a"}$) and also of $\text{"abcabc"}^{\infty}$ (append $\text{"a"}$), so the periods are $3, 6, 7$.

Result:
```
3 6 7
```

## Complexity

- **Time:** $O(n)$ $\textemdash$ the Z-function is linear, and the check is $O(1)$ per position.
- **Memory:** $O(n)$ $\textemdash$ storing the $Z$ array.

## Code (C++)

[Solution Code](../code/Finding%20Periods.cpp)
