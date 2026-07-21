# Tree Coin Collecting II - Lời giải

**ID:** 3149 | **URL:** https://cses.fi/problemset/task/3149

## Phương pháp

### Tóm tắt bài toán

Cho cây $n$ đỉnh, một số đỉnh có đồng xu. Trả lời $q$ truy vấn: đường đi ngắn nhất từ $a$ đến $b$ thăm **tất cả** đỉnh có đồng xu?

### Ý tưởng chính

Để thăm mọi đồng xu, phải duyệt toàn bộ **cây Steiner** — cây con nhỏ nhất chứa mọi đỉnh đồng xu. Duyệt Euler đầy đủ đi mỗi cạnh 2 lần, tổng $\text{base} = 2 \cdot (S - 1)$ với $S$ = số nút Steiner. Khi đi từ $a$ đến $b$ thay vì quay lại gốc, trên đường $a$-$b$ có $k$ nút Steiner (tương đương $k-1$ cạnh Steiner), mỗi cạnh tiết kiệm 1 lần hồi (giảm 2 mỗi cạnh). Gọi $\text{mask}[v] = 1$ nếu cây con $v$ chứa đồng xu, $\text{pre}[v]$ = số nút Steiner trên đường gốc-$v$. Với LCA $l$ của $(a, b)$: nếu $l$ trong cây Steiner, phần trùng $k = \text{pre}[a] + \text{pre}[b] - 2 \cdot \text{pre}[\text{par}[l]] - 1$ (số nút Steiner trên đường $a$-$b$), đáp án $= \text{base} - 2(k-1) + \text{dist}(a, b)$; nếu $l$ ngoài, phải bù thêm $\text{add} = \text{depth}[l] + 1 - \text{pre}[l]$ để đi vào và ra cây Steiner, đáp án $= \text{base} + \text{dist}(a, b) + 2 \cdot \text{add}$.

### Thuật toán

1. **Gốc tại đỉnh có đồng xu.** DFS tính `mask[v]`, `depth[v]`, `pre[v]` và bảng binary lifting `par[v][i]`.
2. Tính `base = 2 * (sum(mask) - 1)`.
3. Với mỗi truy vấn $(a, b)$:
   - Tìm $l = \text{LCA}(a, b)$ và $\text{dist}(a, b)$.
   - Nếu $l$ thuộc cây Steiner (`pre[l] == depth[l] + 1`): tính $k = \text{pre}[a] + \text{pre}[b] - 2 \cdot \text{pre}[\text{par}[l]] - 1$. Đáp án $= \text{base} - 2(k-1) + \text{dist}(a, b)$.
   - Ngược lại: tính $\text{add} = \text{depth}[l] + 1 - \text{pre}[l]$. Đáp án $= \text{base} + \text{dist}(a, b) + 2 \cdot \text{add}$.

### Ví dụ minh họa

$n=5$, đồng xu tại {1, 4}. Nút Steiner: {1, 2, 3, 4}, base = 6.

- Truy vấn $(1, 5)$: nút 5 ngoài cây Steiner. Đáp án = 6.
- Truy vấn $(4, 4)$: dist = 0, phải duyệt hết cây Steiner. Đáp án = 6.

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$
- **Không gian:** $O(n \log n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Tree%20Coin%20Collecting%20II.cpp)
