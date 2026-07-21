# Building Teams

**CSES ID:** 1668  
**Full statement:** https://cses.fi/problemset/task/1668  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given $n$ pupils and $m$ friendship pairs, assign each pupil to one of two teams so no friends share a team. Report the assignment or state it cannot be done.

## Input
Two integers $n, m$, then $m$ lines each listing two pupil indices who are friends.

## Output
A line of $n$ values each `1` or `2` giving the team of each pupil, or `IMPOSSIBLE`.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
