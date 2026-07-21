# Tasks and Deadlines

**CSES ID:** 1630  
**Full statement:** https://cses.fi/problemset/task/1630  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You must process all $n$ tasks one after another starting at time 0. Each task has a duration $a$ and a deadline $d$, and yields reward $d-f$ where $f$ is its finishing time. Maximize the total reward.

## Input
First line: integer $n$. Then $n$ lines, each with duration $a$ and deadline $d$.

## Output
Print one integer: the maximum total reward.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le a, d \le 10^6$
