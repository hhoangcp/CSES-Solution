# All Letter Subgrid Count I - Lời giải

**ID:** 3415 | **URL:** https://cses.fi/problemset/task/3415

## Phương pháp

### Tóm tắt bài toán

Cho lưới $n \times n$ trong đó mỗi ô chứa một trong $k$ chữ cái in hoa đầu tiên, đếm số lượng lưới con hình vuông chứa đầy đủ tất cả $k$ chữ cái.

### Tính đơn điệu và quy về kích thước tối thiểu

Nếu một hình vuông kích thước $s$ tại vị trí $(i, j)$ (góc dưới bên phải) chứa đủ $k$ chữ cái, thì mọi hình vuông lớn hơn có cùng góc dưới bên phải cũng chứa đủ — thêm ô chỉ thêm chữ cái qua phép hợp tập hợp. Tính đơn điệu này cho phép với mỗi vị trí $(i, j)$, ta chỉ cần tìm **kích thước nhỏ nhất** $s_{\min}$ sao cho hình vuông $s_{\min} \times s_{\min}$ chứa đủ $k$ chữ cái. Số hình vuông hợp lệ tại $(i, j)$ là:

$$\max\big(0,\ \min(i+1, j+1) - s_{\min} + 1\big)$$

### Kỹ thuật nhân đôi với bitmask

Vì $k \le 26$, mã hóa tập hợp chữ cái trong một hình vuông bằng bitmask 32 bit (chữ cái $c$ tương ứng bit $c - \text{A}$). Bitmask của hợp các vùng là phép OR bit của các mask. Hình vuông chứa đủ $k$ chữ cái khi mask $= (1 \ll k) - 1$.

Duy trì `mask[i][j]` = bitmask của hình vuông $l \times l$ có góc dưới bên phải tại $(i, j)$, với $l$ nhân đôi mỗi bước.

Với mỗi $l = 1, 2, 4, 8, \ldots$:

1. **Kiểm tra hình vuông $2l \times 2l$:** Kết hợp bốn mask $l \times l$:

$$\text{Mask}_{2l}(i,j) = \text{mask}[i][j] \mid \text{mask}[i{-}l][j] \mid \text{mask}[i][j{-}l] \mid \text{mask}[i{-}l][j{-}l]$$

   Bốn hình vuông $l \times l$ ghép đúng thành hình vuông $2l \times 2l$, nên OR của chúng cho bitmask chính xác. Nếu $\text{Mask}_{2l}(i,j) = \text{full}$, tiến hành tìm kiếm nhị phân.

2. **Tìm kiếm nhị phân trong $[l, 2l]$:** Tìm kích thước nhỏ nhất $s \in [l, 2l]$ có mask bằng `full`. Tìm nhị phân trên độ dời $d \in [0, l]$ với kích thước $s = l + d$:

$$\text{Mask}_s(i,j) = \text{mask}[i][j] \mid \text{mask}[i{-}d][j] \mid \text{mask}[i][j{-}d] \mid \text{mask}[i{-}d][j{-}d]$$

   Bốn hình vuông $l \times l$ chồng nhau tại độ dời $d$ phủ đúng hình vuông $(l+d) \times (l+d)$ có góc dưới bên phải tại $(i, j)$, và OR của chúng thu đúng tập chữ cái trong vùng đó. Vì thêm ô chỉ thêm chữ cái (bitmask OR đơn điệu), tìm kiếm nhị phân cho kết quả chính xác.

3. **Ghi nhận kết quả:** Đặt $\text{hasAns}[i][j] = \text{true}$ và cộng $\max(0, \min(i+1, j+1) - s_{\min} + 1)$ vào tổng. Mảng `hasAns` tránh đếm trùng qua các lần lặp.

4. **Cập nhật mask biểu diễn $2l \times 2l$:** Gộp theo chiều dọc ($\text{mask}[i][j] \mathrel{|}= \text{mask}[i{-}l][j]$) rồi chiều ngang ($\text{mask}[i][j] \mathrel{|}= \text{mask}[i][j{-}l]$). Gộp dọc xếp hai vùng $l \times l$ thành dải $l \times 2l$; gộp ngang ghép hai dải thành hình vuông $2l \times 2l$ hoàn chỉnh.

### Ví dụ minh họa

**Ví dụ đề bài:** $n = 5$, $k = 3$, lưới:

```
A B B B C
B B B B C
B C A A A
A A A A A
A A A A A
```

**Truy vết vị trí (2, 2) (0-indexed), góc dưới phải = 'A':**

- $l = 1$: Kết hợp bốn ô $1 \times 1$: $\text{mask}[2][2] \cup \text{mask}[1][2] \cup \text{mask}[2][1] \cup \text{mask}[1][1] = \{A\} \cup \{B\} \cup \{C\} \cup \{B\} = \{A,B,C\} = \text{full}$.
  - Tìm nhị phân trong $[1, 2]$: kích thước 1 cho $\{A\} \ne$ full; kích thước 2 cho $\{A,B,C\}$ = full → $s_{\min} = 2$.
  - Số hình vuông: $\min(3, 3) - 2 + 1 = 2$ (hình vuông $2 \times 2$ và $3 \times 3$).

**Truy vết vị trí (4, 4), góc dưới phải = 'A':**

- $l = 1$: Bốn ô $1 \times 1$ đều là $A$ → $\{A\} \ne$ full. Bỏ qua.
  - Sau khi cập nhật, $\text{mask}[4][4]$ biểu diễn hình vuông $2 \times 2$ = $\{A\}$.
- $l = 2$: Kết hợp bốn mask $2 \times 2$:
  - $\text{mask}[4][4] = \{A\}$, $\text{mask}[2][4] = \{A,B,C\}$ (các ô B,C,A,A), $\text{mask}[4][2] = \{A\}$, $\text{mask}[2][2] = \{A,B,C\}$ (các ô B,B,C,A).
  - Kết hợp = $\{A,B,C\}$ = full.
  - Tìm nhị phân trong $[2, 4]$: kích thước 3 cho $\{A\} \ne$ full (bốn mask $2 \times 2$ chồng nhau ở góc dưới phải đều là $\{A\}$); kích thước 4 cho full → $s_{\min} = 4$.
  - Số hình vuông: $\min(5, 5) - 4 + 1 = 2$ (hình vuông $4 \times 4$ và $5 \times 5$).

**Kết quả:** Tổng trên tất cả 25 vị trí là **15**. ✓

## Độ phức tạp

- **Thời gian:** $O(n^2 \log n)$ — mỗi bước nhân đôi trong $O(\log n)$ bước xử lý $O(n^2)$ vị trí, tìm kiếm nhị phân thêm $O(\log n)$ mỗi vị trí.
- **Bộ nhớ:** $O(n^2)$ — cho mảng mask và hasAns.

## Mã nguồn (C++)

[Mã nguồn](../code/All%20Letter%20Subgrid%20Count%20I.cpp)
