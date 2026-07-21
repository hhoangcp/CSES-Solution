# Reachable Nodes - Lời giải

**ID:** 2138 | **URL:** https://cses.fi/problemset/task/2138

## Phương pháp

### Tóm tắt bài toán

Cho DAG gồm $n$ đỉnh và $m$ cạnh, tính với mỗi đỉnh số đỉnh có thể đến được (bao gồm cả chính nó).

### Ý tưởng chính

Vì đồ thị là DAG, tập đỉnh đến được từ $u$ thỏa:

$$R(u) = \{u\} \cup \bigcup_{v \in \text{kế}(u)} R(v)$$

Xử lý đỉnh bằng DFS (thứ tự tô-pô ngược đảm bảo kế được tính trước). Quy nạp cấu trúc trên DAG: đỉnh không có kế chỉ đến được chính nó (cơ sở); đỉnh $u$ có kế $v_1, \ldots, v_k$ đến được chính nó và mọi đỉnh đến được từ các kế (bước quy nạp). DFS xử lý xong tất cả kế trước $u$, nên mỗi `dp[v_i]` đúng khi tính `dp[u]`.

**Tối ưu bitset:** Biểu diễn mỗi $R(u)$ bằng bitset $n$ bit. Phép hợp tương ứng với OR bit, tốn $O(n/64)$ thay vì $O(n)$. Với $n = 5 \times 10^4$, mỗi bitset chiếm $\approx 786$ từ 64-bit — phép OR chỉ mất 786 thao tác máy. Đếm số đỉnh bằng `__builtin_popcountll`.

### Thuật toán

1. Với mỗi đỉnh chưa thăm $u$, chạy DFS:
   - Đặt bit $u$ trong `dp[u]`.
   - Với mỗi kế $v$: đệ quy vào $v$, rồi OR `dp[v]` vào `dp[u]`.
2. Với mỗi đỉnh, đếm bit 1 trong `dp[u]` và xuất.

### Ví dụ minh họa

5 đỉnh, 6 cạnh: $(1,2), (1,3), (1,4), (2,3), (3,5), (4,5)$.

| Đỉnh | Kế | $R(u)$ | Đếm |
|------|-----|--------|------|
| 5    | —   | {5}    | 1    |
| 4    | {5} | {4, 5} | 2    |
| 3    | {5} | {3, 5} | 2    |
| 2    | {3} | {2, 3, 5} | 3 |
| 1    | {2, 3, 4} | {1, 2, 3, 4, 5} | 5 |

Kết quả: `5 3 2 2 1`

## Độ phức tạp

- **Thời gian:** $O\left(\dfrac{n \cdot (n + m)}{64}\right)$
- **Bộ nhớ:** $O\left(\dfrac{n^2}{64}\right)$

## Mã nguồn (C++)

[Mã nguồn](../code/Reachable%20Nodes.cpp)
