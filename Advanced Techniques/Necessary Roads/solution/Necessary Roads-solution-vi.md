# Necessary Roads - Lời giải

**ID:** 2076 | **URL:** https://cses.fi/problemset/task/2076

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng liên thông $n$ đỉnh và $m$ cạnh. Tìm tất cả *con đường cần thiết* (cầu) — cạnh mà xóa nó làm đồ thị mất liên thông.

### Ý tưởng chính

Sử dụng thuật toán Tarjan dựa trên DFS với hai mảng:
- `num[u]`: thứ tự phát hiện đỉnh $u$ trong DFS.
- `low[u]`: thứ tự phát hiện nhỏ nhất đến được từ $u$ hoặc cây con của $u$ qua cạnh ngược (khởi tạo bằng `num[u]`).

Trong DFS đồ thị vô hướng, mọi cạnh không phải cạnh cây đều là cạnh ngược (đi tới tổ tiên). Do đó, nếu cây con của $v$ có cạnh ngược tới tổ tiên nào, tổ tiên đó cũng là tổ tiên của cha $u$ của $v$. Điều này cho thấy:

**Cạnh cây $(u, v)$ là cầu khi và chỉ khi $low[v] \geq num[v]$:**
- Nếu $low[v] \geq num[v]$: không đỉnh nào trong cây con $v$ có cạnh ngược tới tổ tiên của $v$, nên xóa $(u, v)$ sẽ cắt đứt cây con $v$.
- Nếu $low[v] < num[v]$: có cạnh ngược từ cây con $v$ tới tổ tiên của $v$ (cũng là tổ tiên của $u$), cung cấp đường đi thay thế không qua $(u, v)$.

**Cạnh ngược không bao giờ là cầu:** đường cây giữa hai đầu mút đã cung cấp đường thay thế.

### Thuật toán

1. Chạy DFS từ mỗi đỉnh chưa thăm $u$:
   - Gán `num[u]` = thứ tự phát hiện, `low[u] = num[u]`.
   - Với mỗi đỉnh kề $v$:
     - Nếu $v$ chưa thăm: đệ quy vào $v$, cập nhật `low[u] = min(low[u], low[v])`.
     - Nếu $v$ đã thăm và $v$ không phải cha: cập nhật `low[u] = min(low[u], num[v])`.
2. Với mỗi cạnh cây $(u, v)$: nếu $low[v] \geq num[v]$, thì $(u, v)$ là cầu.
3. Xuất tất cả cầu.

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

- Cạnh $(4,5)$: $low[5]=4 \geq num[5]=4$. Cầu. ✓ (đường duy nhất từ $\{3,5\}$ sang $\{1,2,4\}$)
- Cạnh $(5,3)$: $low[3]=5 \geq num[3]=5$. Cầu. ✓ (đường duy nhất tới đỉnh 3)
- Cạnh $(2,4)$: $low[4]=1 < num[4]=3$. Không phải cầu (chu trình $1\text{-}2\text{-}4\text{-}1$).

Cầu: **(4, 5)** và **(3, 5)**.

## Độ phức tạp

- **Thời gian:** $O(n + m)$
- **Bộ nhớ:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Necessary%20Roads.cpp)
