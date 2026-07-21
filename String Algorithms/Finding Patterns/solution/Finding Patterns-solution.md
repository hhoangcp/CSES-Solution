# Finding Patterns - Solution

**ID:** 2102 | **URL:** https://cses.fi/problemset/task/2102

## Problem Statement

Given a string $s$ of length $n$ and $k$ patterns, determine for each pattern whether it appears as a substring in $s$.

## Approach

### Step 1: Suffix automaton (SAM)

The suffix automaton of $s$ is a minimal DFA recognizing **exactly** the set of all substrings of $s$. It is built online by appending the characters of $s$ one at a time.

Each state $v$ stores:
- $\text{len}[v]$: the length of the longest string ending at $v$;
- $\text{link}[v]$: the suffix link, pointing to the state representing the longest proper suffix of the string belonging to $v$.

The SAM has at most $2n - 1$ states.

**Core property:** A string $p$ is a substring of $s$ iff, starting from the initial state and following transitions for the characters of $p$ in order, we never get stuck.

*This equivalence* is the basis of the solution: ($\Leftarrow$) every substring of $s$ is a prefix of some suffix; during online construction the last state always represents the suffix $s[1..i]$, and via suffix links every suffix has a path from the root, so every prefix of a suffix (every substring) is recognized. ($\Rightarrow$) each transition $v \xrightarrow{c} u$ is added only when $c$ actually appears right after the string represented by $v$ at some position in $s$, so every path from the root spells a substring of $s$.

### Step 2: Building the SAM

When appending character $c$ to the current string ($\text{last}$ is the state after the previous character):

1. Create a new state $\text{cur}$ with $\text{len}[\text{cur}] = \text{len}[\text{last}] + 1$.
2. Walk up the suffix links from $\text{last}$; for each state $p$ without a $c$-transition, add the edge $p \xrightarrow{c} \text{cur}$.
3. If the walk ends without meeting a state that already has a $c$-edge ($p = -1$), set $\text{link}[\text{cur}] = 0$.
4. Otherwise, let $p$ be a state with an existing edge $p \xrightarrow{c} q$:
   - If $\text{len}[q] = \text{len}[p] + 1$: set $\text{link}[\text{cur}] = q$.
   - If $\text{len}[q] > \text{len}[p] + 1$: **clone** $q$ into a new state $\text{clone}$ with $\text{len}[\text{clone}] = \text{len}[p]+1$, $\text{link}[\text{clone}] = \text{link}[q]$, inheriting all of $q$'s transitions; then set $\text{link}[q] = \text{link}[\text{cur}] = \text{clone}$, and redirect the $c$-transitions from ancestors of $p$ that pointed to $q$ so they point to $\text{clone}$ instead.
5. Update $\text{last} = \text{cur}$.

### Step 3: Checking patterns

For each pattern $p$: start from the initial state and follow transitions for the characters of $p$ in order.

- If at the current state there is no transition for the next character of $p$ $\to$ the pattern does not appear, output `NO`.
- If all of $p$ is consumed without getting stuck $\to$ the pattern is a substring of $s$, output `YES`.

### Example

Using the example from the problem statement: $s = \text{"aybabtu"}$ ($n = 7$), patterns $\text{"bab"}$, $\text{"abc"}$, $\text{"ayba"}$.

The SAM has 9 states (state 6 is a clone). State table and transitions:

| state | $\text{len}$ | $\text{link}$ | transitions |
|---|---|---|---|
| 0 | 0 | $-1$ | a→1, b→6, t→7, u→8, y→2 |
| 1 | 1 | 0 | b→5, y→2 |
| 2 | 2 | 0 | b→3 |
| 3 | 3 | 6 | a→4 |
| 4 | 4 | 1 | b→5 |
| 5 | 5 | 6 | t→7 |
| 6 | 1 | 0 (clone) | a→4, t→7 |
| 7 | 6 | 0 | u→8 |
| 8 | 7 | 0 | — |

Traversing each pattern in the SAM:

| pattern | path | result | occurrence |
|---|---|---|---|
| $\text{"bab"}$ | $0 \xrightarrow{b} 6 \xrightarrow{a} 4 \xrightarrow{b} 5$ | `YES` | $s[3..5]$ |
| $\text{"abc"}$ | $0 \xrightarrow{a} 1 \xrightarrow{b} 5 \xrightarrow{c}\ \text{(missing)}$ | `NO` | — |
| $\text{"ayba"}$ | $0 \xrightarrow{a} 1 \xrightarrow{y} 2 \xrightarrow{b} 3 \xrightarrow{a} 4$ | `YES` | $s[1..4]$ |

Result:
```
YES
NO
YES
```

## Complexity

- **Time:** $O(n \log \sigma + \sum |p_i| \log \sigma)$ $\textemdash$ building the SAM and traversing the patterns ($\sigma = 26$ is the alphabet size; the $\log\sigma$ factor comes from using a transition map).
- **Memory:** $O(n)$ $\textemdash$ the SAM has at most $O(n)$ states and $O(n)$ transition edges.

## Code (C++)

[Solution Code](../code/Finding%20Patterns.cpp)
