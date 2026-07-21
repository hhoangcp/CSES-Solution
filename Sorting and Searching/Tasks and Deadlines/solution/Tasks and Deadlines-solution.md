# Tasks and Deadlines - Solution

**ID:** 1630 | **URL:** https://cses.fi/problemset/task/1630

## Problem Statement

You must process $n$ tasks. Task $i$ has duration $a_i$ and deadline $d_i$. You process all tasks in some order (one at a time), starting from time $0$. If task $i$ finishes at time $f_i$, the reward is $d_i - f_i$ (possibly negative). Find the maximum total reward.

## Approach

### 1. Analyze the objective

Suppose tasks are executed in order $\pi(1), \pi(2), \ldots, \pi(n)$. The completion time of the $k$-th task is:

$$f_{\pi(k)} = \sum_{j=1}^{k} a_{\pi(j)}$$

Total reward:

$$\sum_{k=1}^{n} (d_{\pi(k)} - f_{\pi(k)}) = \sum_{k=1}^{n} d_{\pi(k)} - \sum_{k=1}^{n} f_{\pi(k)}$$

Since $\sum_{k=1}^{n} d_{\pi(k)} = \sum_{i=1}^{n} d_i$ is a constant independent of the order, **maximizing total reward is equivalent to minimizing the sum of completion times** $\sum_{k=1}^{n} f_{\pi(k)}$.

### 2. Greedy strategy: the SPT rule (Shortest Processing Time first)

Minimizing the sum of completion times (with a common start time) has a classical solution: always process the shortest task first. This is the $1 \| \| \sum C_j$ scheduling problem, solved by sorting tasks by duration $a_i$ in increasing order.

### 3. Correctness via an exchange argument

Suppose an optimal order does not follow SPT. Then two adjacent tasks have the first with duration $a$ larger than the second with duration $b$ ($a > b$). Let $T$ be the start time of this pair:

- **Current order $(a, b)$:** completion times $T + a$ and $T + a + b$. Contribution to the sum of completion times: $(T + a) + (T + a + b) = 2T + 2a + b$.
- **Swapped order $(b, a)$:** completion times $T + b$ and $T + b + a$. Contribution: $(T + b) + (T + b + a) = 2T + a + 2b$.

Difference: $(2T + 2a + b) - (2T + a + 2b) = a - b > 0$, so the order $(b, a)$ yields a smaller sum. Swapping does not affect later tasks because the pair's total duration $a + b$ is unchanged (the pair's end time is unchanged). Hence any non-SPT order can be improved by swapping inversions until the array is sorted by increasing duration. SPT is therefore optimal.

## Example

Consider $n = 3$ tasks with $(a_i, d_i) = (6, 10), (8, 15), (5, 12)$.

Sorted by increasing duration: task 3 ($5, 12$), task 1 ($6, 10$), task 2 ($8, 15$).

- **Task 3:** completes at $t = 5$, reward $= 12 - 5 = 7$.
- **Task 1:** completes at $t = 5 + 6 = 11$, reward $= 10 - 11 = -1$.
- **Task 2:** completes at $t = 11 + 8 = 19$, reward $= 15 - 19 = -4$.

Maximum total reward: $7 + (-1) + (-4) = 2$.

## Complexity

- **Time:** $O(n \log n)$ — dominated by sorting the $n$ tasks; the result loop costs only $O(n)$.
- **Memory:** $O(n)$ to store the list of (duration, deadline) pairs.
