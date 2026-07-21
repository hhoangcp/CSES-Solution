# Missing Coin Sum - Lời giải

**ID:** 2183 | **URL:** https://cses.fi/problemset/task/2183

## Hướng tiếp cận

Sắp xếp các đồng xu theo thứ tự tăng dần, sau đó duy trì biến $cur$ với bất biến: **sau khi xử lý các đồng xu $a_1, \ldots, a_{i-1}$, ta có thể tạo ra mọi tổng từ $0$ đến $cur$**. Ban đầu $cur = 0$.

Khi xét đồng xu $a_i$ (đã sắp xếp):

- **Nếu $a_i > cur + 1$:** Ta không thể tạo ra tổng $cur + 1$. Mọi tập con chỉ dùng $a_1, \ldots, a_{i-1}$ có tổng $\leq cur$, và mọi tập con chứa ít nhất một đồng xu từ $a_i, a_{i+1}, \ldots$ có tổng $\geq a_i > cur + 1$ (do mảng đã sắp xếp). Vậy $cur + 1$ là tổng nhỏ nhất không tạo được, thuật toán dừng.

- **Nếu $a_i \leq cur + 1$:** Ta có thể tạo mọi tổng từ $0$ đến $cur + a_i$:
  - Tổng trong $[0, cur]$: tạo được theo bất biến.
  - Tổng trong $[a_i, cur + a_i]$: lấy tổng $t \in [0, cur]$ rồi cộng thêm $a_i$ ta được $t + a_i \in [a_i, cur + a_i]$.
  - Vì $a_i \leq cur + 1$, hai đoạn $[0, cur]$ và $[a_i, cur + a_i]$ nối liền nhau (không có khe hở). Cập nhật $cur \leftarrow cur + a_i$.

Nếu duyệt hết $n$ đồng xu mà không dừng, đáp án là $cur + 1$.

### Ví dụ minh họa

Xét $n = 5$, các đồng xu $[2, 9, 1, 2, 7]$. Sau khi sắp xếp: $[1, 2, 2, 7, 9]$.

| Bước ($i$) | $a_i$ | Điều kiện ($a_i \leq cur + 1$) | $cur$ mới | Đoạn tạo được |
|---|---|---|---|---|
| Khởi tạo | — | — | $0$ | $[0, 0]$ |
| 1 | $1$ | $1 \leq 1$ ✓ | $0 + 1 = 1$ | $[0, 1]$ |
| 2 | $2$ | $2 \leq 2$ ✓ | $1 + 2 = 3$ | $[0, 3]$ |
| 3 | $2$ | $2 \leq 4$ ✓ | $3 + 2 = 5$ | $[0, 5]$ |
| 4 | $7$ | $7 \leq 6$ ✗ | — | Khuyết tại $6$ |

Đáp án: $cur + 1 = 5 + 1 = 6$.

Kiểm tra: từ $\{1, 2, 2\}$ ta tạo được các tổng $0, 1, 2, 3, 4, 5$ nhưng không thể tạo $6$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — sắp xếp chi phối; bước duyệt chỉ mất $O(n)$.
- **Bộ nhớ:** $O(n)$ — lưu mảng.

## Mã nguồn (C++)

[Mã nguồn](../code/Missing%20Coin%20Sum.cpp)
