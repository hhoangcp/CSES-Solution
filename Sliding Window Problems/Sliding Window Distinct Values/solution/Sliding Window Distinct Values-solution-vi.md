# Sliding Window Distinct Values - Lời giải

**ID:** 3222 | **URL:** https://cses.fi/problemset/task/3222

## Hướng tiếp cận

### Tóm tắt bài toán

Cho mảng $n$ số nguyên, với mỗi cửa sổ trượt gồm $k$ phần tử liên tiếp, đếm số giá trị phân biệt trong cửa sổ đó.

### Ý tưởng chính

Khi cửa sổ trượt sang phải một bước, chỉ có hai phần tử thay đổi: một phần tử bước vào, một phần tử rời đi. Duy trì bảng tần số của cửa sổ hiện tại và cập nhật tịnh tiến. Số giá trị phân biệt bằng `map.size()`, với điều kiện phải xóa các khóa có tần số bằng 0 — nếu không chúng sẽ bị đếm thừa.

### Thuật toán

Duy trì bảng tần số `cnt`. Duyệt $i$ từ 1 đến $n$:

1. **Thêm** $a[i]$: tăng `cnt[a[i]]`.
2. **Xóa** $a[i-k]$ (khi $i > k$): giảm `cnt[a[i-k]]`. Nếu tần số về 0, xóa khóa khỏi map.
3. **Xuất kết quả** (khi $i \ge k$): đáp án là `cnt.size()`.

Bước xóa khóa là then chốt: khóa có tần số 0 không tương ứng với phần tử nào trong cửa sổ, giữ lại sẽ làm `cnt.size()` bị phóng đại. Sau khi xóa, mọi khóa trong map đều có tần số $> 0$, nên `cnt.size()` đúng bằng số giá trị phân biệt hiện có.

### Ví dụ minh họa

Với $n=8$, $k=3$, mảng $[1, 2, 3, 2, 5, 2, 2, 2]$:

- $i=3$: cnt $= \{1, 2, 3\}$, kết quả 3
- $i=4$: thêm 2, xóa 1 (tần số về 0, xóa khóa). cnt $= \{2, 3\}$, kết quả 2
- $i=5$: thêm 5, xóa 2 (tần số 2→1). cnt $= \{2, 3, 5\}$, kết quả 3
- $i=6$: thêm 2, xóa 3 (tần số về 0, xóa khóa). cnt $= \{2, 5\}$, kết quả 2
- $i=7$: thêm 2, xóa 2 (tần số 3→2). cnt $= \{2, 5\}$, kết quả 2
- $i=8$: thêm 2, xóa 5 (tần số về 0, xóa khóa). cnt $= \{2\}$, kết quả 1

Kết quả: `3 2 3 2 2 1`

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Bộ nhớ:** $O(k)$

## Mã nguồn (C++)

[Mã nguồn](../code/Sliding%20Window%20Distinct%20Values.cpp)
