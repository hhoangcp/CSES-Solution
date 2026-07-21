# Stick Difference

**CSES ID:** 3401  
**Full statement:** https://cses.fi/problemset/task/3401  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You have $n$ sticks with integer lengths. Make exactly $k$ cuts (each splitting one stick into two positive-integer pieces), producing $n+k$ sticks, for each $k=1,\dots,m$. For each $k$ minimize the difference between the longest and shortest resulting stick.

## Input
First line: $n$ and $m$. Second line: $n$ integers $a_1,\dots,a_n$.

## Output
One line with $m$ integers: the minimal difference for $k=1,\dots,m$ cuts.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a_i \le 10^9$
