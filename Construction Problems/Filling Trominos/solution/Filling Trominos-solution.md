# Filling Trominos - Solution

**ID:** 2423 | **URL:** https://cses.fi/problemset/task/2423

## Approach

### Problem Restatement

Fill an $n \times m$ grid with L-trominoes (three cells in an L-shape) such that adjacent cells have the same letter if and only if they belong to the same tromino. Output the tiling or report that it is impossible.

### Impossible cases

An L-tromino covers exactly 3 cells, so $nm$ must be divisible by 3. However, this alone is not sufficient:

- **Neither dimension divisible by 3:** If $n \bmod 3 \ne 0$ and $m \bmod 3 \ne 0$, then $nm \bmod 3 \ne 0$, so tiling is impossible.
- **$n = 1$ or $m = 1$:** An L-tromino requires at least 2 rows and 2 columns.
- **$3 \times m$ with $m$ odd:** Coloring the grid with 3 colors in a repeating pattern shows the count of each color differs when $m$ is odd, making tiling impossible.

To simplify, we always ensure $m$ is divisible by 3 by **rotating** the grid (swapping $n$ and $m$) if necessary. After rotation, if $m$ is still not divisible by 3, output `NO`.

### Building blocks

The construction relies on two basic blocks, each covered by exactly 2 L-trominoes:

- **$2 \times 3$ block:** Two trominoes fill it horizontally.
- **$3 \times 2$ block:** Two trominoes fill it vertically.

For the hardest case (both dimensions odd), we also use a precomputed **$5 \times 9$ pattern** composed of smaller blocks and manually placed trominoes.

### Construction

After ensuring $m \bmod 3 = 0$ by rotation:

- **$n$ even, $m$ even:** Tile the entire grid with $2 \times 3$ blocks (step 2 in rows, 3 in columns).
- **$n$ odd, $m$ even:** Fill the first 3 rows with $3 \times 2$ blocks, then fill the remaining even number of rows with $2 \times 3$ blocks.
- **$n$ odd, $m$ odd:** Place the $5 \times 9$ pattern at the top-left corner. Fill rows 6 onward with $2 \times 3$ blocks, columns 10 onward with $3 \times 2$ blocks, and the middle region (row 4+, column 10+) with $2 \times 3$ blocks.

Each building block covers an area divisible by 3, and the regions partition the grid without overlap, so the total area is always correct.

### Labeling

Each tromino is assigned a character via a $5 \times 5$ repeating pattern: `Get_char(x, y) = 'A' + ((x-1) mod 5) · 5 + (y-1) mod 5`. Since all building blocks ($2 \times 3$, $3 \times 2$, $5 \times 9$) fit within the $5 \times 5$ boundary, adjacent trominoes always receive different labels.

### Example

$n = 4, m = 6$ (both even): tile with $2 \times 3$ blocks.

```
AAHDDF
AHHDFF
KKRNNP
KRRNPP
```

8 L-trominoes, each formed by 3 adjacent cells sharing the same letter.

$n = 4, m = 7$: after rotation, $m \bmod 3 \ne 0$ → `NO`.

## Complexity

- **Time:** $O(n \cdot m)$ per test case
- **Space:** $O(n \cdot m)$

## Code (C++)

[Solution Code](../code/Filling%20Trominos.cpp)
