# Các Tuyến Đường Khác Nhau - Lời giải

**ID:** 1711 | **URL:** https://cses.fi/problemset/task/1711

## Hướng tiếp cận

### Tóm tắt bài toán

Cho đồ thị có hướng $n$ đỉnh, $m$ cạnh. Tìm số lượng lớn nhất các đường đi không chung cạnh từ đỉnh 1 đến đỉnh $n$, và xuất từng đường đi.

### Ý tưởng chính

Mô hình hóa bài toán thành **luồng cực đại** với sức chứa đơn vị: mỗi cạnh có sức chứa 1, thêm cạnh ngược sức chứa 0 (cạnh dư). Theo định lý Menger, số đường đi không chung cạnh tối đa bằng giá trị luồng cực đại. Điều này đúng vì:

- **Phân tích luồng nguyên:** Với sức chứa đơn vị, định lý Integral Flow đảm bảo tồn tại luồng cực đại mà mỗi cạnh mang 0 hoặc 1 đơn vị. Luồng này phân tích thành các đường đi không chung cạnh (mỗi đường mang 1 đơn vị từ nguồn đến đích).
- **Tính tối ưu:** Nếu tồn tại $k > f^*$ đường đi không chung cạnh, chúng tạo thành luồng hợp lệ giá trị $k$, mâu thuẫn với tính cực đại của $f^*$.
- **Tính không chung cạnh khi trích xuất:** Mỗi cạnh có sức chứa 1, nên luồng trên mỗi cạnh tối đa 1. Hàm `Tracing` đánh dấu mỗi cạnh đã dùng, ngăn tái sử dụng giữa các đường đi.

Sử dụng **thuật toán Dinic** để tính luồng cực đại trên mạng sức chứa đơn vị, sau đó trích xuất từng đường đi bằng cách đi theo cạnh bão hòa ($c = f = 1$).

### Thuật toán

1. **Xây mạng luồng:** Với mỗi cạnh $u \to v$, tạo cạnh thuận sức chứa $c = 1$ và cạnh ngược sức chứa $c = 0$.
2. **Thuật toán Dinic:**
   - **BFS phân tầng:** Xây đồ thị phân tầng từ đỉnh 1, chỉ theo cạnh có sức chứa dư $\geq 1$.
   - **DFS tăng luồng:** Tìm đường tăng luồng trên đồ thị phân tầng, đẩy 1 đơn vị luồng. Cập nhật cạnh thuận $f + 1$, cạnh ngược $f - 1$.
   - Lặp lại đến khi không còn đường tăng luồng.
3. **Trích xuất đường đi:** Lặp $f^*$ lần:
   - BFS từ đỉnh 1 theo cạnh bão hòa ($c = 1, f = 1$) chưa đánh dấu `used`.
   - Truy vết ngược từ $n$ về $1$ theo mảng `trace`.
   - Đánh dấu `used` cho mỗi cạnh trên đường đi.

### Ví dụ minh họa

Đầu vào:
```
6 7
1 2
1 3
2 6
3 4
3 5
4 6
5 6
```

Dinic: Đẩy 1 đơn vị theo $1 \to 2 \to 6$, đẩy 1 đơn vị theo $1 \to 3 \to 4 \to 6$. Luồng cực đại = 2.

Trích xuất:
- Lần 1: BFS theo cạnh bão hòa → đường $1 \to 2 \to 6$. Đánh dấu `used`.
- Lần 2: BFS → đường $1 \to 3 \to 4 \to 6$. Đánh dấu `used`.

Kết quả:
```
2
3
1 2 6
4
1 3 4 6
```

## Độ phức tạp

- **Thời gian:** $O(m\sqrt{n})$ cho Dinic trên mạng sức chứa đơn vị, $O(f^* \cdot m)$ cho trích xuất đường đi.
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Distinct%20Routes.cpp)
