# Course Schedule II

**CSES ID:** 1757  
**Full statement:** https://cses.fi/problemset/task/1757  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You must finish $n$ courses subject to precedence constraints of the form "course $a$ before course $b$". Among all valid schedules, pick the one that completes course 1 earliest, breaking ties by course 2, then course 3, and so on.

## Input
First line: $n$ and $m$ (courses, requirements). Then $m$ lines each with $a,b$ meaning course $a$ must precede course $b$. At least one valid schedule exists.

## Output
Print one line with $n$ integers: the order in which the courses are completed.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
