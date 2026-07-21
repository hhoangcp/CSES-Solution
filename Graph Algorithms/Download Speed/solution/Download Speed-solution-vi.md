# Tốc Độ Tải Xuống - Lời giải

**ID:** 1694 | **URL:** https://cses.fi/problemset/task/1694

## Hướng tiếp cận

### Tóm tắt bài toán

Cho mạng có hướng $n$ đỉnh, $m$ cạnh, mỗi cạnh có sức chứa $c$. Tìm luồng cực đại từ đỉnh 1 (nguồn) đến đỉnh $n$ (đích).

### Ý tưởng chính

Đây là bài toán **luồng cực đại** kinh điển. Sử dụng **thuật toán Dinic** kết hợp capacity scaling:

- **Cạnh dư:** Với mỗi cạnh thuận $u \to v$ sức chứa $c$, thêm cạnh ngược $v \to u$ sức chứa 0. Khi đẩy luồng $f$ trên cạnh thuận, sức chứa dư của cạnh ngược tăng $f$, cho phép "hủy" luồng đã gửi — yếu tố then chốt đảm bảo tính đúng và tối ưu.
- **BFS phân tầng:** Gán nhãn khoảng cách cho mỗi đỉnh từ nguồn, chỉ theo cạnh có sức chứa dư $\geq \text{limit}$. Điều này đảm bảo DFS luôn đi theo đường tăng ngắn nhất.
- **DFS tìm luồng chặn:** Tìm đường tăng trên đồ thị phân tầng, đẩy luồng dọc theo mỗi đường. Mảng `ptr[u]` (tối ưu cung hiện tại) bỏ qua cạnh đã bão hòa, tránh xét lại trong cùng pha.
- **Capacity scaling:** Bắt đầu `limit = 2^{30}`, giảm nửa khi BFS thất bại. Ưu tiên đẩy luồng lớn trước, cho $O(\log C)$ pha với $C$ là sức chứa lớn nhất.

Thuật toán kết thúc khi `limit = 0` và không còn đường tăng. Theo định lý luồng cực đại - lát cắt tối thiểu, luồng thu được là cực đại: nếu tồn tại đường tăng, luồng còn có thể tăng, mâu thuẫn với việc dừng.

### Thuật toán

1. **Xây mạng:** Với mỗi cạnh $(u, v, c)$, thêm cạnh thuận (sức chứa $c$) và cạnh ngược (sức chứa 0). Lưu cạnh kề nhau để cạnh $i$ có đối $i \oplus 1$.
2. **Vòng lặp scaling:** Với `limit` từ $2^{30}$ giảm dần về 1:
   - **BFS:** Xây đồ thị phân tầng theo cạnh có sức chứa dư $\geq \text{limit}$. Nếu không đến được đích, giảm `limit` một nửa.
   - **DFS:** Tìm luồng chặn trên đồ thị phân tầng. Mỗi đường tăng đẩy `limit` đơn vị: cạnh thuận $f + \text{limit}$, cạnh ngược $f - \text{limit}$.
3. Xuất tổng luồng.

### Ví dụ minh họa

Đầu vào:
```
4 5
1 2 3
2 4 2
1 3 4
3 4 5
4 1 3
```

- Pha limit = 4: BFS phân tầng $d = [0, -1, 1, 2]$ (chỉ theo cạnh dư $\geq 4$). DFS đẩy 4 đơn vị qua $1 \to 3 \to 4$. Luồng = 4.
- Pha limit = 2: BFS phân tầng $d = [0, 1, -1, 2]$. DFS đẩy 2 đơn vị qua $1 \to 2 \to 4$. Luồng = 6.
- Pha limit = 1: BFS thất bại (không còn đường tăng với dư $\geq 1$ từ 1 đến $n$). Giảm limit về 0, kết thúc.

Kết quả: `6`

## Độ phức tạp

- **Thời gian:** $O(n^2 \cdot m \cdot \log C)$ — mỗi pha Dinic mất $O(n^2 \cdot m)$, có $O(\log C)$ pha scaling.
- **Không gian:** $O(n + m)$ — danh sách kề và các mảng phụ.

## Mã nguồn (C++)

[Mã nguồn](../code/Download%20Speed.cpp)
