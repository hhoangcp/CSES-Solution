# Chess Tournament

**CSES ID:** 1697  
**Full statement:** https://cses.fi/problemset/task/1697  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In a round-robin-style chess event, each of $n$ players declares how many games they wish to play, and any pair of players may meet at most once. You must schedule a set of matches so that every player's requested count is met exactly.

## Input
First line: integer $n$. Second line: $n$ integers $x_1,\dots,x_n$, the desired game counts.

## Output
Print the number of games $k$, then $k$ lines each with two player indices, or `IMPOSSIBLE` if no schedule exists.

## Constraints
- $1 \le n \le 10^5$
- $\sum_{i=1}^{n} x_i \le 2 \cdot 10^5$
