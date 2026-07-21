# Letter Pair Move Game

**CSES ID:** 2427  
**Full statement:** https://cses.fi/problemset/task/2427  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A row of $2n$ boxes contains two adjacent empty boxes; the rest hold letters "A" and "B" ($n-1$ of each). A move slides a pair of adjacent letters into the two adjacent empty slots, keeping their order. Reach a configuration where every "A" precedes every "B" using at most $1000$ moves, or report impossibility.

## Input
An integer $n$, then a string of $2n$ characters over `A`, `B`, and `.`.

## Output
Print the number of moves followed by the resulting configuration after each move, or `-1` if unsolvable.

## Constraints
- $1 \le n \le 100$
