# Apartments - Solution

**ID:** 1084 | **URL:** https://cses.fi/problemset/task/1084

## Approach

### Problem Restatement

There are $n$ applicants and $m$ apartments. Applicant $i$ accepts any apartment with size in $[a_i - k, a_i + k]$. Apartment $j$ has size $b_j$. Each applicant gets at most one apartment and each apartment goes to at most one applicant. Find the maximum number of matched pairs.

### Core Idea

A brute-force approach that checks every applicant-apartment pair would take $O(nm)$ — too slow. Instead, sort both arrays and apply a **greedy two-pointer** strategy: always match the smallest remaining applicant with the smallest feasible apartment. This is optimal because assigning a smaller apartment to a smaller applicant preserves larger apartments for applicants with larger requirements.

The key observation that makes two pointers work without backtracking:

- If $b_j < a_i - k$ (apartment too small), then $b_j$ is too small for every subsequent applicant as well (since $a$ is sorted increasingly), so we safely skip $b_j$.
- If $b_j > a_i + k$ (apartment too large), then all remaining apartments are also too large for applicant $i$ (since $b$ is sorted increasingly), so we safely skip applicant $i$.
- Otherwise $b_j$ lies in $[a_i - k, a_i + k]$: we match them immediately. This is safe because giving applicant $i$ the smallest feasible apartment cannot reduce the total number of matches — any optimal solution that assigns a larger apartment $b_{j^*}$ ($j^* > j$) to applicant $i$ can be transformed by swapping $b_j$ in, and the freed $b_{j^*}$ remains available for later applicants whose acceptable range is shifted rightward.

### Algorithm

1. Sort $a$ and $b$ in increasing order.
2. Initialize $i = 1$, $j = 1$, $\text{res} = 0$.
3. While $i \le n$ and $j \le m$:
   - If $a_i - b_j > k$: increment $j$ (apartment too small, skip it).
   - Else if $b_j - a_i > k$: increment $i$ (apartment too large, skip applicant).
   - Else: increment $\text{res}$, $i$, and $j$ (match found).

### Example

Input: $n = 4$, $m = 3$, $k = 5$, $a = [60, 45, 80, 60]$, $b = [30, 60, 75]$.

After sorting: $a = [45, 60, 60, 80]$, $b = [30, 60, 75]$.

| Step | $i$ | $a_i$ | $j$ | $b_j$ | Condition | Action |
|------|-----|-------|-----|-------|-----------|--------|
| 1 | 1 | 45 | 1 | 30 | $45 - 30 = 15 > 5$ | $j \to 2$ |
| 2 | 1 | 45 | 2 | 60 | $60 - 45 = 15 > 5$ | $i \to 2$ |
| 3 | 2 | 60 | 2 | 60 | $\|60 - 60\| = 0 \le 5$ | match, res = 1, $i \to 3$, $j \to 3$ |
| 4 | 3 | 60 | 3 | 75 | $75 - 60 = 15 > 5$ | $i \to 4$ |
| 5 | 4 | 80 | 3 | 75 | $\|80 - 75\| = 5 \le 5$ | match, res = 2, $i \to 5$, $j \to 4$ |

Result: **2**.

## Complexity

- **Time:** $O(n \log n + m \log m)$ — sorting dominates; two pointers traverse linearly in $O(n + m)$.
- **Space:** $O(n + m)$ — storing two arrays.

## Code (C++)

[Solution Code](../code/Apartments.cpp)
