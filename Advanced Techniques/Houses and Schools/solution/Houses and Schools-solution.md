# Houses and Schools - Solution

**ID:** 2087 | **URL:** https://cses.fi/problemset/task/2087

## Approach

### Problem Restatement

There are $n$ houses on a street numbered $1, 2, \ldots, n$. The distance between houses $a$ and $b$ is $|a - b|$. Build $k$ schools (each at a house) so each child goes to the nearest school. Minimize the total walking distance.

### Core Idea

**Consecutive partition:** In the optimal solution, schools divide houses into $k$ consecutive groups on the line. If school $A$ at position $p$ serves house $h_2$ while school $B$ at position $q > p$ serves house $h_1$ with $h_1 < h_2$, reassigning $h_1$ to $A$ or $h_2$ to $B$ cannot increase cost due to the convexity of $|x - p|$. This allows a DP over partitions.

**Cost function:** Define $dp[t][j]$ = minimum cost for the first $j$ houses using $t$ schools, with the $t$-th school at position $j$. The transition adds the cost of houses between consecutive schools:

$$dp[t][j] = \min_{k < j} \left(dp[t-1][k] + \text{Cost}(k, j)\right)$$

where $\text{Cost}(k, j) = \text{Left}[k][mid] + \text{Right}[mid{+}1][j]$ with $mid = (k+j)/2$. Here houses $k$ to $mid$ go to school $k$ (closer), and houses $mid{+}1$ to $j$ go to school $j$ (closer). Precompute:
- $\text{Left}[i][j] = \sum_{k=i}^{j}(k-i) \cdot c_k$: total distance from houses $i \ldots j$ to position $i$.
- $\text{Right}[j][i] = \sum_{k=j}^{i}(i-k) \cdot c_k$: total distance from houses $j \ldots i$ to position $i$.

**D&C optimization:** The cost function satisfies the **quadrangle inequality** $\text{Cost}(a,c) + \text{Cost}(b,d) \le \text{Cost}(a,d) + \text{Cost}(b,c)$ for $a \le b \le c \le d$, which guarantees monotone optimal transition points. This enables divide-and-conquer optimization, reducing the DP from $O(kn^2)$ to $O(kn \log n)$.

### Algorithm

1. Precompute `Left` and `Right` tables in $O(n^2)$.
2. Base case: $dp[1][j] = \text{Right}[1][j]$.
3. For each $t = 2 \ldots k$, compute $dp[t][\cdot]$ using D&C optimization.
4. Answer: $\min_{j=k}^{n} (dp[k][j] + \text{Left}[j][n])$ (last school at $j$ serves houses to its right).

### Example

$n = 6$, $k = 2$, children: $[2, 7, 1, 4, 6, 4]$.

Optimal: schools at houses 2 and 5.

| House | Children | Nearest school | Distance | Cost |
|-------|----------|---------------|----------|------|
| 1 | 2 | 2 | 1 | $2 \cdot 1 = 2$ |
| 2 | 7 | 2 | 0 | 0 |
| 3 | 1 | 2 | 1 | $1 \cdot 1 = 1$ |
| 4 | 4 | 5 | 1 | $4 \cdot 1 = 4$ |
| 5 | 6 | 5 | 0 | 0 |
| 6 | 4 | 5 | 1 | $4 \cdot 1 = 4$ |

Total: $2 + 0 + 1 + 4 + 0 + 4 = 11$.

## Complexity

- **Time:** $O(n^2 + k \cdot n \log n)$ — precomputation $O(n^2)$, D&C DP $O(kn \log n)$.
- **Memory:** $O(n^2)$ — `Left` and `Right` tables.

## Code (C++)

[Solution Code](../code/Houses%20and%20Schools.cpp)
