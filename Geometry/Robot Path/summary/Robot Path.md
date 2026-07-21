# Robot Path

**CSES ID:** 1742  
**Full statement:** https://cses.fi/problemset/task/1742  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A robot starts at $(0,0)$ and executes $n$ step commands, each moving some integer distance in one of the four cardinal directions. It stops early the moment it would step onto a previously visited point. You must report the total distance actually travelled.

## Input
First an integer $n$, then $n$ lines each with a character $d \in \{U,D,L,R\}$ and an integer $x$ giving the move distance in that direction.

## Output
Print the total distance the robot moves before stopping.

## Constraints
- $1 \le n \le 10^5$
- $1 \le x \le 10^6$
