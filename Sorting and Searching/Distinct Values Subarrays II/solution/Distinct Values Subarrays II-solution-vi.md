# Distinct Values Subarrays II - Lời giải

**ID:** 2428 | **URL:** https://cses.fi/problemset/task/2428

## Phương pháp

### Tóm tắt bài toán

Cho mảng gồm $n$ số nguyên, đếm số mảng con liên tiếp có nhiều nhất $k$ giá trị phân biệt.

### Ý tưởng chính

Nếu mảng con $[l, r]$ có $\le k$ giá trị phân biệt thì mọi mảng con nằm trong nó cũng vậy — tính đơn điệu này cho phép dùng hai con trỏ. Duy trì cửa sổ trượt $[l, i]$ với $l$ là vị trí trái nhất sao cho cửa sổ chứa $\le k$ giá trị phân biệt. Dùng map `M` lưu tần suất và biến `diff` đếm số giá trị phân biệt. Khi thêm $a[i]$ làm `diff` vượt $k$, dịch $l$ sang phải và giảm tần suất cho đến khi `diff ≤ k`. Khi đó, $l$ là vị trí trái nhất hợp lệ vì nếu thử dịch $l$ thêm về trái thì đoạn đó sẽ có $> k$ giá trị phân biệt. Số mảng con hợp lệ kết thúc tại $i$ là $i - l + 1$ (tất cả đoạn $[j, i]$ với $l \le j \le i$), mỗi mảng con được đếm đúng một lần ứng với biên phải của nó.

### Thuật toán

1. Khởi tạo `l = 1`, `diff = 0`, `res = 0`, map `M` rỗng.
2. Với $i$ từ $1$ đến $n$:
   - Thêm $a[i]$ vào `M`, cập nhật `diff`.
   - Trong khi `diff > k`: giảm tần suất $a[l]$, nếu về 0 thì xóa khỏi map và giảm `diff`; tăng $l$.
   - `res += i - l + 1`.
3. Xuất `res`.

### Ví dụ minh họa

Mảng $[1, 2, 3, 1, 1]$, $k = 2$.

| $i$ | $a_i$ | Cửa sổ | `diff` | $l$ | Số mảng con | Ghi chú |
|-----|-------|--------|--------|-----|-------------|---------|
| 1 | 1 | $[1,1]$ | 1 | 1 | 1 | |
| 2 | 2 | $[1,2]$ | 2 | 1 | 2 | |
| 3 | 3 | $[2,3]$ | 2 | 2 | 2 | loại $a_1=1$ |
| 4 | 1 | $[3,4]$ | 2 | 3 | 2 | loại $a_2=2$ |
| 5 | 1 | $[3,5]$ | 2 | 3 | 3 | |

Tổng: $1 + 2 + 2 + 2 + 3 = \mathbf{10}$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — mỗi phần tử được thêm/xóa map đúng một lần
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Distinct%20Values%20Subarrays%20II.cpp)
