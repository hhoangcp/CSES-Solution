# Factory Machines - Lời giải

**ID:** 1620 | **URL:** https://cses.fi/problemset/task/1620

## Phương pháp

### Tóm tắt bài toán

Có $n$ máy, máy thứ $i$ cần $a_i$ giây để sản xuất một sản phẩm. Các máy hoạt động đồng thời và liên tục. Tìm thời gian tối thiểu để sản xuất ít nhất $t$ sản phẩm.

### Ý tưởng chính

Gọi $f(T) = \sum_{i=1}^{n} \lfloor T / a_i \rfloor$ là tổng sản phẩm sau $T$ giây. Do mỗi hạng tử $\lfloor T/a_i \rfloor$ là hàm không giảm theo $T$, nên $f(T)$ cũng không giảm. Tập hợp các thời gian khả thi $\{T : f(T) \ge t\}$ có dạng $[T^*, +\infty)$ — cho phép tìm kiếm nhị phân trên kết quả để tìm $T^*$ nhỏ nhất. Dùng 64-bit cho $T$ và tổng tích lũy (có thể vượt $10^{18}$), dừng sớm khi tích lũy đạt $t$ để tránh tràn số.

### Thuật toán

1. Đặt $L = 0$, $R = 10^{18}$.
2. Tìm nhị phân $T$ trong $[L, R]$:
   - Với mỗi $mid$, tính $f(mid) = \sum \lfloor mid / a_i \rfloor$ (dừng sớm khi $\ge t$).
   - Nếu $f(mid) \ge t$: ghi nhận đáp án, tìm nửa trái.
   - Ngược lại: tìm nửa phải.

### Ví dụ minh họa

$n = 3$, $t = 7$, $a = [3, 2, 5]$.

| $T$ | $\lfloor T/3 \rfloor$ | $\lfloor T/2 \rfloor$ | $\lfloor T/5 \rfloor$ | Tổng | $\ge 7$? |
|-----|-----------------------|-----------------------|-----------------------|------|----------|
| 7 | 2 | 3 | 1 | 6 | Không |
| 8 | 2 | 4 | 1 | 7 | Có |

Đáp án: **8**.

## Độ phức tạp

- **Thời gian:** $O(n \log(10^{18})) = O(n \cdot 60)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Factory%20Machines.cpp)
