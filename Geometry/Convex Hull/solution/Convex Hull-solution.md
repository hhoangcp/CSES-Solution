# Convex Hull - Solution

**ID:** 2195 | **URL:** https://cses.fi/problemset/task/2195

## Approach

### Problem Restatement

Given $n$ distinct points on the plane, find the convex hull — the smallest convex polygon containing all points. All points on the hull boundary (including collinear ones) must be reported.

### Core idea

Use Andrew's monotone chain algorithm, which builds the lower and upper hulls separately.

Sort all points lexicographically by $(y, x)$. The **lower hull** is built by scanning left-to-right: for each new point, while the last two hull points and the new point form a clockwise (CW) turn, remove the last hull point — that point is interior to the hull, since it lies inside the triangle formed by its predecessor, the new point, and the next hull point. Then add the new point. The **upper hull** is built the same way but scanning in reverse order. The two hulls share their endpoints; merging them (removing duplicates) gives the full convex hull.

The CW turn test uses the cross product: three points $A, B, C$ form a CW turn when $(B_x - A_x)(C_y - A_y) - (B_y - A_y)(C_x - A_x) < 0$. Collinear points (cross product $= 0$) are kept, ensuring all boundary points are reported.

### Algorithm

1. Sort all points by $(y, x)$.
2. Build lower hull: for each point in sorted order, while the last two hull points and the new point form a CW turn, pop the last hull point. Push the new point.
3. Remove the last point of the lower hull (it will be re-added by the upper hull).
4. Build upper hull: for each point in reverse sorted order, apply the same pop/push logic.
5. Remove the last point of the upper hull (it duplicates the first point of the lower hull).
6. Output the hull.

### Example

Points: $(2,1), (2,5), (3,3), (4,3), (4,4), (6,3)$.

Sorted by $(y,x)$: $(2,1), (3,3), (4,3), (6,3), (4,4), (2,5)$.

**Lower hull:**
- $(2,1)$: hull $= [(2,1)]$
- $(3,3)$: hull $= [(2,1), (3,3)]$
- $(4,3)$: CW turn $(2,1) \to (3,3) \to (4,3)$, pop $(3,3)$. hull $= [(2,1), (4,3)]$
- $(6,3)$: CW turn $(2,1) \to (4,3) \to (6,3)$, pop $(4,3)$. hull $= [(2,1), (6,3)]$
- $(4,4)$: CCW turn, keep. hull $= [(2,1), (6,3), (4,4)]$
- $(2,5)$: collinear $(6,3) \to (4,4) \to (2,5)$, keep. hull $= [(2,1), (6,3), (4,4), (2,5)]$

**Upper hull** (reverse order: $(2,5), (4,4), (6,3), (4,3), (3,3), (2,1)$):
- $(2,5), (4,4), (6,3)$: all collinear, kept. hull $= [(2,5), (4,4), (6,3)]$
- $(4,3)$: CW, pop $(6,3)$; CW, pop $(4,4)$. hull $= [(2,5), (4,3)]$
- $(3,3)$: CW, pop $(4,3)$. hull $= [(2,5), (3,3)]$
- $(2,1)$: CW, pop $(3,3)$. hull $= [(2,5), (2,1)]$

**Merge** (remove duplicate endpoints): $(2,1), (6,3), (4,4), (2,5)$ — 4 points.

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Convex%20Hull.cpp)
