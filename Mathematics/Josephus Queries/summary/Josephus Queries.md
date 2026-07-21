# Josephus Queries

**CSES ID:** 2164  
**Full statement:** https://cses.fi/problemset/task/2164  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In the Josephus process with step 2, $n$ people numbered $1 \dots n$ sit in a circle and every second person is eliminated until none remain. Answer $q$ queries: for a given $n$ and $k$, output the label of the $k$-th eliminated person.

## Input
The first line is $q$, followed by $q$ lines each containing $n$ and $k$.

## Output
Print the answer to each query on its own line.

## Constraints
- $1 \le q \le 10^5$
- $1 \le k \le n \le 10^9$
