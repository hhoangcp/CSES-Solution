# Required Substring - Solution

**ID:** 1112 | **URL:** https://cses.fi/problemset/task/1112

## Problem Statement

Given a pattern $S$ of length $m$ (characters 'A'–'Z'), count the number of strings of length $n$ over the 26-letter alphabet that contain $S$ as a substring, modulo $10^9+7$.

## Approach

### Step 1: Complement counting

Count the strings of length $n$ that do **not** contain $S$ as a substring, then subtract from $26^n$:

$$\text{Answer} = 26^n - (\text{strings of length } n \text{ not containing } S) \pmod{10^9+7}$$

### Step 2: DP state

Let $dp[i][j]$ = number of strings of length $i$ not containing $S$, whose longest suffix matches exactly the first $j$ characters of $S$ ($0 \le j < m$). Base case $dp[0][0] = 1$.

**Why track only the longest matching suffix?** As the string is built character by character, the possibility of $S$ appearing depends only on the longest suffix currently matching a prefix of $S$: if it has length $j$, appending the next character can only extend the match or shrink it back to a shorter prefix of $S$. Every shorter matching suffix is already implied by $j$ (since $S[0..j-1]$ matches, so do all its shorter prefixes), so $j$ carries enough information to continue. By induction on $i$: each length-$i$ string in state $j$ is extended by 26 characters, transitioning exactly to the state $j'$ of the new longest suffix, with no double-counting or omission; the state $j' = m$ (which means $S$ has appeared) is excluded.

### Step 3: Computing transitions with the Z-function

When in state $j$ (having matched $S[0..j-1]$) and appending character $c$, the new state is $j' = \text{longest}[j][c]$, the length of the longest prefix of $S$ that is also a suffix of $S[0..j-1]+c$. The $\text{longest}$ table is precomputed with the Z-function:

1. Form $T = S + \text{`.`} + S[0..j-1] + c$ (the `.` separator is not in the alphabet).
2. Compute the Z-function on $T$; $Z[p]$ is how far $T[p..]$ matches the prefix of $T$ (i.e. $S$).
3. In the part corresponding to $S[0..j-1]+c$, find the earliest position $p$ whose match reaches the end ($Z[p]+p-1 = |T|-1$). Then $Z[p]$ is $\text{longest}[j][c]$ — the longest suffix of $S[0..j-1]+c$ equal to a prefix of $S$.

(Since `.` appears in neither $S$ nor $c$, the match cannot cross the `.`; the earliest such $p$ gives the longest suffix, which is exactly the maximum sought.)

### Step 4: Recurrence and answer

For $i = 1..n$, $j = 0..m-1$, each character $c$:

$$dp[i][\text{longest}[j][c]] \mathrel{+}= dp[i-1][j] \pmod{10^9+7}$$

If $\text{longest}[j][c] = m$ (appending $c$ makes $S$ appear), the transition lands in state $m$ — which is discarded, because later loops only iterate $j < m$ and the final sum takes only $j < m$. Hence the number of strings not containing $S$ is $\sum_{j=0}^{m-1} dp[n][j]$, and the answer is $26^n$ minus this quantity (add the modulus to avoid negatives).

### Example

Using the example from the problem statement: $n = 6$, $S = \text{"ABCDB"}$ ($m = 5$).

Transition table $\text{longest}[j][c]$ (only nonzero transitions listed):

| state $j$ | transition on appending a character |
|---|---|
| 0 | A→1 (others →0) |
| 1 | A→1, B→2 (others →0) |
| 2 | A→1, C→3 (others →0) |
| 3 | A→1, D→4 (others →0) |
| 4 | A→1, B→5 (=m, discard) (others →0) |

DP table $dp[i][j]$ (the "sum" column = number of length-$i$ strings not containing $S$):

| $i \backslash j$ | 0 | 1 | 2 | 3 | 4 | sum |
|---|---|---|---|---|---|---|
| 0 | 1 | 0 | 0 | 0 | 0 | 1 |
| 1 | 25 | 1 | 0 | 0 | 0 | 26 |
| 2 | 649 | 26 | 1 | 0 | 0 | 676 |
| 3 | 16873 | 676 | 26 | 1 | 0 | 17576 |
| 4 | 438697 | 17576 | 676 | 26 | 1 | 456976 |
| 5 | 11406121 | 456976 | 17576 | 676 | 26 | 11881375 |
| 6 | 296559121 | 11881375 | 456976 | 17576 | 676 | 308915724 |

The sum at $i=6$ is $308915724 = 26^6 - 52$. Answer: $26^6 - 308915724 = 52$.

Intuition check: a length-6 string containing $\text{"ABCDB"}$ must be of the form $\text{"ABCDB}x\text{"}$ (26 strings) or $x\text{"ABCDB"}$ (26 strings); the two forms do not overlap (at the shared position, one requires `B` while the other requires `A`), so the total is exactly $52$.

Result:
```
52
```

## Complexity

- **Time:** $O(n \cdot m \cdot 26 + m^2 \cdot 26)$ $\textemdash$ precomputing $\text{longest}$ with the Z-function costs $O(m^2 \cdot 26)$, the DP loop costs $O(n \cdot m \cdot 26)$.
- **Memory:** $O(n \cdot m)$ $\textemdash$ the $(n+1) \times m$ DP table and the $O(m \cdot 26)$ transition table.

## Code (C++)

[Solution Code](../code/Required%20Substring.cpp)
