# Counting Numbers - Lời giải

**ID:** 2220 | **URL:** https://cses.fi/problemset/task/2220

## Hướng tiếp cận

### Tóm tắt bài toán

Đếm số số nguyên trong đoạn $[a, b]$ mà không có hai chữ số kề nhau nào giống nhau ($0 \le a \le b \le 10^{18}$).

### Ý tưởng chính

Dùng **quy hoạch động chữ số** (digit DP) với kỹ thuật đếm theo khoảng: $Cal(b) - Cal(a - 1)$, với $Cal(X)$ đếm số số nguyên hợp lệ trong $[0, X]$.

Gọi $DP(cur, e, tight)$ là số cách điền $cur$ chữ số còn lại, chữ số vừa đặt là $e$, và $tight$ cho biết tiền tố đã đặt có bằng tiền tố của $X$ hay không:

- $tight = 0$ (tự do): tiền tố nhỏ hơn, các chữ số còn lại tự do chọn từ 0–9 (chỉ cần $i \neq e$).
- $tight = 1$ (chặt): tiền tố bằng, chữ số tiếp theo tối đa là $C[cur]$ (chữ số tương ứng của $X$).

$$DP(cur, e, 0) = \sum_{\substack{i=0 \\ i \neq e}}^{9} DP(cur-1, i, 0)$$

$$DP(cur, e, 1) = \sum_{\substack{i=0 \\ i \neq e}}^{C[cur]} DP(cur-1, i, [i = C[cur]])$$

Khi $i < C[cur]$, tiền tố nhỏ hơn nên chuyển sang chế độ tự do. Khi $i = C[cur]$, giữ chế độ chặt. Trường hợp cơ sở: $DP(0, e, \cdot) = 1$. Theo quy nạp theo $cur$, mỗi cách chọn chữ số hợp lệ dẫn đến bài toán con đúng, và các cách chọn khác nhau cho số khác nhau ở vị trí $cur$, nên không trùng lặp.

Khi $tight = 0$, kết quả chỉ phụ thuộc $cur$ và $e$ (không phụ thuộc $X$), nên ta ghi nhớ — tối đa $18 \times 10$ trạng thái, mỗi trạng thái lặp 10 chữ số.

### Thuật toán

$Cal(X)$ — đếm số hợp lệ trong $[0, X]$:

1. Nếu $X < 10$: trả về $X$.
2. Biểu diễn $X$ thành $d$ chữ số $C[1], \ldots, C[d]$.
3. Đếm số có **ít hơn $d$ chữ số**: với mỗi độ dài $\ell$ từ 1 đến $d-1$, chữ số đầu từ 1–9 (không có số 0 đầu), còn lại tự do: $\sum_{\ell=1}^{d-1} \sum_{j=1}^{9} DP(\ell-1, j, 0)$.
4. Đếm số có **đúng $d$ chữ số** và $\le X$: chữ số đầu từ 1 đến $C[d]$: $\sum_{j=1}^{C[d]} DP(d-1, j, [j = C[d]])$.

Kết quả: $Cal(b) - Cal(a-1)$. (Khi $a = 0$, $Cal(-1) = -1$, nên kết quả là $Cal(b) + 1$, bao gồm đúng số 0.)

### Ví dụ minh họa

Input: $a = 123$, $b = 321$. Kết quả: $Cal(321) - Cal(122)$.

**$Cal(321)$:** $d = 3$, chữ số $C = [3, 2, 1]$.

- Số 1 chữ số: $9$.
- Số 2 chữ số: $9 \times 9 = 81$ (chữ số đầu 1–9, chữ số thứ hai khác chữ số đầu: 9 lựa chọn).
- Số 3 chữ số $\le 321$:
  - Chữ số đầu $= 1$ (tự do, vì $1 < 3$): $DP(2, 1, 0) = 9 \times 9 = 81$.
  - Chữ số đầu $= 2$ (tự do, vì $2 < 3$): $DP(2, 2, 0) = 81$.
  - Chữ số đầu $= 3$ (chặt): $DP(2, 3, 1)$. Chữ số thứ hai $\le C[2] = 2$ và $\neq 3$: chọn 0, 1, 2.
    - Chữ số 0 (tự do): $DP(1, 0, 0) = 9$.
    - Chữ số 1 (tự do): $DP(1, 1, 0) = 9$.
    - Chữ số 2 (chặt, vì $2 = C[2]$): $DP(1, 2, 1)$. Chữ số thứ ba $\le C[1] = 1$ và $\neq 2$: chọn 0, 1 → $2$.
  - Tổng chữ số đầu 3: $9 + 9 + 2 = 20$.

$Cal(321) = 9 + 81 + 81 + 81 + 20 = 272$.

**$Cal(122)$:** $d = 3$, chữ số $C = [1, 2, 2]$.

- Số 1 chữ số: $9$. Số 2 chữ số: $81$.
- Số 3 chữ số $\le 122$:
  - Chữ số đầu $= 1$ (chặt): $DP(2, 1, 1)$. Chữ số thứ hai $\le C[2] = 2$ và $\neq 1$: chọn 0, 2.
    - Chữ số 0 (tự do): $DP(1, 0, 0) = 9$.
    - Chữ số 2 (chặt): $DP(1, 2, 1)$. Chữ số thứ ba $\le C[1] = 2$ và $\neq 2$: chọn 0, 1 → $2$.
  - Tổng: $9 + 2 = 11$.

$Cal(122) = 9 + 81 + 11 = 101$.

Kết quả: $272 - 101 = 171$.

## Độ phức tạp

- **Thời gian:** $O(\log_{10} b \times 10)$ cho mỗi lần gọi $Cal$ sau ghi nhớ
- **Không gian:** $O(\log_{10} b \times 10)$ cho bảng ghi nhớ

## Mã nguồn (C++)

[Mã nguồn](../code/Counting%20Numbers.cpp)
