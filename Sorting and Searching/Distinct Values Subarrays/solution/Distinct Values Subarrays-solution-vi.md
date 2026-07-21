# Distinct Values Subarrays - Lời giải

**ID:** 3420 | **URL:** https://cses.fi/problemset/task/3420

## Phương pháp

### Tóm tắt bài toán

Cho mảng gồm $n$ số nguyên, đếm số mảng con liên tiếp có tất cả phần tử phân biệt.

### Ý tưởng chính

Nếu mảng con $[l, r]$ có tất cả phần tử phân biệt thì mọi mảng con $[l', r']$ nằm trong nó cũng vậy — tính đơn điệu này cho phép dùng hai con trỏ. Duyệt biên phải $i$ từ trái sang phải, duy trì `maxLeft` là ranh giới trái nghiêm ngặt nhất: mọi mảng con kết thúc tại $i$ phải bắt đầu tại $j > \text{maxLeft}$. Khi gặp phần tử $a[i]$, ta cập nhật `maxLeft = max(maxLeft, Left[a[i]])` với `Left[a[i]]` là lần xuất hiện trước đó của giá trị $a[i]$. Công thức đúng vì: nếu $j \le \text{maxLeft}$ thì tồn tại giá trị xuất hiện hai lần trong $[j, i]$; nếu $j > \text{maxLeft}$ thì mọi giá trị trong $[j, i]$ chỉ xuất hiện một lần. Số mảng con hợp lệ kết thúc tại $i$ là $i - \text{maxLeft}$, và mỗi mảng con hợp lệ được đếm đúng một lần ứng với biên phải của nó.

### Thuật toán

1. Khởi tạo `maxLeft = 0`, `ans = 0`, map `Pos` và `Left`.
2. Với $i$ từ $1$ đến $n$:
   - `Left[a[i]] = Pos[a[i]]`, `Pos[a[i]] = i`.
   - `maxLeft = max(maxLeft, Left[a[i]])`.
   - `ans += i - maxLeft`.
3. Xuất `ans`.

### Ví dụ minh họa

Mảng $[1, 2, 1, 3]$, $n = 4$.

| $i$ | $a_i$ | $\text{Left}[a_i]$ | $\text{maxLeft}$ | Số mảng con | Ghi chú |
|-----|-------|---------------------|-------------------|-------------|---------|
| 1 | 1 | 0 | 0 | 1 | $\{1\}$ |
| 2 | 2 | 0 | 0 | 2 | $\{2\}, \{1,2\}$ |
| 3 | 1 | 1 | 1 | 2 | $\{1\}, \{2,1\}$ |
| 4 | 3 | 0 | 1 | 3 | $\{3\}, \{1,3\}, \{2,1,3\}$ |

Tổng: $1 + 2 + 2 + 3 = \mathbf{8}$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — truy vấn/cập nhật map $O(\log n)$ mỗi phần tử
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Distinct%20Values%20Subarrays.cpp)
