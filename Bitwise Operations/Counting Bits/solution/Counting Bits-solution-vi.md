# Counting Bits - Lời giải

**ID:** 1146 | **URL:** https://cses.fi/problemset/task/1146

## Phương pháp

### Tóm tắt bài toán

Đếm tổng số lượng bit 1 trong biểu diễn nhị phân của tất cả các số nguyên từ $1$ đến $n$.

### Ý tưởng chính

Gọi $f(n)$ là tổng số bit 1 từ $1$ đến $n$, và $p$ là vị trí MSB của $n$ ($2^p \le n < 2^{p+1}$). Chia $[1, n]$ thành khoảng hoàn chỉnh $[1, 2^p - 1]$ và khoảng còn lại $[2^p, n]$. Khoảng hoàn chỉnh đóng góp $p \cdot 2^{p-1}$ (mỗi trong $p$ vị trí bit được đặt đúng $2^{p-1}$ lần trong $2^p$ giá trị). Khoảng còn lại: bit MSB đóng góp $n - 2^p + 1$, các bit thấp hơn được đếm đệ quy bằng $f(n - 2^p)$.

### Thuật toán

Định nghĩa $f(n)$ đệ quy với $f(0) = 0$:

1. **Trường hợp cơ sở (khoảng hoàn chỉnh):** Nếu $n = 2^{p+1} - 1$, mọi vị trí bit từ $0$ đến $p$ đều được đặt đúng $2^p$ lần trong $2^{p+1}$ giá trị từ $0$ đến $n$, suy ra $f(2^{p+1} - 1) = (p+1) \cdot 2^p$.
2. **Trường hợp đệ quy:** $f(n) = (n - 2^p + 1) + p \cdot 2^{p-1} + f(n - 2^p)$, trong đó:
   - $(n - 2^p + 1)$: đóng góp bit MSB từ các số $2^p$ đến $n$.
   - $p \cdot 2^{p-1}$: đóng góp các bit thấp hơn trong khoảng hoàn chỉnh $[0, 2^p - 1]$.
   - $f(n - 2^p)$: đếm đệ quy các bit thấp hơn trong $[2^p, n]$ (bỏ bit MSB).

### Ví dụ minh họa

**$n = 7$:** $p = 2$, và $7 = 2^3 - 1$ (trường hợp cơ sở).

$$f(7) = 3 \cdot 2^2 = 12$$

Kiểm tra: 1 (1), 10 (1), 11 (2), 100 (1), 101 (2), 110 (2), 111 (3) → tổng = 12.

**$n = 5$:** $p = 2$, $5 \ne 2^3 - 1$ (trường hợp đệ quy).

$$f(5) = (5 - 4 + 1) + 2 \cdot 2 + f(1) = 2 + 4 + 1 = 7$$

Kiểm tra: 1 (1), 10 (1), 11 (2), 100 (1), 101 (2) → tổng = 7.

## Độ phức tạp

- **Thời gian:** $O(\log^2 n)$ — $O(\log n)$ lần đệ quy, mỗi lần tìm MSB mất $O(\log n)$
- **Không gian:** $O(\log n)$ (độ sâu đệ quy)

## Mã nguồn (C++)

[Mã nguồn](../code/Counting%20Bits.cpp)
