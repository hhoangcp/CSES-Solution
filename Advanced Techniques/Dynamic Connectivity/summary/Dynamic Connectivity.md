# Dynamic Connectivity

**CSES ID:** 2133  
**Full statement:** https://cses.fi/problemset/task/2133  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

An undirected graph starts with $n$ nodes and $m$ edges, and $k$ events follow, each either creating a new edge or removing an existing one. After each event, report the current number of connected components (and the count before the first event).

## Input
First line: $n,m,k$. Then $m$ lines describing initial edges (pairs $a,b$). Then $k$ lines of form `$t$ $a$ $b$`, where $t=1$ creates an edge and $t=2$ removes one. Created edges never duplicate existing ones; removals only target existing edges.

## Output
Print $k+1$ integers: the component count before the first event and after each event.

## Constraints
- $2 \le n \le 10^5$
- $1 \le m,k \le 10^5$
- $1 \le a,b \le n$
