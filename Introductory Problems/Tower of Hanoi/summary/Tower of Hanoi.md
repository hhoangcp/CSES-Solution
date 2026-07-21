# Tower of Hanoi

**CSES ID:** 2165  
**Full statement:** https://cses.fi/problemset/task/2165  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Three pegs hold $n$ disks of distinct sizes, all initially stacked on peg 1 from smallest (top) to largest. Move every disk to peg 3 following the rule that a larger disk never sits on a smaller one, using the minimum number of moves. Print the move count and each move as a source-destination peg pair.

## Input
A single integer $n$.

## Output
First line: $k$, the minimum number of moves. Then $k$ lines, each with two integers $a$ and $b$ (move top disk from peg $a$ to peg $b$).

## Constraints
- $1 \le n \le 16$
