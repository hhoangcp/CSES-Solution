# Sliding Window Xor - Lời giải

**ID:** 3426 | **URL:** https://cses.fi/problemset/task/3426

## Hướng tiếp cận

### Tóm tắt bài toán

Cho mảng $n$ số nguyên (được sinh theo $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$), tính XOR bitwise của mỗi cửa sổ trượt $k$ phần tử. Xuất XOR của tất cả kết quả XOR cửa sổ. Lưu ý: $n$ có thể lên tới $10^7$, cần thuật toán $O(n)$.

### Ý tưởng chính

XOR có tính tự nghịch đảo ($a \oplus a = 0$), nên loại bỏ phần tử khỏi tổng XOR chỉ cần XOR lại chính nó — không cần phép trừ. Duy trì biến XOR chạy và cập nhật trong $O(1)$ mỗi bước bằng cách XOR phần tử mới vào và XOR phần tử rời ra.

### Thuật toán

**Bước 1: Sinh mảng.** Tính $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$ với $i \ge 2$. Lưu toàn bộ mảng để có thể loại phần tử rời cửa sổ.

**Bước 2: XOR chạy.** Duyệt $i$ từ 1 đến $n$:
1. XOR $x[i]$ vào `sum`.
2. Khi $i \ge k$: XOR $x[i-k]$ vào `sum` (loại phần tử rời đi vì $a \oplus a = 0$), rồi XOR `sum` vào `ans`.

Công thức đúng vì khi trượt từ $[i{-}k{+}1, i]$ sang $[i{-}k{+}2, i{+}1]$: `sum mới` = `sum cũ` $\oplus\ x[i{+}1] \oplus\ x[i{-}k{+}1]$. Phần tử rời đi $x[i{-}k{+}1]$ xuất hiện hai lần nên tự triệt tiêu về 0.

### Ví dụ minh họa

Với $n=8$, $k=5$, bộ sinh $x=3, a=7, b=1, c=11$:

Mảng sinh ra: $[3, 0, 1, 8, 2, 4, 7, 6]$.

- $i=5$: sum $= 3 \oplus 0 \oplus 1 \oplus 8 \oplus 2 = 8$. ans $= 8$
- $i=6$: sum $= 8 \oplus 4 \oplus 3 = 15$. ans $= 8 \oplus 15 = 7$
- $i=7$: sum $= 15 \oplus 7 \oplus 0 = 8$. ans $= 7 \oplus 8 = 15$
- $i=8$: sum $= 8 \oplus 6 \oplus 1 = 15$. ans $= 15 \oplus 15 = 0$

Đáp án: `0`

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Sliding%20Window%20Xor.cpp)
