# Nim Game II

**CSES ID:** 1098  
**Full statement:** https://cses.fi/problemset/task/1098  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A restricted Nim: on each move a player removes $1$, $2$, or $3$ sticks from a single nonempty heap; whoever takes the last stick wins. Decide the winner under optimal play.

## Input
The first line is $t$. Each test gives $n$ followed by a line of $n$ heap sizes $x_i$.

## Output
For each test print `first` or `second`.

## Constraints
- $1 \le t \le 2 \cdot 10^5$
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
- $\sum n \le 2 \cdot 10^5$
