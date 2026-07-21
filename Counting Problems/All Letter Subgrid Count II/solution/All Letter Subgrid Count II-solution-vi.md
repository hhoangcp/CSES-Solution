# All Letter Subgrid Count II - Lời giải

**ID:** 3416 | **URL:** https://cses.fi/problemset/task/3416

## Phương pháp

### Tóm tắt bài toán

Cho lưới $n \times n$ trong đó mỗi ô chứa một trong $k$ chữ cái in hoa đầu tiên, đếm số lượng lưới con **hình chữ nhật** (không chỉ hình vuông) chứa đầy đủ tất cả $k$ chữ cái.

### Bảng thưa 2D cho truy vấn OR bitmask

Vì $k \le 26$, mã hóa tập hợp chữ cái trong một vùng bằng bitmask 32 bit. Vùng chứa đủ $k$ chữ cái khi OR-mask $= (1 \ll k) - 1$. Tính chất quan trọng là phép OR **không bị ảnh hưởng bởi việc chồng lấp**: OR của các vùng chồng nhau bằng OR của hợp chúng, nên có thể dùng bảng thưa (khác với min/max khi chồng lấp gây vấn đề với tổng hay các phép toán khác).

Xây `st[k1][i][k2][j]` = OR-mask của hình chữ nhật $2^{k_1} \times 2^{k_2}$ bắt đầu tại $(i, j)$. Quá trình xây dựng dùng kỹ thuật nhân đôi chuẩn theo cả hai chiều trong $O(n^2 \log^2 n)$:

- Trước tiên, mở rộng từng hàng theo chiều ngang: `st[0][i][l][j] = st[0][i][l-1][j] | st[0][i][l-1][j + 2^{l-1}]`.
- Sau đó, mở rộng theo chiều dọc: `st[t][i][l][j] = st[t-1][i][l][j] | st[t-1][i + 2^{t-1}][l][j]`.

**Truy vấn** hình chữ nhật $(x_1, y_1)$ đến $(x_2, y_2)$ trong $O(1)$: đặt $lx = \lfloor\log_2(x_2 - x_1 + 1)\rfloor$, $ly = \lfloor\log_2(y_2 - y_1 + 1)\rfloor$. Bốn hình chữ nhật lũy thừa 2 chồng nhau phủ kín vùng mục tiêu:

$$\text{result} = st[lx][x_1][ly][y_1] \mid st[lx][x_2{-}2^{lx}{+}1][ly][y_1] \mid st[lx][x_1][ly][y_2{-}2^{ly}{+}1] \mid st[lx][x_2{-}2^{lx}{+}1][ly][y_2{-}2^{ly}{+}1]$$

Vì OR là phép lũy đẳng (các vùng chồng lấp không gây đếm sai), biểu thức này cho đúng mask của hình chữ nhật mục tiêu.

### Hai con trỏ trên cột

Với mỗi cặp hàng $(l, r)$ (có $O(n^2)$ cặp), đếm số cặp cột $(j, i)$ với $j \le i$ sao cho hình chữ nhật hàng $[l, r]$, cột $[j, i]$ chứa đủ $k$ chữ cái.

**Tính đơn điệu:** Nếu hình chữ nhật $(l, j, r, i)$ chứa đủ chữ cái, thì mở rộng nó (giảm $j$ hoặc tăng $i$) vẫn giữ nguyên tính chất — thêm ô chỉ thêm chữ cái qua phép hợp. Tương đương, với biên phải cố định $i$, nếu tăng $j$ (thu hẹp hình chữ nhật) và mất một chữ cái cần thiết, tiếp tục tăng $j$ không thể lấy lại chữ cái đó. Vậy biên trái hợp lệ nhỏ nhất chỉ tăng khi $i$ tăng.

**Thuật toán:** Duy trì con trỏ $j$ (cột nhỏ nhất sao cho hình chữ nhật **chưa** chứa đủ chữ cái; các biên trái hợp lệ là $1, \ldots, j-1$). Với mỗi $i$ từ 1 đến $n$:

```
while j ≤ i và hình chữ nhật (l, j, r, i) chứa đủ chữ cái:
    j++
đóng góp = j - 1
```

Con trỏ $j$ chỉ tiến về phía trước qua tất cả $i$, nên mỗi cặp hàng mất $O(n)$ phân tán, cộng $O(n)$ truy vấn bảng thưa.

### Ví dụ minh họa

**Ví dụ đề bài:** $n = 5$, $k = 3$, lưới:

```
A B B B C
B B B B C
B C A A A
A A A A A
A A A A A
```

**Cặp hàng $(1, 3)$ (1-indexed):**

| $i$ | $j$ (sau vòng lặp) | Hình chữ nhật kiểm tra | Đóng góp ($j-1$) |
|-----|---------------------|------------------------|------------------|
| 1 | 1 | $(1,1,3,1)$: $\{A,B\} \ne$ full | 0 |
| 2 | 2 | $(1,1,3,2)$: $\{A,B,C\}$ = full → $j$++ ; $(1,2,3,2)$: $\{B,C\} \ne$ full → dừng | 1 |
| 3 | 3 | $(1,2,3,3)$: $\{A,B,C\}$ = full → $j$++ ; $(1,3,3,3)$: $\{A,B\} \ne$ full → dừng | 2 |
| 4 | 3 | $(1,3,3,4)$: $\{A,B\} \ne$ full → dừng | 2 |
| 5 | 5 | $(1,3,3,5)$: $\{A,B,C\}$ = full → $j$++ ; $(1,4,3,5)$: $\{A,B,C\}$ = full → $j$++ ; $(1,5,3,5)$: $\{A,C\} \ne$ full → dừng | 4 |

Tổng cho cặp hàng này: $0 + 1 + 2 + 2 + 4 = 9$.

**Tổng trên tất cả 15 cặp hàng** $(l, r)$ với $l \le r$ là **70**. ✓

## Độ phức tạp

- **Thời gian:** $O(n^2 \log^2 n + n^3)$ — $O(n^2 \log^2 n)$ xây bảng thưa, $O(n^3)$ duyệt tất cả cặp hàng với hai con trỏ.
- **Bộ nhớ:** $O(n^2 \log^2 n)$ — cho bảng thưa 2D.

## Mã nguồn (C++)

[Mã nguồn](../code/All%20Letter%20Subgrid%20Count%20II.cpp)
