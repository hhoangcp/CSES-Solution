# String Matching - Solution

**ID:** 1753 | **URL:** https://cses.fi/problemset/task/1753

## Problem Statement

Given a text string $s$ of length $n$ and a pattern $t$ of length $m$ (characters 'a'–'z'), count the number of positions where $t$ occurs in $s$ (overlapping occurrences are allowed).

## Approach

### Step 1: Concatenation technique

Form the combined string $t' = t + \text{sep} + s$, where $\text{sep}$ is a separator character not in 'a'–'z' (the code uses a space). The string $t'$ has length $m + 1 + n$, with the pattern $t$ at positions $1..m$, $\text{sep}$ at position $m+1$, and the text $s$ at positions $m+2..m+1+n$.

### Step 2: Z-function and the bound

Compute the Z-function on $t'$ with the two-pointer method (rightmost window $[L,R]$ matching the prefix), in $O(n+m)$. Since the prefix of $t'$ is exactly the pattern $t$, for each position $i$ in the text part ($i > m+1$), $Z[i]$ is the longest match length between $s$ (from the corresponding position) and the pattern $t$.

**Bound $Z[i] \le m$:** If $Z[i] > m$ for some $i > m+1$, then the matching prefix $t'[1..Z[i]]$ must contain $\text{sep}$ at position $m+1$, so $t'[i+m]$ must also equal $\text{sep}$; but $t'[i+m]$ lies in the text part (only 'a'–'z'), so it cannot be $\text{sep}$. Contradiction. Hence $Z[i] \le m$.

### Step 3: Counting occurrences

The pattern $t$ occurs at position $j$ in the original text ($1 \le j \le n$) iff $Z[m+1+j] = m$:

- ($\Rightarrow$) If $s[j..j+m-1] = t$, then $t'[m+1+j..m+j+m] = t = t'[1..m]$, so $Z[m+1+j] \ge m$; combined with $Z \le m$ (Step 2), it equals $m$.
- ($\Leftarrow$) If $Z[m+1+j] = m$, then $t'[m+1+j..m+j+m] = t'[1..m] = t$, i.e. $s[j..j+m-1] = t$.

So count the positions $j$ with $Z[m+1+j] = m$ (equivalently, scan $i$ from $m+2$ to $m+1+n$ and count those with $Z[i] = m$).

### Example

Using the example from the problem statement: text $s = \text{"saippuakauppias"}$ ($n = 15$), pattern $t = \text{"pp"}$ ($m = 2$).

Combined string $t' = \text{"pp\#saippuakauppias"}$ ($\#$ is the separator), length $18$.

| position in $t'$ | $1..2$ | $3$ | $4..18$ |
|---|---|---|---|
| content | pattern `pp` | separator | text `saippuakauppias` |

Scanning the text part ($i = 4..18$), the positions with $Z[i] = m = 2$:

| text position $j$ | $t'$ index $i = m+1+j$ | $Z[i]$ | matching segment $s[j..j+1]$ |
|---|---|---|---|
| 4 | 7 | 2 | $\text{"pp"}$ ($s[4..5]$) |
| 11 | 14 | 2 | $\text{"pp"}$ ($s[11..12]$) |

(All other positions have $Z[i] < 2$.)

Number of occurrences: $2$.

Result:
```
2
```

## Complexity

- **Time:** $O(n + m)$ $\textemdash$ building the combined string and computing the Z-function with the two-pointer method are both linear in $m+1+n$.
- **Memory:** $O(n + m)$ $\textemdash$ storing the combined string of length $m+1+n$ and the $Z$ array.

## Code (C++)

[Solution Code](../code/String%20Matching.cpp)
