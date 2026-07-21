# Finding Borders - Solution

**ID:** 1732 | **URL:** https://cses.fi/problemset/task/1732

## Problem Statement

Given a string $s$ of length $n$ consisting of characters 'a'–'z'. A border of a string is a prefix that is also a suffix of the string, but not the whole string. Print all border lengths in increasing order.

## Approach

### Step 1: The Z-function

For a string $s$ of length $n$ (1-indexed), $Z[i]$ is the length of the longest substring starting at position $i$ that matches the prefix of $s$: $Z[i] = \max\{k : s[i..i+k-1] = s[1..k]\}$. By convention $Z[1] = 0$.

### Step 2: Relating the Z-function to borders

A substring starting at $i$ ($2 \le i \le n$) is a border iff it matches the prefix (already captured by $Z[i]$) **and** the matching segment extends exactly to the end of the string. The necessary and sufficient condition is:

$$i + Z[i] - 1 = n$$

Indeed, $Z[i]$ measures how far the match with the prefix extends from $i$; this becomes a suffix (ending at $n$) precisely when $i + Z[i] - 1 = n$. Then $s[i..n]$ both matches the prefix $s[1..Z[i]]$ and is a suffix, so it is a border of length $Z[i]$.

**Completeness and uniqueness:** Every border of length $k$ corresponds to $i = n - k + 1$ and satisfies the condition above (since $Z[i] = k$, exactly the number of characters remaining to the end); conversely each qualifying $i$ yields a unique length $Z[i] = n - i + 1$, injective in $i$, so no border is missed or counted twice.

### Step 3: Output order

Scan $i$ from $2$ to $n$ in increasing order, pushing each qualifying border length onto a stack. Since a border of length $k$ corresponds to $i = n - k + 1$, larger $i$ means smaller $k$; so longer borders (found first) sit at the bottom and shorter ones (found later) sit on top. Popping from the stack to print automatically yields the lengths in increasing order, with no extra sorting.

### Example

Using the example from the problem statement: $s = \text{"abcababcab"}$ ($n = 10$).

| $i$ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| $s[i]$ | a | b | c | a | b | a | b | c | a | b |
| $Z[i]$ | 0 | 0 | 0 | 2 | 0 | 5 | 0 | 0 | 2 | 0 |

Checking the condition $i + Z[i] - 1 = n = 10$:

| $i$ | $Z[i]$ | $i + Z[i] - 1$ | border? |
|---|---|---|---|
| 4 | 2 | 5 | no |
| 6 | 5 | 10 | yes, length 5: $\text{"abcab"}$ |
| 9 | 2 | 10 | yes, length 2: $\text{"ab"}$ |

(All other $i$ have $Z[i] = 0$, so $i + Z[i] - 1 < n$.)

Scanning $i$ in increasing order: at $i = 6$ push length $5$, at $i = 9$ push length $2$ (on top). Popping prints $2$ then $5$.

Result:
```
2 5
```

## Complexity

- **Time:** $O(n)$ $\textemdash$ the Z-function is computed in linear time with the two-pointer method, and the border check is $O(n)$.
- **Memory:** $O(n)$ $\textemdash$ storing the $Z$ array and the result stack.

## Code (C++)

[Solution Code](../code/Finding%20Borders.cpp)
