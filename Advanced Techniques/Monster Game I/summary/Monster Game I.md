# Monster Game I

**CSES ID:** 2084  
**Full statement:** https://cses.fi/problemset/task/2084  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A game has $n$ levels, each with a monster of strength $s_i$. You start with skill factor $x$; killing monster $i$ takes time $s_i \cdot f_{\text{current}}$ and replaces your skill factor by $f_i$ (smaller is better). On levels $1\ldots n-1$ you may skip, but you must kill the level-$n$ monster. Find the minimum total time to win. Strengths are nondecreasing and skill factors nonincreasing.

## Input
First line: $n$ and $x$. Second line: $n$ integers $s_1,\ldots,s_n$. Third line: $n$ integers $f_1,\ldots,f_n$.

## Output
Print the minimum total time to win.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x \le 10^6$
- $1 \le s_1 \le s_2 \le \ldots \le s_n \le 10^6$
- $x \ge f_1 \ge f_2 \ge \ldots \ge f_n \ge 1$
