# Sliding Window Mode - Solution

**ID:** 3224 | **URL:** https://cses.fi/problemset/task/3224

## Approach

### Problem Restatement

Given an array of $n$ integers, for each sliding window of $k$ consecutive elements, find the mode — the most frequent element. If multiple elements share the highest frequency, choose the smallest value.

### Core Idea

Maintain a frequency map and a sorted set of (frequency, $-$value) pairs. The last element of the set gives the highest frequency with the smallest value, since sorting by (freq ascending, $-$value ascending) places the maximum frequency and largest $-$value (i.e., smallest value) at the end.

### Algorithm

**Step 1: Data structures.** Maintain:
- `map<int,int> cnt`: frequency of each value in the current window.
- `set<pair<int,int>> S`: pairs of (frequency, $-$value) for all values in the window.

**Step 2: Slide the window.** For each position $i$:
1. **Add** $a[i]$: erase old pair $(\text{cnt}[a[i]], -a[i])$ from $S$ (if it exists), increment `cnt[a[i]]`, insert new pair.
2. **Remove** $a[i-k]$ (when $i > k$): erase old pair from $S$, decrement `cnt[a[i-k]]`. If count reaches 0, erase from `cnt`; otherwise, insert updated pair into $S$.
3. **Mode** is $-S.\text{rbegin()} \to \text{second}$.

The set sorts lexicographically by (frequency, $-$value). The last element has the highest frequency; among elements with that frequency, the largest $-$value corresponds to the smallest original value. Thus `*S.rbegin()` correctly gives the mode under the problem's tiebreaking rule.

### Example

With $n=8$, $k=3$, array $[1, 2, 3, 2, 5, 2, 4, 4]$:

- $i=3$: $S = \{(1,-3), (1,-2), (1,-1)\}$. mode $= -(-1) = \mathbf{1}$
- $i=4$: add 2 (1→2 freq), remove 1. $S = \{(1,-3), (2,-2)\}$. mode $= \mathbf{2}$
- $i=5$: add 5, remove 2 (2→1 freq). $S = \{(1,-5), (1,-3), (1,-2)\}$. mode $= \mathbf{2}$
- $i=6$: add 2 (1→2 freq), remove 3. $S = \{(1,-5), (2,-2)\}$. mode $= \mathbf{2}$
- $i=7$: add 4, remove 2 (2→1 freq). $S = \{(1,-5), (1,-4), (1,-2)\}$. mode $= \mathbf{2}$
- $i=8$: add 4 (1→2 freq), remove 5. $S = \{(1,-2), (2,-4)\}$. mode $= \mathbf{4}$

Output: `1 2 2 2 2 4`

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Sliding%20Window%20Mode.cpp)
