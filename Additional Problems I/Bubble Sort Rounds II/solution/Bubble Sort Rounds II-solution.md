# Bubble Sort Rounds II - Solution

**ID:** 3152 | **URL:** https://cses.fi/problemset/task/3152

## Problem Statement

Given an array of $n$ integers and an integer $k$, find the contents of the array after performing $k$ rounds of Bubble Sort. Note that $k$ can be very large ($10^9$), exceeding the number of rounds needed to fully sort the array.

## Approach

### 1. Analyzing the effect after $k$ bubble sort rounds

As established in the previous problem, in each round of Bubble Sort, an element can "bubble up" (shift left) by at most 1 position. Therefore, after $k$ rounds:

- An element originally at position $i$ can move to any position in the range $[i-k, n-1]$, depending on its value relative to surrounding elements.
- More importantly, at position $i$ of the result array, the chosen value will be the **smallest** among all unchosen elements that can "bubble" to position $i$ after $k$ rounds.

### 2. Algorithm: Sliding window and Min-Heap

To efficiently simulate this effect without running each round in $O(k \cdot n)$, we use a priority queue (Min-Heap) to manage candidates for each position:

1. Iterate through each position $i$ from $0$ to $n-1$ of the result array.
2. For each position $i$, push all elements from the original array that haven't been added to the Heap yet and whose index falls in the range $[0, i+k]$ into the Min-Heap.
3. Extract the smallest element currently in the Heap and place it at position $i$ of the result array.
4. Repeat until the result array is fully filled.

### 3. Proof of correctness

- **Feasibility:** An element at position $j$ in the original array can appear at position $i$ in the result if and only if $j - i \le k$ (i.e., $j \le i+k$). This matches the way we push elements into the Heap up to index $i+k$.
- **Greedy optimality:** Bubble Sort always prioritizes moving smaller elements up first. Taking `pq.top()` (the smallest element) correctly simulates the priority order of the bubble sort algorithm.

### Example walkthrough

Array: `3 2 4 1 4`, $k = 2$.

| Position $i$ | Range pushed into Heap | Heap (before extraction) | Result $res[i]$ |
|:---|:---|:---|:---|
| 0 | $a[0 \dots 2]: \{3, 2, 4\}$ | $\{2, 3, 4\}$ | **2** |
| 1 | $a[3 \dots 3]: \{1\}$ | $\{1, 3, 4\}$ | **1** |
| 2 | $a[4 \dots 4]: \{4\}$ | $\{3, 4, 4\}$ | **3** |
| 3 | (None remaining) | $\{4, 4\}$ | **4** |
| 4 | (None remaining) | $\{4\}$ | **4** |

Final result: `2 1 3 4 4`.

### Note on large $k$

If $k \ge n-1$, the array will be fully sorted. The Min-Heap algorithm still works correctly in this case because the Heap's push range quickly covers the entire original array, equivalent to performing a full `sort`.

## Complexity

- **Time:** $O(n \log n)$. Each element is pushed into and extracted from the Min-Heap exactly once, with each operation costing $O(\log n)$.
- **Memory:** $O(n)$ for storing the original array, result array, and priority queue.

## Code (C++)

[Solution Code](../code/Bubble%20Sort%20Rounds%20II.cpp)
