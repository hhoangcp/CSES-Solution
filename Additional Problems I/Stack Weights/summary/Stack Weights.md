# Stack Weights

**CSES ID:** 2425  
**Full statement:** https://cses.fi/problemset/task/2425  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

There are $n$ coins with unknown but strictly ordered weights (coin $i$ heavier than coin $i-1$). Coins are placed one at a time onto one of two stacks and never removed. After each placement, report which stack is provably heavier (`>` left, `<` right), or `?` when the ordering does not force a winner.

## Input
An integer $n$, then $n$ lines each with coin $c$ and stack $s$ ($1$ left, $2$ right).

## Output
After each move, print `>` , `<`, or `?`.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
