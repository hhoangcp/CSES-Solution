# School Excursion

**CSES ID:** 1706  
**Full statement:** https://cses.fi/problemset/task/1706  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

$n$ children each pick one of two attractions, and $m$ given pairs must share the same choice. Determine every possible total count of children choosing one fixed attraction.

## Input
First line: $n$ and $m$. Then $m$ lines each with two children indices $a$ and $b$.

## Output
A length-$n$ bit string whose $i$-th bit is 1 if exactly $i$ children could pick the fixed attraction (one-indexed).

## Constraints
- $1 \le n \le 10^5$
- $0 \le m \le 10^5$
- $1 \le a, b \le n$
