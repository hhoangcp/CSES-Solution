# Giảm Giá Chuyến Bay - Lời giải

**ID:** 1195 | **URL:** https://cses.fi/problemset/task/1195

## Hướng tiếp cận

### Tóm tắt bài toán

Cho đồ thị có hướng có trọng số không âm. Tìm chi phí tối thiểu để đi từ đỉnh 1 đến đỉnh $n$, với khả năng giảm một nửa (chia nguyên) giá của đúng một cạnh trên đường đi.

### Ý tưởng chính

Mở rộng Dijkstra bằng cách thêm chiều trạng thái theo dõi việc sử dụng phiếu giảm giá. Gọi $d[u][k]$ là chi phí tối thiểu đến đỉnh $u$ với $k = 0$ (chưa dùng phiếu) và $k = 1$ (đã dùng phiếu).

Cách này tạo đồ thị trạng thái với $2n$ đỉnh — mỗi đỉnh gốc $u$ tách thành $(u, 0)$ và $(u, 1)$. Vì mọi trọng số cạnh không âm và $\lfloor c/2 \rfloor \geq 0$, đồ thị trạng thái cũng có trọng số không âm, nên tính đúng của Dijkstra được bảo toàn. Mọi đường đi trong đồ thị gốc (có hoặc không dùng phiếu) tương ứng 1-1 với đường đi từ $(1, 0)$ đến $(n, 0)$ hoặc $(n, 1)$ trong đồ thị trạng thái: việc dùng phiếu trên cạnh $u \to v$ được mô hình bằng chuyển từ $(u, 0)$ sang $(v, 1)$ với trọng số $\lfloor c/2 \rfloor$, mọi cạnh sau chỉ có chuyển $k = 1 \to k = 1$, đảm bảo dùng đúng 1 lần.

### Thuật toán

1. Khởi tạo $d[1][0] = 0$, các $d[u][k]$ khác bằng $\infty$.
2. Chạy Dijkstra trên đồ thị trạng thái. Khi xử lý trạng thái $(u, k)$ với cạnh $u \to v$ trọng số $c$:
   - **Không dùng phiếu:** $d[v][k] = \min(d[v][k],  d[u][k] + c)$
   - **Dùng phiếu** (chỉ khi $k = 0$): $d[v][1] = \min(d[v][1],  d[u][0] + \lfloor c/2 \rfloor)$
3. Đáp án: $\min(d[n][0], d[n][1])$.

### Ví dụ minh họa

Đầu vào:
```
3 4
1 2 3
2 3 1
1 3 7
2 1 5
```

Dijkstra từ $(1, 0)$, $d[1][0] = 0$:
- Xử lý $(1, 0)$: cạnh $1 \to 2$ (3): $d[2][0] = 3$, $d[2][1] = \lfloor 3/2 \rfloor = 1$. Cạnh $1 \to 3$ (7): $d[3][0] = 7$, $d[3][1] = \lfloor 7/2 \rfloor = 3$.
- Xử lý $(2, 1)$, $d = 1$: cạnh $2 \to 3$ (1): $d[3][1] = \min(3, 1 + 1) = 2$.
- Xử lý $(2, 0)$, $d = 3$: cạnh $2 \to 3$ (1): $d[3][0] = \min(7, 3 + 1) = 4$.

Đáp án: $\min(d[3][0], d[3][1]) = \min(4, 2) = 2$ (dùng phiếu cho cạnh $1 \to 2$, rồi đi $2 \to 3$ bình thường).

Kết quả: `2`

## Độ phức tạp

- **Thời gian:** $O((n + m) \log n)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Flight%20Discount.cpp)
