# Writing Numbers - Lời giải

**ID:** 1086 | **URL:** https://cses.fi/problemset/task/1086

## Đề bài

Viết các số $1, 2, 3, \ldots$ và có thể nhấn mỗi phím chữ số (0-9) tối đa $n$ lần. Tìm số cuối cùng có thể viết.

## Hướng tiếp cận

### Nhận xét quan trọng

Nhiều người nghĩ $x \approx n$, nhưng viết một số 18 chữ số đã tốn 18 phím. "Ngân sách" $n$ bị tiêu hao càng nhanh khi số càng lớn, nên đáp án luôn nhỏ hơn $n$ rất nhiều khi $n$ lớn (ví dụ $n = 10^{18}$).

### Công thức đếm chữ số

Cần `count(x)` = số lần xuất hiện nhiều nhất của một chữ số từ 1 đến $x$. Tổng theo từng hàng $h \in \{1, 10, 100, \ldots\}$, với $d = 10h$:

$$\text{count\_pos}(x, h) = \left\lfloor \frac{x}{d} \right\rfloor \cdot h + \min\left(\max\left(x \bmod d - h + 1, 0\right), h\right)$$

- **Chu kỳ hoàn chỉnh:** $\lfloor x/d \rfloor$ cụm $d$ số, mỗi cụm đóng góp $h$ lần cho mỗi chữ số.
- **Phần dư:** cụm cuối đóng góp thêm tối đa $h$ lần.

Vì `count(x)` tăng đơn điệu, chặt nhị phân tìm $x$ lớn nhất thỏa `count(x) ≤ n`.

### Ví dụ

$n = 5$, kiểm tra $x = 12$:

- Hàng đơn vị $h = 1$: $\lfloor 12/10 \rfloor \cdot 1 + \min(\max(2 - 1 + 1, 0), 1) = 1 + 1 = 2$ (chữ số 1 trong số 1, 11)
- Hàng chục $h = 10$: $\lfloor 12/100 \rfloor \cdot 10 + \min(\max(12 - 10 + 1, 0), 10) = 0 + 3 = 3$ (chữ số 1 trong số 10, 11, 12)
- Tổng chữ số 1: $2 + 3 = 5 = n$. Viết đến 13 cần thêm 1 phím số 1 nữa.

Kết quả: **12**.

## Độ phức tạp

- **Thời gian:** $O(\log r \cdot \log_{10} r)$ với $r = 9 \times 10^{17}$
- **Bộ nhớ:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Writing%20Numbers.cpp)
