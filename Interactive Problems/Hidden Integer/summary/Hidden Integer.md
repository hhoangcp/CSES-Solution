# Hidden Integer

**CSES ID:** 3112  
**Full statement:** https://cses.fi/problemset/task/3112  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Interactive problem. A secret integer $x$ in $[1, 10^9]$ must be deduced by comparison queries: you propose $y$ and learn whether $y < x$.

## Input
Protocol: print `? y` to ask if $y < x$ (grader replies `YES`/`NO`); print `! x` to report the value and terminate.

## Output
Comparison queries and a final answer, flushing after each line.

## Constraints
- $1 \le x \le 10^9$
- at most $30$ `?` queries
