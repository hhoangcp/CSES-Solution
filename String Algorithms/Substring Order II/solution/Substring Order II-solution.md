# Substring Order II - Solution

**ID:** 2109 | **URL:** https://cses.fi/problemset/task/2109

## Problem Statement

Given a string $s$ of length $n$ (characters 'a'–'z') and an integer $k$, order all substrings of $s$ (not necessarily distinct — each occurrence counted separately) lexicographically and print the $k$-th smallest one.

## Approach

### Step 1: SAM and propagating occurrence counts

Unlike *Substring Order I* (each distinct substring counted once), here every occurrence of a substring counts separately, so we need the occurrence count of each substring.

Build the suffix automaton (SAM) for $s$. Initialize $\text{cnt}[v] = 1$ for freshly created (non-clone) states and $\text{cnt}[\text{clone}] = 0$. Propagate along suffix links in decreasing $\text{len}$ order:

$$\text{cnt}[\text{link}[v]] \mathrel{+}= \text{cnt}[v]$$

After this, $\text{cnt}[v]$ = the number of occurrences (size of the endpos set) of the substrings of state $v$. Set $\text{cnt}[0] = 0$ (the empty string is not counted).

### Step 2: DP counting total substrings (with duplicates)

For each state $v$, compute $dp[v]$ = the total number of occurrences of all substrings reachable from $v$ (following transitions). Since every transition $v \xrightarrow{c} u$ has $\text{len}[u] > \text{len}[v]$, we process in decreasing $\text{len}$ order (topological order) and use:

$$dp[v] = \text{cnt}[v] + \sum_{v \xrightarrow{c} u} dp[u]$$

**Correctness:** each path from $v$ to state $w$ corresponds to a substring occurring $\text{cnt}[w]$ times. The total occurrences of all substrings reachable from $v$ is $\sum_{v \leadsto w} \text{cnt}[w]$. Split into "stop at $v$" (the empty path, contributing $\text{cnt}[v]$) and "take one more edge $v \xrightarrow{c} u$ then continue from $u$" (contributing $dp[u]$), giving exactly the formula above. (Since $dp[v] \le \frac{n(n+1)}{2}$, the value fits in 64 bits.)

### Step 3: Find the $k$-th substring greedily

Starting from state 0, scan transitions in lexicographic order (the `map` is already sorted). At state $\text{cur}$, for each transition $\text{cur} \xrightarrow{c} u$:

- If $dp[u] < k$: the target is not in the $c$ branch; skip it, $k \mathrel{-}= dp[u]$.
- Otherwise ($dp[u] \ge k$): the target is in the $c$ branch. Append $c$ to the answer, $\text{cur} = u$, $k \mathrel{-}= \text{cnt}[u]$ (having consumed the $\text{cnt}[u]$ occurrences of the current substring leading to $u$). If $k \le 0$, stop; if $k > 0$, continue searching for longer substrings from $u$.

**Correctness:** as in Substring Order I, the outgoing transitions in lexicographic order split the substrings into consecutive groups; scanning while decrementing $k$ stops at the group containing the $k$-th substring. Within the $c$ branch, the $\text{cnt}[u]$ occurrences of the "current string" come immediately before the longer extensions (continuing from $u$), so we subtract $\text{cnt}[u]$ first before considering extensions.

### Example

Using the example from the problem statement: $s = \text{"baabaa"}$ ($n = 6$), $k = 10$. The SAM has 8 states; $dp[0] = 21 = \frac{6\cdot 7}{2}$ (the total number of occurrences of all substrings).

Greedy search (each branch shows $c\to\text{next}$ with $dp$ and $\text{cnt}$):

| step | state | $k$ | branches | action |
|---|---|---|---|---|
| 1 | 0 | 10 | a→4 ($dp=12$, $\text{cnt}=4$), b→1 ($dp=9$, $\text{cnt}=2$) | $12\ge 10$: take `a`, $k-=\text{cnt}[4]=4\to 6$, go to 4 |
| 2 | 4 | 6 | a→3 ($dp=5$, $\text{cnt}=2$), b→5 ($dp=3$, $\text{cnt}=1$) | skip `a` ($5<6$, $k\to 1$); $3\ge 1$: take `b`, $k-=\text{cnt}[5]=1\to 0$, stop |

Answer: $\text{"ab"}$.

Check: the 10 smallest substrings (with duplicates) in order are `a`, `a`, `a`, `a`, `aa`, `aa`, `aab`, `aaba`, `aabaa`, `ab` — the 10th is indeed `ab` (four `a`s, then two `aa`s, then `aab`, `aaba`, `aabaa`, then `ab`).

Result:
```
ab
```

## Complexity

- **Time:** $O(n \log \sigma)$ $\textemdash$ building the SAM, propagating $\text{cnt}$, computing $dp$, and the greedy search are all linear in the number of states/edges (the $\log\sigma$ factor, $\sigma=26$, comes from the transition map).
- **Memory:** $O(n)$ $\textemdash$ the SAM has at most $O(n)$ states and $O(n)$ transition edges, plus the $\text{cnt}$, $dp$ arrays and the topological order.

## Code (C++)

[Solution Code](../code/Substring%20Order%20II.cpp)
