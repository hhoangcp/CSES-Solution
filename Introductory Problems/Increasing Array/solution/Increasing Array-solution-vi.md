# Increasing Array - Lời giải

**ID:** 1094 | **URL:** https://cses.fi/problemset/task/1094

## Phương pháp

### Tóm tắt bài toán

Cho mảng $n$ số nguyên ($1 \le n \le 2 \times 10^5$, $1 \le a_i \le 10^9$). Tìm tổng số thao tác tăng phần tử lên 1 tối thiểu để mảng trở thành không giảm ($a_1 \le a_2 \le \cdots \le a_n$).

### Ý tưởng chính

Vì chỉ được tăng phần tử, nếu $a_i$ nhỏ hơn giá trị lớn nhất của tất cả phần tử trước nó, phải tăng $a_i$ lên ít nhất giá trị đó. Xử lý từ trái sang phải, duy trì `pre` = giá trị lớn nhất chạy của các phần tử đã xử lý (sau điều chỉnh):

- Nếu $a_i < pre$: tăng $a_i$ lên `pre`, tốn $pre - a_i$ thao tác.
- Nếu $a_i \geq pre$: không cần thao tác; cập nhật `pre = a_i`.

*Tính tối ưu:* Mảng kết quả $b$ bất kỳ phải thỏa $b_i \geq \max(a_1, \ldots, a_i)$ (do $b$ không giảm và $b_j \geq a_j$). Để tối thiểu $\sum(b_i - a_i)$, đặt mỗi $b_i$ bằng giá trị hợp lệ nhỏ nhất: $b_i = \max(a_1, \ldots, a_i)$ — chính là chiến lược giá trị lớn nhất chạy. Chọn $b_i$ lớn hơn vừa tốn thêm tại vị trí $i$ vừa gây ràng buộc chặt hơn cho phần tử sau, nên không thể tối ưu.

### Thuật toán

1. Khởi tạo `pre = 0`, `ans = 0`.
2. Với mỗi phần tử $a_i$: nếu $a_i < pre$, cộng $pre - a_i$ vào `ans`; ngược lại đặt `pre = a_i`.
3. Xuất `ans`.

### Ví dụ minh họa

Mảng: `[3, 2, 5, 1, 7]`

| $i$ | $a_i$ | `pre` | Chi phí | `pre` mới |
|-----|-------|--------|---------|-----------|
| 1 | 3 | 0 | 0 | 3 |
| 2 | 2 | 3 | 1 | 3 |
| 3 | 5 | 3 | 0 | 5 |
| 4 | 1 | 5 | 4 | 5 |
| 5 | 7 | 5 | 0 | 7 |

Tổng: **5** thao tác. Kết quả: `[3, 3, 5, 5, 7]`.

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Increasing%20Array.cpp)
