# Collecting Numbers II - Solution

**ID:** 2217 | **URL:** https://cses.fi/problemset/task/2217

## Approach

### Problem Restatement

Given an array where each number from $1$ to $n$ appears exactly once, and $m$ swap operations, print the number of collection rounds after each swap. A round traverses the array left to right, collecting numbers in increasing order.

### Core Idea

From *Collecting Numbers*, the number of rounds equals $1 + \sum_{i=1}^{n-1} [\text{pos}[i+1] < \text{pos}[i]]$ where $\text{pos}[v]$ is the position of value $v$. When swapping two elements at positions $a$ and $b$, only $\text{pos}[x]$ and $\text{pos}[y]$ change (where $x$, $y$ are the swapped values). Therefore, only adjacent-value pairs involving $x$ or $y$ — at most 4 pairs: $(x-1, x)$, $(x, x+1)$, $(y-1, y)$, $(y, y+1)$ — can change state. The global sum splits into an unchanged part and a local varying part, so we simply subtract old contributions of affected pairs, perform the swap, then add new contributions. When $|x - y| = 1$, the overlapping pair appears once and must not be double-counted.

### Algorithm

1. Initialize: build $\text{pos}$ array, compute initial round count.
2. For each swap of positions $a$ and $b$:
   - Let $x$, $y$ be the values at those positions (ensure $x < y$).
   - **Subtract old:** for each affected pair, if $\text{pos}[v+1] < \text{pos}[v]$, decrement Round.
   - **Swap:** update value array and $\text{pos}[x]$, $\text{pos}[y]$.
   - **Add new:** for each affected pair, if $\text{pos}[v+1] < \text{pos}[v]$, increment Round.
   - Print Round.

### Example

Initial array $[4, 2, 1, 5, 3]$, $n = 5$.

$\text{pos}[1]=3$, $\text{pos}[2]=2$, $\text{pos}[3]=5$, $\text{pos}[4]=1$, $\text{pos}[5]=4$. Violating pairs: $(1,2)$ and $(3,4)$. Round = $1 + 2 = 3$.

**Swap 1:** positions 2 and 3 ($x=1, y=2$, $|x-y|=1$).

Affected pair: $(1,2)$. Before: violating → subtract 1, Round = 2. Swap: pos[1]=2, pos[2]=3. After: $\text{pos}[2]=3 > \text{pos}[1]=2$ → not violating. Result: **2**.

Array: $[4, 1, 2, 5, 3]$.

**Swap 2:** positions 1 and 5 ($x=3, y=4$, $|x-y|=1$).

Affected pairs: $(3,4)$, $(2,3)$, $(4,5)$. Before: only $(3,4)$ violating → subtract 1, Round = 1. Swap: pos[3]=1, pos[4]=5. After: $(2,3)$ violating, $(4,5)$ violating → add 2, Round = 3. Result: **3**.

Array: $[3, 1, 2, 5, 4]$.

**Swap 3:** positions 2 and 3 ($x=1, y=2$, $|x-y|=1$).

Affected pairs: $(1,2)$, $(2,3)$. Before: $(2,3)$ violating → subtract 1, Round = 2. Swap: pos[1]=3, pos[2]=2. After: $(1,2)$ violating, $(2,3)$ violating → add 2, Round = 4. Result: **4**.

## Complexity

- **Time:** $O(n + m)$ — initialization $O(n)$, each swap $O(1)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Collecting%20Numbers%20II.cpp)
