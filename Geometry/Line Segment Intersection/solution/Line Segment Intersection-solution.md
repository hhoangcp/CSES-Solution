# Line Segment Intersection - Solution

**ID:** 2190 | **URL:** https://cses.fi/problemset/task/2190

## Approach

### Problem Restatement

Given two line segments, determine whether they intersect (have at least one common point).

### Core idea

Use the cross product to determine orientation. For three points $A, B, C$:

$$\text{cross}(A, B, C) = (B_x - A_x)(C_y - A_y) - (B_y - A_y)(C_x - A_x)$$

Positive means $C$ is left of $\overrightarrow{AB}$, negative means right, zero means collinear.

Two segments $P_1P_2$ and $P_3P_4$ intersect if and only if one of two conditions holds:

**Condition 1 — Straddling:** The endpoints of each segment lie on opposite sides of the line containing the other segment. Formally, $\text{sign}(\text{cross}(P_1, P_2, P_3)) \ne \text{sign}(\text{cross}(P_1, P_2, P_4))$ and $\text{sign}(\text{cross}(P_3, P_4, P_1)) \ne \text{sign}(\text{cross}(P_3, P_4, P_2))$. This works because if each segment's endpoints straddle the other's line, the two lines cross at a unique point lying on both segments. When one cross product is zero and the other is nonzero, this also counts as opposite signs (one endpoint lies on the line).

**Condition 2 — Collinear and overlapping:** When some cross products are zero, points may be collinear. In this case, the segments intersect if any endpoint of one segment lies on the other. Point $C$ lies on segment $AB$ when $\text{cross}(A, C, B) = 0$ and $C$'s coordinates fall within the bounding box of $A$ and $B$. Every case of intersection falls into one of these two conditions: interior crossings satisfy condition 1, and endpoint/overlap cases satisfy condition 2.

### Algorithm

1. Compute $d_1 = \text{cross}(P_1, P_3, P_2)$, $d_2 = \text{cross}(P_1, P_4, P_2)$, $d_3 = \text{cross}(P_3, P_1, P_4)$, $d_4 = \text{cross}(P_3, P_2, P_4)$.
2. If $d_1$ and $d_2$ have opposite signs AND $d_3$ and $d_4$ have opposite signs (zero counts as matching either sign), output YES.
3. Otherwise, if any endpoint lies on the other segment (checked via `On_Segment`), output YES.
4. Otherwise, output NO.

### Example

From the problem's 5 test cases, all sharing $P_1=(1,1), P_2=(5,3)$:

| Test | $P_3$ | $P_4$ | $d_1$ | $d_2$ | $d_3$ | $d_4$ | Result |
|------|-------|-------|-------|-------|-------|-------|--------|
| 1 | $(1,2)$ | $(4,3)$ | $-4$ | $-2$ | $3$ | $1$ | NO (same signs) |
| 2 | $(1,1)$ | $(4,3)$ | $0$ | $-2$ | $0$ | $2$ | YES ($P_1$ on $P_3P_4$) |
| 3 | $(2,3)$ | $(4,1)$ | $-6$ | $6$ | $6$ | $-6$ | YES (opposite signs) |
| 4 | $(2,4)$ | $(4,1)$ | $-10$ | $6$ | $9$ | $-7$ | YES (opposite signs) |
| 5 | $(3,2)$ | $(7,4)$ | $0$ | $0$ | — | — | YES ($P_2$ on $P_3P_4$) |

Test 1: $d_1, d_2$ same sign → straddle fails; no endpoint on other segment → NO.
Test 2: $d_1 = 0$ → straddle pair passes; $P_1$ coincides with $P_3$ (on $P_3P_4$) → YES.
Test 3: Both pairs have opposite signs → YES.
Test 5: Both $d_1 = d_2 = 0$ → straddle fails; $P_2=(5,3)$ lies on $P_3P_4$ (collinear, within bounding box) → YES.

## Complexity

- **Time:** $O(1)$ per test
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Line%20Segment%20Intersection.cpp)
