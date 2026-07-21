# Split into Two Paths

**CSES ID:** 3358  
**Full statement:** https://cses.fi/problemset/task/3358  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a directed acyclic graph on $n$ nodes, decide whether its vertices can be partitioned into two (possibly empty) directed paths, where consecutive vertices in each path must be joined by an edge of the graph. Not every edge needs to be used. If feasible, output the two paths; otherwise report impossibility.

## Input
First line: $n$ and $m$. Then $m$ lines each with a directed edge $a \to b$.

## Output
First print `YES` or `NO`. If `YES`, print two more lines, each starting with the path length followed by the vertices in order; one path may be empty.

## Constraints
- $2 \le n \le 2 \cdot 10^5$
- $0 \le m \le 5 \cdot 10^5$
