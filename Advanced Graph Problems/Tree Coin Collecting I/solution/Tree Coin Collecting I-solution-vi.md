# Tree Coin Collecting I - Lời giải

**ID:** 3114 | **URL:** https://cses.fi/problemset/task/3114

## Phương pháp

### Tóm tắt bài toán

Cho cây $n$ đỉnh, một số đỉnh có đồng xu. Trả lời $q$ truy vấn: đường đi ngắn nhất từ $a$ đến $b$ thăm ít nhất một đỉnh có đồng xu?

### Ý tưởng chính

Mọi đường đi từ $a$ đến $b$ thăm đồng xu đều có dạng: theo đường $a$-$b$ duy nhất, rẽ tại nút $x$ trên đường đi đến đồng xu gần nhất (khoảng cách $\text{val}[x]$), quay lại $x$, rồi tiếp tục. Thêm $2 \cdot \text{val}[x]$ vào $\text{dist}(a, b)$. Luôn chọn được $x$ trên đường $a$-$b$: nếu rẽ qua nút $w$ ngoài đường, đường từ $w$ nối lại đường $a$-$b$ tại nút $y$, và $\text{val}[y]$ không lớn hơn đường đi qua $w$, nên rẽ tại $y$ không tốn hơn. Điểm rẽ tối ưu là nút có $\text{val}$ nhỏ nhất trên đường đi. Đáp án $= \text{dist}(a, b) + 2 \cdot \min_{x \in \text{path}(a,b)} \text{val}[x]$.

### Thuật toán

1. **BFS đa nguồn** từ mọi đỉnh có đồng xu, tính $\text{val}[v]$ (khoảng cách đến đồng xu gần nhất).
2. **Tiền xử lý Binary Lifting:** xây bảng tổ tiên `par[v][i]` và bảng min trên đường `mn[v][i]` = min `val` từ $v$ đến tổ tiên thứ $2^i$.
3. **Truy vấn $(a, b)$:** tính LCA, $\text{dist}(a, b) = \text{depth}[a] + \text{depth}[b] - 2 \cdot \text{depth}[\text{LCA}]$. Tính min trên đường bằng cách nhảy $a$ và $b$ lên LCA (gồm cả `val[LCA]`). Đáp án = dist + 2 × path_min.

### Ví dụ minh họa

$n=5$, đồng xu tại {1, 4}. val: [0, 1, 1, 0, 2]. Truy vấn (1, 5): dist=2, path_min = min(0, 1, 2) = 0, đáp án = 2.

## Độ phức tạp

- **Thời gian:** $O(n \log n + q \log n)$
- **Không gian:** $O(n \log n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Tree%20Coin%20Collecting%20I.cpp)
