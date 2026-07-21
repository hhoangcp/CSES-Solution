# Sliding Window Or - Lời giải

**ID:** 3405 | **URL:** https://cses.fi/problemset/task/3405

## Hướng tiếp cận

### Tóm tắt bài toán

Cho mảng $n$ số nguyên (được sinh theo $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$), tìm phép OR bitwise của mỗi cửa sổ trượt $k$ phần tử. Xuất XOR của tất cả kết quả OR. Lưu ý: $n$ có thể lên tới $10^7$, cần thuật toán $O(n)$.

### Ý tưởng chính

Phép OR bitwise có tính lũy đẳng ($a \mid a = a$) và giao hoán/kết hợp, nên các đoạn chồng lấn có thể gộp mà không sai lệch. Điều này cho phép phân rã khối kiểu sparse table: mỗi cửa sổ kích thước $k$ trải nhiều nhất 2 khối, OR được tính từ mảng hậu tố và tiền tố trong $O(1)$.

### Thuật toán

**Bước 1: Sinh mảng.** Tính $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$ với $i \ge 2$.

**Bước 2: Phân rã khối kích thước $k$.** Chia mảng thành các khối kích thước $k$. Tiền tính:
- `dp[i]`: OR từ đầu khối chứa $i$ đến vị trí $i$. Đặt lại tại ranh giới khối ($i \bmod k = 0$).
- `dq[i]`: OR từ vị trí $i$ đến cuối khối chứa $i$. Đặt lại tại ranh giới khối ($({i+1}) \bmod k = 0$) hoặc cuối mảng.

**Bước 3: OR cửa sổ.** Mọi cửa sổ kích thước $k$ trải nhiều nhất 2 khối. OR của cửa sổ $[i, i{+}k{-}1]$ là:
$$\text{dq}[i] \mid \text{dp}[i+k-1]$$

Công thức đúng vì `dq[i]` bao phần hậu tố khối của $i$, `dp[i+k-1]` bao phần tiền tố khối tiếp theo. Do OR có tính giao hoán, kết hợp và lũy đẳng, việc gộp hai phần rời nhau cho kết quả chính xác — kể khi cửa sổ nằm trọn trong một khối (cả hai phần bao cùng đoạn, OR với chính nó vẫn giữ nguyên nhờ tính lũy đẳng).

Kết quả: $\bigoplus_{i=0}^{n-k} (\text{dq}[i] \mid \text{dp}[i+k-1])$.

### Ví dụ minh họa

Với $n=8$, $k=5$, bộ sinh $x=3, a=7, b=1, c=11$:

Mảng sinh ra: $[3, 0, 1, 8, 2, 4, 7, 6]$. Khối: $B_0=[3,0,1,8,2]$, $B_1=[4,7,6]$.

`dp = [3, 3, 3, 11, 11, 4, 7, 7]`, `dq = [11, 11, 11, 10, 2, 7, 7, 6]`.

- Cửa sổ 0 ($i{=}0$): `dq[0] | dp[4]` $= 11 \mid 11 = 11$
- Cửa sổ 1 ($i{=}1$): `dq[1] | dp[5]` $= 11 \mid 4 = 15$
- Cửa sổ 2 ($i{=}2$): `dq[2] | dp[6]` $= 11 \mid 7 = 15$
- Cửa sổ 3 ($i{=}3$): `dq[3] | dp[7]` $= 10 \mid 7 = 15$

Đáp án: $11 \oplus 15 \oplus 15 \oplus 15 = 4$.

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Sliding%20Window%20Or.cpp)
