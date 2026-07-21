# Collecting Numbers II

**CSES ID:** 2217  
**Full statement:** https://cses.fi/problemset/task/2217  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Same collecting rule as the original problem, but now $m$ swap operations are applied to the permutation. After each swap you must report the current number of rounds.

## Input
First line: integers $n$ and $m$. Next line: $n$ integers forming a permutation. Then $m$ lines, each with two indices $a$ and $b$ whose values are swapped.

## Output
Print $m$ integers: the number of rounds after each swap.

## Constraints
- $1 \le n, m \le 2 \cdot 10^5$
- $1 \le a, b \le n$
