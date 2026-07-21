# Monster Game II

**CSES ID:** 2085  
**Full statement:** https://cses.fi/problemset/task/2085  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Like Monster Game I, you advance through $n$ levels with monsters of strength $s_i$; killing monster $i$ costs time $s_i \cdot f_{\text{current}}$ and updates your skill factor to $f_i$ (smaller is better). You may skip levels $1\ldots n-1$ but must kill the level-$n$ monster. Unlike the first variant, strengths and skill factors are arbitrary. Find the minimum total time to win.

## Input
First line: $n$ and $x$. Second line: $n$ integers $s_1,\ldots,s_n$. Third line: $n$ integers $f_1,\ldots,f_n$.

## Output
Print the minimum total time to win.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x \le 10^6$
- $1 \le s_i,f_i \le 10^6$
