# Sliding Window Distinct Values - Solution

**ID:** 3222 | **URL:** https://cses.fi/problemset/task/3222

## Approach

### Problem Restatement

Given an array of $n$ integers, for each sliding window of $k$ consecutive elements, count the number of distinct values.

### Core Idea

When the window slides right by one position, only two elements change: one enters, one leaves. Maintain a frequency map of the current window and update it incrementally. The number of distinct values equals `map.size()`, provided keys with frequency 0 are erased — otherwise they would be overcounted.

### Algorithm

Maintain a frequency map `cnt`. Iterate $i$ from 1 to $n$:

1. **Add** $a[i]$: increment `cnt[a[i]]`.
2. **Remove** $a[i-k]$ (when $i > k$): decrement `cnt[a[i-k]]`. If the count reaches 0, erase the key.
3. **Output** (when $i \ge k$): the answer is `cnt.size()`.

The erase step is critical: a key with frequency 0 does not correspond to any element in the window, so keeping it would inflate `cnt.size()`. After erasing, every key in the map has frequency $> 0$, meaning `cnt.size()` exactly equals the number of distinct values present.

### Example

With $n=8$, $k=3$, array $[1, 2, 3, 2, 5, 2, 2, 2]$:

- $i=3$: cnt $= \{1, 2, 3\}$, output 3
- $i=4$: add 2, remove 1 (erased). cnt $= \{2, 3\}$, output 2
- $i=5$: add 5, remove 2 (freq 2→1). cnt $= \{2, 3, 5\}$, output 3
- $i=6$: add 2, remove 3 (erased). cnt $= \{2, 5\}$, output 2
- $i=7$: add 2, remove 2 (freq 3→2). cnt $= \{2, 5\}$, output 2
- $i=8$: add 2, remove 5 (erased). cnt $= \{2\}$, output 1

Output: `3 2 3 2 2 1`

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(k)$

## Code (C++)

[Solution Code](../code/Sliding%20Window%20Distinct%20Values.cpp)
