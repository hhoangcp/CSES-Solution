# Course Schedule

**CSES ID:** 1679  
**Full statement:** https://cses.fi/problemset/task/1679  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

There are $n$ courses with $m$ prerequisite pairs where course $a$ must be done before course $b$. Find a valid completion order covering all courses.

## Input
Two integers $n, m$, then $m$ lines each giving a prerequisite pair $a$ before $b$.

## Output
A line listing all $n$ courses in a valid order, or `IMPOSSIBLE` if no order exists.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
