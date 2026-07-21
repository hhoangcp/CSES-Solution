# Inverse Inversions - Lời giải

**ID:** 2214 | **URL:** https://cses.fi/problemset/task/2214

## Phương pháp

### Tóm tắt bài toán

Tạo một hoán vị của các số $1, 2, \ldots, n$ có đúng $k$ nghịch thế. Một nghịch thế là cặp $(a, b)$ với $a < b$ và $p_a > p_b$.

### Ý tưởng chính

Dùng hai con trỏ $l = 1$ và $r = n$ xây dựng hoán vị từ trái sang phải. Tại mỗi vị trí, nếu ngân sách còn lại $k \ge r - l$, đặt giá trị lớn nhất còn lại $r$ — điều này tạo đúng $r - l$ nghịch thế vì tất cả giá trị từ $l$ đến $r - 1$ sẽ xuất hiện sau $r$. Ngược lại, đặt giá trị nhỏ nhất còn lại $l$, tạo 0 nghịch thế.

Tham lam đúng vì mỗi lần đặt $r$ dùng tối đa nghịch thế có thể mà không vượt ngân sách: $r - l$ chính là số giá trị nhỏ hơn còn lại, và chỉ chọn $r$ khi đủ ngân sách đảm bảo $k$ được dùng hết. Mỗi bước $r - l$ giảm ít nhất 1 (tăng $l$ hoặc giảm $r$), nên khi $l = r$ ngân sách còn lại phải bằng 0 và chỉ còn một giá trị.

### Thuật toán

1. Khởi tạo $l = 1$, $r = n$.
2. Lặp khi $l < r$:
   - Nếu $k \ge r - l$: xuất $r$, đặt $k \mathrel{-}= r - l$, đặt $r \mathrel{-}= 1$.
   - Ngược lại: xuất $l$, đặt $l \mathrel{+}= 1$.
3. Xuất $l$ (bằng $r$).

### Ví dụ minh họa

$n = 5$, $k = 4$ (ví dụ đề bài, kết quả hợp lệ: `1 5 2 4 3` hoặc `5 1 2 3 4`):

| Bước | $l$ | $r$ | $k$ | $r - l$ | Hành động | Xuất |
|------|-----|-----|-----|---------|------------|------|
| 1 | 1 | 5 | 4 | 4 | $k \ge 4$ | 5 |
| 2 | 1 | 4 | 0 | 3 | $k < 3$ | 1 |
| 3 | 2 | 4 | 0 | 2 | $k < 2$ | 2 |
| 4 | 3 | 4 | 0 | 1 | $k < 1$ | 3 |
| 5 | 4 | 4 | 0 | 0 | $l = r$ | 4 |

Kết quả: `5 1 2 3 4` — nghịch thế: $(5,1), (5,2), (5,3), (5,4)$, tổng cộng 4.

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Không gian:** $O(1)$ (không tính kết xuất)

## Mã nguồn (C++)

[Mã nguồn](../code/Inverse%20Inversions.cpp)
