# List of Sums - Solution

**ID:** 2414 | **URL:** https://cses.fi/problemset/task/2414

## Problem Statement

Given a list $B$ of $m = \frac{n(n-1)}{2}$ integers representing the sums of every pair of elements from a list $A$ of $n$ positive integers, reconstruct the original list $A$.

## Approach

### 1. Observation and Assumption

Assume list $A$ is sorted in increasing order: $a_1 \le a_2 \le \dots \le a_n$.

Then, list $B$ sorted in increasing order will have:

- **$b[1] = a_1 + a_2$**: This is certainly the smallest sum.
- **$b[2] = a_1 + a_3$**: This is certainly the second smallest sum.
- **$b[p] = a_2 + a_3$**: This value lies somewhere among the first $n$ elements of $B$ (typically $p \in [3, n]$).

### 2. System of equations for the first 3 numbers

If we know $a_1+a_2$, $a_1+a_3$, and $a_2+a_3$, we can solve the system of equations to find $a_1, a_2, a_3$:

$$a_2 = \frac{(a_1+a_2) + (a_2+a_3) - (a_1+a_3)}{2}$$

Corresponding to the source code: `a[2] = (b[1] + b[p] - b[2]) / 2`.

### 3. Search and Match algorithm

Since we don't know for certain which $b[p]$ is $a_2 + a_3$, we try every $p$ from $3$ to $n$:

1. **Compute $a_1, a_2, a_3$** from $b[1], b[2], b[p]$. If any result is non-integer or non-positive, skip this $p$.
2. **Use a greedy matching mechanism**: Maintain the known sums from the elements of $a$ found so far.
3. Traverse the remaining elements $b[i]$ in $B$:
   - If $b[i]$ matches a sum of some pair $(a_j, a_k)$ already found, skip it (already matched).
   - If $b[i]$ does not match any existing pair, then $b[i]$ must be the sum of the smallest element $a_1$ with a new element $a_{next}$.
   - Compute $a_{next} = b[i] - a_1$, then update the list of sums to be matched.
4. If all $m$ elements of $B$ are matched and all $n$ elements of $A$ are found, we have the answer.

### Proof of correctness

- **Uniqueness**: At each step, if we have determined the first $k$ elements of $A$, the smallest unmatched sum in $B$ must be $a_1 + a_{k+1}$. This allows us to determine exactly the next element of $A$ without any further guessing.
- **Search bound**: Trying only $p$ in the range $[3, n]$ is sufficient because $a_2 + a_3$ cannot be larger than sums of the form $a_1 + a_x$ with $x > n$.

## Complexity

- **Time**: $O(n^3)$ — The loop trying $p$ ($O(n)$) combined with the matching process ($O(n^2)$). With $n=100$, this complexity is well within acceptable limits.
- **Memory**: $O(n^2)$ for storing list $B$ and $O(n)$ for list $A$.

## Example

$n=4$, list $B = [3, 6, 7, 8, 9, 12]$ (sorted). $m = 6$.

### Step 1: Identify the 3 smallest sums

$b[1]=3 = a_1+a_2$, $b[2]=6 = a_1+a_3$.

### Step 2: Try $p=3$

$b[3]=7 = a_2+a_3$. Solve the system:
- $a_2 = (3 + 7 - 6)/2 = 2$
- $a_1 = 3 - 2 = 1$
- $a_3 = 6 - 1 = 5$

### Step 3: Match remaining sums

Known $A = [1, 2, 5]$, matched sums: $\{1+2=3, 1+5=6, 2+5=7\}$.

- $b[4]=8$: no match $\Rightarrow$ new element $a_4 = 8-1 = 7$. Add sums: $\{1+7=8, 2+7=9, 5+7=12\}$.
- $b[5]=9$: matches $2+7=9$ ✓
- $b[6]=12$: matches $5+7=12$ ✓

**Result: $A = [1, 2, 5, 7]$.**

### Problem Statement Example

$n=4$, list $B = [4, 4, 4, 6, 6, 6]$ (sorted). $m = 6$.

#### Step 1: Identify the 3 smallest sums

$b[1]=4 = a_1+a_2$, $b[2]=4 = a_1+a_3$.

#### Step 2: Try $p=3$

$b[3]=4 = a_2+a_3$. Solve the system:
- $a_2 = (4 + 4 - 4)/2 = 2$
- $a_1 = 4 - 2 = 2$
- $a_3 = 4 - 2 = 2$

#### Step 3: Match remaining sums

Known $A = [2, 2, 2]$, matched sums: $\{2+2=4, 2+2=4, 2+2=4\}$.

- $b[4]=6$: no match $\Rightarrow$ new element $a_4 = 6-2 = 4$. Add sums: $\{2+4=6, 2+4=6, 2+4=6\}$.
- $b[5]=6$: matches $2+4=6$ ✓
- $b[6]=6$: matches $2+4=6$ ✓

**Result: $A = [2, 2, 2, 4]$.** (Alternative solution $[1,3,3,3]$ is also valid and accepted.)

## Code (C++)

[Solution Code](../code/List%20of%20Sums.cpp)
