# Pattern Positions - Solution

**ID:** 2104 | **URL:** https://cses.fi/problemset/task/2104

## Problem Statement

Given a string $s$ of length $n$ and $k$ patterns (positions 1-indexed), find for each pattern the first position where it appears in $s$; if it does not appear, output $-1$.

## Approach

### Step 1: Suffix automaton with the earliest ending position

Build the suffix automaton (SAM) for $s$, and additionally store for each state $v$ the value $\text{first\_pos}[v]$ = the **smallest** ending position in the endpos set of $v$ (i.e. the earliest position where the substrings of $v$ end).

Setup during online construction:
- When creating a new non-clone state $\text{cur}$ while adding $s[i]$: $\text{first\_pos}[\text{cur}] = \text{len}[\text{cur}] = i$.
- When cloning $\text{clone}$ from state $q$: $\text{first\_pos}[\text{clone}] = \text{first\_pos}[q]$.

**Correctness:** A non-clone state $\text{cur}$ created at position $i$ has its longest string (the prefix $s[1..i]$) ending for the first time exactly at $i$; any later occurrences are at positions $> i$, so $i$ is the smallest ending position. When cloning, the endpos of the clone contains all of $q$'s old endpos plus the new position $i$ (larger than every old one), so the smallest position is unchanged and equals $\text{first\_pos}[q]$. Thus $\text{first\_pos}[v]$ is always the smallest ending position of state $v$.

### Step 2: Answering pattern queries

For each pattern $p$ of length $m$: start from the initial state and follow transitions for the characters of $p$.

- If a transition is missing at some step $\to$ $p$ does not occur, output $-1$.
- If all of $p$ is consumed and we stop at state $v$, the first occurrence ends at $\text{first\_pos}[v]$, so the starting position is:

$$\text{starting position} = \text{first\_pos}[v] - m + 1$$

### Example

Using the example from the problem statement: $s = \text{"aybabtu"}$ ($n = 7$, positions $1=\text{a}, 2=\text{y}, 3=\text{b}, 4=\text{a}, 5=\text{b}, 6=\text{t}, 7=\text{u}$), three patterns $\text{"bab"}, \text{"abc"}, \text{"a"}$. The SAM has 9 states; the table lists only the relevant states and transitions:

| state | $\text{len}$ | $\text{link}$ | $\text{first\_pos}$ | transitions (relevant) |
|---|---|---|---|---|
| 0 | 0 | $-1$ | 0 | a→1, b→6 |
| 1 | 1 | 0 | 1 | b→5 |
| 4 | 4 | 1 | 4 | b→5 |
| 5 | 5 | 6 | 5 | t→7 |
| 6 | 1 | 0 (clone) | 3 | a→4 |

(State 6 is the clone representing $\text{"b"}$; $\text{first\_pos}=3$ is the position of the first 'b'.)

Traversing each pattern:

| pattern | path | end state | $\text{first\_pos}$ | starting position | result |
|---|---|---|---|---|---|
| $\text{"bab"}$ | $0 \xrightarrow{b} 6 \xrightarrow{a} 4 \xrightarrow{b} 5$ | 5 | 5 | $5-3+1=3$ | 3 |
| $\text{"abc"}$ | $0 \xrightarrow{a} 1 \xrightarrow{b} 5 \xrightarrow{c}\ \text{(missing)}$ | — | — | — | $-1$ |
| $\text{"a"}$ | $0 \xrightarrow{a} 1$ | 1 | 1 | $1-1+1=1$ | 1 |

Explanation: $\text{"bab"}$ ends earliest at position 5 ($s[3..5]$), so it starts at 3; $\text{"a"}$ ends earliest at position 1 ($s[1]$), so it starts at 1; $\text{"abc"}$ does not occur in $s$.

Result:
```
3
-1
1
```

## Complexity

- **Time:** $O(n \log \sigma + \sum |p_i| \log \sigma)$ $\textemdash$ building the SAM and traversing the patterns ($\sigma = 26$; the $\log\sigma$ factor comes from using a transition map).
- **Memory:** $O(n)$ $\textemdash$ the SAM has at most $O(n)$ states and $O(n)$ transition edges, plus the $\text{first\_pos}$ array.

## Code (C++)

[Solution Code](../code/Pattern%20Positions.cpp)
