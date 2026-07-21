# Functional Graph Distribution

**CSES ID:** 2415  
**Full statement:** https://cses.fi/problemset/task/2415  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A functional graph is a directed graph in which every node has outdegree exactly $1$. Given $n$, for each $k=1\dots n$ count how many such graphs on $n$ labeled nodes have exactly $k$ (weak) connected components. Answers are modulo $10^9+7$.

## Input
A single line containing the integer $n$.

## Output
Print $n$ lines: for each $k=1\dots n$, the number of functional graphs modulo $10^9+7$.

## Constraints
- $1 \le n \le 5000$
