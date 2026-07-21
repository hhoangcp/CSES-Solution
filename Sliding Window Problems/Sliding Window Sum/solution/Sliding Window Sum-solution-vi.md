# Sliding Window Sum - Lời giải

**ID:** 3220 | **URL:** https://cses.fi/problemset/task/3220

## Hướng tiếp cận

### Tóm tắt bài toán

Cho mảng $n$ số nguyên (được sinh theo $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$), tính tổng mỗi cửa sổ trượt $k$ phần tử. Xuất XOR của tất cả các tổng. Lưu ý: $n$ có thể lên tới $10^7$, tổng cửa sổ có thể đạt $\sim 10^{16}$, cần dùng `long long`.

### Ý tưởng chính

Duy trì tổng chạy của cửa sổ hiện tại. Khi cửa sổ trượt sang phải, cộng phần tử mới và trừ phần tử rời đi. Mỗi bước cập nhật trong $O(1)$.

### Thuật toán

**Bước 1: Sinh mảng.** Tính $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$ với $i \ge 2$. Lưu toàn bộ mảng để có thể trừ phần tử rời cửa sổ.

**Bước 2: Tổng chạy.** Duyệt $i$ từ 1 đến $n$:
1. Cộng $x[i]$ vào `sum`.
2. Khi $i \ge k$: trừ $x[i-k]$ (phần tử rời cửa sổ), rồi XOR `sum` vào `ans`.

Tổng chạy đúng vì khi trượt từ cửa sổ $[i{-}k, i{-}1]$ sang $[i{-}k{+}1, i]$, tổng thay đổi đúng bằng $x[i] - x[i-k]$. Dùng `long long` cho `sum` và `ans` để tránh tràn số.

### Ví dụ minh họa

Với $n=8$, $k=5$, bộ sinh $x=3, a=7, b=1, c=11$:

Mảng sinh ra: $[3, 0, 1, 8, 2, 4, 7, 6]$.

- $i=5$: sum $= 3+0+1+8+2 = 14$. ans $= 14$
- $i=6$: sum $= 14 + 4 - 3 = 15$. ans $= 14 \oplus 15 = 1$
- $i=7$: sum $= 15 + 7 - 0 = 22$. ans $= 1 \oplus 22 = 23$
- $i=8$: sum $= 22 + 6 - 1 = 27$. ans $= 23 \oplus 27 = 12$

Đáp án: `12`

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Sliding%20Window%20Sum.cpp)
