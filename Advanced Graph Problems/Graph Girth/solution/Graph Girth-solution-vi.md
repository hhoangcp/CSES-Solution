# Graph Girth - Lời giải

**ID:** 1707 | **URL:** https://cses.fi/problemset/task/1707

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng, tìm chu vi (girth) — độ dài chu trình ngắn nhất. Nếu không có chu trình, xuất $-1$.

### Ý tưởng chính

Chạy BFS từ mọi đỉnh. Khi BFS từ nguồn $s$ gặp cạnh $\{u,v\}$ mà cả hai đã thăm và không phải cạnh cây (tức $v \neq \text{lab}[u]$ và $u \neq \text{lab}[v]$), chu trình được phát hiện với độ dài $\text{dist}[u] + \text{dist}[v] + 1$. Chu trình ngắn nhất luôn được phát hiện vì BFS từ một đỉnh trên chu trình đó sẽ tìm đường đi ngắn nhất đến mọi đỉnh khác trên chu trình, và cạnh nối hai đường đi sẽ đóng chu trình đúng độ dài. Kiểm tra `lab` loại bỏ cạnh cây (không tạo chu trình trong đồ thị đơn).

### Thuật toán

1. Với mỗi đỉnh nguồn $s$ từ 1 đến $n$:
   - Chạy BFS từ $s$, tính `dist[v]` và `lab[v]`.
   - Khi xử lý đỉnh $u$ và tìm hàng xóm $v$ đã thăm:
     - Nếu $v \neq \text{lab}[u]$ và $u \neq \text{lab}[v]$, cập nhật `ans = min(ans, dist[u] + dist[v] + 1)`.
2. Nếu `ans` vẫn $\infty$, xuất $-1$; ngược lại xuất `ans`.

### Ví dụ minh họa

$n=5$, cạnh: 1-2, 1-3, 2-4, 2-5, 3-4, 4-5.

BFS từ 2: dist = [1, 0, 2, 1, 1]. Cạnh 4-5: $\text{dist}[4]=1$, $\text{dist}[5]=1$, chu trình = 3.

Kết quả: 3.

## Độ phức tạp

- **Thời gian:** $O(n(n + m))$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Graph%20Girth.cpp)
