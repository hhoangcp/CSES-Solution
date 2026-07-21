# Strongly Connected Edges - Lời giải

**ID:** 2177 | **URL:** https://cses.fi/problemset/task/2177

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng, định hướng mỗi cạnh sao cho đồ thị có hướng kết quả liên thông mạnh. Nếu không thể, xuất "IMPOSSIBLE".

### Ý tưởng chính

Đồ thị vô hướng có thể định hướng liên thông mạnh khi và chỉ khi nó liên thông và không có cầu (2-liên thông cạnh). Nếu có cầu, mọi định hướng đều tạo cắt một chiều giữa hai phía cầu. Ngược lại, nếu không cầu, định hướng DFS hoạt động: cạnh cây đi cha→con, cạnh ngược đi con cháu→tổ tiên. Vì không có cầu, mọi cạnh cây $(u,v)$ có `low[v] <= num[u]`, tức cây con $v$ có cạnh ngược đạt đến $u$ hoặc cao hơn — cạnh ngược kết hợp cạnh cây tạo chu trình có hướng qua $(u,v)$. Mọi cạnh nằm trên chu trình nên đồ thị liên thông mạnh.

### Thuật toán

1. Chạy DFS từ đỉnh 1, tính `num[u]` và `low[u]`. Ghi hướng cạnh:
   - Cạnh cây (cha $u$, con $v$): định hướng $u \to v$. Nếu `low[v] > num[u]` (cầu), xuất IMPOSSIBLE và thoát.
   - Cạnh ngược (từ $v$ đến tổ tiên $u$): định hướng $v \to u$.
2. Sau DFS, nếu chưa thăm đủ $n$ đỉnh (không liên thông), xuất IMPOSSIBLE.
3. Ngược lại, xuất tất cả cạnh theo hướng đã định.

### Ví dụ minh họa

$n=3$, $m=3$, cạnh: 1-2, 1-3, 2-3. DFS: cạnh cây 1→2, 2→3; cạnh ngược 3→1. Không cầu. Kết quả: 1→2, 2→3, 3→1.

### Lưu ý cài đặt

- Dùng `tick[]` tránh xử lý/xuất cùng cạnh hai lần.
- Kiểm tra `low[v] > num[u]` phát hiện cầu; thoát ngay nếu tìm.
- Sau DFS, xác nhận mọi đỉnh đã thăm.

## Độ phức tạp

- **Thời gian:** $O(n + m)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Strongly%20Connected%20Edges.cpp)
