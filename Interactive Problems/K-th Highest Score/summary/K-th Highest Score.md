# K-th Highest Score

**CSES ID:** 3305  
**Full statement:** https://cses.fi/problemset/task/3305  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Interactive problem. Two teams of $n$ coders (Finland, Sweden) hold $2n$ distinct scores; find the $k$-th highest overall. Per query you pick a country and rank $i$ to receive that country's $i$-th highest score.

## Input
Read $n$ and $k$ first. Protocol: print `F i` for Finland's $i$-th highest, `S i` for Sweden's, and `! s` to report the overall $k$-th highest and terminate.

## Output
Country-rank queries and a final answer, flushing after each line.

## Constraints
- $1 \le n \le 10^5$
- $1 \le k \le 2n$
- scores in $[1, 10^9]$, all distinct
- at most $100$ total `F`/`S` queries
