# Colored Chairs

**CSES ID:** 3273  
**Full statement:** https://cses.fi/problemset/task/3273  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Interactive problem. Chairs numbered $1$ to $n$ sit in a circle, each colored red or blue, and you must locate two adjacent chairs sharing a color. Since $n$ is odd, such a pair is guaranteed to exist. You query chair colors one at a time.

## Input
Read $n$ first. Protocol: print `? i` to learn chair $i$'s color (`R`/`B`); print `! i` to answer that chairs $i$ and $i+1$ match (wrap-around).

## Output
Color queries and a final answer line, flushing after each.

## Constraints
- $3 \le n \le 2 \cdot 10^5$, $n$ odd
- at most $20$ `?` queries
