# Movie Festival Queries

**CSES ID:** 1664  
**Full statement:** https://cses.fi/problemset/task/1664  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You know the start and end times of $n$ movies. Each query gives an arrival time and a leaving time, and asks for the maximum number of movies you can fully watch inside that interval (a movie can be selected if it begins no earlier than when the previous selected one ends, with arrival/departure at exact interval bounds allowed).

## Input
First line gives $n$ and $q$. Then $n$ lines each give a movie's start $a$ and end $b$. Finally $q$ lines each give arrival $a$ and leaving $b$.

## Output
Print the maximum number of movies watchable for each query.

## Constraints
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le a < b \le 10^6$
