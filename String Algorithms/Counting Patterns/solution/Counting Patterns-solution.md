# Counting Patterns - Solution

**ID:** 2103 | **URL:** https://cses.fi/problemset/task/2103

## Problem Statement

Given a string $s$ of length $n$ and $k$ patterns, count for each pattern the number of positions where it appears in $s$.

## Approach

### Step 1: Build the suffix automaton (SAM)

Build the suffix automaton for $s$. Each state $v$ represents a set of substrings sharing the same set of ending positions (**endpos**); their lengths lie in $(\text{len}[\text{link}[v]], \text{len}[v]]$, where $\text{link}[v]$ is the suffix link, pointing to the state of the longest proper suffix.

Each ending position in $s$ corresponds to a freshly created (non-clone) state when a character is appended to the SAM; cloned states are not tied to a specific position. Hence initialize:

$$\text{cnt}[v] = \begin{cases} 1 & v \text{ is a freshly created state} \\ 0 & v \text{ is a clone or the root} \end{cases}$$

### Step 2: Propagate occurrences along the suffix link tree

If $u$ is a child of $v$ in the reverse suffix link tree (i.e., $\text{link}[u] = v$), then every endpos of $u$ is also an endpos of $v$ (the string at $v$ is a suffix of the string at $u$). Thus the endpos set of $v$ is the union of its children's endpos sets, so the number of occurrences of the string at $v$ equals the sum of those of its children:

$$\text{cnt}[\text{link}[v]] \mathrel{+}= \text{cnt}[v]$$

Process states in decreasing $\text{len}$ order (topological order on the reverse suffix link tree) and accumulate from children to parents. After this step, $\text{cnt}[v]$ is exactly the number of ending positions — i.e., the number of occurrences — of every substring belonging to state $v$.

### Step 3: Answer pattern queries

For each pattern $p$:

- Start from the root and follow transitions character by character along $p$.
- If a transition is missing for some character, $p$ does not occur $\to$ answer $0$.
- If all of $p$ is consumed and we stop at state $v$, the answer is the propagated $\text{cnt}[v]$. This holds because all substrings in the same state $v$ share the same endpos set, so $p$ (if it leads to $v$) occurs exactly $\text{cnt}[v]$ times.

### Example

Using the example from the problem statement: $s = \text{"aybabtu"}$ ($n = 7$), patterns $\text{"bab"}$, $\text{"abc"}$, $\text{"a"}$.

The SAM has 9 states (state 6 is a clone). State table (indices from 0; initial and post-propagation $\text{cnt}$):

| state | $\text{len}$ | $\text{link}$ | initial $\text{cnt}$ | $\text{cnt}$ after propagation | transitions |
|---|---|---|---|---|---|
| 0 | 0 | $-1$ | 0 | 7 | a→1, b→6, t→7, u→8, y→2 |
| 1 | 1 | 0 | 1 | 2 | b→5, y→2 |
| 2 | 2 | 0 | 1 | 1 | b→3 |
| 3 | 3 | 6 | 1 | 1 | a→4 |
| 4 | 4 | 1 | 1 | 1 | b→5 |
| 5 | 5 | 6 | 1 | 1 | t→7 |
| 6 | 1 | 0 | 0 (clone) | 2 | a→4, t→7 |
| 7 | 6 | 0 | 1 | 1 | u→8 |
| 8 | 7 | 0 | 1 | 1 | — |

Reverse suffix link tree (parent $\to$ children) and the propagation of $\text{cnt}$ from leaves to root:

- $0 \to \{1,2,6,7,8\}$, with $1 \to \{4\}$ and $6 \to \{3,5\}$.
- Leaves $4,3,5,2,7,8$ keep $\text{cnt}=1$; $1$ gains $\text{cnt}[4]$ $\to 2$; clone $6$ gains $\text{cnt}[3]+\text{cnt}[5]$ $\to 2$; root $0$ gains $2+1+2+1+1 \to 7$.

Traversing each pattern in the SAM:

| pattern | path | end state | $\text{cnt}$ | answer |
|---|---|---|---|---|
| $\text{"bab"}$ | $0 \xrightarrow{b} 6 \xrightarrow{a} 4 \xrightarrow{b} 5$ | 5 | 1 | 1 |
| $\text{"abc"}$ | $0 \xrightarrow{a} 1 \xrightarrow{b} 5 \xrightarrow{c}\ \text{(missing)}$ | — | — | 0 |
| $\text{"a"}$ | $0 \xrightarrow{a} 1$ | 1 | 2 | 2 |

Explanation: $\text{"bab"}$ appears only at $s[3..5]$, so $\text{cnt}=1$; $\text{"a"}$ appears at $s[1]$ and $s[4]$, so $\text{cnt}=2$; $\text{"abc"}$ is not in $s$, so $0$.

Result (one line per pattern):
```
1
0
2
```

## Complexity

- **Time:** $O(n \log \sigma + \sum |p_i| \log \sigma)$ $\textemdash$ building the SAM, propagating on the suffix link tree, and traversing the patterns ($\sigma = 26$ is the alphabet size; the $\log\sigma$ factor comes from using a transition map).
- **Memory:** $O(n)$ $\textemdash$ the SAM has at most $O(n)$ states and $O(n)$ transition edges.

## Code (C++)

[Solution Code](../code/Counting%20Patterns.cpp)
