# New Flight Routes - Solution

**ID:** 1685 | **URL:** https://cses.fi/problemset/task/1685

## Approach

### Problem Restatement

Given a directed graph with $n$ cities and $m$ one-way flights, add the minimum number of flights so that any city can reach any other city (make the graph strongly connected).

### Core idea

Find SCCs via Tarjan and build the condensation DAG. If only 1 SCC, answer is 0. Otherwise, let $a$ = number of sources (in-degree 0) and $b$ = number of sinks (out-degree 0) in the DAG. The answer is $\max(a, b)$: each source needs an incoming edge and each sink needs an outgoing edge, but one new edge can satisfy at most one source and one sink simultaneously, giving lower bound $\max(a, b)$; conversely, pairing sinks and sources in a cycle always achieves this bound.

### Algorithm

1. Find SCCs via Tarjan. Build condensation DAG, count sources and sinks.
2. If only 1 SCC, output 0.
3. Otherwise, add $\max(a, b)$ edges: pair sinks to sources in a cycle, then handle remaining unmatched sources/sinks.
4. Output edges using representative nodes from each SCC.

### Example

$n=4$, edges: $1\to2$, $2\to3$, $3\to1$, $1\to4$, $3\to4$. SCCs: {1,2,3} (source), {4} (sink). $a=1, b=1$. Add edge $4\to2$.

## Complexity

- **Time:** $O(n + m)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/New%20Flight%20Routes.cpp)
