# Salary Queries

**CSES ID:** 1144  
**Full statement:** https://cses.fi/problemset/task/1144  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A company has $n$ employees, each with a salary that can change over time. Queries ask how many employees currently earn a salary within a given range $[a,b]$.

## Input
First line gives $n$ and $q$. Second line lists initial salaries. Each of the $q$ following lines is either `!` $k$ $x$ (set salary of employee $k$ to $x$) or `?` $a$ $b$ (count salaries in $[a,b]$).

## Output
Print the answer to each `?` query.

## Constraints
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le p_i \le 10^9$
- $1 \le k \le n$
- $1 \le x \le 10^9$
- $1 \le a \le b \le 10^9$
