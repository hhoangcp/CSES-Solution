# Mountain Range

**CSES ID:** 3314  
**Full statement:** https://cses.fi/problemset/task/3314  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

There are $n$ mountains in a row with given heights. Starting from some mountain, you may glide from $a$ to $b$ if mountain $a$ is strictly taller than $b$ and all mountains between them. Find the maximum number of mountains visitable on a single route.

## Input
An integer $n$, then $n$ heights $h_1,\dots,h_n$.

## Output
The maximum number of mountains on a route.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le h_i \le 10^9$
