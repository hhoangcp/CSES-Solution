# Necessary Cities - Lời giải

**ID:** 2077 | **URL:** https://cses.fi/problemset/task/2077

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng liên thông $n$ đỉnh và $m$ cạnh. Tìm tất cả *thành phố cần thiết* (điểm khớp) — đỉnh mà xóa nó (cùng các cạnh kề) làm đồ thị mất liên thông.

### Ý tưởng chính

Sử dụng thuật toán Tarjan dựa trên DFS với hai mảng:
- `num[u]`: thứ tự phát hiện đỉnh $u$ trong DFS.
- `low[u]`: thứ tự phát hiện nhỏ nhất có thể đến từ $u$ hoặc cây con của $u$ qua cạnh ngược.

Đỉnh $u$ là điểm khớp khi và chỉ khi:
1. **Gốc cây DFS:** có $\geq 2$ con. Vì các cây con khác nhau không thể nối bằng cạnh (nếu có thì DFS sẽ duyệt qua), nên xóa gốc sẽ làm chúng mất liên thông.
2. **Đỉnh không phải gốc $u$ (cha của $v$):** $low[v] \geq num[u]$ với một con $v$ nào đó. Nghĩa là không đỉnh nào trong cây con $v$ đến được tổ tiên của $u$ qua cạnh ngược, nên xóa $u$ sẽ cắt đứt cây con $v$. Ngược lại, nếu $low[v] < num[u]$, tồn tại cạnh ngược không qua $u$, nên xóa $u$ không ảnh hưởng.

### Thuật toán

1. Chạy DFS từ mỗi đỉnh chưa thăm $u$:
   - Gán `lab[u] = -1` để đánh dấu gốc.
   - Gán `num[u]` = thứ tự phát hiện.
   - Với mỗi đỉnh kề $v$:
     - Nếu $v$ chưa thăm: đệ quy vào $v$, cập nhật `low[u] = min(low[u], low[v])`.
     - Nếu $v$ đã thăm (cạnh ngược): cập nhật `low[u] = min(low[u], num[v])`.
2. Xác định điểm khớp:
   - Gốc: là điểm khớp nếu có $\geq 2$ con cây DFS.
   - Không gốc: đỉnh $u$ (cha của $v$) là điểm khớp nếu $low[v] \geq num[u]$.
3. Xuất tất cả điểm khớp theo thứ tự tăng dần.

### Ví dụ minh họa

$n=5$, $m=5$, cạnh: $(1,2), (1,4), (2,4), (3,5), (4,5)$.

DFS từ đỉnh 1 (gốc):

| Đỉnh | `num` | `low` | Cha |
|------|-------|-------|-----|
| 1    | 1     | 1     | -1  |
| 2    | 2     | 1     | 1   |
| 4    | 3     | 1     | 2   |
| 5    | 4     | 4     | 4   |
| 3    | 5     | 5     | 5   |

- Đỉnh 4 là điểm khớp: con $v=5$, $low[5]=4 \geq num[4]=3$.
- Đỉnh 5 là điểm khớp: con $v=3$, $low[3]=5 \geq num[5]=4$.
- Đỉnh 1 không phải điểm khớp (gốc chỉ có 1 con).

Điểm khớp: **4, 5**.

## Độ phức tạp

- **Thời gian:** $O(n + m)$
- **Bộ nhớ:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Necessary%20Cities.cpp)
