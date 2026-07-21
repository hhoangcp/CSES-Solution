# Stick Lengths - Solution

**ID:** 1074 | **URL:** https://cses.fi/problemset/task/1074

## Approach

### Problem Restatement

There are $n$ sticks with lengths $a_1, a_2, \ldots, a_n$. Lengthening or shortening a stick by $x$ units costs $x$. We must pick one common target length $t$ and minimize the total modification cost.

### Core idea

With target length $t$, the total cost is
$$f(t) = \sum_{i=1}^{n} |a_i - t|.$$
The $t$ minimizing a sum of absolute deviations is the **median** of the lengths. To see why, sort the array so $a_1 \le a_2 \le \cdots \le a_n$. Between data points $f$ is linear, and its slope equals the number of sticks at most $t$ minus the number above $t$:
$$f'(t) = |\{i : a_i \le t\}| - |\{i : a_i > t\}| = 2\cdot|\{i : a_i \le t\}| - n.$$
This slope starts at $-n$ when $t$ is below every stick and increases by $2$ each time $t$ crosses a stick, finally reaching $+n$ above all of them. Since the slope is non-decreasing, $f$ is convex and its minimum lies where the slope first reaches $0$:
- **$n$ odd:** the slope jumps from $-1$ to $+1$ at the middle element $a_{(n+1)/2}$, the unique optimum.
- **$n$ even:** the slope is $0$ throughout $[a_{n/2}, a_{n/2+1}]$, so any value there is optimal; $a_{n/2}$ is a convenient choice.

In both cases the element at position $\lfloor (n+1)/2 \rfloor$ of the sorted array (1-indexed) is a valid median.

### Algorithm

1. Sort the lengths in non-decreasing order.
2. Take $t = a_{\lfloor (n+1)/2 \rfloor}$ as the common target (the median).
3. Output $\sum_{i=1}^{n} |a_i - t|$.

### Example

The problem's sample is $n = 5$ with $a = [2, 3, 1, 5, 2]$.

1. Sort: $[1, 2, 2, 3, 5]$.
2. Median (position $\lfloor 6/2 \rfloor = 3$): $t = 2$.
3. Cost: $|1-2| + |2-2| + |2-2| + |3-2| + |5-2| = 1 + 0 + 0 + 1 + 3 = 5$.

Answer: $5$, matching the expected output.

## Complexity

- **Time:** $O(n \log n)$ — dominated by sorting; the scan is $O(n)$.
- **Memory:** $O(n)$ — storing the array.
