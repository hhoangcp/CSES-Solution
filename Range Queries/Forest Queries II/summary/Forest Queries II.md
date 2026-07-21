# Forest Queries II

**CSES ID:** 1739  
**Full statement:** https://cses.fi/problemset/task/1739  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Like the static version but now you can toggle individual cells between empty and tree, and still need to answer rectangle tree-count queries.

## Input
First line gives $n$ and $q$. Then $n$ lines of $n$ characters (`.`/`*`) describe the grid. The $q$ query lines are either "$1$ $y$ $x$" (toggle cell) or "2 $y_1$ $x_1$ $y_2$ $x_2$" (count trees in rectangle).

## Output
Print the answer to each type-2 query.

## Constraints
- $1 \le n \le 1000$
- $1 \le q \le 2 \cdot 10^5$
- $1 \le y,x \le n$
- $1 \le y_1 \le y_2 \le n$
- $1 \le x_1 \le x_2 \le n$
