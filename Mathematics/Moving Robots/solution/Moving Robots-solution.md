# Moving Robots - Solution

**ID:** 1726 | **URL:** https://cses.fi/problemset/task/1726

## Approach

### Problem Restatement

An $8 \times 8$ board has one robot per cell. Each robot independently makes $k$ random moves, each step choosing uniformly among valid directions (up, down, left, right, staying within the board). Multiple robots can share a cell. Compute the expected number of empty cells after $k$ steps, rounded to 6 decimal places.

### Core idea

By **linearity of expectation**, the expected number of empty cells equals the sum of probabilities that each cell is empty:

$$E[\text{empty cells}] = \sum_{(x,y)} P(\text{cell } (x,y) \text{ is empty})$$

Since robots move independently, cell $(x,y)$ is empty if and only if **no** robot ends up there. The probability is the product of complementary probabilities:

$$P(\text{cell } (x,y) \text{ empty}) = \prod_{(i,j)} \left(1 - P_{(i,j) \to (x,y)}(k)\right)$$

where $P_{(i,j) \to (x,y)}(k)$ is the probability that a robot starting at $(i,j)$ reaches $(x,y)$ after $k$ steps.

To compute $P_{(i,j) \to (x,y)}(k)$, use DP for the random walk. Let $dp[t][x][y]$ be the probability that a robot starting at $(i,j)$ is at $(x,y)$ after $t$ steps. The transition applies the law of total probability — the robot must come from a neighbor $(u,v)$ that chose to move toward $(x,y)$:

$$dp[t][x][y] = \sum_{(u,v) \in \text{Neighbors}(x,y)} \frac{dp[t-1][u][v]}{\text{deg}(u,v)}$$

where $\text{deg}(u,v)$ is the number of valid neighbors of $(u,v)$ (2 for corners, 3 for edges, 4 for interior cells). Base case: $dp[0][i][j] = 1$, all others 0.

### Algorithm

1. Initialize $ans[x][y] = 1$ for all cells.
2. For each starting position $(i,j)$:
   - Set $dp[0][i][j] = 1$.
   - For $t = 1, \ldots, k$: update $dp[t]$ from $dp[t-1]$ using the transition.
   - For each cell $(x,y)$: $ans[x][y] \mathrel{\times}= (1 - dp[k][x][y])$.
3. Sum all $ans[x][y]$ and output the result rounded to 6 decimal places.

### Example

$k = 10$: the expected number of empty cells is **23.120740**.

For a concrete sub-calculation with $k = 1$: a robot at corner $(1,1)$ has degree 2, so it moves to $(1,2)$ or $(2,1)$ with probability $1/2$ each. After one step, probability $P_{(1,1) \to (1,2)}(1) = 1/2$.

## Complexity

- **Time:** $O(64 \cdot k \cdot 64) = O(k)$ (64 starting positions, each requiring $k$ steps over 64 cells)
- **Space:** $O(k \cdot 64)$, reducible to $O(64)$ by keeping only two time layers

## Code (C++)

[Solution Code](../code/Moving%20Robots.cpp)
