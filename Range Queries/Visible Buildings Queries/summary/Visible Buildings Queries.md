# Visible Buildings Queries

**CSES ID:** 3304  
**Full statement:** https://cses.fi/problemset/task/3304  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

There are $n$ buildings in a row, and you stand to the left of the first; a building is visible if it is strictly taller than every building before it. For each query on a range $[a,b]$ you must report how many buildings would be visible if only that range existed.

## Input
First line gives $n$ and $q$. Second line lists the building heights. The following $q$ lines each give two endpoints $a$ and $b$.

## Output
For each query print the number of visible buildings.

## Constraints
- $1 \le n \le 10^5$
- $1 \le q \le 2 \cdot 10^5$
- $1 \le h_i \le 10^9$
- $1 \le a \le b \le n$
