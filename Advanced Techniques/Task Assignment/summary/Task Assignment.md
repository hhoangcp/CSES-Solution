# Task Assignment

**CSES ID:** 2129  
**Full statement:** https://cses.fi/problemset/task/2129  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

There are $n$ employees and $n$ tasks, with a known cost $c_{ij}$ for assigning task $j$ to employee $i$. Assign each employee exactly one task so that the total cost is minimized, and print an optimal assignment.

## Input
First line: $n$. Then $n$ lines, each with $n$ integers giving the cost row for one employee.

## Output
Print the minimum total cost, then $n$ lines each of the form `$a$ $b$` meaning employee $a$ gets task $b$. Any optimal assignment is accepted.

## Constraints
- $1 \le n \le 200$
- $1 \le c_{ij} \le 1000$
