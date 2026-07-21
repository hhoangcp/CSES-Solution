# Sliding Window Minimum - Solution

**ID:** 3221 | **URL:** https://cses.fi/problemset/task/3221

## Approach

### Problem Restatement

Given an array of $n$ integers (generated via $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$), find the minimum of each sliding window of $k$ elements. Output the XOR of all minimums. Note: $n$ can be up to $10^7$, requiring $O(n)$ time and avoiding output of individual values.

### Core Idea

Use a monotonic deque storing indices in non-decreasing order of their values. The front always holds the index of the current window's minimum. Each index is pushed once and removed at most once, giving $O(n)$ total.

### Algorithm

**Step 1: Generate the array.** Compute $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$ for $i \ge 2$. Use 64-bit multiplication to avoid overflow.

**Step 2: Monotonic deque.** For each position $i$:
1. Remove from back: pop indices $j$ with $x[j] \ge x[i]$. Such elements can never be the minimum for any future window containing $i$, since $x[i]$ is smaller and stays in the window longer.
2. Remove from front: pop indices $\le i - k$ (outside the current window).
3. Push $i$ to the back.
4. When $i \ge k$: the minimum is $x[\text{dq.front()}]$. XOR it into the answer.

After steps 1 and 3, the deque is non-decreasing in value, so the front is always the minimum. No viable minimum candidate is lost: back-removal only discards elements dominated by a smaller, newer one; front-removal only discards out-of-window elements.

### Example

With $n=8$, $k=5$, generator $x=3, a=7, b=1, c=11$:

Generated array: $[3, 0, 1, 8, 2, 4, 7, 6]$.

Deque trace (1-indexed):
- $i=1$: push 1. dq=[1]
- $i=2$: $x[1]=3 \ge 0$, pop 1. Push 2. dq=[2]
- $i=3$: push 3. dq=[2,3]
- $i=4$: push 4. dq=[2,3,4]
- $i=5$: $x[4]=8 \ge 2$, pop 4. Push 5. dq=[2,3,5]. Min $= x[2] = 0$
- $i=6$: push 6. dq=[2,3,5,6]. Min $= x[2] = 0$
- $i=7$: front 2 $\le 7-5$, pop front. dq=[3,5,6]. Push 7. dq=[3,5,6,7]. Min $= x[3] = 1$
- $i=8$: $x[7]=7 \ge 6$, pop 7. Front 3 $\le 8-5$, pop front. dq=[5,6]. Push 8. dq=[5,6,8]. Min $= x[5] = 2$

Minimums: $0, 0, 1, 2$. Answer: $0 \oplus 0 \oplus 1 \oplus 2 = 3$.

## Complexity

- **Time:** $O(n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Sliding%20Window%20Minimum.cpp)
