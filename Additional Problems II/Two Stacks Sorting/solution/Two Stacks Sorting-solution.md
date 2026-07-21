# Two Stacks Sorting - Solution

**ID:** 2402 | **URL:** https://cses.fi/problemset/task/2402

## Problem Statement

Given an input list of $n$ numbers (a permutation of $1 \ldots n$), produce the sorted output list using two stacks. Each number is pushed into one stack (choose stack 1 or 2), then popped from that stack in LIFO order to produce output. Assign each number to stack 1 or 2. If impossible, output `IMPOSSIBLE`.

## Approach

### Step 1: Simulate, determine time intervals

Simulate the mandatory process when output must be $1, 2, \ldots, n$. Determine each element's **lifespan interval**: $In[i]$ is the push time, $Out[i]$ is the pop time. Each element creates interval $[In[i], Out[i]]$.

### Step 2: Classify interval relationships

Traverse elements by value in increasing order ($y = 1 \to n$), comparing with previously seen element $x$ ($x < y$). Three relative positions:

1. **Disjoint:** No conflict, can share a stack.
2. **Nested** ($In[y] < In[x] < Out[x] < Out[y]$): $x$ enters after and leaves before $y$, valid under LIFO.
3. **Overlapping** ($In[x] < In[y] < Out[x] < Out[y]$): $y$ sits on top of $x$ but $x$ must leave first. Contradicts LIFO — $x$ and $y$ **must be in different stacks**.

### Step 3: Efficient conflict detection with set and BIT

Maintain a set of active elements, ordered by $In$ time.

**Set:** Find intervals that may overlap with $y$. Locate the first element with $In > In[y]$, step back one — this is the only element that could be case 3 (overlapping). Elements after it are all case 2 (nested). Since $y$ fully contains them, $y$ will take over handling future conflicts, so remove them from the set.

**BIT:** Check whether any element $z$ intrudes into the intersection $[L, R]$ of $x$ and $y$:
- Case 3 (overlapping): $x, y$ already must differ. If $z$ intrudes $\to$ need 3 stacks $\to$ `IMPOSSIBLE`.
- Case 2 (nested): If $z$ intrudes, to make room for $z$, $x$ and $y$ **must share the same stack**.

**Amortized complexity:** Each element is stepped back at most once per iteration ($n$ total) and stepped forward then removed from the set exactly once ($n$ total). If $>1$ element overlaps with $y$, the 3-stack conflict would have been detected by BIT earlier.

### Step 4: 2-SAT model via DSU

Each element $i$ has two variables: $i$ (stack 1) and $i+n$ (stack 2). Constraints are merged by DSU:
- **Different stacks:** Merge $x$ with $y+n$ and $y$ with $x+n$.
- **Same stack:** Merge $x$ with $y$ and $x+n$ with $y+n$.

If any $i$ has $Find(i) = Find(i+n)$, i.e., $i$ must be in both stacks $\to$ `IMPOSSIBLE`. Otherwise, 2-coloring within DSU allows assigning stacks to all elements.

### Example

$n = 5$, permutation: $[2, 3, 1, 5, 4]$.

Intervals: $In[1]=3, Out[1]=4$; $In[2]=1, Out[2]=5$; $In[3]=2, Out[3]=6$; $In[4]=8, Out[4]=9$; $In[5]=7, Out[5]=10$.

Elements 2 and 3 overlap ($In[2]=1 < In[3]=2 < Out[2]=5 < Out[3]=6$). Feasible assignment: 2, 4 into stack 1; 1, 3, 5 into stack 2.

## Complexity

- **Time:** $O(n \log n)$ — set $O(\log n)$ per operation, BIT $O(\log n)$ per query, amortized linear.
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Two%20Stacks%20Sorting.cpp)
