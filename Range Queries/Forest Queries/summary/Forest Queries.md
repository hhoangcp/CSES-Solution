# Forest Queries

**CSES ID:** 1652  
**Full statement:** https://cses.fi/problemset/task/1652  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given an $n \times n$ grid of a forest where each cell is either empty or contains a tree. For each of several rectangular queries you must report how many trees lie inside the rectangle.

## Input
First line gives the grid size $n$ and query count $q$. Then $n$ lines each of $n$ characters (`.` empty, `*` tree) describe the grid. Finally $q$ lines each give rectangle corners $y_1, x_1, y_2, x_2$.

## Output
Print the number of trees inside each queried rectangle.

## Constraints
- $1 \le n \le 1000$
- $1 \le q \le 2 \cdot 10^5$
- $1 \le y_1 \le y_2 \le n$
- $1 \le x_1 \le x_2 \le n$
