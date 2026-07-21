# Towers - Solution

**ID:** 1073 | **URL:** https://cses.fi/problemset/task/1073

## Problem Statement

You are given $n$ cubes in a certain order. Build towers from them so that whenever two cubes are stacked, the upper cube is strictly smaller than the lower one. You must process the cubes in the given order; at each step you may place the current cube on top of an existing tower or start a new tower. Find the minimum number of towers.

## Approach

### 1. Analyze the greedy strategy

When processing a cube of size $a$, there are two options:

1. Place $a$ on top of an existing tower (requiring that tower's top $> a$).
2. Start a new tower with top $a$.

To minimize the number of towers, we always prefer reusing an existing tower. When several towers have tops $> a$, apply the rule: **place $a$ on the tower whose top is the smallest value still greater than $a$**.

**Reason:** Choosing a tower with an unnecessarily large top wastes a good "foundation" that could hold a larger cube appearing later. Picking the smallest top still $> a$ preserves larger tops for future cubes, maximizing tower reuse.

### 2. Optimize with binary search

We maintain an array `top[]` of tower-top values, always kept sorted increasingly. For each cube of size $a$, binary-search the smallest position $p$ with $\text{top}[p] > a$ (i.e., `std::upper_bound`):

- **Found:** set $\text{top}[p] = a$ (place the cube on tower $p$).
- **Not found:** every top is $\le a$, so we must start a new tower by appending $a$ to `top[]`.

### 3. Preserve the sortedness of the top array

When replacing $\text{top}[p] = a$, the array stays sorted because:

- $\text{top}[p-1] \le a$: since $p$ is the first position with value $> a$, the element just before it is $\le a$.
- $a < \text{top}[p+1]$: since $a < \text{top}[p]_{\text{old}}$ and $\text{top}[p]_{\text{old}} \le \text{top}[p+1]$ (the array is sorted), we get $a < \text{top}[p+1]$.

### 4. Correctness via Dilworth's theorem

The problem is a classic application of **Dilworth's theorem**. Define a partial order: cube $i$ may lie below cube $j$ iff $i$ appears before $j$ ($i < j$) and $k_i > k_j$ (the lower cube is larger). Each valid tower is a strictly decreasing chain in this order.

By Dilworth, the minimum number of chains needed to cover the whole set equals the size of the largest antichain. An antichain is a set of cubes none of which can be stacked on another, corresponding to a **non-decreasing subsequence** (if $i < j$ and $k_i \le k_j$, then $i$ cannot lie below $j$). Hence the minimum number of towers equals the length of the longest non-decreasing subsequence (LNDS). The greedy algorithm with binary search above exactly simulates computing the LNDS length, so its result is always optimal.

## Example

Consider cube sizes $a = [3, 8, 2, 1, 5]$, $n = 5$.

| Step | Cube $a$ | `top[]` before | Position $p$ | Action | `top[]` after |
| --- | --- | --- | --- | --- | --- |
| 1 | 3 | $[]$ | not found | new tower | $[3]$ |
| 2 | 8 | $[3]$ | not found ($3 \le 8$) | new tower | $[3, 8]$ |
| 3 | 2 | $[3, 8]$ | $p=1$ ($\text{top}[1]=3>2$) | place on tower 1 | $[2, 8]$ |
| 4 | 1 | $[2, 8]$ | $p=1$ ($\text{top}[1]=2>1$) | place on tower 1 | $[1, 8]$ |
| 5 | 5 | $[1, 8]$ | $p=2$ ($\text{top}[2]=8>5$) | place on tower 2 | $[1, 5]$ |

Result: the minimum number of towers is the size of `top[]`, i.e., $2$. (Tower 1: $3 \to 2 \to 1$; tower 2: $8 \to 5$.)

## Complexity

- **Time:** $O(n \log n)$ — scanning $n$ cubes, each doing a binary search on the top array (length at most $n$) in $O(\log n)$.
- **Memory:** $O(n)$ for the `top[]` array.
