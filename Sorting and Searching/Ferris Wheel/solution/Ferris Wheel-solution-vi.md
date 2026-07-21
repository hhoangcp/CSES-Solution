# Ferris Wheel - Lời giải

**ID:** 1090 | **URL:** https://cses.fi/problemset/task/1090

## Phương pháp

### Tóm tắt bài toán

Có $n$ đứa trẻ muốn đi vòng quay, trẻ thứ $i$ nặng $p_i$. Mỗi cabin chở tối đa 2 trẻ và tổng trọng lượng không vượt quá $x$. Tìm số cabin tối thiểu.

### Ý tưởng chính

Sắp xếp mảng trọng lượng tăng dần, rồi dùng hai con trỏ từ hai đầu. Trẻ nhẹ nhất luôn cần một cabin; ta cố gắng ghép nó với trẻ nặng nhất có thể để tiết kiệm cabin. Nếu $p_i + p_j \le x$, ghép chúng cùng cabin; nếu $p_i + p_j > x$, trẻ nặng nhất không thể ghép với ai (vì nó nặng hơn mọi trẻ còn lại) nên phải đi một mình. Chiến lược này tối ưu vì: nếu trong nghiệm tối ưu trẻ nhẹ nhất $i$ đi cùng trẻ $j$ nhẹ hơn trẻ nặng nhất $p$, ta có thể đổi — ghép $i$ với $p$ (vẫn hợp lệ vì $p_i + p_j \le x$ và $p_i \le p_j$) và giải phóng trẻ nhẹ $j$ dễ ghép hơn, không làm tăng số cabin.

### Thuật toán

1. Sắp xếp mảng $p$ tăng dần.
2. Khởi tạo $i = 1$, $j = n$, $\text{res} = 0$.
3. Trong khi $i \le j$:
   - Tăng `res` lên 1 (cabin cho trẻ $i$).
   - Nếu $p_i + p_j \le x$: ghép cặp, tăng $i$, giảm $j$.
   - Ngược lại: trẻ $j$ đi một mình, giảm $j$.

### Ví dụ minh họa

$n = 4$, $x = 10$, $p = [7, 2, 3, 9]$.

Sau khi sắp xếp: $[2, 3, 7, 9]$.

| Bước | $i$ | $j$ | $p_i$ | $p_j$ | $p_i + p_j$ | Hành động | Cabin | res |
|------|-----|-----|-------|-------|-------------|-----------|-------|-----|
| 1 | 1 | 4 | 2 | 9 | 11 > 10 | $j$ đi một mình | $\{9\}$ | 1 |
| 2 | 1 | 3 | 2 | 7 | 9 ≤ 10 | Ghép cặp | $\{2, 7\}$ | 2 |
| 3 | 2 | 2 | 3 | 3 | — | $i = j$, đi một mình | $\{3\}$ | 3 |

Kết quả: **3** cabin.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Ferris%20Wheel.cpp)
