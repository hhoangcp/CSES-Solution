# Houses and Schools

**CSES ID:** 2087  
**Full statement:** https://cses.fi/problemset/task/2087  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Houses $1\ldots n$ lie on a line; the distance between houses $a$ and $b$ is $|a-b|$, and each house $i$ has $c_i$ children. Place $k$ schools at chosen houses so that every child walks to the nearest school, and minimize the total walking distance.

## Input
First line: $n$ and $k$. Second line: $n$ integers $c_1,\ldots,c_n$.

## Output
Print the minimum total walking distance.

## Constraints
- $1 \le k \le n \le 3000$
- $1 \le c_i \le 10^9$
