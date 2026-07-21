# Swap Round Sorting - Solution

**ID:** 1698 | **URL:** https://cses.fi/problemset/task/1698

## Approach

### Step 1: Analyze permutation cycles

Decompose the permutation into disjoint cycles. Starting from node $i$, follow $i \to a_i \to a_{a_i} \to \ldots$ until returning to $i$. Cycles of length 1 are already in place, length 2 needs 1 swap, length $c \geq 3$ needs at most 2 rounds.

### Step 2: Round 1 — Reverse the cycles

For each cycle $S = [v_0, v_1, \ldots, v_{m-1}]$ (where $a[v_k] = v_{k+1}$, $v_m = v_0$), swap symmetric pairs: `swap(a[v_l], a[v_r])` with $l < r$ and $l + r = m - 1$. Each element appears at most once, so swaps don't overlap and execute in 1 round.

**Symmetry property after round 1 ($a[i]=j \Leftrightarrow a[j]=i$):** Position $v_l$ after swapping receives the old value of $a[v_r]$, i.e., $v_{r+1} = v_{m-l}$. Position $v_{m-l}$ swaps with $v_{l-1}$, receiving the old value of $a[v_{l-1}] = v_l$. Thus $a[v_l] = v_{m-l}$ and $a[v_{m-l}] = v_l$. Long cycles become cycles of length 2 (or 1 if already correct).

### Step 3: Round 2 — Place elements correctly

After round 1, the array only has symmetric error pairs: $a[i] = j$ and $a[j] = i$. Scan the array; if $a[i] < i$, swap positions $a[i]$ and $i$. This places both elements correctly at once. Since $a[a[i]] = i$ (by symmetry), position $a[i]$ is correct after the swap and doesn't participate in another swap $\Rightarrow$ swaps don't overlap, executable in 1 round.

### Minimum number of rounds

- Already sorted: 0 rounds.
- All cycles length $\leq 2$: 1 round.
- Any cycle length $\geq 3$: at least 2 rounds needed (an element requires at least 2 swaps to reach its correct position, 1 round allows at most 1 swap per element), and the algorithm uses exactly 2 rounds.

### Example

$n = 5$, permutation: $[5, 2, 1, 3, 4]$. Cycle: $(1, 5, 4, 3)$.

- **Round 1:** Swap positions $1 \leftrightarrow 3$ and $5 \leftrightarrow 4$. Array: $[1, 2, 5, 4, 3]$. Now $a[3]=5$ and $a[5]=3$ (symmetric).
- **Round 2:** See $a[5]=3 < 5$, swap positions $3 \leftrightarrow 5$. Array: $[1, 2, 3, 4, 5]$.

Result: 2 rounds.

## Complexity

- **Time:** $O(n)$
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Swap%20Round%20Sorting.cpp)
