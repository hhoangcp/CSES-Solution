# Maximum Average Subarrays

**CSES ID:** 3301  
**Full statement:** https://cses.fi/problemset/task/3301  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

For an array $x_1,\ldots,x_n$, for each ending index $i$ find the length of the subarray ending at $i$ with the maximum average, breaking ties by taking the longest such subarray.

## Input
An integer $n$, then $n$ integers $x_1,\ldots,x_n$.

## Output
Print $n$ integers: the optimal subarray length for each ending index.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^6$
