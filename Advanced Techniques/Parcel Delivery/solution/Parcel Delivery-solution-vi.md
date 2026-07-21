# Parcel Delivery - Lời giải

**ID:** 2121 | **URL:** https://cses.fi/problemset/task/2121

## Phương pháp

### Tóm tắt bài toán

Cho $n$ thành phố và $m$ tuyến đường có hướng, mỗi tuyến có dung lượng $r$ (số bưu kiện tối đa) và chi phí $c$ mỗi bưu kiện. Gửi đúng $k$ bưu kiện từ thành phố 1 đến thành phố $n$ với tổng chi phí thấp nhất (hoặc báo $-1$ nếu không thể).

### Ý tưởng chính

Đây là bài toán **luồng chi phí tối thiểu** (min-cost flow): gửi $k$ đơn vị luồng từ nút 1 đến nút $n$, mỗi cạnh có dung lượng $r$ và chi phí $c$ mỗi đơn vị.

**Xây mạng luồng:** Mỗi tuyến đường $(a, b, r, c)$ tạo cạnh thuận (dung lượng $r$, chi phí $c$) và cạnh ngược (dung lượng 0, chi phí $-c$). Thêm siêu nguồn $S \to$ thành phố 1 và thành phố $n \to$ siêu hội $T$, cả hai dung lượng $k$, chi phí 0.

**Thuật toán đường tăng ngắn nhất liên tiếp (SSAP):** Lặp lại tìm đường tăng chi phí tối thiểu từ $S$ đến $T$ và đẩy luồng. Luồng đạt chi phí tối thiểu khi và chỉ khi không tồn tại đường tăng chi phí âm trong mạng dư — nếu có, tăng luồng theo đường đó sẽ giảm tổng chi phí, mâu thuẫn với tính tối ưu.

**Thế vị cho Dijkstra:** Cạnh ngược trong mạng dư có chi phí âm. Dùng thế vị `del[u]` (khoảng cách ngắn nhất từ $S$ đến $u$) để xác định chi phí rút gọn $w'(i) = c_i + del[u] - del[v] \geq 0$. Tính không âm cho phép dùng Dijkstra; tính bảo toàn đường ngắn nhất do $\sum_{i \in P} w'(i) = \sum_{i \in P} c_i + del[S] - del[T]$ (hằng số cho mọi đường).

### Thuật toán

1. Xây mạng luồng với siêu nguồn $S$ và siêu hội $T$.
2. Lặp lại:
   - Chạy Dijkstra với chi phí rút gọn tìm đường tăng chi phí tối thiểu.
   - Nếu không tìm được: nếu tổng luồng $< k$, xuất $-1$; ngược lại xuất tổng chi phí.
   - Tăng luồng tối đa qua đường tìm được (không vượt quá $k$ còn thiếu).
   - Cập nhật thế vị: $del[u] \mathrel{+}= dist[u]$ với mọi $u$ đến được.
3. Khi luồng đạt $k$, xuất tổng chi phí.

### Ví dụ minh họa

$n=4$, $m=5$, $k=3$. Tuyến: $(1,2,5,100), (1,3,10,50), (1,4,7,500), (2,4,8,350), (3,4,2,100)$.

| Lần | Đường đi | Chi phí/đơn vị | Tăng | Cộng dồn |
|-----|----------|----------------|------|----------|
| 1   | $1 \to 3 \to 4$ | $50+100=150$ | 2 (giới hạn cạnh $3\to4$) | $2 \times 150 = 300$ |
| 2   | $1 \to 2 \to 4$ | $100+350=450$ | 1 | $1 \times 450 = 450$ |

Tổng: $300 + 450 = \mathbf{750}$.

## Độ phức tạp

- **Thời gian:** $O(k \cdot m \log n)$
- **Bộ nhớ:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Parcel%20Delivery.cpp)
