# Counting Bishops - Lời giải

**ID:** 2176 | **URL:** https://cses.fi/problemset/task/2176

## Phương pháp

### Tóm tắt bài toán

Đếm số cách đặt $k$ quân tượng trên bàn cờ $n \times n$ sao cho không có hai tượng tấn công nhau (không hai tượng cùng nằm trên một đường chéo). Kết quả modulo $10^9 + 7$.

### Tính độc lập theo màu

Trên bàn cờ, mỗi ô thuộc một trong hai màu. Tượng di chuyển theo đường chéo, và mỗi đường chéo gồm toàn ô cùng một màu. Do đó, tượng trên ô đen và ô trắng hoàn toàn độc lập — chúng không bao giờ tấn công nhau qua màu.

Chia bài toán: gọi $B_i$ = số cách đặt $i$ tượng không tấn công nhau trên ô đen, $W_j$ = số cách đặt $j$ tượng trên ô trắng. Đáp án là:

$$\text{ans} = \sum_{i=0}^{k} B_i \cdot W_{k-i}$$

### Quy về đặt xe trên bàn cờ hình thang

Sau khi xoay bàn cờ $45^\circ$, các đường chéo theo một hướng trở thành "hàng" và đường chéo theo hướng kia trở thành "cột." Đặt tượng không tấn công nhau (không hai tượng chung đường chéo) trở thành đặt xe không tấn công nhau (không hai xe chung hàng/cột) trên bàn cờ kết quả.

Bàn cờ sau xoay có dạng hình thang: với mỗi màu, kích thước các đường chéo sắp theo thứ tự không giảm tạo thành thang. Tính chất quan trọng của hình thang là các cột của mỗi hàng là tập cha của mọi hàng trước đó. Do đó khi xử lý hàng theo thứ tự không giảm, mỗi xe đã đặt cấm đúng một cột trên hàng hiện tại.

### Kích thước đường chéo

Với bàn cờ $n \times n$, các đường chéo mỗi màu (chỉ số $p = 1, 2, \ldots, 2n-1$) có kích thước:

$$\text{Squares}(p) = \begin{cases} \lfloor p/4 \rfloor \cdot 2 + 1 & \text{nếu } p \text{ lẻ} \\ \lfloor (p-1)/4 \rfloor \cdot 2 + 2 & \text{nếu } p \text{ chẵn} \end{cases}$$

Cách liệt kê này xử lý đường chéo theo thứ tự không giảm kích thước trong mỗi màu: chỉ số lẻ $1, 3, 5, \ldots$ cho một màu và chỉ số chẵn $2, 4, 6, \ldots$ cho màu kia. Với $n = 5$: kích thước ô đen là $\{1, 1, 3, 3, 5\}$ (tổng 13), ô trắng là $\{2, 2, 4, 4\}$ (tổng 12).

### Công thức truy hồi QHD

Gọi $\text{dp}[i][j]$ = số cách đặt $j$ tượng không tấn công nhau trên $i$ đường chéo đầu tiên (cùng màu). Bước nhảy 2 (hai đường chéo cùng màu liên tiếp cách nhau một đường chéo màu kia):

$$\text{dp}[i][j] = \text{dp}[i-2][j] + \text{dp}[i-2][j-1] \cdot (\text{Squares}(i) - j + 1)$$

- **Số hạng đầu:** Không đặt tượng trên đường chéo $i$.
- **Số hạng thứ hai:** Đặt 1 tượng trên đường chéo $i$. Có $\text{Squares}(i)$ ô, nhưng $j-1$ cột (tức đường chéo vuông góc) đã bị chiếm bởi các tượng trước đó. Mỗi tượng cấm đúng 1 ô trên đường chéo $i$ (hai đường chéo vuông góc giao nhau tại đúng 1 ô). Vậy $\text{Squares}(i) - (j-1)$ ô khả dụng.

Tính chất hình thang đảm bảo đếm chính xác: xử lý đường chéo theo thứ tự không giảm bảo đảm tất cả $j-1$ đường chéo vuông góc đã chiếm đều cắt đường chéo $i$.

### Ví dụ minh họa

**Ví dụ đề bài:** $n = 5$, $k = 4$.

**Ô trắng** (chỉ số chẵn, kích thước $\{2, 2, 4, 4\}$):

| $i$ | Kích thước | $j{=}0$ | $j{=}1$ | $j{=}2$ | $j{=}3$ | $j{=}4$ |
|-----|------------|---------|---------|---------|---------|---------|
| 0 | — | 1 | | | | |
| 2 | 2 | 1 | 2 | | | |
| 4 | 2 | 1 | 4 | 2 | | |
| 6 | 4 | 1 | 8 | 14 | 4 | |
| 8 | 4 | 1 | 12 | 38 | 32 | 4 |

Ví dụ, $\text{dp}[6][2] = \text{dp}[4][2] + \text{dp}[4][1] \cdot (4 - 2 + 1) = 2 + 4 \cdot 3 = 14$.

**Ô đen** (chỉ số lẻ, kích thước $\{1, 1, 3, 3, 5\}$): tương tự, $\text{dp}[9]$ cho $B_0{=}1, B_1{=}13, B_2{=}46, B_3{=}46, B_4{=}8$.

**Kết hợp:** $\sum_{i=0}^{4} B_i \cdot W_{4-i} = 1{\cdot}4 + 13{\cdot}32 + 46{\cdot}38 + 46{\cdot}12 + 8{\cdot}1 = 2728$. ✓

## Độ phức tạp

- **Thời gian:** $O(nk)$ — hai lượt QHD, mỗi đường chéo mất $O(k)$.
- **Bộ nhớ:** $O(nk)$ — cho bảng QHD.

## Mã nguồn (C++)

[Mã nguồn](../code/Counting%20Bishops.cpp)
