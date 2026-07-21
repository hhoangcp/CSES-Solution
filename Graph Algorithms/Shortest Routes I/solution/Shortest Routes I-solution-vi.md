# Tuyến Đường Ngắn Nhất I - Lời giải

**ID:** 1671 | **URL:** https://cses.fi/problemset/task/1671

## Hướng tiếp cận

### Tóm tắt bài toán

Cho đồ thị có hướng có trọng số không âm với $n$ đỉnh và $m$ cạnh, tìm khoảng cách ngắn nhất từ đỉnh 1 đến tất cả các đỉnh còn lại.

### Ý tưởng chính

Bài toán đường đi ngắn nhất một nguồn với trọng số không âm, giải bằng **thuật toán Dijkstra**. Thuật toán duy trì mảng khoảng cách $d[u]$ và hàng đợi ưu tiên tối tiểu, hoạt động theo nguyên lý tham lam: luôn lấy đỉnh có khoảng cách tạm thời nhỏ nhất để tối ưu hóa các cạnh kề.

Tại mỗi bước, lấy đỉnh $u$ có $d[u]$ nhỏ nhất từ hàng đợi ưu tiên. Với mỗi cạnh $u \to v$ trọng số $c$: nếu $d[v] > d[u] + c$, cập nhật $d[v] = d[u] + c$ và đẩy khoảng cách mới vào hàng đợi. Các đỉnh không đến được từ đỉnh 1 giữ nguyên giá trị $+\infty$ ban đầu.

**Tính đúng đắn.** Khi đỉnh $u$ được lấy ra khỏi hàng đợi ưu tiên, $d[u]$ chính là khoảng cách ngắn nhất thực sự từ đỉnh 1 đến $u$. Giả sử ngược: tồn tại đường đi ngắn hơn $1 \leadsto u$ với độ dài $d^* < d[u]$. Trên đường đi này, gọi $v_i$ là đỉnh đầu tiên chưa được xử lý. Khi $v_{i-1}$ được xử lý, $d[v_i]$ đã được cập nhật không vượt quá khoảng cách ngắn nhất thực sự đến $v_i$. Vì mọi trọng số không âm, $d[v_i] \leq d^* < d[u]$, mâu thuẫn với việc $u$ được lấy ra trước $v_i$ (hàng đợi ưu tiên phải lấy $v_i$ ra trước).

### Thuật toán

1. Khởi tạo: $d[1] = 0$, $d[u] = +\infty$ với mọi $u \neq 1$. Đẩy $(0, 1)$ vào hàng đợi ưu tiên.
2. Lặp khi hàng đợi còn phần tử:
   - Lấy $(d_u, u)$ có khoảng cách nhỏ nhất.
   - Với mỗi cạnh $u \to v$ trọng số $c$: nếu $d[v] > d[u] + c$, cập nhật $d[v] = d[u] + c$ và đẩy $(d[v], v)$ vào hàng đợi.
3. Xuất $d[1], d[2], \ldots, d[n]$.

### Ví dụ minh họa

Input:
```
3 4
1 2 6
1 3 2
3 2 3
1 3 4
```

Các cạnh: $1 \to 2$ (6), $1 \to 3$ (2), $3 \to 2$ (3), $1 \to 3$ (4).

- Khởi tạo: $d[1] = 0$, $d[2] = d[3] = \infty$. Hàng đợi: $\{(0, 1)\}$.
- Lấy 1 ($d = 0$): tối ưu $1 \to 2$: $d[2] = 6$; tối ưu $1 \to 3$ (w=2): $d[3] = 2$; tối ưu $1 \to 3$ (w=4): $d[3] = 2 < 4$, bỏ qua. Hàng đợi: $\{(2, 3), (6, 2)\}$.
- Lấy 3 ($d = 2$): tối ưu $3 \to 2$: $d[2] = \min(6, 2 + 3) = 5$. Hàng đợi: $\{(5, 2)\}$.
- Lấy 2 ($d = 5$): không có cạnh đi ra. Hàng đợi: rỗng.

Kết quả: $d = [0, 5, 2]$.

Kết quả:
```
0 5 2
```

## Độ phức tạp

- **Thời gian:** $O((n + m) \log n)$ — mỗi đỉnh và mỗi cạnh được xử lý tối đa một lần; thao tác hàng đợi ưu tiên mất $O(\log n)$.
- **Bộ nhớ:** $O(n + m)$ — danh sách kề và các mảng phụ trợ.

## Mã nguồn (C++)

[Mã nguồn](../code/Shortest%20Routes%20I.cpp)
