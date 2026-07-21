# Stick Difference - Solution

**ID:** 3401 | **URL:** https://cses.fi/problemset/task/3401

## Problem Statement

Given $n$ sticks of lengths $a_1, a_2, \ldots, a_n$, perform exactly $k$ cuts so the number of sticks becomes $n + k$. After cutting, minimize the difference between the longest and shortest stick. Compute this minimum difference for all $k = 1, 2, \ldots, m$.

## Approach

### Step 1: Minimize the maximum stick (Arrays `H` and `seg`)

Use a max-heap with elements $(\lceil a_i/p \rceil,\ p,\ id)$. At each step, extract the stick producing the largest piece and cut it once more ($p \to p+1$). Let $H[k]$ be the minimum possible Max after $k$ cuts. Also record `seg[k] = (actual Min, actual Max)` of this configuration.

**Optimality of $H[k]$ (Exchange Lemma):** Suppose a $k$-cut strategy achieves Max $< H[k]$. If a cut doesn't target the current longest stick but stick $t$, exchanging it to cut the longest stick gives Max $\le$ before (the longest stick is split smaller, $t$ uncut is $\le$ the longest). Repeating exchanges, always cutting the longest stick is optimal. Even division giving $\lceil a_i/p \rceil$ is internally optimal.

**Uniqueness of `seg[k]`:** To push Max down to exactly $H[k]$, all $k$ cuts must be spent on the longest sticks with none left to adjust the shortest. The configuration is unique, so `seg[k].fst` exactly reflects the Min that falls in this forced configuration.

### Step 2: Maximize the minimum stick (Array `L`)

Use a max-heap by $\lfloor a_i/p \rfloor$: always cut the stick with the largest minimum piece. Let $L[k]$ be the absolute ceiling of Min after $k$ cuts.

**Optimality of $L[k]$ (Exchange Lemma):** If cutting stick $t$ (with smaller $\lfloor a_t/p_t \rfloor$) instead of stick $s$ (with larger $\lfloor a_s/p_s \rfloor$), exchanging from $t$ to $s$ gives min piece $\lfloor a_s/(p_s+1) \rfloor \ge \lfloor a_t/(p_t+1) \rfloor$, not decreasing the global Min. Repeating yields the greedy strategy.

**Corollary:** Every $k$-cut strategy has Min $\le L[k]$. The system grants at least $k$ safe cuts that don't push Min below $L[k]$.

### Step 3: Hybrid combination (Sliding window)

For each $k$, find a "hybrid" configuration: use $i$ cuts to push Max down (per `seg[i]`), and $k-i$ surplus cuts to trim further without dropping Min too low.

Use two pointers `pA`, `pR` and a `multiset st`:
- `pA` expands: add configurations with $\text{Max} \ge H[k]$ into `st`.
- `pR` shrinks: remove configurations with $\text{Min} > L[k]$ from `st`.

The answer for $k$ cuts is the minimum of 2 cases:
1. **`*st.begin()`** (Min shattered below $L[k]$): configurations in `st` ($pR \le i < pA$), difference is `seg[i].snd - seg[i].fst`.
2. **`seg[pR - 1].snd - L[k]`** (Safe landing at $L[k]$): at state $pR-1$, all pieces $> L[k]$. Owes $k - (pR-1)$ cuts. By the property of $L[k]$, the remaining safe-cut budget exceeds the debt, so applying Strategy B for the owed cuts makes Min decrease gradually and **stop exactly at $L[k]$**.

### Example

$n = 3, m = 3$, lengths: $[7, 3, 2]$.

$H[1] = 4$, $H[2] = 3$, $H[3] = 3$; $L[1] = 2$, $L[2] = 2$, $L[3] = 1$.

Results: $k=1$: $4-2=2$; $k=2$: $3-2=1$; $k=3$: $3-1=2$.

## Complexity

- **Time:** $O((n + m) \log n)$ for heap operations + $O(m \log m)$ for sliding window.
- **Memory:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Stick%20Difference.cpp)
