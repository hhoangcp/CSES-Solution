# Hidden Permutation

**CSES ID:** 3139  
**Full statement:** https://cses.fi/problemset/task/3139  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Interactive problem. A hidden permutation of $1..n$ must be recovered using pairwise comparison queries: pick two indices $i, j$ and learn whether $a_i < a_j$.

## Input
Read $n$ first. Protocol: print `? i j` to ask if $a_i < a_j$ (`YES`/`NO`); print `! a_1 ... a_n` to report the permutation and terminate.

## Output
Comparison queries and a final permutation line, flushing after each.

## Constraints
- $1 \le n \le 1000$
- at most $10^4$ `?` queries
