# Counting Tilings - Lời giải

**ID:** 2181 | **URL:** https://cses.fi/problemset/task/2181

## Hướng tiếp cận

### Tóm tắt bài toán

Đếm số cách lấp đầy lưới $n \times m$ bằng domino $1 \times 2$ và $2 \times 1$, modulo $10^9 + 7$.

### Ý tưởng chính

Vì $n \le 10$ nhỏ, dùng **quy hoạch động profile bị cắt** (broken profile DP): xử lý từng ô từ trái sang phải, từ trên xuống dưới, theo dõi bitmask $n$ bit làm profile. Bit $k$ của profile bằng 1 nghĩa là ô ở hàng $k+1$, cột hiện tại đã bị chiếm bởi domino ngang kéo dài từ cột trước.

Với mỗi ô $(i, j)$ và mỗi profile $mask$, chuyển trạng thái xử lý ba trường hợp:

- **Ô đã bị chiếm** (bit $i{-}1$ bằng 1): ô đã được lấp bởi domino ngang từ cột $j{-}1$. Xóa bit: $mask' = mask \oplus (1 \ll (i{-}1))$.
- **Ô trống, đặt domino ngang** (bit $i{-}1$ bằng 0): lấp ô $(i, j)$ và $(i, j{+}1)$. Đặt bit để đánh dấu kéo dài: $mask' = mask \oplus (1 \ll (i{-}1))$.
- **Ô trống, đặt domino dọc** (bit $i{-}1$ bằng 0, và $i > 1$ với bit $i{-}2$ cũng bằng 0): lấp ô $(i{-}1, j)$ và $(i, j)$. Đánh dấu ô trên đã lấp: $mask' = mask \oplus (1 \ll (i{-}2))$.

Hai trường hợp đầu dùng chung công thức XOR — đặt domino ngang (set bit) và xóa bit đã chiếm đều lật bit $i{-}1$, nên code xử lý chung trong một dòng. Sau khi xử lý xong $n$ ô trong cột $j$, profile biểu diễn các domino ngang kéo dài sang cột $j{+}1$, được dùng làm đầu vào cho cột tiếp.

Mỗi cách lát hợp lệ tương ứng đúng một đường đi trong DP: tại mỗi ô, việc đặt domino xác định duy nhất profile tiếp. Ngược lại, mỗi đường đi xây dựng lại đúng một cách lát. Kết quả là $dp[0]$ sau khi xử lý tất cả $n \times m$ ô — profile 0 nghĩa là không có domino nào kéo dài ra ngoài lưới.

### Thuật toán

1. Khởi tạo $dp[0] = 1$, các trạng thái khác bằng $0$.
2. Với mỗi cột $j = 1$ đến $m$:
   - Với mỗi hàng $i = 1$ đến $n$:
     - Với mỗi profile $mask$ từ $0$ đến $2^n - 1$:
       - $dp'[mask] = dp[mask \oplus (1 \ll (i{-}1))]$ (xóa ô đã chiếm / đặt domino ngang).
       - Nếu $i > 1$ và bit $i{-}1$, bit $i{-}2$ của $mask$ đều bằng 0: $dp'[mask] \mathrel{+}= dp[mask \oplus (1 \ll (i{-}2))]$ (đặt domino dọc).
     - Đặt $dp = dp'$.
3. Kết quả là $dp[0] \bmod (10^9 + 7)$.

### Ví dụ minh họa

Input: $n = 4$, $m = 7$. Để minh họa, xét $n = 2$, $m = 3$:

Sau khi xử lý mỗi cột, giá trị $dp[mask]$:

| Sau cột | $dp[00]$ | $dp[01]$ | $dp[10]$ | $dp[11]$ |
|:---:|:---:|:---:|:---:|:---:|
| 1 | 1 | 0 | 0 | 1 |
| 2 | 2 | 0 | 0 | 1 |
| 3 | 3 | 0 | 0 | — |

- **Cột 1:** mask 00 = hai domino dọc (1 cách). mask 11 = hai domino ngang kéo sang cột 2 (1 cách).
- **Cột 2:** Từ mask 00 → cả dọc (→00) hoặc cả ngang (→11). Từ mask 11 → hai ô đã lấp sẵn, không chọn (→00). Vậy $dp[00]=1{+}1=2$, $dp[11]=1$.
- **Cột 3:** Cùng chuyển. $dp[00]=2{+}1=3$.

Kết quả: $dp[0] = 3$. (3 cách: cả dọc; trái dọc + phải ngang; trái ngang + phải dọc.)

Với input đề bài ($n=4, m=7$): $dp[0] = 781$.

## Độ phức tạp

- **Thời gian:** $O(n \cdot m \cdot 2^n)$
- **Không gian:** $O(2^n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Counting%20Tilings.cpp)
