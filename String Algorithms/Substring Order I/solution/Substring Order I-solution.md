# Substring Order I - Solution

**ID:** 2108 | **URL:** https://cses.fi/problemset/task/2108

## Problem Statement

Given a string $s$ of length $n$ (characters 'a'–'z') and an integer $k$, order all distinct substrings of $s$ lexicographically and print the $k$-th smallest one.

## Approach

### Step 1: Build the SAM

Build the suffix automaton (SAM) for $s$: a minimal DFA recognizing exactly the set of distinct substrings of $s$. Each path from the initial state (state 0) following transitions corresponds to a distinct substring, and vice versa.

### Step 2: DP counting distinct substrings

For each state $v$, compute $dp[v]$ = the number of distinct substrings reachable from $v$ (following transitions). Since every transition $v \xrightarrow{c} u$ has $\text{len}[u] > \text{len}[v]$, we process states in decreasing $\text{len}$ order (a counting sort, i.e. topological order) and use:

$$dp[v] = \sum_{v \xrightarrow{c} u} (dp[u] + 1)$$

**Correctness:** each path from $v$ corresponds to a distinct substring (SAM is a DFA). For a transition $v \xrightarrow{c} u$, substrings starting with $c$ are: $c$ itself (1 substring) and $c$ followed by any substring from $u$ ($dp[u]$ substrings) — total $dp[u]+1$. Summing over the outgoing transitions gives $dp[v]$. (Since $dp[v] \le \frac{n(n+1)}{2}$, each value is capped by a large constant to avoid overflow.)

### Step 3: Find the $k$-th substring greedily

Starting from state 0, scan the transitions in lexicographic order (using a `map`, so the characters are already sorted). At state $\text{cur}$, for each transition $\text{cur} \xrightarrow{c} u$:

- If $dp[u] + 1 < k$: the target is not in the $c$ branch; skip it, $k \mathrel{-}= dp[u] + 1$.
- Otherwise ($dp[u] + 1 \ge k$): the target is in the $c$ branch; append $c$ to the answer, $\text{cur} = u$, $k \mathrel{-}= 1$ (having chosen the single-character substring $c$), and continue searching from $u$.

Repeat until $k = 0$.

**Correctness:** the outgoing transitions of a state in lexicographic order split the substrings into consecutive groups (the first group = substrings starting with the smallest character, etc.). Scanning in this order while decrementing $k$ stops at the group containing the $k$-th substring; within the group, the same reasoning applies recursively.

### Example

Using the example from the problem statement: $s = \text{"babaacbaab"}$ ($n = 10$), $k = 10$. The SAM has 14 states; $dp[0] = 43$ (the total number of distinct substrings).

Greedy search (each branch shows $c\to\text{next}$ and its count $dp[\text{next}]+1$):

| step | state | $k$ | branches | action |
|---|---|---|---|---|
| 1 | 0 | 10 | a→6 (21), b→1 (17), c→7 (5) | $21 \ge 10$: take `a`, $k\to9$, go to 6 |
| 2 | 6 | 9 | a→11 (7), b→13 (8), c→7 (5) | skip `a` ($7<9$, $k\to2$); $8\ge 2$: take `b`, $k\to1$, go to 13 |
| 3 | 13 | 1 | a→4 (7) | $7\ge 1$: take `a`, $k\to0$, stop |

Answer: $\text{"aba"}$.

Check: the 10 smallest distinct substrings in order are `a`, `aa`, `aab`, `aac`, `aacb`, `aacba`, `aacbaa`, `aacbaab`, `ab`, `aba`; the 10th is indeed `aba`.

Result:
```
aba
```

## Complexity

- **Time:** $O(n \log \sigma)$ $\textemdash$ building the SAM (with a transition map, $\sigma = 26$), the counting-sort topological order, computing $dp$, and the greedy search are all linear in the number of states/edges (the $\log\sigma$ factor comes from the transition map).
- **Memory:** $O(n)$ $\textemdash$ the SAM has at most $O(n)$ states and $O(n)$ transition edges, plus the $dp$ array and the topological order.

## Code (C++)

[Solution Code](../code/Substring%20Order%20I.cpp)
