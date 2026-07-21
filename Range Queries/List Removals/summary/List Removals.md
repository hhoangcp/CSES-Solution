# List Removals

**CSES ID:** 1749  
**Full statement:** https://cses.fi/problemset/task/1749  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You start with a list of $n$ integers and must remove elements one at a time, where each removal specifies a position counted in the current (shrinking) list. You must output the removed values in removal order.

## Input
First line gives $n$. Second line lists the $n$ list elements. Third line lists $n$ removal positions $p_1,\dots,p_n$ (positions in the current list).

## Output
Print the removed elements in the order of removal.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
- $1 \le p_i \le n-i+1$
