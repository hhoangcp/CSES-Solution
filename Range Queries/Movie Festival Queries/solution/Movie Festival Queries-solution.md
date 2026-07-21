# Movie Festival Queries - Solution

**ID:** 1664 | **URL:** https://cses.fi/problemset/task/1664

## Approach

### Problem Restatement

Given $n$ movies with start and end times, process $q$ queries: if you arrive at time $s$ and leave at time $t$, what is the maximum number of movies you can watch entirely? You can watch movie $j$ after movie $i$ if movie $i$ ends $\le$ movie $j$ starts.

### Core idea

The greedy strategy for movie scheduling is to always pick the movie that ends earliest. Working backwards from the end time $t$, this translates to: at each step, jump to the **latest start time** of a movie ending at or before the current time. Define:

$$f[v] = \max\left(\max\{s_i : t_i \le v\}, f[v-1]\right)$$

The prefix maximum ensures $f$ is non-decreasing. Standing at time $v$, watching one optimally-chosen movie jumps us back to $f[v]$. This is the greedy choice: picking the movie ending closest to $v$ with the latest start maximizes remaining time for subsequent movies.

To avoid linear-time traversal, apply **binary lifting**: build $\text{jump}[v][i]$ = the time reached after watching $2^i$ movies starting from $v$. Base case: $\text{jump}[v][0] = f[v]$. Transition: $\text{jump}[v][i] = \text{jump}[\text{jump}[v][i-1]][i-1]$. This is correct by induction: watching $2^{i-1}$ movies from $v$ reaches $\text{jump}[v][i-1]$, then $2^{i-1}$ more from there reaches $\text{jump}[\text{jump}[v][i-1]][i-1]$, totaling $2^i$ movies.

### Algorithm

1. **Build $f$:** For each movie $(s_i, t_i)$, set $\text{jump}[t_i][0] = \max(\text{jump}[t_i][0], s_i)$. Then compute prefix maximum over time.
2. **Build binary lifting table:** For $i = 1$ to $20$, for each time $v$: $\text{jump}[v][i] = \text{jump}[\text{jump}[v][i-1]][i-1]$.
3. **Answer query** $(s, t)$: Iterate $i$ from $20$ down to $0$. If $\text{jump}[t][i] \ge s$, add $2^i$ to the answer and set $t = \text{jump}[t][i]$.

### Example

Input:
```
4 3
2 5
6 10
4 7
9 10
5 9
2 10
7 10
```

Movies: $(2,5)$, $(6,10)$, $(4,7)$, $(9,10)$. Key $f$ values: $f[5]=2$, $f[7]=4$, $f[9]=4$, $f[10]=9$.

- Query $(5,9)$: $\text{jump}[9][0] = 4 < 5$. Cannot watch any movie. Answer = **0**.
- Query $(2,10)$: $\text{jump}[10][1] = \text{jump}[f[10]][0] = \text{jump}[9][0] = 4 \ge 2$. Take jump: $+2$ movies, $t = 4$. Then $\text{jump}[4][0] = 0 < 2$. Stop. Answer = **2**.
- Query $(7,10)$: $\text{jump}[10][0] = 9 \ge 7$. Take jump: $+1$ movie, $t = 9$. Then $\text{jump}[9][0] = 4 < 7$. Stop. Answer = **1**.

Output:
```
0
2
1
```

## Complexity

- **Time:** $O(T \log T + q \log T)$ with $T = 10^6$
- **Space:** $O(T \log T)$

## Code (C++)

[Solution Code](../code/Movie%20Festival%20Queries.cpp)
