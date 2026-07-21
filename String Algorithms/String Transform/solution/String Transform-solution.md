# String Transform - Solution

**ID:** 1113 | **URL:** https://cses.fi/problemset/task/1113

## Problem Statement

The Burrows-Wheeler Transform (BWT) appends a character `#` to the string (`#` is smaller than every character 'a'–'z'), generates all rotations, sorts them lexicographically, and concatenates the last character of each rotation into the result string. Given this result string (the last column, of length $n+1$), recover the original string of length $n$.

## Approach

### Step 1: The LF property and the Next array

Let $L$ be the last column (the given BWT string) and $F$ the first column (which is just $L$ sorted in increasing order). Both columns have $n+1$ rows (indexed $1..n{+}1$).

**LF (Last-First) property:** in the matrix of sorted rotations, the $i$-th occurrence of a character $c$ in the last column $L$ corresponds to the $i$-th occurrence of $c$ in the first column $F$. Indeed, rotations ending with the same $c$ are ordered by the part right after $c$; that part is the prefix of the next rotation starting with $c$, so the relative order among occurrences of $c$ is preserved between $L$ and $F$.

From this we build the array $\text{Next}$: $\text{Next}[k]$ = the position (row) in $L$ corresponding to the $k$-th element of $F$ (i.e. $L[\text{Next}[k]] = F[k]$, the same occurrence). This is the inverse of LF (from the first column to the last column).

### Step 2: Building Next with stacks

1. **Classify:** scan $L$ from right to left, pushing each position $i$ onto the stack for the character $L[i]$ (`#` goes to stack 0). The right-to-left scan leaves smaller positions on top — matching the increasing order of occurrences in $L$.
2. **Assign Next:** iterate the stacks in increasing character order (`#`, `a`, `b`, …, `z`) — matching the order of the first column $F$ — popping from each; the element popped at step $k$ is $\text{Next}[k]$.

### Step 3: Recovering the original string

The rotation starting with `#` is the smallest, so it heads $F$ (row 1); the rotation ending with `#` is the original string plus `#`. Let $\text{start}$ = the position of `#` in $L$. Following the $\text{Next}$ cycle:

$$\text{start} \to \text{Next}[\text{start}] \to \text{Next}[\text{Next}[\text{start}]] \to \cdots$$

each step jumps to the row of the rotation shifted left by one character; the character $L[\text{cur}]$ read there is the leading character of the previous rotation, i.e. the next character of the original string in forward order. Repeat until returning to $\text{start}$ (skipping `#`); this yields the whole original string in order.

### Example

Using the example from the problem statement: the BWT (last column $L$) $= \text{"cb\#ab"}$ ($n{+}1 = 5$, original has $n = 4$).

The first column $F = L$ sorted increasingly $= \text{"\#abbc"}$.

Stack classification (top = smallest position, due to the right-to-left scan):

| character | `#` | `a` | `b` | `c` |
|---|---|---|---|---|
| rows in $L$ | 3 | 4 | 2, 5 | 1 |

Assigning $\text{Next}$ in the order of $F$ (`#`, `a`, `b`, `b`, `c`):

| $k$ (row of $F$) | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|
| $F[k]$ | # | a | b | b | c |
| $\text{Next}[k]$ (row in $L$) | 3 | 4 | 2 | 5 | 1 |
| $L[\text{Next}[k]]$ | # | a | b | b | c |

(The row $L[\text{Next}[k]]$ matches $F[k]$, exhibiting the LF property.)

$\text{start} = 3$ (position of `#` in $L$). Following the $\text{Next}$ cycle, reading $L[\text{cur}]$ (skipping `#`):

$$3 \xrightarrow{\text{Next}} 2 \xrightarrow{\text{Next}} 4 \xrightarrow{\text{Next}} 5 \xrightarrow{\text{Next}} 1 \xrightarrow{\text{Next}} 3$$

Characters read: $L[2]=\text{b}, L[4]=\text{a}, L[5]=\text{b}, L[1]=\text{c}$ $\to$ `"babc"`.

Result:
```
babc
```

## Complexity

- **Time:** $O(n)$ $\textemdash$ stack classification, assigning $\text{Next}$, and the recovery traversal are all linear.
- **Memory:** $O(n)$ $\textemdash$ the $\text{Next}$ array, the input string, and 27 classification stacks.

## Code (C++)

[Solution Code](../code/String%20Transform.cpp)
